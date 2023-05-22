/*
*
@author: Asutosh Karanam
*
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//Initialize the Main vector and Target Size of the Subset
void init_vector_list(vector<int>& mainArray, int& subArrSz)
{
	mainArray = {1, 10, 30, 20, 100, 2, 3};
	subArrSz = 3;
}

int main(int argc, char* argv[]) {
	vector<int> numList;
	int propDiffMin = 0;
	int subArrSize = 0;
	//Initialization helper function
	init_vector_list(numList, subArrSize);
	//Sort the vector
	sort(numList.begin(), numList.end());

	//Start a Sliding Window	
	int windowSIdx = 0;
	int windowEIdx = subArrSize-1;
	//Initialize the MinDiff to the Diff of the First Subset
	propDiffMin = numList[windowEIdx] - numList[windowSIdx];
	//Move the window till the end and update the MinDiff Property accordingly
	while (windowEIdx <= (numList.size()-1)) {
		//Print the Subset
		cout<<"Subset";
		for(int j=windowSIdx; j<=windowEIdx; j++) {
			cout <<" "<<numList[j];
		}
		//Print the Diff
		int diff = numList[windowEIdx] - numList[windowSIdx];
		cout<<"; Property Diff - "<<diff<<";"<<endl;
		//If the Curr. Diff is Greater than Old Diff then don't update the MinDiff
		propDiffMin = (propDiffMin < diff) ? propDiffMin : diff;
		//Move the Window by one step
		windowEIdx++;
		windowSIdx++;
	}
	//Print the Property
	cout<<"P = "<<propDiffMin;
}
