// Declaring Header Files::::::::
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

#define size 100
int reserve = 999;

// Classes List
class Airline;
class menu;

// Creating Class For Airline Reservation System
class Airlines
{
public:
    // Declaring Data Members
    int to;
    string name[100];
    int age[100];
    long long int phone_number[100];
    char gender[100];
    int seat_number[100];
    int meal[100];
    int choice;
    int n = 0;
    int bill;

    // Declaring Member Functions
    void flight_schedule();
    void flight_details();
    void get_details(int n);
    void printdetails(int n);
    void billing(int n);
    void print_list(int n);
    void print_report(int n);
};

// Inheritance::(Inherited Class Airlines By Class Menu)
class Menu : public Airlines
{
public:
    // Declaring Member Function
    void displayMenu();
};

// Function For Printing The Flights Schedule
// FILE HANDLING::
void Airlines::flight_schedule()
{
    ifstream file;
    file.open("Flight_data.txt");
    string line;
    while (file.good())
    {
        getline(file, line);
        cout << line << endl;
    }
    file.close();
}

// Function For Printing The Available Flights
void Airlines::flight_details()
{
    cout << "Available Flights:" << endl;
    cout << endl;

    cout << "************************************************************" << endl;
    cout << "\t NAME OF FLIGHT  ACCESS CODE " << endl;
    cout << endl;

    cout << "\t IndiGo          ------ [1] \n";
    cout << "\t Air India       ------ [2] \n";
    cout << "\t Go first        ------ [3] \n";
    cout << "\t SpiceJet        ------ [4] \n";
    cout << "\t Vistara         ------ [5] \n ";
    cout << "************************************************************" << endl;

    cout << "Please Enter Your Flight Choice:: ";
    cin >> choice;

    // Exception Handling
    try
    {
        if (choice < 1 || choice > 6)
        {
            throw "Error";
        }
    }
    catch (const char *a)
    {
        cout << "Enter valid Choice";
    }

    switch (choice)
    {

    case 1:
        cout << "\n-----------Welcome to Indigo-----------\n";
        cout << endl;
        break;

    case 2:
        cout << "\n-----------Welcome to Air India-----------\n ";
        cout << endl;
        break;

    case 3:
        cout << "\n-----------Welcome to Go first-----------\n";
        cout << endl;
        break;

    case 4:
        cout << "\n-----------Welcome to Spice jet-----------\n";
        cout << endl;
        break;

    case 5:
        cout << "\n-----------Welcome to Vistara-----------\n";
        cout << endl;
        break;
    }
}

// Function For Getting The Details Of Passenger
void Airlines::get_details(int n)
{
    cout << "Please Enter Your Flight Destination Preference from below::\n";
    cout << endl;
    cout << "      Flight Destination      Access Code\n";
    cout << "      Pune => Mumbai           ..... '1'\n";
    cout << "      Pune => Delhi            ..... '2'\n";
    cout << "      Pune => Chennai          ..... '3'\n\n";
    cout << "Enter Destination Choice :: ";
    cin >> to;
    cout << endl;

    cout << "ENTER YOUR PERSONAL DETAILS : " << endl;
    cout << endl;

    for (int i = 1; i < n + 1; i++)
    {

        cout << "Enter the name of passenger " << i << " :: ";
        cin >> name[i];

        cout << "Enter the age of passenger " << i << " :: ";
        cin >> age[i];

        cout << "Enter the Phone Number of passenger " << i << " :: ";
        cin >> phone_number[i];

        cout << "Enter the gender of passenger " << i << "(M/F) :: ";
        cin >> gender[i];

        cout << "Please Enter the Seat Number for passenger " << i << " :: ";
        cin >> seat_number[i];

        while (seat_number[i] > size)
        {
            cout << "Try again:: ";
            cin >> seat_number[i];
        }

        cout << "Please Enter Your Menu Preference from below:\n";
        cout << "      Veg     ..... '1'\n";
        cout << "      Non-Veg ..... '2'\n";
        cout << "      No meal ..... '3'\n\n";
        cout << "Enter Meal Choice :: ";

        cin >> meal[i];

        cout << "----------------------------------------------";
        cout << endl;
    }

    cout << "\tRESERVATION COMPLETED" << endl;
    cout << "----------------------------------------------" << endl;
    cout << endl;
}

