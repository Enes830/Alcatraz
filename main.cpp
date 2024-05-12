#include <iostream>
#include "Person.h"
#include "Staff.h"
#include "Inmate.h"
#include <vector>

vector<Person> Person::persons;
int main() {
    // Inmate obj;
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
                Person newPerson;
                newPerson.addPerson();
                newPerson.writeDataToFile();
                cout << "Inmate added successfully!\n";

                break;
            }
            case 2: {
            Person newPerson;
            newPerson.readDataFromFile(); // Read data from file into newPerson1

            cout << "List of Persons:\n";
            

            for (const auto& person : newPerson.persons) {
                person.displayInfo(); // Display information for each person in the vector
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