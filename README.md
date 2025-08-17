# Clinic-Management-System

A simple Clinic Management System written in C for educational purposes.

The system allows two modes: Admin Mode and User Mode, providing basic functionality for managing patient records and doctor reservations.


📌 Features

🔑 Admin Mode (Password protected – default: 1234)

Add New Patient Record
- Enter name, age, gender, and unique ID.
- Rejects duplicate IDs.

Edit Patient Record
- Update patient details by entering ID.

Reserve a Slot with the Doctor
- 5 available slots:
-- 2:00 – 2:30 PM
-- 2:30 – 3:00 PM
-- 3:00 – 3:30 PM
-- 4:00 – 4:30 PM
-- 4:30 – 5:00 PM
- Reserved slots are no longer available for other patients.

Cancel Reservation
- Cancel by entering patient ID.
- The slot becomes available again.

👥 User Mode (No password required)

View Patient Record
- Retrieve details by entering patient ID.

View Today’s Reservations
- Displays all reservations with patient IDs attached to time slots.


📂 Project Structure

├── a.exe            # Compiled executable (Windows)

├── main.c           # Entry point of the program

├── program.c        # Implementation of system functions

├── interface.h      # Function declarations (APIs)

├── config.h         # Configuration settings

├── std_types.h      # Standard data types definitions

└── README.md        # Project Documentation


🤝 Contributing

Contributions are welcome! Fork this repo and submit a pull request to suggest improvements.
