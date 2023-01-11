#include <iostream>
using namespace std;


void heapify(int arr[], int N, int i)
{

	// Initialize largest as root
	int largest = i;

	// left = 2*i + 1
	int l = 2 * i + 1;

	// right = 2*i + 2
	int r = 2 * i + 2;

	// If left child is larger than root
	if (l < N && arr[l] > arr[largest])
		largest = l;

	// If right child is larger than largest
	// so far
	if (r < N && arr[r] > arr[largest])
		largest = r;

	// If largest is not root
	if (largest != i) {
		swap(arr[i], arr[largest]);

		// Recursively heapify the affected
		// sub-tree
		heapify(arr, N, largest);
	}
}


void heapSort(int arr[], int N)
{

	// Build heap (rearrange array)
	for (int i = N / 2 - 1; i >= 0; i--)
		heapify(arr, N, i);

	// One by one extract an element
	// from heap
	for (int i = N - 1; i > 0; i--) {

		// Move current root to end
		swap(arr[0], arr[i]);

		// call max heapify on the reduced heap
		heapify(arr, i, 0);
	}
}

// A utility function to print array of size n
void printArray(int arr[], int N)
{
	for (int i = 0; i < N; ++i)
		cout << arr[i] << " ";
	cout << "\n";
}

// Driver's code
int main(){
    int choice, n;
    cout << "Heap Sort" << endl;

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
            heapSort(arr, n);
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
