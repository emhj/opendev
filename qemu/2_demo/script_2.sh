#!/bin/bash

mkfs.ext2 -F test.img
mkdir -p tmp
sudo mount -o loop test.img tmp

