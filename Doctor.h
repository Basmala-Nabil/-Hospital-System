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
        Doctor();
        Doctor (string id , string name ,double duration ,double rate );
        virtual double calculateTotalFee();
        virtual string PrettyPrint();
};
#endif // DOCTOR_H
