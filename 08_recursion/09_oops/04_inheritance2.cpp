#include <iostream>
#include <vector>
using namespace std;
class Student  {
public:
    string name;
    string branch;
    int roll_no;
    Student(string name, string branch, int roll_no) {
        this->name = name;
        this->branch = branch;
        this->roll_no = roll_no;

    }
    Student() {
        cout << "hey i am the parent consturctor" << endl;

    }
    ~Student() {
        cout << "hey i am the parent destructor" << endl;
    }

    
};
class Person : public Student {
public:
    int id;
     Person() {
        cout << "i am the child consturctor" << endl;

     }
    void getinfo() {
        cout << "name :" << name << endl;
        cout << "branch :" << branch << endl;
        cout << "roll_no :" << roll_no << endl;
    }
    ~Person() {
        cout << "hey i am the child destructor" << endl;
    }
};

int main() {
    Person p1;
    p1.name = "imteyaz alam";
    p1.branch = "aiml";
    p1.roll_no = 4354;
    p1.getinfo() ;


}