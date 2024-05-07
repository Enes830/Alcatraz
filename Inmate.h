// Inmate.h
#ifndef INMATE_H
#define INMATE_H

#include <string>
#include "Person.h"
using namespace std;

class Inmate : public Person {
    public:
        //Constructor:
        Inmate();
        Inmate(string fullName,string id,string nationality,int age,float height , 
        float weight,string felony,string cage,string sentenceStart,
        int sentenceLength);
        //deconstructor:
        virtual ~Inmate();
        //Declaring Setters:
        void setFelony(string felony);
        void setCage(string cage);
        void setSentenceStart(string sentenceStart);
        void setSentenceLength(int sentenceLength);
         //Declaring Getters:
        string getFelony();
        string getCage();
        string getSentenceStart();
        int getSentenceLength();
        //Declaring Functions:
        void displayInfo();
        void addPerson();
    private:
        //Declaring Attributes:
        string cage,sentenceStart,felony;
        int sentenceLength;
};

#endif