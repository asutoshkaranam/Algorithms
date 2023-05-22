/**
  @author Asutosh Karanam
 **/
#include <iostream>
#include <unordered_map>
#include <stack>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char* argv[])
{
	unordered_map<string, int> fixedCapacity; //Map to store the Fixed Capacity of each hospital.
	unordered_map<string, int> avlCapacity; //Map to keep track of available positions in run-time.
	stack<string> freeHospital; //Stack to process the Hospitals with Free positions.
	unordered_map<string, string> students; //Student-Hospital mapping.
	unordered_map<string, int> proposalCnt; //Proposal Counter to count the number of proposals made.

	/*Initialize the PrefList of Hospitals*/
	unordered_map<string, vector<pair<string, int>>> hospitals { 
		{"H1", {{"S4",1}, {"S2",2}, {"S6",3}, {"S1",4}, {"S5",5}, {"S3",6}}}, 
			{"H2", {{"S2",1}, {"S4",2}, {"S3",3}, {"S1",4}, {"S5",5}, {"S6",6}}}
	}; 

	/*Initialize the PrefList of the student Applicants*/
	unordered_map<string, unordered_map<string, int>> applicants {
		{"S1", {{"H1",1}, {"H2",2}}},
			{"S2", {{"H1",1}, {"H2",2}}},
			{"S3", {{"H2",1}, {"H1",2}}},
			{"S4", {{"H2",1}, {"H1",2}}},
			{"S5", {{"H1",1}, {"H2",2}}},
			{"S6", {{"H2",1}, {"H1",2}}}
	};

	/*Intialize the total fixed Capacities*/
	fixedCapacity["H1"] = 2;
	fixedCapacity["H2"] = 3;

	//Intialize the Proposal Counter
	proposalCnt["H1"] = 0;
	proposalCnt["H2"] = 0;

	avlCapacity = fixedCapacity;

	//Push all Hospitals to the stack for processing
	freeHospital.push("H2");
	freeHospital.push("H1");

	//Initialize the student-hospital Map for each student
	students["S1"]="";
	students["S2"]="";
	students["S3"]="";
	students["S4"]="";
	students["S5"]="";
	students["S6"]="";

	//Start the loop to process the freehospital Stack
	while(!freeHospital.empty()) {
		string block = freeHospital.top();
		//If hospital has Avlbl positions process it. Else, Remove it from stack.
		if(avlCapacity[block] > 0) {
			//cout<<"Current Available number of positions in Hospital "<<block<<" : "<<avlCapacity[block]<<endl;
			for (int index=proposalCnt[block]; index < hospitals[block].size(); index++) //Iterate across the hospital prefList
				//for (auto& index : hospitals[block])
			{
				pair<string, int> stu = hospitals[block][index];
				int prev_index,curr_index;
				//cout<<"Hospital "<<block<<" offers to student "<<stu.first<<endl;
				proposalCnt[block]++;
				if (students[stu.first] == "") { //Student currently without an offer accepts.
					students[stu.first] = block;
					avlCapacity[block]--;
					//cout<<"Student "<<stu.first<<" accepts the offer given by the hospital "<<block<<endl;
					//cout<<"Current Available number of positions in Hospital "<<block<<" : "<<avlCapacity[block]<<endl;
					if (avlCapacity[block] == 0) {
						break;
					}
				}
				else if ((students[stu.first] != "")) { //If an offer already exists, Student determines the priority and chooses.
					string str = students[stu.first];
					if (applicants[stu.first].find(str) != applicants[stu.first].end()) //find the priority of the previous offer from the applicant's preflist
					{
						prev_index = applicants[stu.first][str];
					}

					if (applicants[stu.first].find(block) != applicants[stu.first].end()) //Find the priority of the current proposal from the applicant's preflist
					{
						curr_index = applicants[stu.first][block];
					}

					if ((curr_index < prev_index)) //If curr is preferred over prev, Reject prev and Accept curr
					{
						string idx = students[stu.first];
						//cout<<"Student "<<stu.first<<" accepts the offer given by the hospital "<<block<<" and rejects the offer given by the hospital "<<idx<<endl;
						freeHospital.push(idx);
						avlCapacity[idx]++;
						//cout<<"Current Available number of positions in Hospital "<<idx<<" : "<<avlCapacity[idx]<<endl;
						students[stu.first] = block;
						avlCapacity[block]--;
						//cout<<"Current Available number of positions in Hospital "<<block<<" : "<<avlCapacity[block]<<endl;
						if (avlCapacity[block] == 0) {
							break;
						}
					}
					else {
						//cout<<"Student "<<stu.first<<" Ignores the offer given by Hospital "<<block<<endl;
					}
				}
			}
		} else {
			freeHospital.pop();
		}
	}

	//Dump the Mapping to enlist the final matching pairs.
	for (auto& i : students) {
		cout<<i.first << " --> "<<i.second<<endl;
	}
}
