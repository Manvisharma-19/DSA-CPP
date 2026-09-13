#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;

    string names[5] = {
        "Sheldon",
        "Leonard",
        "Penny",
        "Rajesh",
        "Howard"
    };

    long long group = 5;

    while (n > group) {
        n = n - group;
        group = group * 2;
    }

    long long index = (n - 1) / (group / 5);

    cout << names[index];

    return 0;
}
