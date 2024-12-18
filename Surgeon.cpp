#include "Surgeon.h"
#include <sstream>

using namespace std;
Surgeon::Surgeon(): Doctor("","",0.0,0.0)
{
  numSurgeriesScheduled =0 ;

}

Surgeon::Surgeon(int num_surgeries, string id , string name , double duration , double rate ): Doctor(id,name,duration,rate)
{
  numSurgeriesScheduled = num_surgeries;

}

Surgeon::Surgeon(const Surgeon &obj)
{
    Name=obj.Name;
    ID=obj.ID;
    Duration=obj.Duration;
    Rate=obj.Rate;
    numSurgeriesScheduled  = obj.numSurgeriesScheduled ;
    for(int i =0 ; i<numSurgeriesScheduled ; i++)
    {
        schedule[i] = obj.schedule[i];
    }

}

double Surgeon::calculateTotalFee()
{
    return (Duration / 60) * Rate;
}


string Surgeon::PrettyPrint()
{
    return string("Dr. ")+Name+string(" is a surgeon whose total fee is ")+to_string(calculateTotalFee());
}


void Surgeon::printSurgeries()const
{
    cout<<"Dr. "<<Name<<"'surgeries schedule: "<<endl;
    for(int i=0 ; i<numSurgeriesScheduled ; i++)
    {
        cout<<"A surgery on "<<schedule[i].getdate()<<" for patient : "<<schedule[i].getpatientName()<<endl;
    }
}


string Surgeon::getName()
{
    return Name;
}

Surgeon::~Surgeon()
 {
         delete [] schedule;
 }


