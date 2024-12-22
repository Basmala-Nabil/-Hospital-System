#include "Doctor.h"


// Default constructor for the Doctor class
Doctor::Doctor():ID(""),Name(""),Duration(0.0),Rate(0.0){}// Initializes ID and Name as empty strings, and Duration and Rate as zero

// Parameterized constructor for the Doctor class
Doctor::Doctor(string id , string name ,double duration ,double rate ):ID(id),Name(name),Duration(duration),Rate(rate){}

// Function to calculate the total fee
double Doctor::calculateTotalFee()
{
    return 0.0;// Currently returns 0.0; should be overridden in derived classes
}

// Function to return the doctor's information as a formatted string
string Doctor::PrettyPrint()
{
    return string("Doctor ID is ")+ID+string(" and name is Dr. ")+Name;
}

