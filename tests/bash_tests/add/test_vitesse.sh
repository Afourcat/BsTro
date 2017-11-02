#!/bin/bash

for i in `seq 1 1000`; do

    nombre_1=$(cat /dev/urandom | tr -dc '0-9' | fold -w 256 | head -n 1 | sed -e 's/^0*//' | head --bytes $(( ( RANDOM % 3000 )  + 1 )))
    nombre_2=$(cat /dev/urandom | tr -dc '0-9' | fold -w 256 | head -n 1 | sed -e 's/^0*//' | head --bytes $(( ( RANDOM % 3000 )  + 1 )))
    ./add/infin_add $nombre_1 $nombre_2
done
