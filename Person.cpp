#include "Person.h"
#include <iostream>
#include <string>
using namespace std;

Person::Person() {

}

Person::~Person() {

}
void Person::setFullName(string fullName){
    this -> fullName = fullName;
}

void Person::setAge(int age){
    this -> age = age;
}

string Person::getFullName(){
    return fullName;
}