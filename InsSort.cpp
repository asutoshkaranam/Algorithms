#include <iostream>

using namespace std;

int main()
{
	int arr[] = {5,1,4,-1,88,8,2,3,0};
	
	for(int j=1; j<(sizeof(arr)/sizeof(arr[0])); j++) {
		int hole = j;
		int key = arr[hole];
		while (hole>0 && (arr[hole-1] > key)) {
			arr[hole] = arr[hole-1];
			hole--;
		}
		arr[hole] = key;
	}
	for(int j =0; j<(sizeof(arr)/sizeof(arr[0])); j++){
		cout<<arr[j]<<"\n";
	}
}