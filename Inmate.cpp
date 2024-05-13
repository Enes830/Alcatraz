#include <iostream>
#include <fstream>
#include <string>
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
void Inmate::writeDataToFile() {
    Person::writeDataToFile();
    ofstream outFile("data/inmate.txt", ios::app); // Open file in append mode
    if (outFile.is_open())
    {
        outFile << cage << " " << felony << " " << sentenceStart << " "
                << sentenceLength << endl;
        outFile.close();
    }
    else
    {
        cout << "Error opening the file for writing." << endl;
    }
}

void Inmate::readDataFromFile() {
    Person::readDataFromFile();
    ifstream inFile("data/inmate.txt");
    if (inFile.is_open()) {
        while (inFile >> cage >> felony >> sentenceStart >> sentenceLength) {
            Inmate inmate;
            inmate.cage = cage;
            inmate.felony = felony;
            inmate.sentenceStart = sentenceStart;
            inmate.sentenceLength = sentenceLength;
            inmates.push_back(inmate);
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
