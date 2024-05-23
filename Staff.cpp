#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib> // For system()
#include <algorithm> // For std::remove_if
#include <limits>
#include "Staff.h"
#include "Person.h"
#include <sstream>


using namespace std;

// Constructor:
Staff::Staff(){}
Staff::Staff(string fullName,string id,string nationality,int age,float height ,float weight,string job,int salary,string address,int yearJoined){
    Person::setAll(fullName,id,nationality,age,height,weight);
    this->salary = salary;
    this->job = job;
    this -> address = address;
    this -> yearJoined = yearJoined;
}

// Deconstructor:  
Staff::~Staff(){}

// Initialize Setters:
void Staff::setJob(string job){
    this -> job = job;
}
void Staff::setAddress(string address){
    this -> address = address;
}

void Staff::setSalary(int salary){
    this -> salary = salary;
}

void Staff::setYearJoined(int yearJoined){
    this -> yearJoined = yearJoined;
}

// Initialize Getters:
string Staff::getJob(){
    return job;
}
string Staff::getAddress(){
    return address;
}
int Staff::getSalary(){
    return salary;
}
int Staff::getYearJoined(){
    return yearJoined;
}

// Function for displaying all the values of Staff:
void Staff::displayInfo(){
    cout<<endl;
    Person::displayInfo();
        Person::displayInfo();
        cout << "Job: " << job << endl;
        cout << "Salary: " << salary << " $" << endl;
        cout << "Address: " << address << endl;
        cout << "Year Joined: " << yearJoined << endl;
        // Demonstrating the incrementSalary functions
        incrementSalary(45.0, 200); // Example values for percentage and monthly bonus
        cout << "Increased Salary for %45 and $200 bonus: " << salary << " $" << endl;
}

// Function for increase salary:
void Staff::incrementSalary(double percentage) {
        if (percentage > 0)
            salary *= (1 + percentage / 100); // Correcting multiplication to increase by percentage
    }

    void Staff::incrementSalary(int monthlyBonus) {
        if (monthlyBonus > 0)
            salary += monthlyBonus;
    }

    void Staff::incrementSalary(double percentage, int monthlyBonus) {
        incrementSalary(percentage);
        incrementSalary(monthlyBonus);
    }

// Function for adding new Staff:
void Staff::addPerson(){
    Person::addPerson();

    cout<<"Enter job: ";
    cin>>job;

    salary = inputInteger("Enter salary: ");

    cout<<"Enter address: ";
    cin>>address;
    
    yearJoined = inputInteger("Enter year joined: ");
}


//FILE HANDLING:

// WRITER:
void Staff::writeDataToFile()
{
    Person::writeDataToFile();
    ifstream inFile("data/staff.csv");
    bool isEmpty = inFile.peek() == EOF;  // Check if the file is empty

    // Calculate the next ID based on the number of lines (excluding the header)
    int nextId = 1;  // Start IDs from 1
    string line;
    if (!isEmpty) {
        getline(inFile, line); // Skip the header line
        while (getline(inFile, line)) {
            nextId++;  // Count each line to get the next ID
        }
    }
    inFile.close();  // Close the input file

    ofstream outFile("data/staff.csv", ios::app); // Open file in append mode
    if (outFile.is_open())
    {
        if (isEmpty) {
            // Write headers if the file is empty
            outFile << "ID,Full Name,Nationality,Age,Height,Weight,Job,Address,Salary,Year Joined" << endl;
        }

        // Write the data with the next ID
        outFile << nextId << "," << getFullName() << "," << getNationality() << "," << getAge() << "," << getHeight() <<","<< getWeight() <<","<< job << "," << address << "," << salary <<"$"<< ","
                << yearJoined << endl;
        outFile.close();
    }
    else
    {
        cout << "Error opening the file for writing." << endl;
    }
}

// READER:
void Staff::readDataFromFile() {
    ifstream inFile("data/staff.csv"); // Assuming your CSV file is named "staff.csv"
    if (inFile.is_open()) {
        string line;
        getline(inFile, line); // Skip the header if your CSV includes headers.
        vector<Staff> staffs;

        while (getline(inFile, line)) {
            stringstream ss(line);
            string cell;
            Staff staff;

            getline(ss, cell, ','); // ID
            staff.setId(cell);

            getline(ss, cell, ','); // Full Name
            staff.setFullName(cell);

            getline(ss, cell, ','); // Nationality
            staff.setNationality(cell);

            getline(ss, cell, ','); // Age
            staff.setAge(stoi(cell));

            getline(ss, cell, ','); // Height
            staff.setHeight(stof(cell));

            getline(ss, cell, ','); // Weight
            staff.setWeight(stof(cell));

            getline(ss, cell, ','); // Cage
            staff.setJob(cell);

            getline(ss, cell, ','); // Felony
            staff.setAddress(cell);

             // Assuming date is handled as string or appropriately

            getline(ss, cell, ','); // Sentence Length
            staff.setSalary(stoi(cell));

            getline(ss, cell, ','); // Sentence Start
            staff.setYearJoined(stoi(cell));

            // Add the populated staff object to your data structure (e.g., vector or other container)
            staffs.push_back(staff);
        }

        for (auto& staff : staffs) {
            staff.displayInfo();
            cout<<"-----------------------";
        }
        inFile.close();
    } else {
        cout << "Error opening the file for reading." << endl;
    }
}

