#include <string>
#include <iostream>
#include "Inmate.h"
#include "Person.h"

using namespace std;


Inmate::Inmate(){}
Inmate::Inmate(string fullName,string id,string nationality,int age,float height ,float weight,string felony,string cage,string sentenceStart,int sentenceLength){
    Person::setAll(fullName,id,nationality,age,height,weight);
    this -> felony = felony;
    this->cage = cage;
    this->sentenceStart = sentenceStart;
    this -> sentenceLength = sentenceLength;
}

Inmate::~Inmate() {
    cout << "Destructor called for Inmate"<< endl;
}


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

