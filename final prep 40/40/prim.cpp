#include <bits/stdc++.h>
using namespace std;

vector<int> p;

int dsuGet(int v) {
    if (v == p[v]) {
        return v;
    }

    return dsuGet(p[v]);
}

void dsuMerge(int u, int v) {
    u = dsuGet(u);
    v = dsuGet(v);

    p[u] = v;
}

int main() {

    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    vector<pair<int, pair<int, int>>> edges;
    int m, n;
    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        int u, v, w; // w - weight
        cin >> u >> v >> w;
        u--;
        v--;

        edges.push_back({w, {u, v}});
    }
    sort(edges.begin(), edges.end());
    // for (auto &i : edges) {
    //     cout << i.first << " " << i.second.first << " " << i.second.second << '\n';
    // }

    int cost = 0;
    p.resize(m);

    vector<pair<int, int>> e;
    for (int i = 0; i < m; i++) {
        p[i] = i;
    }

    for (int i = 0; i < n; i++) {
        // <pair<int, pair<int, int>>>
        int u = edges[i].second.first;
        int v = edges[i].second.second;
        int w = edges[i].first;

        if (dsuGet(u) != dsuGet(v)) {
            cost += w;
            e.push_back({u + 1, v + 1});
            dsuMerge(u, v);
        }
    }

    cout << cost << '\n';
    for (auto &i : e) {
        cout << i.first << " " << i.second << "\n";
    }

    return 0;
}