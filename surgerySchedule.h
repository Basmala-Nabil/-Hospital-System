#ifndef SURGERYSCHEDULE_H
#define SURGERYSCHEDULE_H
#include <string>
#include <sstream>
using namespace std;
class surgerySchedule
{
    private:
        string patientName , Date;
    public:
        surgerySchedule();
        surgerySchedule(string patient_name , string date);
        void setpatientName(string name);
        void setdate(string date);
        string getpatientName()const;
        string getdate()const;

};

#endif // SURGERYSCHEDULE_H
