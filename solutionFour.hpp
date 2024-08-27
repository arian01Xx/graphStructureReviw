#ifndef SOLUTION_FOUR_HPP
#define SOLUTION_FOUR_HPP

#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class SolutionSeventeen{
public:
	int findChampion(int n, vector<vector<int>>& edges){
		vector<int> deg(n,0);
		for(const auto& it: edges){
			int w=it[1];
			deg[w]++;
		}
		vector<int> deg0;
		for(int i=0; i<n; i++){
			if(deg[i]==0) deg0.push_back(i);
		}
		if(deg0.size()!=1) return -1;
		else return deg0[0];
	}
};

#endif