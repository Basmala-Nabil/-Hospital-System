#ifndef DOCTOR_H
#define DOCTOR_H
#include <string>
#include <sstream>
#include <iostream>
using namespace std;
class Doctor
{
    protected:
        string ID ;
        string Name ;
        double Duration , Rate ;
    public:
        Doctor();// Default constructor
        Doctor (string id , string name ,double duration ,double rate );// Parameterized constructor to initialize a Doctor object with specific values
        virtual double calculateTotalFee();// Virtual function to calculate the total fee based on duration and rate
        virtual string PrettyPrint();// Virtual function to return a formatted string with doctor's details
};
#endif // DOCTOR_H
