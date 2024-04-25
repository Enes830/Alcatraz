// Person.h
#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person {
public:
    Person(std::string name, int age);
    virtual ~Person();

private:
    std::string name;
    int age;
};

#endif // PERSON_H
