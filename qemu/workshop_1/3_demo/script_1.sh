#!/bin/bash

qemu-img create test.img 100M
mkfs.ext2 -F test.img
mkdir -p tmp
sudo mount -o loop test.img tmp

mkdir -p tmp/bin
mkdir -p tmp/boot
mkdir -p tmp/dev
mkdir -p tmp/etc
mkdir -p tmp/home
mkdir -p tmp/lib
mkdir -p tmp/mnt
mkdir -p tmp/proc
mkdir -p tmp/root
mkdir -p tmp/sbin
mkdir -p tmp/sys
mkdir -p tmp/tmp
mkdir -p tmp/usr
mkdir -p tmp/var

cp busybox tmp/bin
cd tmp/bin

ln -s busybox init
ln -s busybox sh
ln -s busybox mount
ln -s busybox ls
ln -s busybox find
ln -s busybox sync
ln -s busybox klogd
ln -s busybox vi
ln -s busybox getty

cd -

sleep 1

sudo umount tmp
rmdir tmp

