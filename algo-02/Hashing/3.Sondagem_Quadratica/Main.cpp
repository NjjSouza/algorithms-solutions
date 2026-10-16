#include <iostream>
#include "hashing.h"
using namespace std;

int main() {
    int k, m, c1, c2;

    // lê até EOF
    while (cin >> k >> m >> c1 >> c2) {
        for (int i = 0; i < m; i++) {
            cout << hash2(k, i, m, c1, c2);
            if (i < m - 1) {
                cout << " ";
            }
        }
    }
cout<<" ";
    return 0;
}