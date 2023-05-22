#include <iostream>

using namespace std;

int main() {
    int arr[] = {5,1,4,-1,88,8,2,3,0};
    for (int j=0; j<(sizeof(arr)/sizeof(arr[0])); j++) {
        int min = j;
        int temp,i;
        for ( i=j+1; i<(sizeof(arr)/sizeof(arr[0])); i++)
        {
            if(arr[min] > arr[i])
                min = i;
        }
        temp = arr[j];
        arr[j] = arr[min];
        arr[min] = temp;
    }
    for (int i =0; i<(sizeof(arr)/sizeof(arr[0])); i++)
    {
        cout<<arr[i]<<"\n";
    }
}
