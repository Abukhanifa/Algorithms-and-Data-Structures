#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n; // число вершин
vector<int> g[MAXN]; // граф
bool used[MAXN];
vector<int> ans;

void dfs(int v){
    used[v] = true;
    for(int i=0; i<g[v].size(); i++){
        int to = g[v][i];
        if(!used[to]){
            dfs(to);
        }
        
    }
    ans.push_back(v);

}

void topsort(){
    for(int i=0; i<n; i++)
        used[i] = false;
    ans.clear();
    for(int i=0; i<n; i++){
        if(!used[i])
        dfs(i);
    }
    reverse(ans.begin(), ans.end());
}

int main(){


    return 0;
}