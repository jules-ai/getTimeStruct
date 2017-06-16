#include <iostream>
#include "getTimeStruct.hpp"

void printTimeStruct(const std::tm& time_info, const std::string& description) {
    std::cout << description << ":\n";
    std::cout << "Year: " << (time_info.tm_year + 1900) << "\n";
    std::cout << "Month: " << (time_info.tm_mon + 1) << "\n";
    std::cout << "Day: " << time_info.tm_mday << "\n";
    std::cout << "Hour: " << time_info.tm_hour << "\n";
    std::cout << "Minute: " << time_info.tm_min << "\n";
    std::cout << "Second: " << time_info.tm_sec << "\n";
    std::cout << "--------------------------\n";
}

int main() {
    // Example 1: Get UTC time
    std::tm utc_time = getTimeStruct(); // UTC timezone
    printTimeStruct(utc_time, "UTC Time");

    // Example 2: Get Beijing time (UTC+8)
    std::tm beijing_time = getTimeStruct(8); // UTC+8 timezone
    printTimeStruct(beijing_time, "Beijing Time");

    // Example 3: Convert a specific timestamp to local time
    int64_t example_timestamp = 1630000000; // Replace with any Unix timestamp
    std::tm custom_time = getTimeStruct(8, example_timestamp); // Convert with UTC+8 timezone
    printTimeStruct(custom_time, "Custom Timestamp Conversion");

    return 0;
}