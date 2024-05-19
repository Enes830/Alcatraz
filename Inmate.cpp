#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "Inmate.h"
#include "Person.h"

using namespace std;


Inmate::Inmate(){}
Inmate::Inmate(string fullName,string id,string nationality,int age,float height ,float weight,string felony,string cage,string sentenceStart,int sentenceLength){
    Person::setAll(fullName,id,nationality,age,height,weight);
    this -> felony = felony;
    this -> cage = cage;
    this -> sentenceStart = sentenceStart;
    this -> sentenceLength = sentenceLength;
}

Inmate::~Inmate() {}

void Inmate::setFelony(string felony){
    this -> felony = felony;
}
string Inmate::getFelony(){
    return felony;
};

void Inmate::setCage(string cage){
    this -> cage = cage;
}
string Inmate::getCage(){
    return cage;
};

void Inmate::setSentenceStart(string sentenceStart){
    this -> sentenceStart = sentenceStart;
}
string Inmate::getSentenceStart(){
    return sentenceStart;
};

void Inmate::setSentenceLength(int sentenceLength){
    this -> sentenceLength = sentenceLength;
}
int Inmate::getSentenceLength(){
    return sentenceLength;
};

void Inmate::displayInfo(){
    cout<<endl;
    Person::displayInfo();
    cout<<"Cage: "<<cage<<endl;
    cout<<"Felony: "<<felony<<endl;
    cout<<"Sentence Start: "<<sentenceStart<<endl;
    cout<<"Sentence Length: "<<sentenceLength<<" Days"<<endl;
}

void Inmate::addPerson(){
Person::addPerson();

cout<<"Enter cage: ";
cin>>cage;

cout<<"Enter felony: ";
cin>>felony;

cout<<"Enter sentenceStart: ";
cin>>sentenceStart;

cout<<"Enter sentenceLength: ";
cin>>sentenceLength;
}

//FILE HANDLING:
void Inmate::writeDataToFile()
{
    Person::writeDataToFile();
    ifstream inFile("data/inmate.csv");
    bool isEmpty = inFile.peek() == EOF;  // Check if the file is empty

    // Calculate the next ID based on the number of lines (excluding the header)
    int nextId = 1;  // Start IDs from 1
    string line;
    if (!isEmpty) {
        getline(inFile, line); // Skip the header line
        while (getline(inFile, line)) {
            nextId++;  // Count each line to get the next ID
        }
    }
    inFile.close();  // Close the input file

    ofstream outFile("data/inmate.csv", ios::app); // Open file in append mode
    if (outFile.is_open())
    {
        if (isEmpty) {
            // Write headers if the file is empty
            outFile << "ID,Full Name,Nationality,Age,Height,Weight,Cage,Felony,Sentence Start,Sentence Length" << endl;
        }

        // Write the data with the next ID
        outFile << nextId << "," << getFullName() << "," << getNationality() << "," << getAge() << "," << getHeight() <<","<< getWeight() <<","<< cage << "," << felony << "," << sentenceStart << ","
                << sentenceLength << endl;
        outFile.close();
    }
    else
    {
        cout << "Error opening the file for writing." << endl;
    }
}
/*
void Inmate::readDataFromFile() {
    ifstream inFile("data/inmate.csv"); // Assuming your CSV file is named "inmate.csv"
    if (inFile.is_open()) {
        string line;
        getline(inFile, line); // Optionally skip the header if your CSV includes headers.
        vector<Inmate> inmates;

        while (getline(inFile, line)) {
            stringstream ss(line);
            string cell;
            Inmate inmate;
            // Assuming the order of data in the CSV is: fullName, id, nationality, age, height, weight, cage, sentenceStart, felony, sentenceLength
            getline(ss, cell, ',');
            inmate.setFullName(cell);

            getline(ss, cell, ',');
                try {
                    inmate.setId(cell);
                } catch (const invalid_argument& e) {
                    cerr << "Invalid ID: " << cell << " Skipping entry." << endl;
                    continue;
                }

            getline(ss, cell, ',');
            nationality = cell;

            // Similar parsing for age, height, weight, cage, sentenceStart, felony, and sentenceLength...
            // (Implement the parsing for other attributes)

            // Create an Inmate object and populate its attributes
            Inmate inmate;
            inmate.setId(id);
            inmate.setFullName(fullName);
            inmate.setNationality(nationality);
            inmate.setAge(age);
            inmate.setHeight(height);
            inmate.setWeight(weight);
            inmate.cage;
            inmate.felony;
            inmate.sentenceStart;
            inmate.sentenceLength;
            // Set other attributes similarly...

            // Add the populated Inmate object to your data structure (e.g., vector or other container)
            inmates.push_back(inmate);
        }
        inFile.close();
    } else {
        cout << "Error opening the file for reading." << endl;
    }
}
*/



void Inmate::updateDataInFile() {
    Person::updateDataInFile();
    ifstream inFile("data/inmate.txt");
    ofstream tempFile("data/temp3.txt");
    string findId;
        while (inFile >> cage >> felony >> sentenceStart >> sentenceLength) {
    {
        if (getId() == findId)
        {
        }
        tempFile << cage << " " << felony << " " << sentenceStart << " "
                << sentenceLength << endl;
    }
    inFile.close();
    tempFile.close();
    remove("data/inmate.txt");
    rename("data/temp3.txt", "data/inmate.txt");
    }
}

void Inmate::removeDataFromFile() {
    Person::removeDataFromFile();
        ifstream inFile("data/inmate.txt");
    ofstream tempFile("data/temp3.txt");
    string findId;
        while (inFile >> cage >> felony >> sentenceStart >> sentenceLength) {
    {
        if (getId() != findId)
        {
            tempFile << cage << " " << felony << " " << sentenceStart << " "
                << sentenceLength << endl;
        }
    }
    inFile.close();
    tempFile.close();
    remove("data/inmate.txt");
    rename("data/temp3.txt", "data/inmate.txt");

    }
}
