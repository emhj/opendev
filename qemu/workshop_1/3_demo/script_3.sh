#!/bin/bash

qemu-system-arm -M vexpress-a9                   \
                -nographic                       \
                -serial mon:stdio                \
                -serial stdio                    \
                -sd test.img                     \
                -kernel ../data/zImage           \
                -append "console=ttyAMA0,115200 root=/dev/mmcblk0 init=/bin/sh"
