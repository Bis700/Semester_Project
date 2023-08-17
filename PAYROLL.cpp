#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    string name;
    int id;
    double hourlyRate;
    double hoursWorked;

public:
    // Constructor to initialize member variables
    Employee(string n, int i, double hr, double hw) : name(n), id(i), hourlyRate(hr), hoursWorked(hw) {}

    string getName() {
        return name;
    }

    int getID() {
        return id;
    }

    double calculateGrossPay() {
        return hourlyRate * hoursWorked;
    }
};

class PayrollSystem {
public:
    void run() {
        Employee emp("", 0, 0.0, 0.0);
        string name;
        int id;
        double hourlyRate;
        double hoursWorked;

        cin.ignore(); // Clear the newline character from previous input
        cout << "Enter employee name: ";
        getline(cin, name);

        cout << "Enter employee ID: ";
        cin >> id;

        cout << "Enter hourly rate: ";
        cin >> hourlyRate;

        cout << "Enter hours worked: ";
        cin >> hoursWorked;

        emp = Employee(name, id, hourlyRate, hoursWorked);

        double grossPay = emp.calculateGrossPay();
        double deductions = calculateDeductions(grossPay);
        double netPay = grossPay - deductions;

        displayPayroll(emp, grossPay, deductions, netPay);
    }

private:
    double calculateDeductions(double grossPay) {
        // In a real application, you might have various deduction calculations.
        // For this example, we'll just assume a flat 20% deduction.
        return 0.20 * grossPay;
    }

    void displayPayroll(Employee emp, double grossPay, double deductions, double netPay) {
        cout << "\nPayroll Summary\n";
        cout << "Employee Name: " << emp.getName() << endl;
        cout << "Employee ID: " << emp.getID() << endl;
        cout << "Gross Pay: $" << grossPay << endl;
        cout << "Deductions: $" << deductions << endl;
        cout << "Net Pay: $" << netPay << endl;
    }
};

int main() {
    PayrollSystem payroll;
    payroll.run();

    return 0;
}

