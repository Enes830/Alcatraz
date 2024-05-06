#include <string>
#include "Person.h"
using namespace std;
#define STAFF_H

class Staff : public Person{
    public:
        Staff();
        Staff(string fullName,string id,string nationality,int age,float height ,float weight,string job,int salary,string address,int yearJoined);
        virtual ~Staff();
        void incrementSalary(double percentage);
        void incrementSalary(double percentage,int monthlyBonus);
        void incrementSalary(int monthlyBonus);
        void displayInfo();
    private:
        string job,address;
        int salary,yearJoined;

};
