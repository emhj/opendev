#!/bin/bash

qemu-system-arm -M vexpress-a9                    \
                -nographic                        \
                -serial mon:stdio                 \
                -serial stdio                     \
                -kernel ../data/zImage            \
                -append "console=ttyAMA0,115200"