// Function For Printing The Details Of Passenger
void Airlines::printdetails(int n)
{

    cout << endl;
    cout << "THE DETAILS OF PASSENGER:" << endl;
    cout << endl;

    switch (choice)
    {

    case 1:
        cout << "\nThe Flight Choice of Passenger is Indigo\n";
        cout << endl;
        break;

    case 2:
        cout << "\nThe Flight Choice of Passenger is Air India\n ";
        cout << endl;
        break;

    case 3:
        cout << "\nThe Flight Choice of Passenger is Go first\n";
        cout << endl;
        break;

    case 4:
        cout << "\nThe Flight Choice of Passenger is Spice jet-\n";
        cout << endl;
        break;

    case 5:
        cout << "\nThe Flight Choice of Passenger is Vistara\n";
        cout << endl;
        break;
    }

    if (to == 1)
    {
        cout << "The Flight Destination of Passenger is Pune => Mumbai " << endl;
        cout << endl;
    }

    else if (to == 2)
    {
        cout << "The Flight Destination of Passenger is Pune => Delhi " << endl;
        cout << endl;
    }

    else
    {
        cout << "The Flight Destination of Passenger is Pune => Chennai " << endl;
        cout << endl;
    }

    for (int i = 1; i < n + 1; i++)
    {

        cout << "The Name of Passenger " << i << " is " << name[i] << endl;

        cout << "The Age of Passenger " << i << " is " << age[i] << endl;

        cout << "The Phone Number of Passenger " << i << " is " << phone_number[i] << endl;

        if (gender[i] == 'M' || gender[i] == 'm')
            cout << "The Gender of Passenger(M/F) " << i << " is Male" << endl;
        else
            cout << "The Gender of Passenger(M/F) " << i << " is female" << endl;

        cout << "The Seat Number of Passenger " << i << " is " << seat_number[i] << endl;

        if (meal[i] == 1)
            cout << "The Meal For Passenger " << i << " is Veg " << endl;
        else if (meal[i] == 2)
            cout << "The Meal For Passenger " << i << " is Non-Veg " << endl;
        else
            cout << "The Meal For Passenger " << i << " is No Meal " << endl;

        cout << "**************************************************" << endl;
        cout << endl;
    }
}

// Function For Printing The Total Bill
void Airlines::billing(int n)
{
    if (to == 1)
    {
        if (choice == 1)
        {

            bill = n * 1000;
            cout << "The Total Bill Is :" << bill << endl;
        }
        else if (choice == 2)
        {
            bill = n * 1250;
            cout << "The Total Bill Is :" << bill << endl;
        }
        else if (choice == 3)
        {
            bill = n * 1750;
            cout << "The Total Bill Is :" << bill << endl;
        }
        else if (choice == 4)
        {
            bill = n * 1110;
            cout << bill;
            cout << "The Total Bill Is :" << bill << endl;
        }
        else if (choice == 5)
        {
            bill = n * 1550;
            cout << "The Total Bill Is :" << bill << endl;
        }
    }
    else if (to == 2)
    {
        if (choice == 1)
        {

            bill = n * 1200;
            cout << "The Total Bill Is :" << bill << endl;
        }
        else if (choice == 2)
        {
            bill = n * 1400;
            cout << "The Total Bill Is :" << bill << endl;
        }
        else if (choice == 3)
        {
            bill = n * 1950;
            cout << "The Total Bill Is :" << bill << endl;
        }
        else if (choice == 4)
        {
            bill = n * 1250;
            cout << bill;
            cout << "The Total Bill Is :" << bill << endl;
        }
        else if (choice == 5)
        {
            bill = n * 1250;
            cout << "The Total Bill Is :" << bill << endl;
        }
    }
    else if (to == 3)
    {
        if (choice == 1)
        {

            bill = n * 1400;
            cout << "The Total Bill Is :" << bill << endl;
        }
        else if (choice == 2)
        {
            bill = n * 1350;
            cout << "The Total Bill Is :" << bill << endl;
        }
        else if (choice == 3)
        {
            bill = n * 1550;
            cout << "The Total Bill Is :" << bill << endl;
        }
        else if (choice == 4)
        {
            bill = n * 1750;
            cout << bill;
            cout << "The Total Bill Is :" << bill << endl;
        }
        else if (choice == 5)
        {
            bill = n * 1470;
            cout << "The Total Bill Is :" << bill << endl;
        }
    }
}

