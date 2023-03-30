#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {

    vector<int> arr;
    int n;

    while (cin >> n) { // Read integers from input stream
        arr.push_back(n); // Add the integer to the list
        sort(arr.begin(), arr.end()); // Sort the list
        int len = arr.size();

        if (len % 2 == 1) { // For odd number of elements
            cout << "["; 
            for (int i = 0; i < len; i++) {
                cout << arr[i] << (i == len - 1 ? "]  " : ", "); // Print sorted list
            }
            cout << " " << fixed << setprecision(1) << (float) arr[len/2] << endl; // Print median

        }
        
        else { // For even number of elements
            cout << "["; 
            for (int i = 0; i < len; i++) {
                cout << arr[i] << (i == len - 1 ? "]  " : ", "); // Print sorted list
            }
            double median = (arr[len/2 - 1] + arr[len/2]) / 2.0;
            cout << " " << fixed << setprecision(1) << (float) median << endl; // Print median
        }

    }
    
    return 0;
}