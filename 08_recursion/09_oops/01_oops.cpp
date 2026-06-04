#include <iostream>
#include <string>
using namespace std;

class Teacher {
private :
    double salary;
public :
    string name;
    string depart;
    string subject;

    void changedepart(string newdepart){
        depart = newdepart;
    }

    //setter
    void setSalary(double s) {
        salary = s;
    }

    //getter
    double getSalary() {
        return salary;
    }

};



int main() {
    Teacher t1;
    t1.name = "imteyaz alam";
    t1.depart = "AIML";
    t1.subject = "c++";
    t1.setSalary(25000);

    cout << t1.name << endl;
    cout << t1.depart << endl;
    cout << t1.subject << endl;
    cout << t1.getSalary() << endl;
    
}