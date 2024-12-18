#include "surgerySchedule.h"

surgerySchedule::surgerySchedule():patientName(""),Date(""){}

surgerySchedule::surgerySchedule(string patient_name , string date):patientName(patient_name),Date(date){}


void surgerySchedule::setpatientName(string name)
{
    patientName = name;
}

void surgerySchedule::setdate(string date)
{
    Date = date;
}

string surgerySchedule::getpatientName()const
{
    return patientName;
}
string surgerySchedule::getdate()const
{
    return Date;
}

