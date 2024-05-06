#include <string>
#include <iostream>
#include "Inmate.h"
using namespace std;


Inmate::Inmate(){}
Inmate::Inmate(string fullName,string id,string nationality,int age,float height ,float weight,string address,string cage,string sentenceStart,int sentenceLength,string felony,bool isAlive){
    Person::setAll(fullName,id,nationality,age,height,weight);
    this->cage = cage;
    this->sentenceStart = sentenceStart;
    this -> sentenceLength = sentenceLength;
    this -> felony = felony;
    this->isAlive = true;
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
    cout << "Alive: " << (isAlive? "Yes" : "No") << endl;
    cout << "Dead: " << (isAlive? "No" : "Yes") << endl;
}

// bool isPersonAlive(Inmate& Inmate) {
//     cout << "Checking person's status..." << endl;
//     return Inmate.getAlive();
// }