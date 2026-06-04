#include <iostream>
using namespace std;

bool palindrome(int n) {
    if(n < 0) {
        return 0;
    }
    int ans = 0;
    int a = n;
    while( a > 0) {
        int rem = a%10;
        ans = ans * 10 + rem;
        a = a/10;
    }
    return ans == n;
}

int main() {
    int n;
    cin >> n;
    cout << palindrome(n) << endl;
}