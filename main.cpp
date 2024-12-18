#include <iostream>
#include <fstream>
#include "Doctor.h"
#include "surgerySchedule.h"
#include "Surgeon.h"
#include "Specialist.h"
using namespace std;

int main()
{
    cout<<"Welcome to the Hospital System..."<<endl;
    int num_of_doctors=0;
    cout<<"Enter number of doctors :";
    cin>>num_of_doctors;
    Doctor * doctors[num_of_doctors];
    for(int i=0 ; i<num_of_doctors ; i++)
    {
        string dr_id ;
        int num_of_surgeries;
        string dr_name , type , patient , patient_date , dr_speciality;
        double dr_duration , dr_rate;
        cout<<"A- Surgeon. \nB- Specialist."<<endl;
        cout<<"Enter Doctor "<< i+1<<" type: "<<endl;
        cin>>type;
        if(type=="A"||type=="a")
        {
            cout<<"Enter Doctor Details: "<<endl;
            cout<<"Name: ";
            cin>>dr_name;
            cout<<"ID: ";
            cin>>dr_id;
            cout<<"Duration: ";
            cin>>dr_duration;
            cout<<"Rate: ";
            cin>>dr_rate;
            cout<<"Number of Surgeries: ";
            cin>>num_of_surgeries;
            surgerySchedule* schedules = new surgerySchedule[num_of_surgeries];
            for(int k=0 ; k<num_of_surgeries ; k++)
            {
                cout<<"Enter patient "<<k+1<<" Name: ";
                cin>>patient;
                cout<<"Enter patient "<<k+1<<" Surgery Date: ";
                cin>>patient_date;
                 schedules[i]=surgerySchedule(patient,patient_date);
            }
            doctors[i]=new Surgeon(num_of_surgeries,dr_id,dr_name,dr_duration,dr_rate);

        }
        else if (type=="B"||type=="b")
        {
            cout<<"Enter Doctor Details: "<<endl;
            cout<<"Name: ";
            cin>>dr_name;
            cout<<"ID: ";
            cin>>dr_id;
            cout<<"Duration: ";
            cin>>dr_duration;
            cout<<"Rate: ";
            cin>>dr_rate;
            cout<<"Speciality: ";
            cin>>dr_speciality;
            doctors[i]=new Specialist(dr_speciality,dr_id,dr_name,dr_duration,dr_rate);
        }}

        fstream outFile("doctors.txt",::ios::out);
        // doctors in hospital details
        for(int i=0 ; i<num_of_doctors; i++)
        {
            cout<<doctors[i]->PrettyPrint()<<endl;
            outFile<<doctors[i]->PrettyPrint()<<endl;
        }
        for(int i=0 ; i<num_of_doctors ; i++)
        {
             Surgeon* surgeon = dynamic_cast<Surgeon*>(doctors[i]);
            if(surgeon)
            {

                surgeon->printSurgeries();
            }
        }


    return 0;
}
