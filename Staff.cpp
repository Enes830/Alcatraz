#include <iostream>
#include <fstream>
#include <string>
#include "Staff.h"
#include "Person.h"
#include <sstream>


using namespace std;


Staff::Staff(){}
Staff::Staff(string fullName,string id,string nationality,int age,float height ,float weight,string job,int salary,string address,int yearJoined){
    Person::setAll(fullName,id,nationality,age,height,weight);
    this->salary = salary;
    this->job = job;
    this -> address = address;
    this -> yearJoined = yearJoined;
}

Staff::~Staff() {}

void Staff::setJob(string job){
    this -> job = job;
}
string Staff::getJob(){
    return job;
}

void Staff::setAddress(string address){
    this -> address = address;
}
string Staff::getAddress(){
    return address;
}

void Staff::setSalary(int salary){
    this -> salary = salary;
}
int Staff::getSalary(){
    return salary;
}

void Staff::setYearJoined(int yearJoined){
    this -> yearJoined = yearJoined;
}
int Staff::getYearJoined(){
    return yearJoined;
}




void Staff::displayInfo(){
    cout<<endl;
    Person::displayInfo();
    cout<<"Job: "<<job<<endl;
    cout<<"Salary: "<<salary<<" $"<<endl;
    cout<<"Address: "<<address<<endl;
    cout<<"Year Joined: "<<yearJoined<<endl;

}
void Staff::incrementSalary(double percentage){
    if (percentage>0)
        salary *=percentage;
}
void Staff::incrementSalary(int monthlyBonus){
    if (monthlyBonus>0)
        salary += monthlyBonus;
}
void Staff::incrementSalary(double percentage,int monthlyBonus){
    incrementSalary(percentage);
    incrementSalary(monthlyBonus);
}

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

void Staff::searchDataInFile() {
    ifstream inFile("data/staff.csv"); // Assuming your CSV file is named "staff.csv"
    if (inFile.is_open()) {
        string line;
        getline(inFile, line); // Skip the header if your CSV includes headers.

        cout << "Enter the staff ID to search: ";
        string targetId;
        cin >> targetId;

        while (getline(inFile, line)) {
            stringstream ss(line);
            string cell;
            Staff staff;

            getline(ss, cell, ','); // Staff ID
            if (cell == targetId) {
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

            getline(ss, cell, ','); // Sentence Length
            staff.setSalary(stoi(cell));

            getline(ss, cell, ','); // Sentence Start
            staff.setYearJoined(stoi(cell));

                // Display the information for the matching staff ID
                staff.displayInfo();
                cout << "-----------------------" << endl;
                break; // Exit the loop after finding the match
            }
        }

        inFile.close();
    } else {
        cout << "Error opening the file for reading." << endl;
    }
}

void Staff::removeDataFromFile() {
    Person::removeDataFromFile();
    ifstream inFile("data/staff.txt");
    ofstream tempFile("data/temp2.txt");
    string findId;
    while (inFile >> job >> salary >> address >> yearJoined)
    {
        if (getId() != findId)
        {
        }
        tempFile << job << " " << salary << " " << address << " "
                 << yearJoined << endl;
    }
    inFile.close();
    tempFile.close();
    remove("data/staff.txt");
    rename("data/temp2.txt", "data/staff.txt");
}