// SEARCHER:
void Staff::searchDataInFile() {
    ifstream inFile("data/staff.csv"); // Assuming your CSV file is named "staff.csv"
    if (!inFile.is_open()) {
        cout << "Error opening the file for reading." << endl;
        return;
    }

    string line;
    getline(inFile, line); // Skip the header if your CSV includes headers.

    vector<string> ids;
    while (getline(inFile, line)) {
        stringstream ss(line);
        string id;
        getline(ss, id, ','); // Read the ID
        id = trim(id); // Trim any whitespace from the ID
        ids.push_back(id); // Store the ID
    }
    inFile.close();

    bool continueSearch = true;
    while (continueSearch) {
        cout << "Available IDs: " << endl;
        for (const string& id : ids) {
            cout << id << " ";
        }
        cout << endl;

        cout << "Enter the ID to search: ";
        string targetId;
        cin >> targetId;
        targetId = trim(targetId); // Trim any whitespace from the input

        inFile.open("data/staff.csv");
        if (!inFile.is_open()) {
            cout << "Error opening the file for reading." << endl;
            return;
        }
        getline(inFile, line); // Skip the header

        bool found = false;
        while (getline(inFile, line)) {
            stringstream ss(line);
            string cell;
            Staff staff;

            getline(ss, cell, ','); // Staff ID
            cell = trim(cell); // Trim any whitespace from the cell
            if (cell == targetId) {
                staff.setId(cell);

                getline(ss, cell, ','); // Full Name
                staff.setFullName(trim(cell));

                getline(ss, cell, ','); // Nationality
                staff.setNationality(trim(cell));

                getline(ss, cell, ','); // Age
                try {
                    staff.setAge(stoi(trim(cell)));
                } catch (const invalid_argument& e) {
                    cerr << "Invalid age format: " << cell << endl;
                    continue;
                }
                getline(ss, cell, ','); // Height
                staff.setHeight(stof(trim(cell)));

                getline(ss, cell, ','); // Weight
                staff.setWeight(stof(trim(cell)));

                getline(ss, cell, ','); // Job
                staff.setJob(trim(cell));

                getline(ss, cell, ','); // Address
                staff.setAddress(trim(cell));

                getline(ss, cell, ','); // Salary
                staff.setSalary(stoi(trim(cell)));

                getline(ss, cell, ','); // Year Joined
                staff.setYearJoined(stoi(trim(cell)));

                // Display the information for the matching staff ID
                staff.displayInfo();
                cout << "-----------------------" << endl;
                found = true;
                break; // Exit the loop after finding the match
            }
        }

        inFile.close();

        if (!found) {
            cout << "ID not found." << endl;
        }

        cout << "Do you want to search for another ID? (y/n): ";
        char choice;
        cin >> choice;
        continueSearch = (choice == 'y' || choice == 'Y');
    }
}

// REMOVER:
void Staff::removeDataFromFile() {
    std::vector<std::string> records;
    std::string line, targetId;

    system("cls"); // Clear the screen at the beginning

    std::ifstream inFile("data/staff.csv");
    if (!inFile.is_open()) {
        std::cerr << "Error: Unable to open input file. Please check the file path and permissions." << std::endl;
        return;
    }

    while (std::getline(inFile, line)) {
        records.push_back(line); // Store each line as a complete record
    }
    inFile.close();

    if (records.empty()) {
        std::cout << "Notice: There are no records available to delete. The file is empty." << std::endl;
        return;
    }

    do {
        system("cls"); // Clear the screen before showing IDs
        std::cout << "Available IDs:\n";
        for (const auto& record : records) {
            std::istringstream iss(record);
            std::getline(iss, line, ','); // Extract ID from record
            line = Person::trim(line); // Ensure ID is trimmed of whitespace
            std::cout << line << std::endl;
        }

        std::cout << "______________________________________________________________\n";
        std::cout << "Please enter the ID you wish to delete or type 'exit' to terminate the operation: ";
        std::cin >> targetId; // Use cin to read the next word
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the input buffer to remove any leftover characters

        targetId = Person::trim(targetId); // Trim whitespace from user input

        if (targetId == "exit") {
            std::cout << "Exiting operation." << std::endl;
            break;
        }

        bool found = false;
        std::vector<std::string> updatedRecords;

        for (auto& record : records) {
            std::istringstream iss(record);
            std::getline(iss, line, ','); // Extract ID
            line = Person::trim(line); // Trim the ID

            if (line == targetId) {
                found = true;
            } else {
                updatedRecords.push_back(record);
            }
        }

        if (!found) {
            std::cout << "Warning: The ID '" << targetId << "' was not found in the records. Please try again." << std::endl;
        } else {
            std::cout << "Success: The ID '" << targetId << "' has been successfully deleted from the records." << std::endl;
            records = updatedRecords; // Update the main records vector to reflect the deletion
            std::ofstream outFile("data/staff.csv");
            for (const auto& record : updatedRecords) {
                outFile << record << std::endl;
            }
            outFile.close();
        }

        std::cout << "Would you like to delete another ID? (yes/no): ";
        std::getline(std::cin, targetId); // Directly use getline to capture the next line of input
        if (Person::trim(targetId) != "yes") {
            std::cout << "No further deletions requested. Exiting now." << std::endl;
            break;
        }

    } while (true); // Loop indefinitely until 'exit' is entered
}