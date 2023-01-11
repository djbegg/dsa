#include <iostream>
using namespace std;


int getMax(int arr[], int n)
{
	int mx = arr[0];
	for (int i = 1; i < n; i++)
		if (arr[i] > mx)
			mx = arr[i];
	return mx;
}

// counting sort of arr[] according to the digit represented by exp.
void countSort(int arr[], int n, int exp)
{
	int output[n]; // output array
	int i, count[10] = { 0 };

	// Store count of occurrences in count[]
	for (i = 0; i < n; i++)
		count[(arr[i] / exp) % 10]++;

	// Change count[i] so that count[i] now contains actual
	// position of this digit in output[]
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	// Build the output array
	for (i = n - 1; i >= 0; i--) {
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}

	// Copy the output array to arr[], so that arr[] now
	// contains sorted numbers according to current digit
	for (i = 0; i < n; i++)
		arr[i] = output[i];
}

// The main function to that sorts arr[] of size n using
// Radix Sort
void radixsort(int arr[], int n)
{
	// Find the maximum number to know number of digits
	int m = getMax(arr, n);

	// Do counting sort for every digit. Note that instead
	// of passing digit number, exp is passed. exp is 10^i
	// where i is current digit number
	for (int exp = 1; m / exp > 0; exp *= 10)
		countSort(arr, n, exp);
}


void printArray(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
}

int main(){
    int choice, n;
    cout << "Radix Sort" << endl;

    do{
        int elem;
        cout << "CHOOSE ANY ONE OPTION" << endl;
        cout << "========================" << endl;
        cout << "1. Input array" << endl;
        cout << "2. Exit" << endl;

        cout<<"Enter your choice :"<<endl;
        cin>>choice;

        if(choice==1){
            cout<<"Enter Number of elements :"<<endl;
            cin>>n;
            cout<<"Enter the elements :"<<endl;
            int arr[n];
            for(int i=0;i<n; i++){
                cin >> elem;
                arr[i] = elem;
            }
            radixsort(arr, n);
            cout<<"The sorted array is"<<endl;
            printArray(arr, n);
            cout<<endl;
        }
        else if(choice==2){
            return 0;
        }
        else{
            cout<<"Please enter a valid choice"<<endl;
        }
    }while(choice==1 || choice==2);

        return 0;
}
