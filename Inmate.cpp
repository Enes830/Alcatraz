#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm> // For std::remove_if
#include <limits>
#include <cstdlib> // For system()
#include "Inmate.h"
#include "Person.h"

using namespace std;

Inmate::Inmate() {}
Inmate::Inmate(string fullName, string id, string nationality, int age, float height, float weight, string felony, string cage, string sentenceStart, long long  sentenceLength)
{
    Person::setAll(fullName, id, nationality, age, height, weight);
    this->felony = felony;
    this->cage = cage;
    this->sentenceStart = sentenceStart;
    this->sentenceLength = sentenceLength;
}

Inmate::~Inmate() {}

void Inmate::setFelony(string felony)
{
    this->felony = felony;
}
string Inmate::getFelony()
{
    return felony;
};

void Inmate::setCage(string cage)
{
    this->cage = cage;
}
string Inmate::getCage()
{
    return cage;
};

void Inmate::setSentenceStart(string sentenceStart)
{
    this->sentenceStart = sentenceStart;
}
string Inmate::getSentenceStart()
{
    return sentenceStart;
};

void Inmate::setSentenceLength(long long sentenceLength)
{
    this->sentenceLength = sentenceLength;
}
long long Inmate::getSentenceLength()
{
    return sentenceLength;
};

void Inmate::displayInfo()
{
    cout << endl;
    Person::displayInfo();
    cout << "Cage: " << cage << endl;
    cout << "Felony: " << felony << endl;
    cout << "Sentence Start: " << sentenceStart << endl;
    cout << "Sentence Length: " << sentenceLength << " Days" << endl;
}

void Inmate::addPerson()
{
    Person::addPerson();

    cout << "Enter cage: ";
    cin >> cage;

    cout << "Enter felony: ";
    cin >> felony;

    cout << "Enter sentenceStart: ";
    cin >> sentenceStart;

    
    sentenceLength = inputInteger("Enter sentence length: ");
}

// FILE HANDLING:
void Inmate::writeDataToFile()
{
   // Person::writeDataToFile();
    ifstream inFile("data/inmate.csv");
    bool isEmpty = inFile.peek() == EOF; // Check if the file is empty

    // Calculate the next ID based on the number of lines (excluding the header)
    int nextId = 1; // Start IDs from 1
    string line;
    if (!isEmpty)
    {
        getline(inFile, line); // Skip the header line
        while (getline(inFile, line))
        {
            nextId++; // Count each line to get the next ID
        }
    }
    inFile.close(); // Close the input file

    ofstream outFile("data/inmate.csv", ios::app); // Open file in append mode
    if (outFile.is_open())
    {
        if (isEmpty)
        {
            // Write headers if the file is empty
            outFile << "ID,Full Name,Nationality,Age,Height,Weight,Cage,Felony,Sentence Start,Sentence Length" << endl;
        }

        // Write the data with the next ID
        outFile << nextId << "," << getFullName() << "," << getNationality() << "," << getAge() << "," << getHeight() << "," << getWeight() << "," << cage << "," << felony << "," << sentenceStart << ","
                << sentenceLength << endl;
        outFile.close();
    }
    else
    {
        cout << "Error opening the file for writing." << endl;
    }
}

