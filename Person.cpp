#include <iostream>
#include <fstream>
#include <limits>
#include <algorithm>
#include <string>
#include "Person.h"
using namespace std;

Person::Person(){}

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
    cin >> fullName;

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

// Helper function to trim whitespace from both ends of a string
std::string Person::trim(const std::string& str) {
    size_t first = str.find_first_not_of(" \t\n\r");
    size_t last = str.find_last_not_of(" \t\n\r");
    if (first == std::string::npos)
        return "";  // No non-whitespace characters
    return str.substr(first, (last - first + 1));
}



// FILE HANDLING:
void Person::writeDataToFile()
{
}

// void Person::readDataFromFile() {
// }


void Person::removeDataFromFile()
{
}