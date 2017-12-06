[ref1](https://www.postgresql.org/docs/9.0/static/app-pgdump.html)
[ref2]()
[ref3]()

# pg_dump

- extract a PostgreSQL database into a script file or other archive file

:pg_dump is a utility for backing up a PostgreSQL database. It makes consistent backups even if the database is being used concurrently. pg_dump does not block other users accessing the database

- -a : Dump only the data, not the schema (data definitions).

- -n {schema} : Dump only schemas matching schema; this selects both the schema itself, and all its contained objects. When this option is not specified, all non-system schemas in the target database will be dumped. Multiple schemas can be selected by writing multiple -n switches. 

- -N {schema} : Do not dump any schemas matching the schema pattern. The pattern is interpreted according to the same rules as for -n. -N can be given more than once to exclude schemas matching any of several patterns. 

- -t {table} : Dump only tables (or views or sequences) matching table. Multiple tables can be selected by writing multiple -t switches. Also, the table parameter is interpreted as a pattern according to the same rules used by psql's \d commands

- -T {table} : Do not dump any tables matching the table pattern. The pattern is interpreted according to the same rules as for -t. -T can be given more than once to exclude tables matching any of several patterns.
 
ex)
```
pg_dump -U username -d databasename -n schemaname > /a/b/c.sql
```

- pg_dump internally executes SELECT statements. If you have problems running pg_dump, make sure you are able to select information from the database using

- If your database cluster has any local additions to the template1 database, be careful to restore the output of pg_dump into a truly empty database; otherwise you are likely to get errors due to duplicate definitions of the added objects. To make an empty database without any local additions, copy from template0 not template1, for example:

```
CREATE DATABASE foo WITH TEMPLATE template0;
```
