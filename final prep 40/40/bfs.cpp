#include <iostream>
#include <queue>
using namespace std;

vector<vector<int> > g;
vector<bool> visited;

void bfs(int v){
    queue<int>q;
    q.push(v);
    visited[v] = true;
    while(!q.empty()){
        int curr = q.front();
        for(int i=0; i<g[v].size(); i++){
            int u = g[curr][i];
            if(!visited[u]){
                q.push(u);
                visited[u] = true;
            }

        }
        q.pop();
    }


}