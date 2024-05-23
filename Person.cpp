#include <iostream>
#include <fstream>
#include <limits>
#include <algorithm>
#include <string>
#include "Person.h"
using namespace std;

// Constructor:
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

// Deconstructor:          
Person::~Person(){}

// Function to set all the values of Person:  
void Person::setAll(string fullName, string id, string nationality, int age, float height, float weight)
{
    this->fullName = fullName;
    this->id = id;
    this->nationality = nationality;
    this->age = age;
    this->height = height;
    this->weight = weight;
}

// Function for displaying all the values of Person:
void Person::displayInfo() const
{
    cout << "Full Name: " << fullName << endl;
    cout << "ID: " << id << endl;
    cout << "Nationality: " << nationality << endl;
    cout << "Age: " << age << endl;
    cout << "Height: " << height << endl;
    cout << "Weight: " << weight << endl;
}

// Initialize Setters:
void Person::setFullName(string fullName)
{
    this->fullName = fullName;
}

void Person::setId(string id)
{
    this->id = id;
}

void Person::setNationality(string nationality)
{
    this->nationality = nationality;
}

void Person::setAge(int age)
{
    this->age = age;
}

void Person::setHeight(float height){
    this->height=height;
}

void Person::setWeight(float weight){
    this->weight=weight;
}

// Initialize Getters:
string Person::getFullName()
{
    return fullName;
}

string Person::getNationality()
{
    return nationality;
}

int Person::getAge()
{
    return age;
}

float Person::getHeight(){
    return height;
}

float Person::getWeight(){
    return weight;
}

// Function for adding new Person:
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

// Function for making the user gives Integers:
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

// Helper function to trim whitespace from both ends of a string:
std::string Person::trim(const std::string& str) {
    size_t first = str.find_first_not_of(" \t\n\r");
    size_t last = str.find_last_not_of(" \t\n\r");
    if (first == std::string::npos)
        return "";  // No non-whitespace characters
    return str.substr(first, (last - first + 1));
}


// FILE HANDLING:

// WRITER:
void Person::writeDataToFile()
{
}

// READER:
void Person::readDataFromFile() 
{
}

//SEARCHER:
void Person::searchDataInFile()
{    
}

// REMOVER:
void Person::removeDataFromFile()
{
}