// defs.h
#ifndef DEFS_H
#define DEFS_H

#include <stdio.h>

#define PRINT1(val) printf("val: %d\n", val) // print one
#define PRINT2(val1, val2) printf("val1: %d, val2: %d", val1, val2) // print two
#define MAX2(x, y) (x > y ? x : y) // return max of two
#define MAX3(x, y, z) (x > MAX2(y,z) ? x : MAX2(y,z)) // return max of three

#endif // !DEFS_H