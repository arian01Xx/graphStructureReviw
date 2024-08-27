#ifndef SOLUTION_ONE_HPP
#define SOLUTION_ONE_HPP

#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class SolutionFourteen{
public:
	int dfs(int node, vector<vector<int>>& graph, vector<int>& quiet, vector<int>& ans, vector<bool> visited){
		if(visited[node]) return ans[node];
		visited[node]=1;
		ans[node]=node;
		for(auto& newnode: graph[node]){
			int candidate=dfs(newnode,graph,quiet,ans,visited);
			if(quiet[candidate]>quiet[ans[node]]) ans[node]=candidate;
		}
		return ans[node];
	}
	vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet){
		int n=quiet.size();
		vector<vector<int>> graph(n);
		vector<int> ans(n,-1);
		vector<bool> visited(n,false);
		for(auto& it: richer){
			graph[it[1]].push_back(it[0]);
		}
		for(int i=0; i<n; i++){
			if(!visited[i]){
				dfs(i,graph,quiet,ans,visited);
			}
		}
		return ans;
	}
};

#endif