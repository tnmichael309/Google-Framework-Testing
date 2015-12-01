#ifndef GTEST_SAMPLES_HW1_H_
#define GTEST_SAMPLES_HW1_H_

#include <stdio.h>

// Return expected sells
// 1 <= nLock <= 70 or nLock = -1
// 1 <= nBarrel <= 80
// 1 <= nStock <= 90
// lock: $45, barrel: $25, stock: $30
// commission rate: 10%
const char* Commission(int nLock, int nBarrel, int nStock);

// Returns next date
const char* NextDate(int year, int month, int day);

// Returns type of the triangle
const char* Triangle(int a, int b, int c);

#endif  // GTEST_SAMPLES_SAMPLE1_H_
