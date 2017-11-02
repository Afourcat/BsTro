#!/bin/sh
## EPITECH PROJECT, 2017
## bash
## File description:
## bash
##

mul=1

for i in `seq 1 9000`; do

    nombre_1=$(cat /dev/urandom | tr -dc '0-9' | fold -w 256 | head -n 1 | sed -e 's/^0*//' | head --bytes $(( ( RANDOM % 30 )  + 1 )))
    nombre_2=$(cat /dev/urandom | tr -dc '0-9' | fold -w 256 | head -n 1 | sed -e 's/^0*//' | head --bytes $(( ( RANDOM % 30 )  + 1 )))
    result=$(echo "$nombre_1 * $nombre_2" | bc)
    echo "Test (mul, mul_$mul) 
{
	cr_assert_str_eq(infin_mul($nombre_1, $nombre_2), $result, \"Should return $result.\n\");
}

" >> test_test.c
mul=$(($mul + 1))
done
