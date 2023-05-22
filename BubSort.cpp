#include <iostream>

using namespace std;

int main()
{
	int arr[] = {5,1,4,-1,88,8,2,3,0};
	for(int j =0; j<(sizeof(arr)/sizeof(arr[0])); j++)
	{
		for(int i=0; i<(sizeof(arr)/sizeof(arr[0]))-j-1; i++) {
			if(arr[i] > arr[i+1]) {
				int temp = arr[i];
				arr[i] = arr[i+1];
				arr[i+1] = temp;
			}
		}
	}
	for(int j =0; j<(sizeof(arr)/sizeof(arr[0])); j++){
		cout<<arr[j]<<"\n";
	}
}