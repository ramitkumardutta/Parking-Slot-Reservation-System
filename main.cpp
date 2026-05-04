#include "ParkingLot.h"
#include <iostream>

using namespace std;

int main() {
    ParkingLot& lot = ParkingLot::getInstance();

    lot.addFloor(5);
    lot.addFloor(5);

    int choice;

    while (true) {
        cout << "\n===== PARKING SYSTEM =====\n";
        cout << "1. Make Reservation\n";
        cout << "2. Cancel Reservation\n";
        cout << "0. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        if (choice == 1) {
            lot.makeReservation();
        }
        else if (choice == 2) {
            lot.cancelReservation();
        }
        else if (choice == 0) {
            break;
        }
    }

    return 0;
}