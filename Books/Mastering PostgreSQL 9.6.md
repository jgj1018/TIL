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