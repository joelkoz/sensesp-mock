/*
 noniso.cpp - replacements for non-ISO functions used by Arduino core
 Copyright © 2016 Ivan Grokhotkov
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
*/


#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <math.h>
#include "stdlib_noniso.h"
#include <stdio.h>


void reverse(char* begin, char* end) {
    char *is = begin;
    char *ie = end - 1;
    while(is < ie) {
        char tmp = *ie;
        *ie = *is;
        *is = tmp;
        ++is;
        --ie;
    }
}

char* utoa(unsigned value, char* result, int base) {
    if(base < 2 || base > 16) {
        *result = 0;
        return result;
    }

    char* out = result;
    unsigned quotient = value;

    do {
        const unsigned tmp = quotient / base;
        *out = "0123456789abcdef"[quotient - (tmp * base)];
        ++out;
        quotient = tmp;
    } while(quotient);

    reverse(result, out);
    *out = 0;
    return result;
}

char* itoa(int value, char* result, int base) {
    if(base < 2 || base > 16) {
        *result = 0;
        return result;
    }
    if (base != 10) {
	return utoa((unsigned)value, result, base);
   }

    char* out = result;
    int quotient = abs(value);

    do {
        const int tmp = quotient / base;
        *out = "0123456789abcdef"[quotient - (tmp * base)];
        ++out;
        quotient = tmp;
    } while(quotient);

    // Apply negative sign
    if(value < 0)
        *out++ = '-';

    reverse(result, out);
    *out = 0;
    return result;
}

int atoi(const char* s) {
    return (int) atol(s);
}

long atol(const char* s) {
    char * tmp;
    return strtol(s, &tmp, 10);
}

double atof(const char* s) {
    char * tmp;
    return strtod(s, &tmp);
}

char *dtostrf(double val, signed char width, unsigned char prec, char *sout) {

  char fmtStr[10];
  sprintf(fmtStr, "%%%d.%df", (int)width, (int)prec);
  sprintf(sout, fmtStr, val);
  return sout;
}


char* ltoa( long value, char *string, int radix ) {
    itoa((int)value, string, radix);
    return string;
}


char* ultoa( unsigned long value, char *string, int radix ) {
    itoa((int)value, string, radix);
    return string;
}