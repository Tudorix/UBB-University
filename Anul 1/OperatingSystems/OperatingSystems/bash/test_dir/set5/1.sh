#!/bin/bash

find $1 -type f | grep -Ec '\.c$'
