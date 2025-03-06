
#pragma warning (disable: 4996)
#include <iostream>
#include "hospital.h"

using namespace std;

int main() {
    hospital h;

    int choice;
    bool running = true;

    h.addDepartment("heart");
    h.addDepartment("clinic");
    h.addDoctor("tamir", "nerves", "heart");
    h.addNurse("noa", 12, "clinic");
    patient* x;
    x= h.addPatient("bob", 12, 1998, patient::male, "12/12", "pain");
    h.addPatientToDepartment("clinic", x);
    researchCenter research("RC shiba");
    researcher* z= research.addResearcher("ofek");
    research.addArticleToReasearcher("skulls","12/2/2023","theMagazine",z);
    research.addArticleToReasearcher("bones", "5/2/2022", "theMagazine", z);
    cout << "bar's Hospital Management System" << endl;

    while (running) {
        cout << "1. Add Department" << endl;
        cout << "2. Add Nurse to Department" << endl;
        cout << "3. Add Doctor to Department" << endl;
        cout << "4. Add Patient Visit" << endl;
        cout << "5. Add Researcher to Research Center" << endl;
        cout << "6. Add Article to Researcher" << endl;
        cout << "7. Show All Patients in Department" << endl;
        cout << "8. Show All Medical Staff" << endl;
        cout << "9. Show All Researchers" << endl;
        cout << "10.Search Patient by ID" << endl;
        cout << "11.Test assignment operator (operator=)" << endl;
        cout << "12.Test output operator (operator<<)" << endl;
        cout << "13.Exit" << endl;
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) 
        {
        case 1:
        {
            char name[50];
            cout << "Enter department name: ";
            cin >> name;
            if (h.addDepartment(name)) {
                cout << "Department added successfully." << endl;
            }
            else {
                cout << "Failed to add department (maybe it already exists)." << endl;
            }
            break;
        }
        case 2:
        {
            char name[50], department[50];
            int  experience;
            cout << "Enter nurse's name: ";
            cin >> name;
            cout << "Enter " << name << " experience : ";
            cin >> experience;
            cout << "Enter department to assign " << name << ":";
            cin >> department;

            h.addNurse(name, experience, department);
            break;
        }
        case 3:
        {
            char name[50], specialization[50], department[50];
            cout << "Enter doctor's name: ";
            cin >> name;
            cout << "Enter specialization: ";
            cin >> specialization;
            cout << "Enter department to assign " << name << ":";
            cin >> department;

            h.addDoctor(name, specialization, department);
            break;
        }
        case 4:
        {
            char name[50], department[50], date[50], reason[50];
            int id, yearOfBirth, sexInput;
            patient::eSex sex;
            patient* b;
            cout << "Has patient visited before ? (1 for Yes, 0 for No) : ";
            int visitedBefore;
            cin >> visitedBefore;
            if (visitedBefore)
            {
                cout << "Enter patient ID: ";
                cin >> id;
                b = h.findPatient(id);
            }
            else 
            {
                cout << "Enter patient's name: ";
                cin >> name;
                cout << "Enter " << name << " ID: ";
                cin >> id;
                cout << "Enter year of birth: ";
                cin >> yearOfBirth;
                cout << "Enter " << name << " sex(0 for male, 1 for female, 2 for other) :";
                cin >> sexInput;
                sex = static_cast<patient::eSex>(sexInput);
                cout << "Enter date of arrival: ";
                cin >> date;
                cout << "Enter reason of visit: ";
                cin >> reason;
                b = h.addPatient(name, id, yearOfBirth, sex, date, reason);
            }

            cout << "Enter department for visit: ";
            cin >> department;

            if (h.addPatientToDepartment(department, b)) 
            {
                cout << "Patient visit added successfully." << endl;
            }
            else {
                cout << "Failed to add visit (department may not exist)." << endl;
            }
            break;
        }
        case 5:
            char researcherName[50], articleName[50], dateOfPublish[50], Magazine[50];
            researcher* t;
            cout << "Enter researcher's name: ";
            cin >> researcherName;
            t = research.addResearcher(researcherName);
            cout << "Do you want to add an article to this researcher? (1 for Yes, 0 for No) " << endl;
            int addArticleToResearcher;
            cin >> addArticleToResearcher;
            if (addArticleToResearcher)
            {
                cout << "Enter article name: " << endl;
                cin >> articleName;
                cout << "Enter article date of publish : " << endl;
                cin >> dateOfPublish;
                cout << "Enter article magazine: " << endl;
                cin >> Magazine;

                research.addArticleToReasearcher(articleName, dateOfPublish, Magazine,t);
            }
            break;
        case 6:
            cout << "Enter researcher name: ";
            cin >> researcherName;
            t = research.findResearcher(researcherName);
            cout << "Enter article name: " << endl;
            cin >> articleName;
            cout << "Enter article date of publish : " << endl;
            cin >> dateOfPublish;
            cout << "Enter article magazine: " << endl;
            cin >> Magazine;
            research.addArticleToReasearcher(articleName, dateOfPublish, Magazine,t);
            break;
        case 7:
        {
            char department[50];
            cout << "Enter department name to show patients: ";
            cin >> department;
            h.printPatientsFromCertainDepartment(department);
            break;
        }
        case 8:
            h.printAllStuffMembers();
            break;
        case 9:
            research.printAllResearchers();
            break;
        case 10:
        {
            int patientId;
            cout << "Enter patient ID to search: ";
            cin >> patientId;
            h.findPatient(patientId);
            break;
        }
        case 11:
        {
            nurse n1(employee(person("goni")), 12);
            nurse n2(employee(person("boni")), 4);

            cout << "Before assignment:" << endl;
            cout << "n1: " << n1 << endl;
            cout << "n2: " << n2 << endl;

            n2 = n1;
            cout << "After assignment (n2 = n1):" << endl;
            cout << "n2: " << n2 << endl;
            break;
        }
        case 12:
        {
            nurse n(employee(person("alice")), 12);
            cout << "Testing output operator:" << endl;
            cout << n << endl;
            break;
        }
        case 13:
            running = false;
            cout << "Exiting system..." << endl;
            break;
        default:
            cout << "Invalid option, please try again." << endl;
        }
    }
    return 0;
}
