#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> parent;
vector <int> rnk;

void make_set(int v){
    parent[v] = v;
    rnk[v] = 0;
}

int find_set(int v){
    if(v == parent[v]){
        return v;
    }
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b){
    a = find_set(a);
    b = find_set(b);
    if(a!=b){
        if(rnk[a] < rnk[b])
            swap(a,b);
        parent[b] = a;
        if(rnk[b] == rnk[a])
            rnk[a++];

        
    }
}

struct Edge{
    int u,v,weight;
    bool operator <(Edge const& other){
    return weight < other.weight; 
}
};



int main(){
    int n;
    vector<Edge> Edges;

    int cost = 0;
    vector<Edge> result;
    parent.resize(n);
    rnk.resize(n);

    for(int i=0; i<n; i++){
        make_set(i);
    }

    sort(Edges.begin(), Edges.end());

    for(Edge e: Edges){
        if(find_set(e.u) != find_set(e.v)){
            cost += e.weight;
            result.push_back(e);
            union_sets(e.u, e.v);
        }
    }



}