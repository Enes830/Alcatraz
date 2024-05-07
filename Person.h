// Person.h
#ifndef PERSON_H
#define PERSON_H
using namespace std;
#include <string>

class Person {
public:
    //Constructor:
    Person();
    Person(string fullName,string id,string nationality,int age,float height ,float weight);
    //deconstructor:
    virtual ~Person();
    //Declaring Setters:
    void setFullName(string fullName);
    void setId(string id);
    void setNationality(string nationality);
    void setAge(int age);
    void setHeight(float height);
    void setWeight(float weight);
    //Declaring Getters:
    string getFullName();
    string getId();
    string getNationality();
    int getAge();
    //Declaring Functions:
    void addPerson();
    void displayInfo();
    void setAll(string fullName,string id,string nationality,int age,float height ,float weight);
private:
    //Declaring Attributes:
    int age;
    float height, weight;
    string fullName,id,nationality;
};

#endif