#include "Surgeon.h"
#include <sstream>

using namespace std;
// Default constructor for the Surgeon class
Surgeon::Surgeon() : Doctor("", "", 0.0, 0.0) {
    numSurgeriesScheduled = 0; // Initialize the number of surgeries scheduled to 0
    schedule = nullptr; // Initialize the schedule pointer to nullptr
}

// Parameterized constructor for the Surgeon class
Surgeon::Surgeon(int num_surgeries, surgerySchedule *schedules, string id, string name, double duration, double rate)
    : Doctor(id, name, duration, rate) { // Call the base class constructor
    numSurgeriesScheduled = num_surgeries; // Set the number of surgeries scheduled
    schedule = new surgerySchedule[numSurgeriesScheduled]; // Allocate memory for the surgery schedule array
    for (int i = 0; i < numSurgeriesScheduled; i++) {
        schedule[i] = schedules[i]; // Copy the surgery schedules from the provided array
    }
}

// Copy constructor for the Surgeon class
Surgeon::Surgeon(const Surgeon &obj) : Doctor(obj) { // Call the base class copy constructor
    numSurgeriesScheduled = obj.numSurgeriesScheduled; // Copy the number of surgeries scheduled
    schedule = new surgerySchedule[numSurgeriesScheduled]; // Allocate memory for the surgery schedule array
    for (int i = 0; i < numSurgeriesScheduled; i++) {
        schedule[i] = obj.schedule[i]; // Copy the surgery schedules from the source object
    }
}

// Function to calculate the total fee based on duration and rate
double Surgeon::calculateTotalFee() {
    return (Duration / 60) * Rate; // Calculate total fee as (Duration in hours) * Rate
}

// Function to return a formatted string with the surgeon's details
string Surgeon::PrettyPrint() {
    return string("Dr. ") + Name + string(" is a surgeon whose total fee is ") + to_string(calculateTotalFee());
}

// Function to print the surgeries scheduled for the surgeon
string Surgeon::printSurgeries() {
    string surgeriesSchedule = "Dr. " + Name + "'s surgeries schedule:\n"; // Initialize the schedule string

    // Check if there are no surgeries scheduled
    if (numSurgeriesScheduled == 0) {
        surgeriesSchedule += "No surgeries scheduled.\n"; // Add message if no surgeries are scheduled
    } else {
        // Loop through each scheduled surgery and append details to the string
        for (int i = 0; i < numSurgeriesScheduled; i++) {
            surgeriesSchedule += " - Surgery on " + schedule[i].getdate() + " for patient: " + schedule[i].getpatientName() + "\n";
        }
    }
    return surgeriesSchedule; // Return the complete surgeries schedule string
}

// Destructor for the Surgeon class
Surgeon::~Surgeon() {
    delete[] schedule; // Free the allocated memory for the surgery schedule array
    numSurgeriesScheduled = 0; // Reset the number of surgeries scheduled
    schedule = nullptr; // Set the schedule pointer to nullptr to avoid dangling pointer

}

