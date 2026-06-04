#include <iostream>
#include <vector>
using namespace std;

long long binaryExponentiation(int n) {
    long binForm =  n;
    long long ans =1;
    long x = 2;
    cout << binForm << endl;
    while(binForm > 0) {
        if(binForm %2 ==1  ) {
            ans *= x;
        }
        x *= x;
        binForm/=2;;

    }
    return ans;
    
}

int main() {
    int n = 10;
    cout << binaryExponentiation(n) << endl;
    return 0;
}