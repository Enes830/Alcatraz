// Person.h
#ifndef PERSON_H
#define PERSON_H
using namespace std;
#include <string>
#include <vector>

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
    float getHeight();
    float getWeight();
    
    //Declaring Functions:
    void addPerson();
    void displayInfo() const;
    void setAll(string fullName,string id,string nationality,int age,float height ,float weight);
    void writeDataToFile();
    void readDataFromFile();
    void updateDataInFile();
    void removeDataFromFile();
    static vector<Person> persons;
protected:
    //Declaring Attributes:
    int inputInteger(const string& prompt);
    int age;
    float height, weight;
    string fullName,id,nationality;

    
};

#endif