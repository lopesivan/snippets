FROM base/archlinux
MAINTAINER Thiago Perrotta <echo dGhpYWdvcGVycm90dGE5NUBnbWFpbC5jb20K | base64 -d>
RUN pacman --noprogressbar --noconfirm --needed -Syu base-devel 
RUN pacman --noprogressbar --noconfirm -Syu curl devtools git grml-zsh-config man-db man-pages mesa-demos mg mtr pkgfile rsync sudo tmux vim wget xf86-video-intel xorg-xeyes zsh
RUN pacman --noprogressbar --noconfirm -Scc

RUN useradd -m -G wheel -s /bin/bash archie && echo '%wheel ALL=(ALL) NOPASSWD:ALL' >> /etc/sudoers
USER archie 
WORKDIR /home/archie

ENV DISPLAY :0
ENV XSOCK "/tmp/.X11-unix/X0"

ADD install_cower.sh /home/archie/install_cower.sh
RUN exec sh -x ./install_cower.sh

CMD /bin/bash
