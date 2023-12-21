#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > g;
vector<bool> visited;

void dfs(int v){
    visited[v] = true;
    for(int i=0; i<g[v].size(); i++){
        int u = g[v][i];
        if(!visited[u]){
            dfs(u);
        }
    }
    
}