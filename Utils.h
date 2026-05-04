#pragma once
#include <ctime>

bool isOverlap(time_t aStart, time_t aEnd, time_t bStart, time_t bEnd);
time_t nowTime();
time_t addDuration(time_t start, int h, int m, int s);
