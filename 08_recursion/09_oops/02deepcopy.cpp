#include <iostream>
#include <vector>
using namespace std;

class Student {
public:
    string name;
    double *cgpaptr;
    Student(string name, double cgpa) {
        this->name = name;
        cgpaptr = new double; // memory dynamically allocated
        *cgpaptr = cgpa;
    }
    //copy constructor
    Student(Student &obj) {
        this->name = obj.name;
        this->cgpaptr= new double; // making deep copy
        *this->cgpaptr = *obj.cgpaptr;
        
    }
    void getInfo() {
        cout << "name :" << name << endl;
        cout << "cgpa :" << *cgpaptr << endl;
    }
    ~Student() { // destructor :- deallocate the memory
        cout << "hi delete everything" << endl;
        delete cgpaptr;
    }
};

int main() {
    Student s1("imteyaz", 4.4);
   
    Student s2(s1);
    *s2.cgpaptr = 9.2;
   
    s1.getInfo();

}