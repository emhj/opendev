#!/bin/bash

mkdir -p tmp
sudo mount -o loop test.img tmp

mkdir -p tmp/etc/init.d

echo "mount -t proc proc /proc" > tmp/etc/init.d/rcS
echo "mount -t devtmpfs devtmpfs /dev" >> tmp/etc/init.d/rcS
chmod a+x tmp/etc/init.d/rcS

sleep 1

sudo umount tmp
rmdir tmp

