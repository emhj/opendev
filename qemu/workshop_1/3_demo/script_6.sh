#!/bin/bash

qemu-system-arm -M vexpress-a9                   \
                -nographic                       \
                -curses                          \
                -monitor pty                     \
                -serial stdio                    \
                -sd test.img                     \
                -kernel ../data/zImage           \
                -append "console=ttyAMA0,115200 root=/dev/mmcblk0"
