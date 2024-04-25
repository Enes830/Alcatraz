#include <string>
#include "Person.h"
using namespace std;
#define STAFF_H

class Staff : public Person{
    public:
        Staff(string job,int salary);
        virtual ~Staff();
    private:
        string job;
        int salary;

};
