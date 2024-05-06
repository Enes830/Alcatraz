#include <iostream>
#include "Person.h"
#include "Staff.h"
#include "Inmate.h"

int main() {
    Staff s1("Anas Fateen","S-001","Egyption",20,180,60,"manager",5000,"istanbul",2023);
    Inmate m1("Bilal Kadi","P-001","East Turkistan",20,170.9, 75.2,"gultepe","AC-001","6/5/2024",30,"shop lefting","yes");
    Inmate m2("Abdolmonem Naser","P-002","Syrian",20,172.1,65.9,"Basaksehir","AC-002","6/5/2024",3,"Murdering","No");
    // s1.displayInfo();
    // m1.displayInfo();
    // m2.displayInfo();
    Staff s2("Abdullah Ali","S-002","Yemeni",22,170.1,66.1,"fucker",10000,"vaditepe",2024);
        s2.incrementSalary(2500);

    s2.displayInfo();


    return 0;
}
