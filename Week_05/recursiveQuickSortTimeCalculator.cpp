#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

void quickSort(int arr[], int left, int right) {
    int i = left, j = right;
    int tmp;
    int pivot = arr[(left + right) / 2];

    // Partition the array
    while (i <= j) {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j) {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    };

    // Recursively sort the left and right subarrays
    if (left < j)
        quickSort(arr, left, j);
    if (i < right)
        quickSort(arr, i, right);
}

int main() {
    int arr[] = {32,49,19,86,81,45,64,29,24,31,53,17,4,12,0,11,12,74,94,8,31,82,80,8,55,10,27,95,80,35,24,25,75,67,23,22,86,5,55,39,38,16,71,38,12,25,58,92,84,63};
    int n = sizeof(arr) / sizeof(arr[0]);
    auto start = high_resolution_clock::now(); // Get start time
    quickSort(arr, 0, n - 1);
    auto stop = high_resolution_clock::now(); // Get stop time
    auto duration = duration_cast<nanoseconds>(stop - start); // Calculate duration in microseconds
    cout << "Array Size : "<<n<<endl;
    cout << "Time taken by recursion code : " << duration.count() << " nanoseconds" << endl;
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}