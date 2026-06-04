#include <iostream>
#include <vector>
using namespace std;

class parent {
public:
    int id;
    string name;
    string sem;
    parent() {
        cout << "this is parent constructor" << endl;
    }
    parent(int id, string name, string sem) {
        this->name = name;
        this->id = id;
        this->sem = sem;
    }
    void display_info() {
        cout << id << endl;
        cout << name << endl; 
        cout << sem << endl;
    }
};
class child :public  parent {
public:
    string subject;
    float cgpa;
    child() {
        cout << "this is child constructor " << endl;
    }
    child(int id, string name, string sem,string subject, float cgpa ) : parent(id, name, sem) {
        this->subject = subject;
        this->cgpa = cgpa;
    }
    void child_info() {
        cout << subject << endl;
        cout << cgpa << endl;
    }
};
class subject : public child {
public:
    int maths;
    int dsa;
    int dstl;
    int coa;
    subject() {
        cout << "this is subject constructor" << endl;

    }
    subject(int id, string name, string sem, string subject, float cgpa,int maths, int dsa, int dstl, int coa): child(id, name, sem, subject, cgpa){
        this->maths = maths;
        this->dsa = dsa;
        this->dstl = dstl;
        this->coa = coa;

    }
    void subject_info() {
        cout << maths << endl;
        cout << dsa << endl;
        cout << dstl << endl;
        cout << coa << endl;
    }
};

int main() {
   
    subject p3;
    subject p2(1, "imteyaz", "third","math", 8.5,88,65,55,90);
    p2.display_info();
    p2.child_info();
    p2.subject_info();
}