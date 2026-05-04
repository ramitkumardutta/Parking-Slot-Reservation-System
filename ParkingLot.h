#pragma once
#include <vector>
#include <string>
#include "ParkingFloor.h"
#include "Reservation.h"

class ParkingLot {
    std::vector<ParkingFloor> floors;
    std::vector<Reservation> reservations;

    ParkingLot() {}

public:
    static ParkingLot& getInstance();

    void addFloor(int spots);

    void makeReservation();
    void cancelReservation();

    std::string generateId();
};