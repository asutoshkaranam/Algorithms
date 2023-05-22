/*
*
@author : Asutosh Karanam
*
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

//Intialize the Inputs
void init_vector_list(vector<int>& students_t, vector<int>& heights_t) 
{
	students_t = {2,4,6,8,10,12,14,16,18,20}; //Skiers
    heights_t = {1,2,3,4,5,6,7,8,9,10,11,12}; //Skis
//    students_t = {5,5,7,8,9,10};
//    heights_t = {1,2,4,5,6,7,9,11,12};
}

//Core Function that implements Bottom-Up Dynamic Programming
int findMatchDP(vector<int>& students_t, vector<int>& heights_t, vector<vector<int>>& c) 
{	
	int m = heights_t.size();
	int n = students_t.size();
	int min_cost = 0;
	
	//Return if the Input Sizes are NULL
	if ((n==0) || (m==0))
		return min_cost;
	
	//Iteratiely construct the Table
	for (int i = 1; i <=n; i++) {
		for (int j = 1; j <=m; j++) {
			if (j < i) {
				c[i][j] = INT_MAX;
			}
			else {
				c[i][j] = min(c[i][j - 1], (c[i - 1][j - 1] + abs(students_t[i-1] - heights_t[j-1])));
			}
		}
	}
	
	// Compute the minimum cost by finding c[n, m].
	min_cost = c[n][m];
	//return
	return min_cost;
}

int main(int argc, char* argv[])
{
	vector<int> students;
	vector<int> heights;
	
	//Initialize the input vector list
	init_vector_list (students, heights);
	
	vector<vector<int>> cost_t(students.size()+1, vector<int>(heights.size()+1, INT_MAX));
	
	//Base Initialization 0th Row
    for (int i = 0; i <= heights.size(); i++) {
        cost_t[0][i] = 0;
    }
	
	//Solve the DP problem.
	int cost = findMatchDP(students, heights, cost_t);
	
	// Display the min. cost.
	cout << "The minimum cost is " << cost << endl;
	
	// Trace back using the cost 2D vector and generate the optimal solution.
	int i = students.size(), j = heights.size();
	vector<int> skis;
	vector<int> skiers;
	
	while (i > 0 and j > 0) {
		if(cost_t[i][j] == cost_t[i][j-1])
			j--;
		else {
			skis.push_back(students[i-1]);
			skiers.push_back(heights[j-1]);
			i--;
			j--;
		}
	}

	// Print the optimal solution.
	cout<<"The optimal solution of the final mapping is"<<endl;
	for (int i=0; i<skis.size();i++) {
		cout<< skis[i] << " <-> " << skiers[i]<<endl;
	}

	return 0;
}