#include <iostream>
#include <fstream>
#include <string>
#include "Staff.h"
#include "Person.h"

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

    cout<<"Enter salary: ";
    cin>>salary;

    cout<<"Enter address: ";
    cin>>address;
    
    cout<<"Enter yearJoined: ";
    cin>>yearJoined;
}


//FILE HANDLING:
void Staff::writeDataToFile() {
    Person::writeDataToFile();
        ofstream outFile("data/staff.txt", ios::app); // Open file in append mode
    if (outFile.is_open())
    {
        outFile << job << " " << salary << " " << address << " "
                << yearJoined << endl;
        outFile.close();
    }
    else
    {
        cout << "Error opening the file for writing." << endl;
    }
}

void Staff::readDataFromFile() {
    Person::readDataFromFile();
ifstream inFile("data/staff.txt");
    if (inFile.is_open()) {
        while (inFile >> job >> salary >> address >> yearJoined) {
            Staff staff;
            staff.job = job;
            staff.salary = salary;
            staff.address = address;
            staff.yearJoined = yearJoined;
            staffs.push_back(staff);
        }
        inFile.close();
    } else {
        cout << "Error opening the file for reading." << endl;
    }
}

void Staff::updateDataInFile() {
    Person::updateDataInFile();
    ifstream inFile("data/staff.txt");
    ofstream tempFile("data/temp2.txt");
    string findId;
    while (inFile >> job >> salary >> address >> yearJoined)
    {
        if (getId() == findId)
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