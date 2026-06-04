#include <iostream>
#include <vector>
using namespace std;

int reverse(int n) {
    if(n == 0) {
        return 0;
    }
    int currSum =0;
    while( n > 0)  {
        int rem =  n %10;
        if(currSum > INT_MAX/10 ||  currSum < INT_MIN/10) {
            return 0;
        }
        currSum = currSum * 10 + rem;
        n = n/10;


    }
    return currSum;

}

int main() {
    int n;
    cin >> n;
    cout << reverse(n) << endl;
}