[reference1](https://git-scm.com/docs/git-reflog)

[reference2](https://git-scm.com/book/ko/v1/Git%EC%9D%98-%EB%82%B4%EB%B6%80-%EC%9A%B4%EC%98%81-%EB%B0%8F-%EB%8D%B0%EC%9D%B4%ED%84%B0-%EB%B3%B5%EA%B5%AC)

# Git reflog

Reference logs(reflogs) record when the tips of brances and other references were updated in the local repository.


```
git reflog
1a410ef HEAD@{0}: 1a410efbd13591db07496601ebc7a059dd55cfe9: updating HEAD
ab1afef HEAD@{1}: ab1afef80fac8e34258ff41fc1b867c702daa24b: updating HEAD
```

```
git branch recover-branch ab1afef
```

or

```
git reset --hard HEAD@{0}
```

"show" subcommand(default) the log of the reference provided in the command-line. The reflog covers all recent actions and in addition the HEAD reflog records branch switching.

when I delete ./git/logs/ all the datas of Reflog will be removed either. There is only one option that I can restore deleted commit in this situation.

```
// this show all the commits which doesn't belong to anywhere.
git fsck --full 
dangling blob d670460b4b4aece5915caf5c68d12f560a9fe3e4
dangling commit ab1afef80fac8e34258ff41fc1b867c702daa24b
dangling tree aea790b9a58f6cf6f2804eeac9f0abbe9631e4c9
dangling blob 7108f7ecb345ee9d0084193f147cdad4d2998293
```

```
git branch recover-branch ab1afef.
```