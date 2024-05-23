#include <iostream>
#include "Person.h"
#include "Staff.h"
#include "Inmate.h"
#include <vector>
#include <conio.h>
using namespace std;

vector<Person> Person::persons;
vector<Staff> Staff::staffs;
vector<Inmate> Inmate::inmates;


int main() {
    int choice;
    int choice1;
    int choice2;
    do {
        system("cls");
        system("Color 7");
        string test;

        cout << "Prison Management System\n\n";
        cout << "Main Menu"<<endl;
        cout << "==================================="<<endl;
        cout << "[1] Inmate management"<<endl;
        cout << "[2] Staff management"<<endl;
        cout << "[0] Exit\n";
        cout << "==================================="<<endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {   
                do{
                system("Color 6");
                system("cls");
                cout << "==================================="<<endl;
                cout<<"[1] Add Inmate"<<endl;
                cout<<"[2] List of Inmates"<<endl;
                cout<<"[3] Search for Inmate"<<endl;
                cout<<"[4] Delete Inmate"<<endl;
                cout<<"[0] Go back to Main Menu"<<endl;
                cout << "==================================="<<endl;
                cout<< "Enter your choice: ";
                cin>> choice1;

                switch(choice1){
                    case 1:{
                        system("cls");
                        system("Color 2");
                        Inmate newInmate;
                        newInmate.addPerson();
                        newInmate.writeDataToFile();
                        cout<<"Inmate added successfully"<<endl;
                        cout<<"\n\nPress any button to exit:";
                        cin>>test;
                        break;
                    }
                    case 2:{
                        cout<<"2";
                        system("cls");
                        system("Color 5");
                        Inmate newInmate;
                        cout << "List of Inmates:\n";
                        newInmate.readDataFromFile();
                        cout<<"\n\nPress any button to exit:";
                        cin>>test;
                        break;
                    }
                    case 3:{
                        system("cls");
                        system("Color 3");
                        Inmate newInmate;
                        newInmate.searchDataInFile();
                        cout << "\n\nPress any button to exit:";
                        cin >> test;
                        break;
                    }
                    case 4:{
                        system("Color 4");
                        system("cls");
                            Inmate inmate; // Constructor should handle the initialization
                            inmate.removeDataFromFile(); // This function prompts and deletes
                            cout << "\n\nPress any button to exit: ";
                            cin >> test;
                        break;
                    }
                    case 0:{

                        break;
                    }
                    

                }
                } while(choice1 !=0);
                break;
    } 
            case 2:{
                do{
                system("Color 6");
                system("cls");
                cout << "==================================="<<endl;
                cout<<"[1] Add Employee"<<endl;
                cout<<"[2] List of Employees"<<endl;
                cout<<"[3] Search for Employee"<<endl;
                cout<<"[4] Delete Employee"<<endl;
                cout<<"[0] Go back to Main Menu"<<endl;
                cout << "==================================="<<endl;
                cout<< "Enter your choice: ";
                cin>> choice2; 

                switch(choice2){
                    case 1:{
                        system("cls");
                        system("Color 2");           
                        Staff newEmployee;
                        newEmployee.addPerson();
                        newEmployee.writeDataToFile();
                        cout<<"\nEmployee added successfully"<<endl;
                        cout<<"\n\nPress any button to exit:";
                        cin>>test;
                        break;
                    }
                    case 2:{
                        system("cls");
                        system("Color 5");
                        Staff newEmployee;
                        cout << "List of Inmates:\n";
                        newEmployee.readDataFromFile();
                        
                        cout<<"\n\nPress any button to exit:";
                        cin>>test;
                        break;
                    }
                    case 3:{
                        system("cls");
                        system("Color 3");
                        Staff newEmployee;
                        newEmployee.searchDataInFile();
                        cout << "\n\nPress any button to exit:";
                        cin >> test;
                        break;
                    }
                    case 4:{
                        system("Color 4");
                        system("cls");
                        Staff staff;
                        staff.removeDataFromFile();
                        cout << "\n\nPress any button to exit: ";
                        cin >> test;                        
                        break;
                    }
                    case 0:{
                        system("cls");
                        break;
                    }
                    

                }
                     } while(choice2 !=0);
                     break;
                   }
                case 0:{
                    cout << "Exiting...\n";
                    break;
                }

            }
        }while(choice !=0);


    return 0;

    }

