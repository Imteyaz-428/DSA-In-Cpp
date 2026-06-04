#include <iostream>
#include <vector>
using namespace std;

int GCDs(int n1, int n2) {
    while(n1 > 0 && n2 > 0) {
        if(n1> n2) {
            n1 = n1 %n2;
        } else {
            n2 = n2 %n1;
        }
        if(n1 == 0) {
            return n2;
        }
        if(n2 == 0) {
            return n1;
        }
    }
    return n1 == 0? n2: n1;
}

int GCD(int n1, int n2) {
    int n = min(n1, n2) ;
    int ans =1;
    for(int i=1; i<n; i++) {
        if(n1%i ==0 && n2% i == 0) {
            ans = i;
        }
    }
    return ans;
}
int main() {
    int n1;
    int n2;
    cin >> n1;

    cin >> n2;
    cout << GCDs(n1, n2) << endl;
}