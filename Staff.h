#ifndef STAFF_H
#define STAFF_H

#include <string>
#include "Person.h"
using namespace std;

class Staff : public Person{
    public:
        //Constructor:
        Staff();
        Staff(string fullName,string id,string nationality,int age,float height ,float weight,string job,int salary,string address,int yearJoined);
        //deconstructor:
        virtual ~Staff();
        //Declaring Setters:
        void setJob(string job);
        void setAddress(string address);
        void setSalary(int salary);
        void setYearJoined(int yearJoined);
        //Declaring Getters:
        string getJob();
        string getAddress();
        int getSalary();
        int getYearJoined();
        //Declaring Functions:
        void incrementSalary(double percentage);
        void incrementSalary(double percentage,int monthlyBonus);
        void incrementSalary(int monthlyBonus);
        void displayInfo();
        void addPerson();
    private:
        //Declaring Attributes:
        string job,address;
        int salary,yearJoined;

};

#endif