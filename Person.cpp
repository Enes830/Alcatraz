#include <iostream>
#include <fstream>
#include <string>
#include "Person.h"
using namespace std;

Person::Person() {

}
Person::Person(string fullName,string id,string nationality,int age,float height ,float weight){
    this -> fullName = fullName;
    this -> id = id;
    this -> nationality = nationality;
    this -> age = age;
    this -> height = height;
    this -> weight = weight;
}

Person::~Person() {

}

void Person::setAll(string fullName,string id,string nationality,int age,float height ,float weight){
    this -> fullName = fullName;
    this -> id = id;
    this -> nationality = nationality;
    this -> age = age;
    this -> height = height;
    this -> weight = weight;
}

void Person::displayInfo(){
    cout<<"Full Name: "<<fullName<<endl;
    cout<<"ID: "<<id<<endl;
    cout<<"Nationality: "<<nationality<<endl;
    cout<<"Age: "<<age<<endl;
    cout<<"Height: "<<height<<endl;
    cout<<"Weight: "<<weight<<endl;    
}

void Person::setFullName(string fullName){
    this -> fullName = fullName;
}

string Person::getFullName(){
    return fullName;
}

void Person::setId(string id){
    this -> id = id;

}

string Person::getId(){
    return id;

}

void Person::setNationality(string nationality){
    this -> nationality = nationality;

}

string Person::getNationality(){
    return nationality;

}


void Person::setAge(int age){
    this -> age = age;
}

int Person::getAge(){
    return age;
}

void Person::addPerson(){
cout<<"Enter full name: ";
cin>>fullName;

cout<<"Enter id: ";
cin>>id;

cout<<"Enter Nationality: ";
cin>>nationality;

cout<<"Enter age: ";
cin>>age;

cout<<"Enter height: ";
cin>>height;

cout<<"Enter weight: ";
cin>>weight;
}


//FILE HANDLING:
void Person::writeDataToFile() {
    ofstream outFile("data/people.txt");
    if (outFile.is_open()) {
        outFile << fullName << " " << id << " " << nationality << " "
                << age << " " << height << " " << weight << endl;
        outFile.close();
    } else {
        cout << "Error opening the file for writing." << endl;
    }
}

void Person::readDataFromFile() {
    ifstream inFile("data/people.txt");
    if (inFile.is_open()) {
        inFile >> fullName >> id >> nationality >> age >> height >> weight;
        inFile.close();
    } else {
        cout << "Error opening the file for reading." << endl;
    }
}

void Person::updateDataInFile() {     ifstream inFile("data/people.txt");
    ofstream tempFile("data/temp.txt");
    string findId; 
    while (inFile >> fullName >> id >> nationality >> age >> height >> weight) {
        if (id == findId) {
        }
        tempFile << fullName << " " << id << " " << nationality << " "
    << age << " " << height << " " << weight << endl;
    }
    inFile.close();
    tempFile.close();
    remove("data/people.txt"); 
    rename("data/temp.txt", "data/people.txt"); 
}

void Person::removeDataFromFile() {      
        ifstream inFile("data/people.txt");
    ofstream tempFile("data/temp.txt");
    string findId;
    while (inFile >> fullName >> id >> nationality >> age >> height >> weight) {
        if (id != findId) {
            tempFile << fullName << " " << id << " " << nationality << " "
    << age << " " << height << " " << weight << endl;
        }
    }
    inFile.close();
    tempFile.close();
    remove("data/people.txt");
    rename("data/temp.txt", "data/people.txt");
}