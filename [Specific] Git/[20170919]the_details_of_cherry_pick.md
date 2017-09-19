#Cherry-pick


- Given one or more existing commits, apply the change each one introduces, recording a new commit for each. This requires my working tree to be clean(no modifications from the HEAD commit)

- git commit's id is a hash of both its contents and its history. What git cherry-pick does, basically, is take a commit from somewhere else, and "play it back" wherever you are right now. 




[reference1](http://think-like-a-git.net/sections/rebase-from-the-ground-up/cherry-picking-explained.html)

[reference2](https://git-scm.com/docs/git-cherry-pick)