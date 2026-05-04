#include "Utils.h"
#include <ctime>

bool isOverlap(time_t aStart, time_t aEnd, time_t bStart, time_t bEnd) {
    return (aStart < bEnd) && (bStart < aEnd);
}

time_t nowTime() {
    return std::time(nullptr);
}

time_t addDuration(time_t start, int h, int m, int s) {
    return start + h * 3600 + m * 60 + s;
}
