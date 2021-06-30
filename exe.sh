#!/bin/sh
#cria o Object file (arquivos.o)
gcc -c libraries/auxiliary_functions.c -lrt
gcc -c libraries/sorting_methods.c -lrt
gcc -c main.c -lrt

aux='auxiliary_functions.o'
sorting='sorting_methods.o'
main='main.o'

#cria o linker juntando todos os object file criados anteriorimente.
gcc -o binary $aux $sorting $main -lrt

#executa o linker (executavel)
./binary

rm *.o
rm binary