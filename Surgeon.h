#ifndef SURGEON_H
#define SURGEON_H
#include <string>
#include <sstream>
#include "Doctor.h"
#include "surgerySchedule.h"

using namespace std;
class Surgeon : public Doctor
{
   int numSurgeriesScheduled =0 ;
   surgerySchedule *schedule ;
   public:
       Surgeon();
       Surgeon(int num_surgeries, string id , string name , double duration , double rate );
       Surgeon(const Surgeon &obj);
       double calculateTotalFee();
       string PrettyPrint();
       void printSurgeries()const;
       string getName();
       ~Surgeon();
};

#endif // SURGEON_H
