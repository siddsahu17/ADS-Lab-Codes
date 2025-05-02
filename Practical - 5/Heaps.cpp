#include<bits/stdc++.h>
using namespace std;

class HeapSort {
    vector<int> arr;

    void heapify(int n, int i, bool ascending) {
        int extreme = i;
        int left = 2*i + 1;
        int right = 2*i + 2;

        if (ascending) {
            if (left < n && arr[left] > arr[extreme])
                extreme = left;
            if (right < n && arr[right] > arr[extreme])
                extreme = right;
        } else {
            if (left < n && arr[left] < arr[extreme])
                extreme = left;
            if (right < n && arr[right] < arr[extreme])
                extreme = right;
        }

        if (extreme != i) {
            swap(arr[i], arr[extreme]);
            heapify(n, extreme, ascending);
        }
    }

public:
    HeapSort(vector<int> input) {
        arr = input;
    }

    vector<int> sort(bool ascending = true) {
        int n = arr.size();
        for (int i = n/2 - 1; i >= 0; i--)
            heapify(n, i, ascending);

        for (int i = n - 1; i > 0; i--) {
            swap(arr[0], arr[i]);
            heapify(i, 0, ascending);
        }
        return arr;
    }
};

int main() {
    vector<int> nums = {10, 3, 76, 34, 23, 32};

    HeapSort sorter(nums);

    vector<int> asc = sorter.sort(true);
    cout << "Ascending Order: ";
    for (int num : asc) cout << num << " ";
    cout << endl;

    HeapSort sorter2(nums);
    vector<int> desc = sorter2.sort(false);
    cout << "Descending Order: ";
    for (int num : desc) cout << num << " ";
    cout << endl;

    return 0;
}
