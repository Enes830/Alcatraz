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


/*
//FILE HANDLING:
void writeDataToFile() {
    // Implementation for writing data to the file
    // ...
}

void readDataFromFile() {
    // Implementation for reading data from the file
    // ...
}

void updateDataInFile() {
    // Implementation for updating data in the file
    // ...
}

void removeDataFromFile() {
    // Implementation for removing data from the file
    // ...
}
*/