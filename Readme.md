# Parking Slot Reservation System

A **production-style Parking Lot Management System** built using **C++ (OOP + System Design principles)** that supports **time-based reservations, VIP priority allocation, EV charging slots, and cancellation with refund logic**.

---

## Overview

This project simulates a real-world parking system with:

* Multi-floor parking management
* Time-slot based reservation system
* Conflict detection (no double booking)
* VIP priority allocation
* EV charging slot support
* Reservation lifecycle (create, cancel, refund)
* CLI-based interactive system

Designed with a strong focus on **Low-Level Design (LLD)** and **scalable architecture**.

---

## Key Features

### Reservation System

* Book parking slots for specific time durations
* Prevents overlapping bookings using interval logic

### EV Charging Support

* Dedicated EV-enabled parking spots
* Allocated only when requested

### VIP Priority Booking

* VIP users can override non-VIP reservations

### Cancellation & Refund

* Cancel active reservations
* Refund calculated based on remaining time

### Multi-Floor Management

* Supports multiple floors with multiple parking slots

### Modular Design

* Clean separation using `.h` and `.cpp` files
* Easily extensible for future features

---

## System Design

### Design Principles Used:

* Object-Oriented Programming (OOP)
* Modular Architecture
* Separation of Concerns

### Core Components:

* `ParkingLot` → Singleton controller
* `ParkingFloor` → Manages slots per floor
* `Reservation` → Booking entity
* `Vehicle` → Type abstraction
* `Utils` → Time & helper functions

---

## Tech Stack

* **Language:** C++17
* **Concepts:** OOP, System Design, CLI
* **Storage:** In-memory (vector-based simulation)

---

## How to Run

### 1. Clone the repository

```bash
git clone https://github.com/ramitkumardutta/Parking-Slot-Reservation-System.git
cd Parking-Slot-Reservation-System
```

### 2. Compile

```bash
g++ main.cpp ParkingLot.cpp ParkingFloor.cpp Reservation.cpp -o parking
```

### 3. Run

```bash
./parking
```

---

## Sample CLI Flow

```
===== PARKING SYSTEM =====
1. Make Reservation
2. Cancel Reservation
0. Exit
```

---

## Example Output

```
===== RESERVATION SUCCESS =====
ID: RES-10234
Name: xyz
Vehicle: WB38AB1234
Spot: F1-S3
VIP: YES
Charging: NO
Valid Till: 18:30
```

---

## Future Enhancements

* Database integration (SQLite / MongoDB)
* REST API backend (Node.js / Spring Boot)
* Web-based UI dashboard
* Payment gateway integration
* Real-time slot tracking

---

## Author

**Ramit Kumar Dutta**

* GitHub: https://github.com/ramitkumardutta

---

## If you like this project

Give it a on GitHub and feel free to contribute!

---
