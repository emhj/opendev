#!/bin/bash

qemu-system-arm -M vexpress-a9                    \
                -nographic                        \
                -serial mon:stdio                 \
                -serial stdio                     \
                -drive file=test.img,if=sd        \
                -kernel ../data/zImage            \
                -append "console=ttyAMA0,115200"
