#include <iostream>

using namespace std;

int CountOnes(int n) {
    int count = 0;
    while (n) {
        n = n & (n - 1);
        count++;
    }
    return count;
}

void PrintPartialSet(int n, int k) {
    for (int i = 0; i < (1 << n); ++i) {
        if (CountOnes(i) == k) {
            for (int j = 0; j < n; ++j) {
                if (i & (1 << j))
                    cout << j << " ";
            }
            cout << endl;
        }
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    PrintPartialSet(n, k);
    return 0;
}