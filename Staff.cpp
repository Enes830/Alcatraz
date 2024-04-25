#include <string>
#include <iostream>
#include "Staff.h"
using namespace std;

Staff::Staff(string job, int salary) : Person("Default Name", 0) {
    this->salary = salary;
    this->job = job;
}

Staff::~Staff() {
    cout << "Destructor called for Staff with job: " << job << endl;
}
