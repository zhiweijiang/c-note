#!/bin/bash
case $1 in
    "hello")
        echo "Hello, how are you ?"
        ;;
    "")
        echo "You MUST inpu parameters, ex> {$0 someword}"
        ;;
     *)
        echo "Usage $0 {hello}"
        ;;
esac
