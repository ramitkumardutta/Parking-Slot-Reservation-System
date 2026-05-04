#pragma once
#include <string>
#include <ctime>
#include "Vehicle.h"

using namespace std;

enum class ReservationStatus { ACTIVE, CANCELLED };

class Reservation {
public:
    string id;
    string name;
    string documentId;
    string vehicleNumber;
    VehicleType type;

    bool isVIP = false;
    bool needsCharging = false;

    time_t start;
    time_t end;
    string spotId;

    ReservationStatus status = ReservationStatus::ACTIVE;

    void print() const;
};