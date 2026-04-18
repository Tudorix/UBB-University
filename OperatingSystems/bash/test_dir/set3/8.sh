#!/bin/bash

df -kP | awk 'NR>1 {
    size = $2        # total size (KB)
    used = $3
    avail = $4

    used_percent = used / size * 100

    if (size < 1048576 || used_percent > 80)
        print $0
}'
