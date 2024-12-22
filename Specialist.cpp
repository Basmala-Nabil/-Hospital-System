#include "Specialist.h"

// Default constructor
Specialist::Specialist() : Doctor(0,"",0.0,0.0),Speciality(""){}

// Parameterized constructor
Specialist::Specialist(string speciality, string id , string name , double duration , double rate ):Doctor(id,name,duration,rate),Speciality(speciality){}


// Function to calculate the total fee
double Specialist::calculateTotalFee()
{
    return (Duration / 15) * Rate;
}


// Function to return a formatted string with the specialist's details
string Specialist::PrettyPrint()
{
    return string("Dr. ")+Name+string(" is a Specialist with whose total  fee is ")+to_string(calculateTotalFee());
}
