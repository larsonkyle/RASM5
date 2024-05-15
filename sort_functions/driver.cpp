#include <iostream>
using namespace std;

extern "C" void InsertionSortA(int arr[], int length);

// used to individually test each function

int main() {
    int n = 10;
    int arr[n] = {0, -11, 135, 5, 6, -5, -23, 856, -83425, 748};	

	for(int i = 0; i < n; i++) cout << arr[i] << endl;

	cout << "========================================================" << endl;

	InsertionSortA(arr,n);

	for(int i = 0; i < n; i++) cout << arr[i] << endl;
	return 0;
}
