#include "Reservation.h"
#include <iostream>

void Reservation::print() const {
    cout << "\n===== RESERVATION SUCCESS =====\n";
    cout << "ID: " << id << "\n";
    cout << "Name: " << name << "\n";
    cout << "Vehicle: " << vehicleNumber << "\n";
    cout << "Spot: " << spotId << "\n";
    cout << "VIP: " << (isVIP ? "YES" : "NO") << "\n";
    cout << "Charging: " << (needsCharging ? "YES" : "NO") << "\n";
    cout << "Valid Till: " << ctime(&end);
}