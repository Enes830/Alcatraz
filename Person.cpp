#include <iostream>
#include <fstream>
#include <limits>
#include <string>
#include "Person.h"
using namespace std;

Person::Person()
{
}
Person::Person(string fullName, string id, string nationality, int age, float height, float weight)
{
    this->fullName = fullName;
    this->id = id;
    this->nationality = nationality;
    this->age = age;
    this->height = height;
    this->weight = weight;
}

Person::~Person()
{
}

void Person::setAll(string fullName, string id, string nationality, int age, float height, float weight)
{
    this->fullName = fullName;
    this->id = id;
    this->nationality = nationality;
    this->age = age;
    this->height = height;
    this->weight = weight;
}

void Person::displayInfo() const
{
    cout << "Full Name: " << fullName << endl;
    cout << "ID: " << id << endl;
    cout << "Nationality: " << nationality << endl;
    cout << "Age: " << age << endl;
    cout << "Height: " << height << endl;
    cout << "Weight: " << weight << endl;
}

void Person::setFullName(string fullName)
{
    this->fullName = fullName;
}

string Person::getFullName()
{
    return fullName;
}

void Person::setId(string id)
{
    this->id = id;
}

string Person::getId()
{
    return id;
}

void Person::setNationality(string nationality)
{
    this->nationality = nationality;
}

string Person::getNationality()
{
    return nationality;
}

void Person::setAge(int age)
{
    this->age = age;
}

int Person::getAge()
{
    return age;
}

void Person::setHeight(float height){
    this->height=height;
}

float Person::getHeight(){
    return height;
}

void Person::setWeight(float weight){
    this->weight=weight;
}

float Person::getWeight(){
    return weight;
}

void Person::addPerson()
{
    cout << "Enter full name: ";
    cin.ignore(); //clear the line before calling getline
    getline(cin,fullName);  //reads the entire line

    cout << "Enter Nationality: ";
    cin >> nationality;

    age = inputInteger("Enter age: ");
    height = inputInteger("Enter height: ");
    weight = inputInteger("Enter weight: ");
}

int Person::inputInteger(const string& prompt) {
        int value;
        cout << prompt;
        while (!(cin >> value)) {
            cin.clear(); // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore wrong input
            cout << "Please enter an integer value: "; // Prompt the user again
        }
        return value;
    }





// FILE HANDLING:
void Person::writeDataToFile()
{
}
void Person::searchDataInFile()
{    
}
// void Person::readDataFromFile() {
// }


void Person::updateDataInFile()
{
}

void Person::removeDataFromFile()
{
}