#include <iostream>
#include <vector>
using namespace std;

class subject {
private:
    int maths;
    int dsa;
    int coa;
    int dstl;
public:
    subject() {
        cout << "this is subject constructor" << endl;
    } 
    subject(int maths, int dsa, int coa , int dstl) {
        this->maths = maths;
        this->dsa = dsa;
        this->coa = coa;
        this->dstl = dstl;
    }
    void subject_info() {
        cout << "this is subject info :- " << endl;
        cout << maths << endl;
        cout << dsa << endl;
        cout << coa << endl;
        cout << dstl << endl;
    }
};
class student {
private:
    string sem;
    string fav_sub;
    float cgpa;
public:
    student() {
        cout << "this is student constructor" << endl;
    }
    student(string sem, string fav_sub, float cgpa) {
        this->sem = sem;
        this->fav_sub = fav_sub;
        this->cgpa  = cgpa;
    }
    void student_info() {
        cout << "this is student info :- " << endl;
        cout << sem << endl;
        cout << fav_sub << endl;
        cout << cgpa << endl;
    }
};
class person : public student , public subject {
private:
    int id;
    string name;
    string branch;
public:
    person() {
        cout << "this is person constroctor" << endl;
    }
    person(int id, string name, string branch, string sem, string fav_sub, float cgpa,int maths, int dsa, int coa, int dstl): student(sem, fav_sub, cgpa), subject(maths, dsa, coa, dstl) {
        this->id = id;
        this->branch = branch;
        this->name = name;
    }
    void person_info() {
        cout << "this is person info :-" << endl;
        cout << id << endl;
        cout << branch << endl;
        cout << name << endl;
    }
};
int main() {
    person p1;
    person p2(1, "imteyaz", "aiml", "third", "dsa", 7.8, 87,54,34,91);
    p2.person_info();
    p2.student_info();
    p2.subject_info();
}