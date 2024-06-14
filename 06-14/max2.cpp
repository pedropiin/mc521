#include <bits/stdc++.h>

#define INF 1e9

using namespace std;

typedef long long ll;

void augment(int s, int t, int v, int minEdge, int &flow, vector<int> &p, vector<vector<int>> &capacity) {
    if (v == s) {
        flow = minEdge;
    } else if (p[v] != - 1) {
        augment(s, t, p[v], min(minEdge, capacity[p[v]][v]), flow, p, capacity);
        capacity[p[v]][v] -= flow;
        capacity[v][p[v]] += flow;
    }
}

int get_flow_edges(int s, int t, vector<vector<int>> &capacity, vector<vector<int>> &og_capacity) {
    int count = 0;
    for (int i = 0; i < capacity.size(); i++) {
        for (int j = 0; j < capacity[i].size(); j++) {
            if (og_capacity[i][j] > 0 && capacity[i][j] < og_capacity[i][j]) {
                count++;
            }
        }
    }
    return count;
}


int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, s, t;
    cin >> n >> m >> s >> t;

    vector<vector<int>> adj(n);
    vector<vector<int>> capacity(n, vector<int>(n, 0));
    vector<vector<int>> og_capacity(n, vector<int>(n, 0));

    int u, v, c;
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> c;
        adj[u].push_back(v);
        capacity[u][v] = c;
        og_capacity[u][v] = c;
    }

    int max_flow = 0;
    int flow;
    vector<int> p;
    while (1) {
        flow = 0;
        bitset<n> vis;
        vis[s] = true;
        queue<int> q;
        q.push(s);
        p.assign(n, -1);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            if (u == t) {
                break;
            }
            for (int j = 0; j < adj[u].size(); j++) {
                int v = adj[u][j];
                if (capacity[u][v] > 0 && !vis[v]) {
                    vis[v] = true;
                    q.push(v);
                    p[v] = u;
                }
            }
            augment(s, t, t, INF, flow, p, capacity);
            if (flow == 0) {
                break;
            }
            max_flow += flow;
        }
    }

    int count = get_flow_edges(s, t, capacity, og_capacity);
    cout << n << " " << max_flow << " " << count << endl;
    for (int i = 0; i < capacity.size(); i++) {
        for (int j = 0; j < capacity[i].size(); j++) {
            if (og_capacity[i][j] > 0 && capacity[i][j] < og_capacity[i][j]) {
                cout << i << " " << j << " " << og_capacity[i][j] - capacity[i][j] << endl;
            }
        }
    }
    return 0;
}