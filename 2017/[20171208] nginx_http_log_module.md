# Module ngx_http_log_module

The ngx_http_log_module module writes request logs in the specified format.

# directive - access_log

- example

```
access_log /spool/logs/nginx-access.log compression buffer=32k;
```

```
Syntax:	access_log path [format [buffer=size] [gzip[=level]] [flush=time] [if=condition]];
access_log off;
Default:	access_log logs/access.log combined;
Context:	http, server, location, if in location, limit_except
```

: Sets the path, format, and configuration for a buffered log write. Several logs can be specified on the same level. Logging to syslog can be configured by specifying the “syslog:” prefix in the first parameter. 


# directive - log_format 

```
Syntax:	log_format name [escape=default|json] string ...;
Default:	
log_format combined "...";
Context:	http
```

: Specifies log format.


- $request_time : request processing time in seconds with a milliseconds resolution; time elapsed between the first bytes were read from the client and the log write after the last bytes were sent to the client
- $status : response status
- $time_local : local time in the Common Log Format
- $msec : time in seconds with a milliseconds resolution at the time of the log write
- $bytes_sent : the number of bytes sent to a client

- example
```
log_format combined '$remote_addr - $remote_user [$time_local] '
                    '"$request" $status $body_bytes_sent '
                    '"$http_referer" "$http_user_agent"';
```

# directive - open_log_file_cache

```
Syntax:	open_log_file_cache max=N [inactive=time] [min_uses=N] [valid=time];
open_log_file_cache off;
Default:	
open_log_file_cache off;
Context:	http, server, location
```
- Defines a cache that stores the file descriptors of frequently used logs whose names contain variables. The directive has the following parameters:

- max : sets the maximum number of descriptors in a cache; if the cache becomes full the least recently used (LRU) descriptors are closed

- inactive : sets the time after which the cached descriptor is closed if there were no access during this time; by default, 10 seconds

- valid : sets the time after which it should be checked that the file still exists with the same name; by default, 60 seconds

- off : disables caching.

- example
```
open_log_file_cache max=1000 inactive=20s valid=1m min_uses=2;
```