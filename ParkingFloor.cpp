#include "ParkingFloor.h"

ParkingFloor::ParkingFloor(int no, int totalSpots) {
    floorNo = no;

    for (int i = 1; i <= totalSpots; i++) {
        Spot s;
        s.id = "F" + to_string(no) + "-S" + to_string(i);
        s.isEV = (i % 3 == 0); // every 3rd spot is EV
        spots.push_back(s);
    }
}

string ParkingFloor::findAvailableSpot(time_t start, time_t end,
                                       const vector<Reservation>& reservations,
                                       bool needsEV,
                                       bool isVIP) {

    for (auto& spot : spots) {

        // EV filtering
        if (needsEV && !spot.isEV) continue;

        bool free = true;

        for (auto& r : reservations) {
            if (r.status == ReservationStatus::CANCELLED) continue;

            if (r.spotId == spot.id) {
                if (isOverlap(r.start, r.end, start, end)) {

                    // VIP override logic
                    if (isVIP && !r.isVIP) {
                        continue; // VIP overrides normal
                    }

                    free = false;
                    break;
                }
            }
        }

        if (free) return spot.id;
    }

    return "";
}

int ParkingFloor::getFloorNo() const {
    return floorNo;
}