#ifndef SPECIALIST_H
#define SPECIALIST_H
#include <string>
#include <sstream>
#include "Doctor.h"
using namespace std;
class Specialist : public Doctor
{
     private:
         string Speciality;
     public:
        Specialist();
        Specialist(string speciality, string id , string name , double duration , double rate );
        double calculateTotalFee();
        string PrettyPrint();

};

#endif // SPECIALIST_H
