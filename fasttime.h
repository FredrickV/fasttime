/****************************************************************
* Name:       fasttime.h
* Purpose:    Fast clock timer for game engines
* Author:     Fredrick Vamstad
* Created:    2018 - August
* License:	  Public domain
****************************************************************/

#ifndef FAST_TIME_H
#define FAST_TIME_H

#include <stdint.h> // int64_t

#ifdef _WINDOWS
#define WIN32_LEAN_AND_MEAN
#include <windows.h>

typedef struct {
    LARGE_INTEGER startTime;
    LARGE_INTEGER freq;
}ftime_t;

// Initializes and sets the time. Call ftReset for further rounds
inline ftime_t ftInit() {
    ftime_t t;
    QueryPerformanceFrequency(&t.freq);
    QueryPerformanceCounter(&t.startTime);
    return t;
}

// Variant 2
inline void ftInit(ftime_t &t) {
    QueryPerformanceFrequency(&t.freq);
    QueryPerformanceCounter(&t.startTime);
}

// Note, ftInit must be called once
inline void ftReset(ftime_t &t) {
    QueryPerformanceCounter(&t.startTime);
}

inline int64_t ftElapsed(const ftime_t &t) {
    LARGE_INTEGER now;
    QueryPerformanceCounter(&now);
    return ((now.QuadPart - t.startTime.QuadPart) * 1000) / t.freq.QuadPart;
}
#endif // _WINDOWS


#endif // FAST_TIME_H 