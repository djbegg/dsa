#include <iostream>
using namespace std;

int partition(int arr[], int start, int end)
{

	int pivot = arr[start];

	int count = 0;
	for (int i = start + 1; i <= end; i++) {
		if (arr[i] <= pivot)
			count++;
	}

	// Giving pivot element its correct position
	int pivotIndex = start + count;
	swap(arr[pivotIndex], arr[start]);

	// Sorting left and right parts of the pivot element
	int i = start, j = end;

	while (i < pivotIndex && j > pivotIndex) {

		while (arr[i] <= pivot) {
			i++;
		}

		while (arr[j] > pivot) {
			j--;
		}

		if (i < pivotIndex && j > pivotIndex) {
			swap(arr[i++], arr[j--]);
		}
	}

	return pivotIndex;
}

void quickSort(int arr[], int start, int end)
{

	// base case
	if (start >= end)
		return;

	// partitioning the array
	int p = partition(arr, start, end);

	// Sorting the left part
	quickSort(arr, start, p - 1);

	// Sorting the right part
	quickSort(arr, p + 1, end);
}

void printArray(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
}


int main(){
    int choice, n;
    cout << "Quick Sort" << endl;

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
            quickSort(arr,0,n-1);
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


