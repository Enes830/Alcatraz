#include <string>
#include <iostream>
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

Staff::~Staff() {
    cout << "Destructor called for Staff with job: " << job << endl;
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