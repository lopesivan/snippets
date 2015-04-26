#!/bin/sh

wget https://aur.archlinux.org/packages/co/cower/cower.tar.gz
tar zxvf cower.tar.gz
cd cower/
makepkg --skippgpcheck --noconfirm -si
