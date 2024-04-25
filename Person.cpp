#include "Person.h"
#include <iostream>
#include <string>
using namespace std;

Person::Person(string name, int age) {
    this->name = name;
    this->age = age;
}

Person::~Person() {
    cout << "Destructor called for " << name << endl;
}
