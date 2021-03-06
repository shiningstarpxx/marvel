#include <iostream>
#include <algorithm>
#include <time.h>

using namespace std;

int data[] = {1, 2, 3, 4, 5, 6, 8, 9, 10, 32, 15, 18, 33};
int num = 0;  // permutation count
void PartialPermutation(int begin, int end, int partial, bool p = false);

void Permutation(int begin, int end) {
    PartialPermutation(begin, end, end - begin + 1);
}

void PartialPermutation(int begin, int end, int partial, bool p) {
    if (begin == partial) {
        if (p) {
            for (int i = 0; i < partial; i++) {
                cout << data[i] << " ";
            }
            cout << endl;
        }
        num++;
        return;
    } else {
        for (int i = begin; i <= end; ++i) {
            swap(data[i], data[begin]);
            PartialPermutation(begin + 1, end, partial);
            swap(data[i], data[begin]);
        }
    }
}

int main() {
    clock_t start, end;
    start = clock();
    Permutation(0, 9);
    end = clock();
    cout << num << ", " << (double)(end - start)/CLOCKS_PER_SEC << endl;

    num = 0;
    PartialPermutation(0, 9, 3);
    cout << num << endl;
}
