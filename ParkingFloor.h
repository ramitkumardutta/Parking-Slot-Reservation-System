#pragma once
#include <vector>
#include <string>
#include "Reservation.h"
#include "Utils.h"

using namespace std;

struct Spot {
    string id;
    bool isEV;
};

class ParkingFloor {
    int floorNo;
    vector<Spot> spots;

public:
    ParkingFloor(int no, int totalSpots);

    string findAvailableSpot(time_t start, time_t end,
                             const vector<Reservation>& allReservations,
                             bool needsEV,
                             bool isVIP);

    int getFloorNo() const;
};