// Function For Printing The Details Of All Passenger
void Airlines::print_list(int n)
{

    cout << endl;
    cout << "PRINTING THE LIST OF PASSENGERS WITH DETAILS::" << endl;
    cout << endl;

    switch (choice)
    {

    case 1:
        cout << "\nFlight Choice ::Indigo\n";
        cout << endl;
        break;

    case 2:
        cout << "\nFlight Choice ::Air India\n ";
        break;

    case 3:
        cout << "\nFlight Choice ::Go first\n";
        cout << endl;
        break;

    case 4:
        cout << "\nFlight Choice ::Spice jet-\n";
        cout << endl;
        break;

    case 5:
        cout << "\nFlight Choice ::Vistara\n";
        cout << endl;
        break;
    }

    if (to == 1)
    {
        cout << "Flight Destination :: Pune => Mumbai " << endl;
        cout << endl;
    }

    else if (to == 2)
    {
        cout << "Flight Destination :: Pune => Delhi " << endl;
        cout << endl;
    }

    else
    {
        cout << "Flight Destination :: Pune => Chennai " << endl;
        cout << endl;
    }

    for (int i = 1; i < n + 1; i++)
    {
        reserve++;

        cout << "Printing The Details Of Passenger " << i << ":" << endl;
        cout << endl;

        cout << "Reservation Number ::" << reserve << endl;

        cout << "Name ::" << name[i] << endl;

        cout << "Age ::" << age[i] << endl;

        cout << "Phone Number ::" << phone_number[i] << endl;

        if (gender[i] == 'M' || gender[i] == 'm')
            cout << "Gender :: Male" << endl;
        else
            cout << "Gender :: Female" << endl;

        cout << "Seat Number::" << seat_number[i] << endl;

        if (meal[i] == 1)
            cout << "Meal :: Veg " << endl;
        else if (meal[i] == 2)
            cout << "Meal :: Non-Veg " << endl;
        else
            cout << "Meal :: No Meal " << endl;

        cout << "**************************************************" << endl;
        cout << endl;
    }
    cout << "**************************************************" << endl;
}

// Function For Printing The Flight Seats Status
void Airlines::print_report(int n)
{

    cout << "Printing The Status Of Flight Seats =====>" << endl;
    cout << endl;

    cout << "The Total Booked Seats ::" << n << endl;
    cout << "The Total Remaining Seats ::" << (size - n) << endl;
    cout << "**************************************************" << endl;
}

// Function For Printing ARS(AIRLINE RESERVATION SYSTEM) Menu
void Menu::displayMenu()
{
    int menu = 0;
    do
    {
        cout << "******************** AIRLINE RESERVATION SYSTEM ********************* \n";
        cout << endl;

        cout << "---------------------------------------------------------------------" << endl;
        cout << "\t OPTIONS::  \t     OPTION CODE" << endl;
        cout << endl;

        cout << "\t Flight Schedule      ------ [1] \n";
        cout << "\t Make Reservation     ------ [2] \n";
        cout << "\t Print list           ------ [3] \n";
        cout << "\t Seat Status          ------ [4] \n";
        cout << "\t Quit                 ------ [5] \n ";

        cout << "---------------------------------------------------------------------" << endl;
        cout << "Enter Your Option Code :: ";

        cin >> menu;

        // Exception Handling
        try
        {
            if (menu < 1 || menu > 5)
            {
                throw "Error";
            }
        }
        catch (const char *a)
        {
            cout << "Enter valid Number";
        }

        switch (menu)
        {

        case 1:
            cout << endl;
            cout << "********************************** WELCOME TO FLIGHT SCHEDULE *********************************" << endl;
            cout << endl;

            flight_schedule();
            break;

        case 2:
            cout << endl;
            cout << "************** WELCOME TO RESERVATION DESK **************" << endl;
            cout << endl;

            flight_details();
            cout << "Enter The Number Of Passenger :: ";
            cin >> n;
            cout << endl;
            get_details(n);
            printdetails(n);
            billing(n);
            cout << endl;
            break;

        case 3:
            print_list(n);
            cout << endl;
            billing(n);
            cout << endl;
            break;

        case 4:
            print_report(n);
            break;

        case 5:
            cout << "\n\nThank you come again\n\n\n";
            exit(0);
        }
        cout << "   PROCESS COMPLETED...";
        cout << "\n   THANKS FOR VISIT, HAVE A GOOD DAY ...\n";
        cout << "***************************************************************************************************************************************" << endl;
        cout << endl;

    } while (menu != 5);
}

// Main Function
int main()
{

    cout << endl;
    cout << "---------------------------------------------------------------------" << endl;
    cout << "*************** WELCOME TO PUNE INTERNATIONAL AIRPORT *************** \n";
    cout << "---------------------------------------------------------------------" << endl;
    cout << endl;

    Menu m;
    m.displayMenu();
}