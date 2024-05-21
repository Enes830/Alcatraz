// Inmate.h
#ifndef INMATE_H
#define INMATE_H
using namespace std;
#include "Person.h"
#include <string>
#include <vector>

class Inmate : public Person {
    public:
        //Constructor:
        Inmate();
        Inmate(const std::string& id) : Person(id) {}
        Inmate(string fullName,string id,string nationality,int age,float height , 
        float weight,string felony,string cage,string sentenceStart,
        long long sentenceLength);
        //deconstructor:
        virtual ~Inmate();
        //Declaring Setters:
        void setFelony(string felony);
        void setCage(string cage);
        void setSentenceStart(string sentenceStart);
        void setSentenceLength(long long sentenceLength);
         //Declaring Getters:
        string getFelony();
        string getCage();
        string getSentenceStart();
        long long getSentenceLength();
        //Declaring Functions:
        void displayInfo();
        void addPerson();
        void writeDataToFile();
        void readDataFromFile();
        void removeDataFromFile();
        void searchDataInFile();
        static vector<Inmate> inmates;
    private:
        //Declaring Attributes:
        string cage,sentenceStart,felony;
        long long sentenceLength;
};

#endif