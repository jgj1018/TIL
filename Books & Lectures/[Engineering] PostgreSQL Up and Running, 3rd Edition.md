* The context is the scope of the setting. Some settings have a wider effect than others, depending on their context. User settings can be changed by each user to affect just that user’s sessions. If set by the superuser, the setting becomes a default for all users who connect after a reload. Superuser settings can be changed only by a superuser, and will apply to all users who connect after a reload. Users cannot individually override the setting. Postmaster settings affect the entire server (postmaster represents the PostgreSQL service) and take effect only after a restart.


* setting is the current setting; boot_val is the default setting; reset_val is the new setting if you were to restart or reload the server. Make sure that setting and reset_val match after you make a change. If not, the server needs a restart or reload.


* effective_cache_size : With a dedicated server, setting the value to half of your RAM is a good starting point. Changes require a reload.


* maintenance_work_mem : You shouldn’t set it higher than about 1 GB. Reload after changes.


* max_parallel_workers_per_gather : The setting determines the maximum parallel worker threads that can be spawned for each gather operation. The default setting is 0, which means parallelism is completely turned off. If you have more than one CPU core, you will want to elevate this. 


* There are few scenarios where you should cancel all active update queries: before backing up the database and before restoring the database.


* If you don’t terminate the connection, the client may immediately reconnect after restore and run the offending query anew. If you did not already cancel the queries on the connection, terminating the connection will cancel all of its queries.


* lock_timeout : This is the amount of time a query should wait for a lock before giving up, and is most applicable to update queries. Before data updates, the query must obtain an exclusive lock on affected records. The default is 0, meaning that the query will wait infinitely. This setting is generally used at the function or session level. lock_timeout should be lower than statement_timeout, otherwise statement_timeout will always occur first, making lock_timeout irrelevant.


* For backward compatibility, CREATE USER and CREATE GROUP still work in current versions, but shun them and use CREATE ROLE instead.


* You can bypass the password setting by mapping an OS root user to the new role and using ident, peer, or trust for authentication.


* You should never alter template0 because it is the immaculate model that you’ll need to copy from if you screw up your templates. Make your customizations to template1 or a new template database you create. You can’t change the encoding and collation of a database you create from template1 or any other template database you create. So if you need a different encoding or collation from those in template1, create the database from template0.


* You can pick any database to serve as the template. This could come in quite handy when making replicas.


* Use pg_dump to back up specific databases. To back up all databases in plain text along with server globals, use pg_dumpall, which    needs to run under a superuser account so that it back up all databases. Use pg_basebackup to do system-level disk backup of all databases.


* If you have a reasonably sized database, as in 500 GB or more, you should be using pg_basebackup as part of your backup strategy.