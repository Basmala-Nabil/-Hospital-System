// Basmala Nabil El-Sayed      20235005
#include <iostream>
#include <fstream>
#include "Doctor.h"
#include "surgerySchedule.h"
#include "Surgeon.h"
#include "Specialist.h"
using namespace std;

int main()
{
    // Welcome message
    cout<<"Welcome to the Hospital System..."<<endl;
    int num_of_doctors;
    cout<<"Enter number of doctors :";
    cin>>num_of_doctors;
    // Array to hold pointers to Doctor objects
    Doctor * doctors[num_of_doctors];
    // Loop to gather information for each doctor
    for(int i=0 ; i<num_of_doctors ; i++)
    {
        string dr_id ;
        int num_of_surgeries;
        string dr_name , type , patient , patient_date , dr_speciality;
        double dr_duration , dr_rate;
        cout<<"A- Surgeon. \nB- Specialist."<<endl;
        cout<<"Enter Doctor "<< i+1<<" type: "<<endl;
        cin>>type;
        // If the doctor is a surgeon
        if(type=="A"||type=="a")
        {
            cout<<"Enter Doctor Details: "<<endl;
            cout<<"Name: ";
            cin.ignore(); // Clear the newline character
            getline(cin, dr_name);// Get the doctor's name
            cout<<"ID: ";
            cin>>dr_id;// Get the doctor's ID
            cout<<"Duration: ";
            cin>>dr_duration;// Get the duration spent with patients
            cout<<"Rate: ";
            cin>>dr_rate;// Get the rate charged by the doctor
            cout<<"Number of Surgeries: ";
            cin>>num_of_surgeries;// Get the number of surgeries scheduled
            // Dynamically allocate an array for surgery schedules
            surgerySchedule* schedules = new surgerySchedule[num_of_surgeries];
            // Loop to gather details for each surgery
            for(int k=0 ; k<num_of_surgeries ; k++)
            {
                cout<<"Enter patient "<<k+1<<" Name: ";
                cin.ignore(); // Clear the newline character
                getline(cin, patient);// Get the patient's name
                cout<<"Enter patient "<<k+1<<" Surgery Date: ";
                cin>>patient_date;// Get the surgery date
                // Create a SurgerySchedules object for the patient and date
                schedules[k]=surgerySchedule(patient,patient_date);
            }
            // Create a new Surgeon object and store it in the array
            doctors[i]=new Surgeon(num_of_surgeries,schedules,dr_id,dr_name,dr_duration,dr_rate);

        }
        // If the doctor is a specialist
        else if (type=="B"||type=="b")
        {
            cout<<"Enter Doctor Details: "<<endl;
            cout<<"Name: ";
            cin.ignore(); // Clear the newline character
            getline(cin, dr_name);// Get the doctor's name
            cout<<"ID: ";
            cin>>dr_id;// Get the doctor's ID
            cout<<"Duration: ";
            cin>>dr_duration;// Get the duration spent with patients
            cout<<"Rate: ";
            cin>>dr_rate;// Get the rate charged by the doctor
            cout<<"Speciality: ";
            cin>>dr_speciality;// Get the doctor's specialty
            // Create a new Specialist object and store it in the array
            doctors[i]=new Specialist(dr_speciality,dr_id,dr_name,dr_duration,dr_rate);
        }}
        // Open a file to write doctor details
        fstream outFile("doctors.txt",::ios::out);
        // Loop through each doctor to print and save their details
        for(int i=0 ; i<num_of_doctors; i++)
        {
            cout<<doctors[i]->PrettyPrint()<<endl;// Print to console
            outFile<<doctors[i]->PrettyPrint()<<endl;// Write to file
        }
        // Loop to print surgeries for each surgeon
       for(int i=0 ;i<num_of_doctors ;i++)
        {
            Surgeon* surgeon=dynamic_cast<Surgeon*>(doctors[i]);
            if(surgeon) {
                   cout<<surgeon->printSurgeries()<<endl;
                 }}
        // Loop through each doctor to print surgeries for each surgeon
        for(int i=0 ;i<num_of_doctors ;i++)
        {

            if(Surgeon* surgeon = dynamic_cast<Surgeon*>(doctors[i])) {
            // If the cast is successful, print the surgeries for this surgeon
            string surgeries = surgeon->printSurgeries();// Get the surgeries as a string
            outFile<<surgeries;

        }
    }
            for(int i=0;i<num_of_doctors;i++)
            {// Check if the first doctor is a surgeon
            if(Surgeon* surgeon = dynamic_cast<Surgeon*>(doctors[i])) {
                // Create a copy of the first surgeon using the copy constructor
                Surgeon* copySurgeon = new Surgeon(*dynamic_cast<Surgeon*>(doctors[i]));
                cout<<"Copy of the surgeon: "<<endl<<copySurgeon->PrettyPrint()<<endl;// Print the copied surgeon's details
                outFile<<"Copy of the surgeon: "<<endl<<copySurgeon->PrettyPrint()<<endl;// Write the copied surgeon's details to the output file
                // Print and write the surgeries of the copied surgeon
                cout<<"Copy of the surgeon 'surgeries: "<<endl<<copySurgeon->printSurgeries()<<endl;// Print surgeries to console
                outFile<<"Copy of the surgeon 'surgeries: "<<endl<<copySurgeon->printSurgeries()<<endl;// Write surgeries to the output file
                delete copySurgeon;//Free up memory allocated to the copied surgeon
            }}



   outFile.close();// Close the output file after writing all details
   //Free up memory allocated to all doctors
   for (int i = 0; i < num_of_doctors; i++) {
        delete doctors[i]; // Freeing up memory allocated to each Doctor object
    }

    return 0;
}
