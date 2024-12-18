#include "Specialist.h"

Specialist::Specialist() : Doctor(0,"",0.0,0.0),Speciality(""){}


Specialist::Specialist(string speciality, string id , string name , double duration , double rate ):Doctor(id,name,duration,rate),Speciality(speciality){}



double Specialist::calculateTotalFee()
{
    return (Duration / 15) * Rate;
}



string Specialist::PrettyPrint()
{
    return string("Dr. ")+Name+string(" is a Specialist with whose total  fee is ")+to_string(calculateTotalFee());
}
