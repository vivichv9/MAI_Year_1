#!/bin/bash

while [ -n "$1" ]
do
case "$1" in
    -sf) suffix="$2"
    shift ;;
    -o) outFile="$2"
    shift ;;
    --) shift
    break ;;
    *) echo "$1 is not an option";;
esac
shift
done

path=$(pwd)
blockSize=4096

rm $outFile

for file in "$path"/*
do
    if [[ -f $file ]]
    then
        if ! [[ -x $file ]]
        then
            if [[ $file == *"$suffix."* ]]
            then
                size=$(wc -c $file | awk '{print $1}')
                if [[ $(( $size%$blockSize )) -eq 0 ]]
                then
                    echo "$file $size" | tee -a $outFile
                fi
            fi
        fi
    fi
done