void Inmate::readDataFromFile() {
    ifstream inFile("data/inmate.csv"); // Assuming your CSV file is named "inmate.csv"
    if (inFile.is_open()) {
        string line;
        getline(inFile, line); // Skip the header if your CSV includes headers.
        vector<Inmate> inmates;

        while (getline(inFile, line)) {
            stringstream ss(line);
            string cell;
            Inmate inmate;

            getline(ss, cell, ','); // ID
            inmate.setId(cell);

            getline(ss, cell, ','); // Full Name
            inmate.setFullName(cell);

            getline(ss, cell, ','); // Nationality
            inmate.setNationality(cell);

            getline(ss, cell, ','); // Age
            try {
                inmate.setAge(stoi(cell));
            } catch (const invalid_argument& e) {
                cerr << "Invalid age format: " << cell << endl;
                continue;
            }

            getline(ss, cell, ','); // Height
            try {
                inmate.setHeight(stof(cell));
            } catch (const invalid_argument& e) {
                cerr << "Invalid height format: " << cell << endl;
                continue;
            }

            getline(ss, cell, ','); // Weight
            try {
                inmate.setWeight(stof(cell));
            } catch (const invalid_argument& e) {
                cerr << "Invalid weight format: " << cell << endl;
                continue;
            }

            getline(ss, cell, ','); // Cage
            inmate.setCage(cell);

            getline(ss, cell, ','); // Felony
            inmate.setFelony(cell);

            getline(ss, cell, ','); // Sentence Start
            inmate.setSentenceStart(cell); // Assuming date is handled as string or appropriately

            getline(ss, cell, ','); // Sentence Length
            try {
                inmate.setSentenceLength(stoi(cell));
            } catch (const invalid_argument& e) {
                cerr << "Invalid sentence length format: " << cell << endl;
                continue;
            }

            // Add the populated Inmate object to your data structure (e.g., vector or other container)
            inmates.push_back(inmate);
        }

        for (auto& inmate : inmates) {
            inmate.displayInfo();
            cout<<"______________________________________________________________";
        }
        inFile.close();
    } else {
        cout << "Error opening the file for reading." << endl;
    }
}

//Function to display IDs and handle the deletion process:
void Inmate::removeDataFromFile() {
    std::vector<std::string> records;
    std::string line, targetId;

    system("cls"); // Clear the screen at the beginning

    std::ifstream inFile("data/inmate.csv");
    if (!inFile.is_open()) {
        std::cerr << "Error: Unable to open input file. Please check the file path and permissions." << std::endl;
        return;
    }

    while (std::getline(inFile, line)) {
        records.push_back(line); // Store each line as a complete record
    }
    inFile.close();

    if (records.empty()) {
        std::cout << "Notice: There are no records available to delete. The file is empty." << std::endl;
        return;
    }

    do {
        system("cls"); // Clear the screen before showing IDs
        std::cout << "Available IDs:\n";
        for (const auto& record : records) {
            std::istringstream iss(record);
            std::getline(iss, line, ','); // Extract ID from record
            line = Person::trim(line); // Ensure ID is trimmed of whitespace
            std::cout << line << std::endl;
        }

        std::cout << "______________________________________________________________\n";
        std::cout << "Please enter the ID you wish to delete or type 'exit' to terminate the operation: ";
        std::cin >> targetId; // Use cin to read the next word
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the input buffer to remove any leftover characters

        targetId = Person::trim(targetId); // Trim whitespace from user input

        if (targetId == "exit") {
            std::cout << "Exiting operation." << std::endl;
            break;
        }

        bool found = false;
        std::vector<std::string> updatedRecords;

        for (auto& record : records) {
            std::istringstream iss(record);
            std::getline(iss, line, ','); // Extract ID
            line = Person::trim(line); // Trim the ID

            if (line == targetId) {
                found = true;
            } else {
                updatedRecords.push_back(record);
            }
        }

        if (!found) {
            std::cout << "Warning: The ID '" << targetId << "' was not found in the records. Please try again." << std::endl;
        } else {
            std::cout << "Success: The ID '" << targetId << "' has been successfully deleted from the records." << std::endl;
            records = updatedRecords; // Update the main records vector to reflect the deletion
            std::ofstream outFile("data/inmate.csv");
            for (const auto& record : updatedRecords) {
                outFile << record << std::endl;
            }
            outFile.close();
        }

        std::cout << "Would you like to delete another ID? (yes/no): ";
        std::getline(std::cin, targetId); // Directly use getline to capture the next line of input
        if (Person::trim(targetId) != "yes") {
            std::cout << "No further deletions requested. Exiting now." << std::endl;
            break;
        }

    } while (true); // Loop indefinitely until 'exit' is entered
}