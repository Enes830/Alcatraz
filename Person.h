// Person.h
#ifndef PERSON_H
#define PERSON_H
using namespace std;
#include <string>

class Person {
public:
    Person();
    Person(string fullName,string id,string nationality,int age,float height ,float weight);
    virtual ~Person();
    void setFullName(string fullName);
    void setAge(int age);
    void setId(string id);
    void setHeight(float height);
    void setWeight(float weight);
    void setNationality(string nationality);
    void displayInfo();
    void setAll(string fullName,string id,string nationality,int age,float height ,float weight);
    string getFullName();
    int getAge();
    string getId();


private:
    int age;
    float height, weight;
    string fullName,id,nationality;

};

#endif // PERSON_H
