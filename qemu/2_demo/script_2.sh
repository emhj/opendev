#!/bin/bash

mkfs.ext2 -F test.img
mkdir -p tmp
sudo mount -o loop test.img tmp
arm-linux-gnueabi-gcc -static -o hello hello_world.c

mkdir -p tmp/etc
cp hello tmp/etc/init

sleep 1

sudo umount tmp
rmdir tmp

