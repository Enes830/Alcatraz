#include "Person.h"
#include <iostream>
#include <string>
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


