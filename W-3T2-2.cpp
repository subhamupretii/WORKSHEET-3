#include <iostream>
#include <fstream> 
using namespace std;

class Student {
    int roll;
    char name[100];
    int marks;

public:
    void readFromFile(const char* filename) {
        ifstream inFile(filename);
        char line[200];

        cout << "\nReading student records:\n";
        while (inFile.getline(line, 200)) {
            if (sscanf(line, "%d %99[^,],%d", &roll, name, &marks) == 3) {  
                if (marks >= 0 && marks <= 100) {
                    cout << "Roll: " << roll << ", Name: " << name << ", Marks: " << marks << "\n";
                } else {
                    cout << "Invalid marks for roll " << roll << ".\n";
                }
            } else {
                cout << "Error reading line: " << line << "\n";
            }
        }
        inFile.close();
    }

    void addNewRecord(const char* filename) {
        cout << "\nEnter new student details:\n";
        cout << "Roll number: ";
        cin >> roll;
        cin.ignore();  

        cout << "Name: ";
        cin.getline(name, 100);

        cout << "Marks (0-100): ";  
        cin >> marks;

        if (marks < 0 || marks > 100) {
            cout << "Error: Marks must be between 0 and 100.\n";
            return;
        }

        ofstream outFile(filename, ios::app);
        outFile << roll << " " << name << "," << marks << "\n";
        outFile.close();
        cout << "Record added successfully.\n";
    }
};

int main() {
    Student s;
    char filename[] = "students.txt";

    s.readFromFile(filename);

    char choice;
    cout << "\nDo you want to add a new student? (y/n): ";
    cin >> choice;
    cin.ignore();  

    if (choice == 'y' || choice == 'Y') {
        s.addNewRecord(filename);
    }

    return 0;
}
