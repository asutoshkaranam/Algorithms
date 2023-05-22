/**
  @author Asutosh Karanam
 **/
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <unordered_set>

using namespace std;

void init_graph_adjacencylist(vector<vector<pair<int,int>>>& adjList) {
	adjList = {
		{make_pair(9,1),make_pair(14,5), make_pair(15,6)},
		{make_pair(23,2)},
		{make_pair(19,7),make_pair(2,4)},
		{make_pair(6,2),make_pair(6,7)},
		{make_pair(11,3),make_pair(16,7)},
		{make_pair(18,2),make_pair(30,4),make_pair(5,6)},
		{make_pair(20,4),make_pair(44,7)},
		{make_pair(0,0)}
	};
}

unsigned int getPrediction() {
	int ret = (rand() % 100);
	cout<<"Web-Site Predicted a Deviation of "<<ret<<endl;
	return ret;
}

int main(int argc, char* argv[])
{
	vector<vector<pair<int,int>>> graph;
	init_graph_adjacencylist(graph);
	
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> visitedNodes;
	
	vector<int> distance(graph.size()+1, INT_MAX);
	cout<<"Graph size is "<<graph.size()<<endl;
	
	visitedNodes.push(make_pair(0,0));
	distance[0] = 0;
	
	//unordered_set<int> connComp;
	
	while (!visitedNodes.empty()) {
		pair<int,int> itr = visitedNodes.top();
        visitedNodes.pop();
        cout<<"Itr "<<itr.first<<" and "<<itr.second<<endl;
		for(auto vertex : graph[itr.second]) {
			cout<<"Vertex "<<vertex.first<<" and "<<vertex.second<<endl;
			int prediction = (vertex.first + getPrediction());
			if ( distance[vertex.second] > itr.first + prediction) {
				cout<<"Distance of "<<vertex.second<<" is to be updated"<<endl;
				distance[vertex.second] = itr.first + prediction;
				cout<<"Updated Distance is "<<distance[vertex.second]<<endl;
				visitedNodes.push(make_pair(distance[vertex.second],vertex.second));
			}
		}
	}
	cout<<"Printing the path from Source to All Nodes"<<endl;
    
	for (int i = 0; i < graph.size(); i++)
        cout<<"Node"<<i<<" "<<distance[i]<<endl;
        
	return 0;
}
