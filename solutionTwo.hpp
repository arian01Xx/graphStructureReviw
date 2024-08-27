#ifndef SOLUTION_TWO_HPP
#define SOLUTION_TWO_HPP

#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class SolutionFifteen{
public:
	int n;
	void dfs(int node, vector<int>& vis, vector<vector<int>>& stones){
		vis[node]=1;
		for(int j=0; j<n; j++){
			if(!vis[j]){
				if(stones[node][0]==stones[j][0] || stones[node][1]==stones[j][1]){
					dfs(j,vis,stones);
				}
			}
		}
	}
	int removeStones(vector<vector<int>>& stones){
		n=stones.size();
		vector<int> vis(n,0);
		int ans=0;
		for(int i=0; i<n; i++){
			if(!vis[i]){
				dfs(i,vis,stones);
				ans++;
			}
		}
		return ans;
	}
};

#endif