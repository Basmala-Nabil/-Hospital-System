#include "surgerySchedule.h"

// Default constructor
surgerySchedule::surgerySchedule():patientName(""),Date(""){}

// Parameterized constructor
surgerySchedule::surgerySchedule(string patient_name , string date):patientName(patient_name),Date(date){}

// Setter for patientName
void surgerySchedule::setpatientName(string name)
{
    patientName = name;
}
// Setter for Date
void surgerySchedule::setdate(string date)
{
    Date = date;
}
// Getter for patientName
string surgerySchedule::getpatientName()const
{
    return patientName;
}
// Getter for Date
string surgerySchedule::getdate()const
{
    return Date;
}
