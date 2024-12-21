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
    int num_of_doctors;
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
                 schedules[k]=surgerySchedule(patient,patient_date);
            }
            doctors[i]=new Surgeon(num_of_surgeries,schedules,dr_id,dr_name,dr_duration,dr_rate);

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
        for(int i=0 ; i<num_of_doctors; i++)
        {
            cout<<doctors[i]->PrettyPrint()<<endl;
            outFile<<doctors[i]->PrettyPrint()<<endl;
        }
       for(int i=0 ;i<num_of_doctors ;i++)
        {
            Surgeon* surgeon=dynamic_cast<Surgeon*>(doctors[i]);
            if(surgeon) {
                   cout<<surgeon->printSurgeries()<<endl;
                 }}
        for(int i=0 ;i<num_of_doctors ;i++)
        {

            if (Surgeon* surgeon = dynamic_cast<Surgeon*>(doctors[i])) {

            string surgeries = surgeon->printSurgeries();
            outFile << surgeries;

        }
    }

    if(num_of_doctors>1)
    {cout << "Do you want to shift surgeries from a surgeon to another surgeon? \nA- Yes.\nB- No." << endl;
    string choice1;
    cin >> choice1;

    if (choice1 == "A" || choice1 == "a") {

        int chosen_surgeon,target_surgeon;// chosen surgeon is the surgeon we take his surgeries , target surgeon the surgeon how will take the surgeries
        cout<<"Enter the index of the chosen surgeon (1 to "<<num_of_doctors<<"): ";
        cin>>chosen_surgeon;
        chosen_surgeon--;

        cout<<"Enter the index of the target surgeon (1 to "<<num_of_doctors<<"): ";
        cin>>target_surgeon;
        target_surgeon--;

        Surgeon* chosenSurgeon=dynamic_cast<Surgeon*>(doctors[chosen_surgeon]);
        Surgeon* targetSurgeon=dynamic_cast<Surgeon*>(doctors[target_surgeon]);

        if(!chosenSurgeon||!targetSurgeon) {
            cout<<"One or both selected doctors are not surgeons."<<endl;
           }

          else{

int totalSurgeries = chosenSurgeon->getnumSurgeriesScheduled()+targetSurgeon->getnumSurgeriesScheduled();


surgerySchedule* newSchedule = new surgerySchedule[totalSurgeries];


for (int i = 0; i < targetSurgeon->getnumSurgeriesScheduled(); i++) {
    newSchedule[i] = targetSurgeon->getSchedule()[i];
}


for (int i = 0; i < chosenSurgeon->getnumSurgeriesScheduled(); i++) {
    newSchedule[targetSurgeon->getnumSurgeriesScheduled()+i] = chosenSurgeon->getSchedule()[i];
}


targetSurgeon = new Surgeon(targetSurgeon->getnumSurgeriesScheduled() + chosenSurgeon->getnumSurgeriesScheduled(), newSchedule, targetSurgeon->getID(), targetSurgeon->getName(), targetSurgeon->getDuration(), targetSurgeon->getRate());


chosenSurgeon->~Surgeon();


cout<<"\nSurgeon 1 Details (After transferring surgeries):"<<endl;
cout<<chosenSurgeon->printSurgeries();
outFile<<"\nSurgeon 1 Details (After transferring surgeries):"<<endl;
outFile<<chosenSurgeon->printSurgeries();

cout<<"Surgeon 2 Details (After receiving surgeries):"<<endl;
cout<<targetSurgeon->printSurgeries();
outFile<<"Surgeon 2 Details (After receiving surgeries):"<<endl;
outFile<<targetSurgeon->printSurgeries();

delete[] newSchedule;

    }} }










    outFile.close();
    return 0;
}
