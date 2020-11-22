### Understanding Transactions and Locking

* many commercial or open source databases are still (as of 2017) unable to handle concurrent reads and writes. In PostgreSQL, this is absolutely not a problem. Reads and writes can coexist. Writing transactions won't block reading transactions.


* Suppose you want to count the number of hits on a website. If you run the code as outlined just now, no hit can be lost because PostgreSQL guarantees that one UPDATE is performed after the other. PostgreSQL will only lock rows affected by the UPDATE.


* If one SELECT FOR UPDATE is waiting for some other SELECT FOR UPDATE, one has to wait until the other one completes (COMMIT or ROLLBACK). If the first transaction does not want to end, for whatever reason, the second transaction might potentially wait forever. To avoid that, it is possible to use SELECT FOR UPDATE NOWAIT.


* If NOWAIT is not flexible enough for you, consider using lock_timeout. It will contain the amount of time you want to wait on locks. You can set this on a per-session level:


* By default, PostgreSQL runs in READ COMMITTED transaction isolation mode. This means that every statement inside a transaction will get a new snapshot of the data, which will be constant throughout the query.


*  if you try to start a read uncommitted transaction, PostgreSQL will silently map to read committed.


### Making Sense of Backups and Replication


* PostgreSQL also provides a means to ensure that a crash cannot harm the data integrity or the data itself. It is guaranteed that if the power cuts out, the system will always be able to come back up again and do its job. The means to provide this kind of security is called write ahead log (WAL) or xlog.


* One thing to notice is that in PostgreSQL, the number of transaction log files is not related to the size of a transaction. You can have a very small set of transaction log files and still run a multi-TB transaction easily.


* when data is written, it first goes to the transaction log, and then a dirty buffer is put into shared buffers. Those dirty buffers have to go to disk and are written out to the data files by the background writer or during a checkpoint. As soon as all dirty buffers up to point have been written, the transaction log can be deleted.


* Please never ever delete transaction log files manually. In the event of a crash, your database server will not be able to start up again and the amount of disk space needed will be reclaimed anyway as new transactions come in. Never touch the transaction log manually. PostgreSQL takes care of things on its own, and doing things in there is really just harmful.


* Large checkpoint distances will actually decrease the amount of WAL created. Yes, that is right—larger checkpoint distances will lead to less WAL.


* PostgreSQL also allows us to configure whether or not checkpoints should be short and intense or whether they should be spread out over a longer period. The default value is 0.5, which means that the checkpoint should be done in a way that the process has finished between halfway between the current and the next checkpoint: Increasing this value basically means that the checkpoint is stretched out and less intensive. In many cases, a higher value has proven beneficial to flatten out I/O spikes caused by intense checkpointing.

```
#checkpoint_completion_target = 0.5 
```

* Note that you can put any command into the archive_command variable. Many people use rsync, scp, and so on to transport their WAL files to a safe location. If your script returns 0, PostgreSQL will assume that the file has been archived. If anything else is returned, PostgreSQL will try to archive the file again. This is necessary because the database engine has to ensure that no files are lost. To perform the recovery process, not a single file is allowed to go missing.


* --xlog-method=stream: By default, pg_basebackup connects to the master server and starts copying files over. Now, keep in mind that those files are modified while they are copied. The data reaching the backup is therefore inconsistent. This inconsistency can be repaired during the recovery process using the WAL. The backup itself, however, is not consistent. By adding --xlog-method=stream parameter it is possible to create a self-contained backup; it can be started directly without replaying transaction log (this is nice if you just want to clone an instance and not use PITR).


* There is one more thing to see in the archive. As described already, it is important to see that those files are actually archived. But there is more: when pg_basebackup extension is called, you will see a .backup file in the stream of WAL files. It is small and contains only some information about the base backup itself—it is purely informative and is not needed by the replay process. However, it gives you some vital clues. When you start to replay transaction log later on, you can delete all WAL files that are older than the .backup file. In this case, our backup file is called 000000010000000000000002.00000028.backup. This means that the replay process starts somewhere within file ...0002 (at position ...28). It also means that we can delete all files older than ...0002. Older WAL files won't be needed for recovery anymore. Keep in mind that you can keep more than just one backup around so I am only referring to the current backup.


* Keep in mind that base backups can happen while the database is fully operational—only a brief restart to change the max_wal_sender and wal_level variables is needed. The backup can happen while the database is fully active. Now after the system has been working properly, we might face a crash from which we want to recover. Therefore, we can perform PITR to restore as much data as potentially possible. The first thing we've got to do is take the base backup and put it at the desired location.


* It can be a good idea to save the old database cluster. Even if it is broken, your PostgreSQL support company might need it to track down the reason of the crash. You can still delete it later on once you've got everything up and running again.


* After the recovery has finished, the recovery.conf file will be renamed recovery.done so that you can see what you have done during recovery. All the processes of your database server will be up and running and you will have a ready to use database instance.


* The idea is to figure out how much WAL has already been replayed and to continue as necessary. However, keep this in mind: once a server has been promoted, you cannot just continue to replay WAL without further precautions.



* The idea behind streaming replication is simple. After an initial base backup, the secondary can connect to the master and fetch transaction log in real time and apply it. Transaction log replay is not a single operation anymore, but rather a continuous process that is supposed to keep running as long as the cluster exists.


* Theoretically, it is enough to have just one WAL sender process. However, it is pretty inconvenient. A base backup that uses the --xlog-method=stream parameter will already need two WAL sender processes. If you want to run a slave and perform a base backup at the same time, there are already three processes in use. So, make sure that you allow PostgreSQL to create enough processes to save on pointless restarts.


* Then comes the hot_standby variable. Basically, a master ignores the hot_standby variable and does not take it into consideration. All it does is to make the slave readable during WAL replay. So why do we care? Keep in mind: pg_basebackup extension will clone the entire server including its configuration. This means that if you have already set the value on the master, the slaves will automatically get it already when the data directory is cloned.


* Slaves can also connect to other slaves to stream transaction log. It is possible to cascade replication by simply creating base backups from a slave. So master really means source server in this context.