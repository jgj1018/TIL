[ref1](https://getcomposer.org/doc/03-cli.md#install)
[ref2](https://getcomposer.org/doc/01-basic-usage.md)

# install

- The install command reads the composer.json file from the current directory, resolves the dependencies, and installs them into vendor. If there is a composer.lock file in the current directory, it will use the exact versions from there instead of resolving them. This ensures that everyone using the library will get the same versions of the dependencies.
- Tip: If you are using git for your project, you probably want to add vendor in your .gitignore. You really don't want to add all of that third-party code to your versioned repository.
 
- --dry-run: Simulate the command without actually doing anything.
- --dev: Install packages listed in require-dev (this is the default behavior).

# update

- In order to get the latest versions of the dependencies and to update the composer.lock file, you should use the update command.
- Note: Composer will display a Warning when executing an install command if composer.lock and composer.json are not synchronized.


- --lock: Only updates the lock file hash to suppress warning about the lock file being out of date.
- --dry-run: Simulate the command without actually doing anything.
- --dev: Install packages listed in require-dev (this is the default behavior).
# require

- The require command adds new packages to the composer.json file from the current directory. If no file exists one will be created on the fly.

- --no-update: Disables the automatic update of the dependencies.
- --dev: Add packages to require-dev.

# remove

The remove command removes packages from the composer.json file from the current directory.

- --no-update: Disables the automatic update of the dependencies.
- --dev: Add packages to require-dev.