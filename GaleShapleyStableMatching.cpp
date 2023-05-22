#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void init_pref_list(vector<vector<int>>& Mtx)
{
    vector<int> a = {6,5,8,9,7}; //5
    vector<int> b = {8,6,5,7,9}; //6
    vector<int> c = {6,9,7,8,5}; //7
    vector<int> d = {5,8,7,6,9}; //8
    vector<int> e = {6,8,5,9,7}; //9
    vector<int> u = {4,0,1,3,2}; //5
    vector<int> v = {2,1,3,0,4}; //6
    vector<int> w = {1,2,3,4,0}; //7
    vector<int> x = {0,4,3,2,1}; //8
    vector<int> y = {3,1,4,2,0}; //9
    Mtx.push_back(a);
    Mtx.push_back(b);
    Mtx.push_back(c);
    Mtx.push_back(d);
    Mtx.push_back(e);
    Mtx.push_back(u);
    Mtx.push_back(v);
    Mtx.push_back(w);
    Mtx.push_back(x);
    Mtx.push_back(y);
}

int main(int argc, char* argv[])
{
    vector<vector<int>> prefMtx;
    stack<int> freeMen;
    vector<int> women;

	init_pref_list(prefMtx);
	
	for(int i=4; i>=0; i--){
		freeMen.push(i);
	}
	
    for (int i=0; i<10; i++) {
    	women.push_back(-1);
	}
	
	while(!freeMen.empty()) {
		int man = freeMen.top();
		freeMen.pop();
		for (int index=0; index<5; index++) {
			int woman = prefMtx[man][index];
			int prev_index,curr_index;
            
			if (women[woman] == -1) {
				women[woman] = man;
				break;
			}
			for(int i=0; i<5; i++) {
			    if (women[woman] == prefMtx[woman][i])
			        prev_index = i;
			}
			
			for(int i=0; i<5; i++) {
			    if (man == prefMtx[woman][i])
			        curr_index = i;
			}
			if ((women[woman] != -1) && (curr_index < prev_index))
			{
				freeMen.push(women[woman]);
				women[woman] = man;
				break;
			}
			else {
				//Do nothing
			}
		}
	}
	
	for (int i=5; i<10; i++) {
		cout<<i<<"-"<<women[i]<<endl;
	}
}