#include <iostream>
#include "hashing.h"
using namespace std;

int main() {
    int k, m;

    // lê até EOF
    while (cin >> k >> m) {
        for (int i = 0; i < m; i++) {
            cout << hash1(k, i, m);
            if (i < m - 1) {
                cout << " ";
            }
        }
    }
cout<<" ";
    return 0;
}