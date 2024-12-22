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
       Surgeon();// Default constructor
       // Parameterized constructor
       Surgeon(int num_surgeries,surgerySchedule *schedules, string id , string name , double duration , double rate );
       // Copy constructor
       Surgeon(const Surgeon &obj);
       // Function to calculate the total fee
       double calculateTotalFee();
       // Function to return a formatted string
       string PrettyPrint();
       // Function to print all scheduled surgeries for the surgeon
       string printSurgeries();
       // Destructor
       ~Surgeon();
};

#endif // SURGEON_H
