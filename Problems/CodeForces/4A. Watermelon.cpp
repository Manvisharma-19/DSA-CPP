//By manvi_sharma19, contest: Codeforces Beta Round 4 (Div. 2 Only), problem: (A) Watermelon, Accepted, #, Copy
#include<iostream>
using namespace std;
 
int main() {
    int w;
    cin >> w;
 
    if (w % 2 == 0 && w > 3) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;  
    }
    
    return 0;
}
