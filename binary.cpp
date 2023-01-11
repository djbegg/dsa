#include <bits/stdc++.h>
using namespace std;


int binarySearch(int arr[], int l, int r, int x)
{
	while (l <= r) {
		int m = l + (r - l) / 2;

		// Check if x is present at mid
		if (arr[m] == x)
			return m;

		// If x greater, ignore left half
		if (arr[m] < x)
			l = m + 1;

		// If x is smaller, ignore right half
		else
			r = m - 1;
	}

	// if we reach here, then element was
	// not present
	return -1;
}

void printArray(int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}

int main(){
    int choice, n, x;
    cout << "Binary Search" << endl;

    do{
        int elem;
        cout<<endl;
        cout << "CHOOSE ANY ONE OPTION" << endl;
        cout << "========================" << endl;
        cout << "1. Create array and Search" << endl;
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

            cout<<"Created Array :"<<endl;
            printArray(arr, n);
            cout<<endl;

            cout<<"Enter the element to be searched:"<<endl;
            cin>>x;
            int result = binarySearch(arr, 0, n-1, x);
            (result == -1)
            ? cout << "Element is not present in array"
            : cout << "Element is present at index " << result;

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
