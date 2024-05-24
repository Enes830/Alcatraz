#ifndef STAFF_H
#define STAFF_H

#include "Person.h"
#include <string>
#include <vector>
using namespace std;

class Staff : public Person{
    public:
        // Constructor:
        Staff();
        Staff(const string& id) : Person(id) {}
        Staff(string fullName,string id,string nationality,int age,float height ,float weight,string job,int salary,string address,int yearJoined);

        // Deconstructor:
        virtual ~Staff();

        // Declaring Setters:
        void setJob(string job);
        void setAddress(string address);
        void setSalary(int salary);
        void setYearJoined(int yearJoined);

        // Declaring Getters:
        string getJob();
        string getAddress();
        int getSalary();
        int getYearJoined();

        // Declaring Functions:
        void incrementSalary(double percentage);
        void incrementSalary(double percentage,int monthlyBonus);
        void incrementSalary(int monthlyBonus);
        void displayInfo();
        void addPerson();
        void writeDataToFile();
        void readDataFromFile();
        void searchDataInFile();
        void removeDataFromFile();
        static vector<Staff> staffs;

    private:
        // Declaring Attributes:
        string job,address;
        int salary,yearJoined;

};

#endif