# README

## Overview
This project provides a C++ utility to retrieve time information in different time zones. It includes a function to convert Unix timestamps into structured time representations (`std::tm`) adjusted for specific time zones.

## Usage
### Compiling the Project
The project can be compiled using a standard C++ compiler:
```bash
g++ main.cpp -o getTimeStructExample
```

### Running the Program
After compilation, run the program:
```bash
./getTimeStructExample
```

The program will output:
- Current UTC time.
- Current Beijing time (UTC+8).
- A custom timestamp converted to the Beijing time zone.

### Example Output
```
UTC Time:
Year: 2023
Month: 9
Day: 25
Hour: 14
Minute: 30
Second: 45
--------------------------
Beijing Time:
Year: 2023
Month: 9
Day: 25
Hour: 22
Minute: 30
Second: 45
--------------------------
Custom Timestamp Conversion:
Year: 2021
Month: 8
Day: 23
Hour: 20
Minute: 26
Second: 40
--------------------------
```

## Functions
### `getTimeStruct(int time_zone = 0, int64_t time_stamp = current_time)`
Converts a Unix timestamp to a `std::tm` structure adjusted for the specified time zone.

#### Parameters
- `time_zone`: The time zone offset from UTC in hours (e.g., `8` for UTC+8).
- `time_stamp`: Optional Unix timestamp; defaults to the current system time if not provided.

#### Returns
A `std::tm` structure containing the broken-down time components for the specified time zone and timestamp.