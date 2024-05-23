// Person.h
#ifndef PERSON_H
#define PERSON_H
using namespace std;
#include <string>
#include <vector>
#include <algorithm>


class Person {
public:
    // Constructor:
    Person();
    Person(const std::string& id) : id(id) {}
    Person(string fullName,string id,string nationality,int age,float height ,float weight);

    // Deconstructor:
    virtual ~Person();

    //Declaring Setters:
    void setFullName(string fullName);
    void setId(string id);
    void setNationality(string nationality);
    void setAge(int age);
    void setHeight(float height);
    void setWeight(float weight);

    // Declaring Getters:
    string getFullName();
    virtual std::string getId() const { return id; }
    string getNationality();
    int getAge();
    float getHeight();
    float getWeight();
    
    // Declaring Functions:
    void addPerson();
    void displayInfo() const;
    void setAll(string fullName,string id,string nationality,int age,float height ,float weight);
    void writeDataToFile();
    void readDataFromFile();
    void removeDataFromFile();
    void searchDataInFile();
    static vector<Person> persons;

protected:
    // Declaring Attributes:
    int inputInteger(const string& prompt);
    static std::string trim(const std::string& str);
    int age;
    float height, weight;
    string fullName,id,nationality;
};

#endif