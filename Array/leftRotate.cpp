// Program for Array Rotation - Rev and Juggling Algo
#include <iostream>
using namespace std;

int gcd(int n, int k) {
    if (k == 0) {
        return n;
    }
    return gcd(k, n%k);
}
// Juggling Algorithm O(n)
void arrayRotate(int A[], int n, int k) {
    for (int i = 0; i<gcd(n,k); i++) {
        int j = i, d;
        int temp = A[j];
        while (1) {
            d = (j + k)%n;
            if (d == i) {
                break;
            }
            A[j] = A[d];
            j = d;
        }
        A[j] = temp;
    }
}

void reverseArray(int A[], int m, int n) {
    while (m <= n) {
        int temp = A[m];
        A[m] = A[n];
        m = m + 1;
        A[n] = temp;
        n = n - 1;
    }
}

void arrayRotateByRevAlgo(int A[], int n, int k) {
    reverseArray(A, 0, k-1);
    reverseArray(A, k, n-1);
    reverseArray(A, 0, n-1);
}

void printArray(int A[], int n) {
    for (int i=0; i<n-1; i++) {
        cout << A[i] << " ";
    }
    cout << A[n-1] << endl;
}

int main() {
    int n, k;
    cin >> n >> k;
    int A[n];
    for (int i = 0; i<=n-1; i++) {
        cin >> A[i];
    }
    arrayRotateByRevAlgo(A, n, k);
    printArray(A, n);
    return 0;
}
