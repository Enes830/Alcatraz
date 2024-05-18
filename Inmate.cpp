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
    ifstream inFile("data/people.csv");
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

void readDataFromFile() {
        ifstream inFile("data/inmate.csv");
        if (inFile.is_open()) {
            string line;
            getline(inFile, line);  // Optionally skip the header if your CSV includes headers.

            while (getline(inFile, line)) {
                stringstream ss(line);
                string cell;
                
                getline(ss, cell, ',');
                int id = 0;
                if (!cell.empty()) {
                    try {
                        id = stoi(cell);
                    } catch (const invalid_argument& e) {
                        cerr << "Invalid ID: " << cell << endl;
                        continue;
                    }
                }

                getline(ss, cell, ',');
                string fullName = cell;

                getline(ss, cell, ',');
                string nationality = cell;

                getline(ss, cell, ',');
                int age = 0;
                if (!cell.empty()) {
                    try {
                        age = stoi(cell);
                    } catch (const invalid_argument& e) {
                        cerr << "Invalid Age: " << cell << endl;
                        continue;
                    }
                }

                getline(ss, cell, ',');
                float height = 0.0f;
                if (!cell.empty()) {
                    try {
                        height = stof(cell);
                    } catch (const invalid_argument& e) {
                        cerr << "Invalid Height: " << cell << endl;
                        continue;
                    }
                }

                getline(ss, cell, ',');
                float weight = 0.0f;
                if (!cell.empty()) {
                    try {
                        weight = stof(cell);
                    } catch (const invalid_argument& e) {
                        cerr << "Invalid Weight: " << cell << endl;
                        continue;
                    }
                }

                getline(ss, cell, ',');
                string cage = cell;

                getline(ss, cell, ',');
                string felony = cell;

                getline(ss, cell, ',');
                string sentenceStart = cell;

                getline(ss, cell, ',');
                long long sentenceLength = 0;
                if (!cell.empty()) {
                    try {
                        sentenceLength = stoll(cell);
                    } catch (const invalid_argument& e) {
                        cerr << "Invalid Sentence Length: " << cell << endl;
                        continue;
                    }
                }

                Inmate inmate;
                inmate.setFullName(fullName);
                inmate.setNationality(nationality);
                inmate.setAge(age);
                inmate.setHeight(height);
                inmate.setWeight(weight);
                inmate.setCage(cage);
                inmate.setFelony(felony);
                inmate.setSentenceStart(sentenceStart);
                inmate.setSentenceLength(sentenceLength);

              //  inmates.push_back(inmate);  // Assuming a vector<Inmate> inmates is part of the class.
            }
            inFile.close();
        } else {
            cout << "Error opening the file for reading." << endl;
        }
    }

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
