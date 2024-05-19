#include <iostream>
#include <fstream>
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
    cin >> fullName;
/*
    cout << "Enter id: ";
    cin >> id;
*/
    cout << "Enter Nationality: ";
    cin >> nationality;

    cout << "Enter age: ";
    cin >> age;

    cout << "Enter height: ";
    cin >> height;

    cout << "Enter weight: ";
    cin >> weight;
}

// FILE HANDLING:
void Person::writeDataToFile()
{/*
    ofstream outFile("data/people.txt", ios::app); // Open file in append mode
    if (outFile.is_open())
    {
        outFile << fullName << " " << id << " " << nationality << " "
                << age << " " << height << " " << weight << endl;
        outFile.close();
    }
    else
    {
        cout << "Error opening the file for writing." << endl;
    }
    */
}

void Person::readDataFromFile() {
    /*
    ifstream inFile("data/people.csv"); // Assuming your CSV file is named "people.csv"
    if (inFile.is_open()) {
        string line;
        getline(inFile, line); // Optionally skip the header if your CSV includes headers.

        while (getline(inFile, line)) {
            stringstream ss(line);
            string cell;

            // Assuming the order of data in the CSV is: fullName, id, nationality, age, height, weight
            string fullName;
            int id;
            string nationality;
            int age;
            float height;
            float weight;

            getline(ss, cell, ',');
            fullName = cell;

            getline(ss, cell, ',');
            try {
                id = stoi(cell);
            } catch (const invalid_argument& e) {
                cerr << "Invalid ID: " << cell << endl;
                continue;
            }

            getline(ss, cell, ',');
            nationality = cell;

            getline(ss, cell, ',');
            try {
                age = stoi(cell);
            } catch (const invalid_argument& e) {
                cerr << "Invalid Age: " << cell << endl;
                continue;
            }

            getline(ss, cell, ',');
            try {
                height = stof(cell);
            } catch (const invalid_argument& e) {
                cerr << "Invalid Height: " << cell << endl;
                continue;
            }

            getline(ss, cell, ',');
            try {
                weight = stof(cell);
            } catch (const invalid_argument& e) {
                cerr << "Invalid Weight: " << cell << endl;
                continue;
            }

            Person person;
            person.fullName = fullName;
            person.id = id;
            person.nationality = nationality;
            person.age = age;
            person.height = height;
            person.weight = weight;
            persons.push_back(person);
        }
        inFile.close();
    } else {
        cout << "Error opening the file for reading." << endl;
    }*/            
}


void Person::updateDataInFile()
{
    /*
    ifstream inFile("data/people.txt");
    ofstream tempFile("data/temp.txt");
    string findId;
    while (inFile >> fullName >> id >> nationality >> age >> height >> weight)
    {
        if (id == findId)
        {
        }
        tempFile << fullName << " " << id << " " << nationality << " "
                 << age << " " << height << " " << weight << endl;
    }
    inFile.close();
    tempFile.close();
    remove("data/people.txt");
    rename("data/temp.txt", "data/people.txt");
    */
}

void Person::removeDataFromFile()
{
    /*
    ifstream inFile("data/people.txt");
    ofstream tempFile("data/temp.txt");
    string findId;
    while (inFile >> fullName >> id >> nationality >> age >> height >> weight)
    {
        if (id != findId)
        {
            tempFile << fullName << " " << id << " " << nationality << " "
                     << age << " " << height << " " << weight << endl;
        }
    }
    inFile.close();
    tempFile.close();
    remove("data/people.txt");
    rename("data/temp.txt", "data/people.txt");
    */
}