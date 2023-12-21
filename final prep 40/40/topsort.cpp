#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int> > g;
vector<bool> visited;
vector<int> topsort;

void dfs(int v){
    visited[v] = true;

    for(int i=0; i<g[v].size(); i++){
        int u = g[v][i];
        if(!visited[u]){
            dfs(u);
        }
    }
    topsort.push_back(v);
}

int main(){
	int m, n;
	cin >> m >> n;
	visited.resize(m);
	g.resize(m);
	for (int i = 0; i < n; i++) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		g[u].push_back(v);
	}
    for(int i=0; i<m; i++){
        if(!visited[i]){
            dfs(i);
        }
    }

    reverse(topsort.begin(), topsort.end());
	for (auto i : topsort) {
		cout << i + 1 << " ";
	}


}