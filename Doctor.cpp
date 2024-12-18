#include "Doctor.h"



Doctor::Doctor():ID(""),Name(""),Duration(0.0),Rate(0.0){}


Doctor::Doctor(string id , string name ,double duration ,double rate ):ID(id),Name(name),Duration(duration),Rate(rate){}


double Doctor::calculateTotalFee()
{
    return 0.0;
}


string Doctor::PrettyPrint()
{
    return string("Doctor ID is ")+ID+string(" and name is Dr. ")+Name;
}


