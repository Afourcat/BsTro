#!/bin/bash

for i in `seq 1 250`; do

    nombre_1=$(cat /dev/urandom | tr -dc '0-9' | fold -w 256 | head -n 1 | sed -e 's/^0*//' | head --bytes $(( ( RANDOM % 30 )  + 1 )))
    nombre_2=$(cat /dev/urandom | tr -dc '0-9' | fold -w 256 | head -n 1 | sed -e 's/^0*//' | head --bytes $(( ( RANDOM % 30 )  + 1 )))
    result=$(echo "$nombre_1 - $nombre_2" | bc)
    attend=$(./sub/infin_sub $nombre_1 $nombre_2)

    echo $result > test1
    echo $attend > test2
    
    diff=$(diff test1 test2)

    if [ "$diff" == "" ]
	then
		echo -e "\033[32mOK	: Resultat = $result\033[0m"
	else
		echo -e "\033[31mKO     : Resultat = $result Attendu = $attend\033[0m"
		echo -e "RESULT  = $result
ATTENDU = $attend
PAR     : $nombre_1 - $nombre_2

" >> log 
    fi

done

for i in `seq 1 250`; do

    nombre_1=$(cat /dev/urandom | tr -dc '0-9' | fold -w 256 | head -n 1 | sed -e 's/^0*//' | head --bytes $(( ( RANDOM % 30 )  + 1 )))
    nombre_2=$(cat /dev/urandom | tr -dc '0-9' | fold -w 256 | head -n 1 | sed -e 's/^0*//' | head --bytes $(( ( RANDOM % 30 )  + 1 )))
    result=$(echo "$nombre_1 - -$nombre_2" | bc)
    attend=$(./sub/infin_sub $nombre_1 -$nombre_2)

    echo $result > test1
    echo $attend > test2
    
    diff=$(diff test1 test2)

    if [ "$diff" == "" ]
	then
		echo -e "\033[32mOK	: Resultat = $result\033[0m"
	else
		echo -e "\033[31mKO     : Resultat = $result Attendu = $attend\033[0m"
		echo -e "RESULT  = $result
ATTENDU = $attend
PAR     : $nombre_1 - $nombre_2

" >> log 
    fi

done

for i in `seq 1 250`; do

    nombre_1=$(cat /dev/urandom | tr -dc '0-9' | fold -w 256 | head -n 1 | sed -e 's/^0*//' | head --bytes $(( ( RANDOM % 30 )  + 1 )))
    nombre_2=$(cat /dev/urandom | tr -dc '0-9' | fold -w 256 | head -n 1 | sed -e 's/^0*//' | head --bytes $(( ( RANDOM % 30 )  + 1 )))
    result=$(echo "-$nombre_1 - $nombre_2" | bc)
    attend=$(./sub/infin_sub -$nombre_1 $nombre_2)

    echo $result > test1
    echo $attend > test2
    
    diff=$(diff test1 test2)

    if [ "$diff" == "" ]
	then
		echo -e "\033[32mOK	: Resultat = $result\033[0m"
	else
		echo -e "\033[31mKO     : Resultat = $result Attendu = $attend\033[0m"
		echo -e "RESULT  = $result
ATTENDU = $attend
PAR     : $nombre_1 - $nombre_2

" >> log 
    fi

done

for i in `seq 1 250`; do

    nombre_1=$(cat /dev/urandom | tr -dc '0-9' | fold -w 256 | head -n 1 | sed -e 's/^0*//' | head --bytes $(( ( RANDOM % 30 )  + 1 )))
    nombre_2=$(cat /dev/urandom | tr -dc '0-9' | fold -w 256 | head -n 1 | sed -e 's/^0*//' | head --bytes $(( ( RANDOM % 30 )  + 1 )))
    result=$(echo "-$nombre_1 - -$nombre_2" | bc)
    attend=$(./sub/infin_sub -$nombre_1 -$nombre_2)

    echo $result > test1
    echo $attend > test2
    
    diff=$(diff test1 test2)

    if [ "$diff" == "" ]
	then
		echo -e "\033[32mOK	: Resultat = $result\033[0m"
	else
		echo -e "\033[31mKO     : Resultat = $result Attendu = $attend\033[0m"
		echo -e "RESULT  = $result
ATTENDU = $attend
PAR     : $nombre_1 - $nombre_2

" >> log 
    fi

done

rm test1 test2

