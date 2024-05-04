// Inmate.h
#ifndef INMATE_H
#define INMATE_H
#include <string>
#include "Person.h"
using namespace std;

class Inmate : public Person {
    public:
        Inmate();
        Inmate(string fullName,string id,string nationality,int age,float height ,float weight,string address);
        virtual ~Inmate();
        void setCage(string cage);
        void setSentenceStart(string sentenceStart);
        void setSentenceLength(int sentenceLength);
        void setFelony(string felony);
        void setAlive(bool isAlive);
        string getSentenceStart();
        int getSentenceLength();
        string getFelony();
        bool getAlive();
        void displayInfo();
    private:
        string cage,sentenceStart,felony;
        int sentenceLength;
        bool isAlive;
};

bool isPersonAlive(Inmate& Inmate);

#endif // INMATE_H
