* The context is the scope of the setting. Some settings have a wider effect than others, depending on their context. User settings can be changed by each user to affect just that user’s sessions. If set by the superuser, the setting becomes a default for all users who connect after a reload. Superuser settings can be changed only by a superuser, and will apply to all users who connect after a reload. Users cannot individually override the setting. Postmaster settings affect the entire server (postmaster represents the PostgreSQL service) and take effect only after a restart.


* setting is the current setting; boot_val is the default setting; reset_val is the new setting if you were to restart or reload the server. Make sure that setting and reset_val match after you make a change. If not, the server needs a restart or reload.


* effective_cache_size : With a dedicated server, setting the value to half of your RAM is a good starting point. Changes require a reload.


* maintenance_work_mem : You shouldn’t set it higher than about 1 GB. Reload after changes.


* max_parallel_workers_per_gather : The setting determines the maximum parallel worker threads that can be spawned for each gather operation. The default setting is 0, which means parallelism is completely turned off. If you have more than one CPU core, you will want to elevate this. 


* There are few scenarios where you should cancel all active update queries: before backing up the database and before restoring the database.


* If you don’t terminate the connection, the client may immediately reconnect after restore and run the offending query anew. If you did not already cancel the queries on the connection, terminating the connection will cancel all of its queries.