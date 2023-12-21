#include <bits/stdc++.h>
using namespace std;

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

    vector<pair<int, int>> e;
    vector<int> components(m);
    for (int i = 0; i < m; i++) {
        components[i] = i;
    }

    for (int i = 0; i < n; i++) {
        // <pair<int, pair<int, int>>>
        int u = edges[i].second.first;
        int v = edges[i].second.second;
        int w = edges[i].first;

        if (components[u] != components[v]) {
            cost += w;
            e.push_back({u + 1, v + 1});

            int componentOfU = components[u];
            int componentOfV = components[v];

            for (int j = 0; j < n; j++) {
                if (components[j] == componentOfV) {
                    components[j] = componentOfU;
                }
            }
        }
    }

    cout << cost << '\n';
    for (auto &i : e) {
        cout << i.first << " " << i.second << "\n";
    }

    for (auto &i : components) {
        cout << i << " ";
    }

    return 0;
}