#include <iostream>

using namespace std;

void PrintSubset(int n ) {
    for (int i = 0; i < (1 << n); ++i) {
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) {
                cout << j << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    int n;
    cin >> n;
    PrintSubset(n);
    return 0;
}