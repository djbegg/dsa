#include <bits/stdc++.h>
using namespace std;

void insertionSort(int arr[], int n)
{
	int i, key, j;
	for (i = 1; i < n; i++)
	{
		key = arr[i];
		j = i - 1;

		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

void printArray(int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}

int main(){
    int choice, n;
    cout << "Insertion Sort" << endl;

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
            insertionSort(arr, n);
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


