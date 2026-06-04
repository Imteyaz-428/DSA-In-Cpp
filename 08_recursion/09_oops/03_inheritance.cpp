#include <iostream>
#include <vector>
using namespace std;

class Student {
public:
    string name;
    string branch;
    double marks;
    double* cgpaptr;
    Student() {
        cout << "this is default consturctor" << endl;
    }
    Student(string name, string branch, double marks, double cgpa) {
        cout << "parant consturctor" << endl;
        this->name = name;
        this->branch = branch;
        this->marks = marks;
        cgpaptr = new double;
        *cgpaptr = cgpa;
        
    }
   
    //copy consturctor
    Student(Student &obj) {
        this->name = obj.name;
        this->branch = obj.branch;
        this->marks = obj.marks;
        this->cgpaptr = new double;
        this->cgpaptr = obj.cgpaptr;
    }
    void getinfo() {
        cout << "name :"  << name << endl;
        cout << "branch :" << branch << endl;
        cout << "marks :" << marks << endl;
        cout << "cgpa : " << *cgpaptr << endl;
    }


};
class Person : public Student {
public:
    Person(string name, string branch, double marks, double cgpa) :Student(name, branch , marks,  cgpa ){
        int rool_no;
        cout << "child constructor" << endl;
        
        
        
    }

};

int main() {
    double cgpa = 9.1;
    Student s1("imteyaz", "aiml", 98.2,3.2);
    s1.getinfo();
    Person p1("imteyaz", "aiml", 5.3,3.2);
    p1.getinfo();

    
    
}