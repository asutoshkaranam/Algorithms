#include <iostream>
#include <bits/stdc++.h>
#include <sys/time.h>
/**
 *
 * @author <Asutosh Karanam>
 *
 */
using namespace std;

/*Helper Function to print the array*/
void printArray(int *arr, int n)
{
	for(int i=0; i<n; i++) //iterates across the arr of size n and prints the elements.
	{
		cout<<arr[i]<<"\n";
	}
}

void sortByMax(int *arrA, int *arrB, int n) {
	//Iterate the array -- FindMAX -- Copy to B -- Push MAX to end by Swapping
	for (int i=n-1; i>=0; i--) //Pointer i runs backwards
	{
		int maxPos=0; //Position of the MAX element. At this stage, we assume that the first element is the MAX.
		for (int j=1; j<=i; j++) {
	        if((arrA[j] > arrA[maxPos])) { //Checking if each element at a certain position is greater than the previous MAX
	        	maxPos = j;
	        }
	    }
	    arrB[i] = arrA[maxPos];//Copy the element at maxPos and put it in the i-th index of B
	    if (maxPos != i) {
			int temp = arrA[i]; //Push the max elements to the back of Array A by Swapping to reduce the search space to find the next MAX element.
		    arrA[i] = arrA[maxPos];
		    arrA[maxPos] = temp;
		}
	}
}

int main(int argc, char* argv[])
{
	int n;
	//Checking if the total number of elements to be sorted is provided or not when the program is run.
    if( argc < 2 )
    {
		cout <<"No Input Array Size is Provided in Runtime Args." << endl;
		cout<<"Enter the total number of elements to be sorted:"<<endl; //If the # of elements are not given during runtime, Prompting the user to enter the info.
		cin>>n;
    }

	// If the runtime args are properly provided, getting the int value of # of elements
	if( argc > 1 )
    	n = atoi(argv[1]);

	if (n<=0) { //Validating bad inputs
		cout <<"Invalid number of elements" << endl;
		return 0;
	}
	
	int arr[n]; //Initiating an array of size #
	for(int i=0; i<n; i++) 
	{
		arr[i] = (rand() % 1000); // Filling the array with random elements.
	}
	
	int size = (sizeof(arr)/sizeof(arr[0]));
	cout<<"The Randomly generated Array is"<<endl;
	printArray(arr, size); //Array Elements Dump Function.

	struct timeval s_timestamp;
	struct timeval e_timestamp;
	int arrB[n]; //New array to store the sequentially computed Max. elements in Array A.
  
	gettimeofday( &s_timestamp, NULL ); // Function defined in time.h to get the current time relative to the epoch. Recording the timestamp before the sort algo.
	sortByMax(arr, arrB, size); // Core Function that implements the sort Algorithm.
	gettimeofday( &e_timestamp, NULL ); // Recording the timestamp after algo terminates.
	
	cout<<"The Sorted Array is"<<endl;
	printArray(arrB,n); //Print elements in B to verify correctness.
	
	double computationTimeInSeconds;
	double computationTimeInMicroseconds;
	//Calculating the time taken to sort by subtracting the relative timestamps.
	if( e_timestamp.tv_usec < s_timestamp.tv_usec )
	{
		computationTimeInSeconds = ((e_timestamp.tv_sec-1) - s_timestamp.tv_sec);
		computationTimeInMicroseconds = (((e_timestamp.tv_usec+1000000) - s_timestamp.tv_usec));
	}
	else
	{
		computationTimeInSeconds = (e_timestamp.tv_sec - s_timestamp.tv_sec);
		computationTimeInMicroseconds = ((e_timestamp.tv_usec - s_timestamp.tv_usec));
	}
    cout << "Computation Time taken is " << computationTimeInSeconds << " seconds " << computationTimeInMicroseconds << " Microseconds"<< endl; //Print the total time taken.
	return 0;
}