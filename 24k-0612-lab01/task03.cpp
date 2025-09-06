#include <iostream>
using namespace std;

class Exam {
private:
    int* marks;      
    int numSubjects;

public:
  
    Exam(int n) {
        numSubjects = n;
        marks = new int[numSubjects];
        for (int i = 0; i < numSubjects; ++i) {
            marks[i] = 0;  
        }
    }

    
    ~Exam() {
        delete[] marks;
    }

    
    void setMark(int index, int value) {
        if (index >= 0 && index < numSubjects) {
            marks[index] = value;
        }
    }

   
    int getMark(int index) const {
        if (index >= 0 && index < numSubjects) {
            return marks[index];
        }
        return -1; 
    }

   
    void printMarks(const string& name) const {
        cout << name << " Marks: ";
        for (int i = 0; i < numSubjects; ++i) {
            cout << marks[i] << " ";
        }
        cout << endl;
    }
};


int main() {
    
    Exam exam1(3);
    exam1.setMark(0, 80);
    exam1.setMark(1, 90);
    exam1.setMark(2, 70);
    exam1.printMarks("Exam1");

    Exam exam2 = exam1; 

    exam2.setMark(1, 100);
    cout << "\nAfter modifying Exam2:\n";
    exam2.printMarks("Exam2");
    exam1.printMarks("Exam1 (affected by shallow copy)");

    return 0;
}