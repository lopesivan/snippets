portable-arch
=============

Arch Linux goodness everywhere! Portable Arch, with docker.

To get it, do a 

    sudo docker pull thiagowfx/portable-arch
    
To start it, do a

    sudo docker run -t -i -v /dev/dri:/dev/dri:rw -v /tmp/.X11-unix/X0:/tmp/.X11-unix/X0:rw --privileged thiagowfx/portable-arch`
