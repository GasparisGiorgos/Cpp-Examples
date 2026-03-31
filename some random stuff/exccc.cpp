#include <iostream>

using namespace std;

class Student {
private:
    int id;
    float grade;

public:
    Student(int i, float g) {
        id = i;
        grade = g;
    }

    void set_grade(float g) {
        grade = g;
    }

    float get_grade() {
        return grade;
    }

    void print() {
        cout << "\n--- Student Info ---" << endl;
        cout << "Student id: " << id << endl;
        cout << "Grade: " << grade << endl;
    }
};

int main() {
    int inputId;
    float inputGrade;

    cout << "Please enter the student's ID: ";
    cin >> inputId;

    cout << "Please enter the student's grade: ";
    cin >> inputGrade;

    Student myStudent(inputId, inputGrade);

    myStudent.print();

    float newGrade;
    cout << "\nEnter a new grade to update the student: ";
    cin >> newGrade;
    
    myStudent.set_grade(newGrade);
    cout << "Updated grade: " << myStudent.get_grade() << endl;

    return 0;
}