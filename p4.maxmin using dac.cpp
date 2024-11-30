#include <iostream>
using namespace std;

void findMinMax(int arr[], int low, int high, int &min, int &max) {
    if (low == high) {
        min = max = arr[low];
        return;
    }

    int mid = (low + high) / 2;
    int minLeft, maxLeft, minRight, maxRight;

    findMinMax(arr, low, mid, minLeft, maxLeft);

    findMinMax(arr, mid + 1, high, minRight, maxRight);

    min = (minLeft < minRight) ? minLeft : minRight;
    max = (maxLeft > maxRight) ? maxLeft : maxRight;
}

int main() {
    int n;

    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int arr[n];

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int min, max;
    findMinMax(arr, 0, n - 1, min, max);

    cout << "Minimum: " << min << endl;
    cout << "Maximum: " << max << endl;

    return 0;
}

