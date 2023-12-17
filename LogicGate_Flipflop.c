//
//성현욱
//2023.11.20
//test
//test2s
#include <stdio.h>
#include <time.h>

#define CLOCK tm.tm_sec % 2

void ratch(int* q, int* negativeQ, const int s, const int r) {
    
    *q = !(r | *negativeQ);
    *negativeQ = !(*q | s);
    
    if (*q == *negativeQ)
        ratch(q, negativeQ, s, r);
    
}

void srFlipflop(int* q, int * negativeQ, const int s, const int r) {
    
    // 시스템 시간 받아오기
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    
    printf("Clock123: %d, ", CLOCK);
    
    ratch(q, negativeQ, s & CLOCK, r & CLOCK);
    
}

void dFlipflop(int* q, int* negativeQ, const int d) {
    
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    
    printf("Clock: %d, ", CLOCK);
    
    ratch(q, negativeQ, d & CLOCK, !d & CLOCK);
    
}

void jkFlipflop(int* q, int* negativeQ, const int j, const int k) {
    
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    
    printf("Clock: %d, ", CLOCK);
    
    ratch(q, negativeQ, *negativeQ & j & CLOCK, *q & k & CLOCK);
    
}

void tFlipflop(int* q, int* negativeQ, const int t) {
    
    time_t tt = time(NULL);
    struct tm tm = *localtime(&tt);
    
    printf("Clock: %d, ", CLOCK);
    
    ratch(q, negativeQ, t & *negativeQ & CLOCK, t & *q & CLOCK);
    
    
}
