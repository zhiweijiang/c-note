#!/bin/bash
set -- "First one" "sencond" "third:one" "" "Fifth::one"
echo
echo 'IFS unchanged, using "$*"'
c=0
for i in "$*"
   do echo "$((c+=1)):[$i]"
   done
echo ---
echo 'IFS unchanged, using $*'
c=0
for i in $*
do echo "$((c+=1)):[$i]"
done
echo ---
echo 'IFS unchanged, using "$@"'
c=0
for i in "$@"
    do echo "$((c+=1)):[$i]"
    done
echo ---
echo 'IFS unchanged, using $@'
c=0
for i in $@
    do echo "$((c+=1)):[$i]"
    done
echo ---
IFS=:
echo 'IFS=":", using "$*"'
c=0
for i in "$*"
    do echo "$((c+=1)):[$i]"
    done
echo ---
echo 'IFS=":", using $*'
c=0
for i in $*
do echo "$((c+=1)):[$i]"
done
echo ---
var=$*
echo 'IFS=":", using "$var"(var=$*)'
c=0
for i in "$var"
do echo "$((c+=1)):[$i]"
done
echo ---
echo 'IFS=":", using $var(var=$*)'
for i in $var
do echo "$((c+=1)):[$i]"
done
echo ---
var="$*"
echo 'IFS=":", using $var (var="$*")'
c=0
for i in $var
do echo "$((c+=1)):[$i]"
done
echo ---
var="$*"
echo 'IFS=":", using "$var" (var="$*")'
c=0
for i in "$var"
do echo "$((c+=1)):[$i]"
done
echo ---
var="$*"
echo 'IFS=":", using "$@"'
c=0
for i in "$@"
do echo "$((c+=1)):[$i]"
done
echo ---

echo 'IFS=":", using $@'
c=0
for i in $@
do echo "$((c+=1)):[$i]"
done
echo ---
var=$@
echo 'IFS=":", using $var (var=$@)'
c=0
for i in $var
do echo "$((c+=1)):[$i]"
done
echo ---

echo 'IFS=":", using "$var" (var=$@)'
c=0
for i in "$var"
do echo "$((c+=1)):[$i]"
done
echo ---
var="$@"
echo 'IFS=":", using "$var" (var="$@")'
c=0
for i in "$var"
do echo "$((c+=1)):[$i]"
done
echo ---

echo 'IFS=":", using $var (var="$@")'
c=0
for i in $var
do echo "$((c+=1)):[$i]"
done
echo
exit 0
