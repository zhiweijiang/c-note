#!/bin/bash
if [ -e file ];then
    rm -rf file
else
    touch file
fi
exit 0;
