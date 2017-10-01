# git add -p

--patch

: Interactively choose hunks of patch between the index and the work tree and add them to the index. This gives the user a chance to review the difference before adding modified contents to the index. 

y = stage this hunk
n = do not stage this hunk
q = quit; do not stage this hunk or any of the remaining one.
a = stage this hunk and all later hunks in the file.

# git commit -v

--verbose

: show unified diff between the HEAD commit and what would be committed at the bottom of the commit message template to help the user describe the commit by reminding what changes the commit has. Note that this diff output doesn't have its lines prefixed with #. This diff will not be a part of the commit message.

# git blame -L <start,end> <file> 

: Annotates each line in the given file with information from the revision which last modified the line. Optionally, start annotating from the given revision.

When specified one or more times, -L restricts annotation to the requested lines.

<start> and <end> are optional. “-L <start>” or “-L <start>,” spans from <start> to end of file. “-L ,<end>” spans from start of file to <end>. 