#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

class Patient
{
    int pId, age;
    string name, symptoms;

public:
    Patient(int pId, string name, int age, string symptoms) : pId(pId), age(age), name(name), symptoms(symptoms) {};

    int getId() { return pId; }
    string getName() { return name; }
    int getAge() { return age; }
    string getSymp() { return symptoms; }
};

class Doctor
{
protected:
    int dId;
    string name, specialization;

public:
    vector<int> pIds;
    Doctor(int dId, string name, string specialization) : dId(dId), name(name), specialization(specialization) {};

    int getId() { return dId; }
    string getName() { return name; }
    string getSpecialization() { return specialization; }
    vector<int> getPatientsId() { return pIds; }
};

class Management
{
public:
    void viewPatients(vector<Patient> &patients)
    {
        if (patients.size() == 0)
        {
            cout << "No patient registered!" << endl;
            return;
        }
        cout << "Patients Lists:\n";
        cout << setw(5) << "pID" << setw(15) << "Name" << setw(5) << "Age" << "  " << "Symptoms" << endl;
        for (auto &patient : patients)
        {
            cout << setw(5) << patient.getId() << setw(15) << patient.getName() << setw(5) << patient.getAge() << "  " << patient.getSymp() << endl;
        }
    }

    void viewDoctors(vector<Doctor> &doctors)
    {
        if (doctors.size() == 0)
        {
            cout << "No Doctor is available!" << endl;
            return;
        }
        cout << "Doctors List:\n";
        cout << setw(5) << "dID" << "   " << "Name" << "   " << "Specialization" << "   " << "PatientIds" << endl;
        for (auto &doctor : doctors)
        {
            cout << setw(5) << doctor.getId() << "   " << doctor.getName() << "   " << doctor.getSpecialization() << "   ";
            for (auto &pId : doctor.pIds)
            {
                cout << pId << ",";
            }
            cout << endl;
        }
    }

    int addPatient(vector<Patient> &patients)
    {
        int pId, age;
        string name, symptoms;

        cout << "Enter the Patient Id : ";
        cin >> pId;
        cout << "Enter the Patient Name : ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter the age : ";
        cin >> age;
        cout << "What are your symptoms ?\n";
        cin.ignore();
        getline(cin, symptoms);

        for (auto &patient : patients)
        {
            if (pId == patient.getId())
            {
                cout << "Patient Id is already created! Please Enter a different Patient Id.\n";
                return 0;
            }
        }

        patients.emplace_back(pId, name, age, symptoms);
        cout << "Patient is added successfully!\n";
        return 0;
    }

    int addDoctors(vector<Doctor> &doctors)
    {
        int dId;
        string name, specialization;

        cout << "Enter the Doctor Id : ";
        cin >> dId;
        cout << "Enter the Doctor Name : ";
        cin.ignore();
        getline(cin, name);
        cout << "What are your Specialization ?\n";
        cin.ignore();
        getline(cin, specialization);

        for (auto &doctor : doctors)
        {
            if (dId == doctor.getId())
            {
                cout << "Doctor Id is already created! Please Enter a different Doctor Id.\n";
                return 0;
            }
        }

        doctors.emplace_back(dId, name, specialization);
        cout << "Doctor is added successfully!\n";
        return 0;
    }
};

int main()
{
    vector<Patient> patients = {
        // Patient(1, "Rahul", 20, "Fewer"),
    };

    vector<Doctor> doctors = {
        // Doctor(1,"Mukesh Gupta", "Pharmacy"),
    };

    Management system;

    int choice;
    do
    {
        cout << "1. View Patients\n";
        cout << "2. Add Patients\n";
        cout << "3. View Doctors\n";
        cout << "4. Add Doctors\n";
        cout << "5. Exit\n";
        cout << "Enter a Number : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            system.viewPatients(patients);
            cout << "===============================================================\n";
            break;
        case 2:
            system.addPatient(patients);
            cout << "===============================================================\n";
            break;
        case 3:
            system.viewDoctors(doctors);
            cout << "===============================================================\n";
            break;
        case 4:
            system.addDoctors(doctors);
            cout << "===============================================================\n";
            break;
        case 5:
            cout << "-------------- Thank You for the visit --------------";
            break;
        default:
            cout << "Invalid Number\n";
            cout << "---------TRY AGAIN---------\n";
            cout << "===============================================================\n";
        }
    } while (choice != 5);
    return 0;
}