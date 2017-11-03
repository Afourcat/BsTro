#!/bin/sh
## EPITECH PROJECT, 2017
## bash
## File description:
## bash
##

echo "
#include <criterion/criterion.h>
#include \"infin_add.h\"
#include \"infin_sub.h\"
#include \"infin_mul.h\"
#include \"utils.h\"
" >> test_test.c

add=1

for i in `seq 1 3000`; do

    nombre_1=$(cat /dev/urandom | tr -dc '0-9' | fold -w 256 | head -n 1 | sed -e 's/^0*//' | head --bytes $(( ( RANDOM % 3000 )  + 1 )))
    nombre_2=$(cat /dev/urandom | tr -dc '0-9' | fold -w 256 | head -n 1 | sed -e 's/^0*//' | head --bytes $(( ( RANDOM % 3000 )  + 1 )))
    result=$(echo "$nombre_1 + $nombre_2" | bc)
    echo "Test (add, add_$add)
{
	cr_assert_str_eq(infin_add(my_strdup(\"$nombre_1\"), my_strdup(\"$nombre_2\")), \"$result\", \"Should return $result.\n\");
}

" >> test_test.c
add=$(($add + 1))
done

echo "Add Done."

sub=1

for i in `seq 1 3000`; do

    nombre_1=$(cat /dev/urandom | tr -dc '0-9' | fold -w 256 | head -n 1 | sed -e 's/^0*//' | head --bytes $(( ( RANDOM % 3000 )  + 1 )))
    nombre_2=$(cat /dev/urandom | tr -dc '0-9' | fold -w 256 | head -n 1 | sed -e 's/^0*//' | head --bytes $(( ( RANDOM % 3000 )  + 1 )))
    result=$(echo "$nombre_1 - $nombre_2" | bc)
    echo "Test (sub, sub_$sub)
{
	cr_assert_str_eq(infin_sub(my_strdup(\"$nombre_1\"), my_strdup(\"$nombre_2\")), \"$result\", \"Should return $result.\n\");
}

" >> test_test.c
sub=$(($sub + 1))
done

echo "Sub Done."

#mul=1

#for i in `seq 1 3001`; do

#    nombre_1=$(cat /dev/urandom | tr -dc '0-9' | fold -w 256 | head -n 1 | sed -e 's/^0*//' | head --bytes $(( ( RANDOM % 3000 )  + 1 )))
#    nombre_2=$(cat /dev/urandom | tr -dc '0-9' | fold -w 256 | head -n 1 | sed -e 's/^0*//' | head --bytes $(( ( RANDOM % 3000 )  + 1 )))
#    result=$(echo "$nombre_1 * $nombre_2" | bc)
#    echo "Test (mul, mul_$mul)
#{
#	cr_assert_str_eq(infin_mul(my_strdup(\"$nombre_1\"), my_strdup(\"$nombre_2\")), \"$result\", \"Should return $result.\n\");
#}

#" >> test_test.c
#mul=$(($mul + 1))
#done

#echo "Mul Done."


#div=1

#for i in `seq 1 3001`; do

#    nombre_1=$(cat /dev/urandom | tr -dc '0-9' | fold -w 256 | head -n 1 | sed -e 's/^0*//' | head --bytes $(( ( RANDOM % 3000 )  + 1 )))
#    nombre_2=$(cat /dev/urandom | tr -dc '0-9' | fold -w 256 | head -n 1 | sed -e 's/^0*//' | head --bytes $(( ( RANDOM % 3000 )  + 1 )))
#    result=$(echo "$nombre_1 / $nombre_2" | bc)
#    echo "Test (div, div_$div)
#{
#	cr_assert_str_eq(infin_div(my_strdup(\"$nombre_1\"), my_strdup(\"$nombre_2\")), \"$result\", \"Should return $result.\n\");
#}

#" >> test_test.c
#div=$(($div + 1))
#done

#echo "div Done."

#pow=1

#for i in `seq 1 3001`; do

#    nombre_1=$(cat /dev/urandom | tr -dc '0-9' | fold -w 256 | head -n 1 | sed -e 's/^0*//' | head --bytes $(( ( RANDOM % 3000 )  + 1 )))
#    nombre_2=$(cat /dev/urandom | tr -dc '0-9' | fold -w 256 | head -n 1 | sed -e 's/^0*//' | head --bytes $(( ( RANDOM % 3000 )  + 1 )))
#    result=$(echo "$nombre_1 ^ $nombre_2" | bc)
#    echo "Test (pow, pow_$pow)
#{
#	cr_assert_str_eq(infin_pow(my_strdup(\"$nombre_1\"), my_strdup(\"$nombre_2\")), \"$result\", \"Should return $result.\n\");
#}

#" >> test_test.c
#pow=$(($pow + 1))
#done

#echo "pow Done."


#mod=1

#for i in `seq 1 3001`; do

#    nombre_1=$(cat /dev/urandom | tr -dc '0-9' | fold -w 256 | head -n 1 | sed -e 's/^0*//' | head --bytes $(( ( RANDOM % 3000 )  + 1 )))
#    nombre_2=$(cat /dev/urandom | tr -dc '0-9' | fold -w 256 | head -n 1 | sed -e 's/^0*//' | head --bytes $(( ( RANDOM % 3000 )  + 1 )))
#    result=$(echo "$nombre_1 % $nombre_2" | bc)
#    echo "Test (mod, mod_$mod)
#{
#	cr_assert_str_eq(infin_mod(my_strdup(\"$nombre_1\"), my_strdup(\"$nombre_2\")), \"$result\", \"Should return $result.\n\");
#}

#" >> test_test.c
#mod=$(($mod + 1))
#done

#echo "mod Done."
