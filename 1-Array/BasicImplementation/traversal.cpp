//Basic Traversal of an Array
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Array elements are: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
// This code takes the size of an array and its elements as input from the user,
// and then prints the elements of the array. It uses a simple for loop to traverse
// through the array and display its elements. The code is written in C++ and uses
// basic input/output functions from the iostream library. The array is declared
// with a size specified by the user, and the elements are stored in it using
// standard input. The traversal is done using a for loop, which iterates from

// 0 to n-1, where n is the size of the array. The elements are printed to the
// console using the cout function, with a space between each element for better