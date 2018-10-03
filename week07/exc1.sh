#!/bin/bash

rm testprog 2> /dev/null

gcc week06_exc6.c -o testprog
size testprog | cut -f 1-3 > ex1.txt

rm testprog
