windows-setups-nevermore
========================

Install your favorite programs under Windows, **automatically**. It
should work fine under Windows 8+, and possibly under Windows 7 as
well.

The MIT License (MIT) Copyright (c) 2015 Thiago Barroso Perrotta. For
further details, see `LICENSE`.

# Instructions

1. Download the project files `setup.ps1`, `setup.cmd` and
   `packages.config`.
2. Choose the packages you want within the `packages.config` file. Its
syntax should be pretty straightforward. To add a new package, add a
line such as:

```<package id="Emacs" version="24.3" />```

You don't need to specify a version. ```<package id="Emacs" />```
would do it as well.

To find if your package exist, check out the
[Chocolatey Gallery](http://chocolatey.org/packages).

Now, just execute the ```setup.cmd``` file - you might double click in
it or run it from `cmd`.

- - -

Inspired by [this](http://www.developerfusion.com/article/145913/apt-windows-lets-get-chocolatey-part-2-multiple-installs-and-package-creation/).
