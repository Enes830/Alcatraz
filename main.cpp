#include <iostream>
#include "Person.h"
#include "Staff.h"
#include "Inmate.h"
#include <vector>
using namespace std;

vector<Person> Person::persons;
vector<Staff> Staff::staffs;
vector<Inmate> Inmate::inmates;


int main() {
     //Inmate obj;
    // obj.addPerson();
   //  obj.writeDataToFile();
    // obj.addPerson();
    // obj.displayInfo();
    
    int choice;
    do {
        cout << "Prison Management System\n";
        cout << "1. Add Inmate\n";
        cout << "2. Display Inmate Information\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {   
                Inmate inm_obj;
                inm_obj.addPerson();
                inm_obj.writeDataToFile();
                cout << "Inmate added successfully!\n";

                break;
            }
            case 2: {
            Inmate inm_obj;
            inm_obj.displayInfo();
            inm_obj.readDataFromFile(); // Read data from file into inm_obj1

            cout << "List of Persons:\n";
            

            for (const auto& inmate : inm_obj.inmates) {
                inm_obj.displayInfo(); // Display information for each person in the vector
                cout << endl;
            }
            break;
            }
            case 3:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 3);

    return 0;
}