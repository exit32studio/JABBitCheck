#
# Makefile for BitCheck
#
# J.Bobula - 2017

JABBitCheck: JABBitCheck.c
	clang -ggdb3 -oO -std=c11 -Wall -Werror -o JABBitCheck JABBitCheck.c
    
