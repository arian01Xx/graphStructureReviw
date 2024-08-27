#ifndef SOLUTION_THREE_HPP
#define SOLUTION_THREE_HPP

#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class SolutionSixteen{
public:
	int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted){
		unordered_map<int,vector<int>> graph;
		unordered_set<int> restrictedSet(restricted.begin(), restricted.end());

		vector<bool> visited(n,false);

		for(const auto& it: edges){
			graph[it[0]].push_back(it[1]);
			graph[it[1]].push_back(it[0]);
		}

		int count=0;
		queue<int> q;
		q.push(0);
		visited[0]=true;
		while(!q.empty()){
			int node=q.front();
			q.pop();
			count++;
			for(auto& neighbor: graph[node]){
				if(!visited[neighbor] && restrictedSet.find(node)==restrictedSet.end()){
					visited[neighbor]=true;
					q.push(neighbor);
				}
			}
		}
		return count;
	}
};

#endif