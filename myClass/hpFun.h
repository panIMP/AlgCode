#ifndef HP_FUN_H
#define HP_DFUN_H

#include <stdio.h>

#define DEBUG
#ifdef DEBUG
#define DEBUG_PRINT(info, ...) printf("File: " __FILE__ "\nLine: %d\n" info, __LINE__, ##__VA_ARGS__)
#else
#define DEBUG_PRINT(info, ...)
#endif

#endif // STDFUN_H
