#!/bin/sh

diff -q "$1" "$2" > /dev/null 2> /dev/null

if [ $? -eq 0 ]; then 
    echo "Test: \033[0;32mPASSED\033[0m"
else 
    echo "Test: \033[0;31mFAILED\033[0m"
    exit 1
fi