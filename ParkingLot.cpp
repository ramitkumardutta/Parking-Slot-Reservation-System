#include "ParkingLot.h"
#include <iostream>
#include <cstdlib>

using namespace std;

ParkingLot& ParkingLot::getInstance() {
    static ParkingLot instance;
    return instance;
}

void ParkingLot::addFloor(int spots) {
    floors.emplace_back(floors.size() + 1, spots);
}

string ParkingLot::generateId() {
    return "RES-" + to_string(rand() % 100000);
}

void ParkingLot::makeReservation() {

    int type;
    cout << "Vehicle Type (0=Bike,1=Car,2=Truck): ";
    cin >> type;

    bool isVIP, needsCharging;
    cout << "VIP user? (1=yes,0=no): ";
    cin >> isVIP;

    cout << "Need EV charging? (1=yes,0=no): ";
    cin >> needsCharging;

    int h, m, s;
    cout << "Enter duration (h m s): ";
    cin >> h >> m >> s;

    while((h > 24 && h < 0) || (m < 0 && m > 59) || (s < 0 || s > 59)) {
        cin >> h >> m >> s;
    }

    time_t start = nowTime();
    time_t end = addDuration(start, h, m, s);

    string assigned = "";

    for (auto& f : floors) {
        assigned = f.findAvailableSpot(start, end, reservations, needsCharging, isVIP);
        if (assigned != "") break;
    }

    if (assigned == "") {
        cout << "\n❌ No Slot Available for this time.\n";
        return;
    }

    Reservation r;
    r.id = generateId();
    r.start = start;
    r.end = end;
    r.spotId = assigned;
    r.type = (VehicleType)type;
    r.isVIP = isVIP;
    r.needsCharging = needsCharging;

    cout << "\n--- Registration ---\n";
    cout << "Name: "; cin >> r.name;
    cout << "Document ID: "; cin >> r.documentId;
    cout << "Vehicle Number: "; cin >> r.vehicleNumber;

    reservations.push_back(r);
    r.print();
}

void ParkingLot::cancelReservation() {
    string id;
    cout << "Enter Reservation ID to cancel: ";
    cin >> id;

    for (auto& r : reservations) {
        if (r.id == id) {
            r.status = ReservationStatus::CANCELLED;
            cout << "\nReservation " << id << " cancelled.\n";
            return;
        }
    }

    cout << "\n SORRY! Reservation not found.\n";
}