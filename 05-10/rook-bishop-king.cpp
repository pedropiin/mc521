#include <bits/stdc++.h>

#define SIZE 8
#define INF 1e9

using namespace std;

typedef long long ll;

vector<vector<int>> adj_rook(SIZE * SIZE, vector<int>());
vector<vector<int>> adj_bishop(SIZE * SIZE, vector<int>());
vector<vector<int>> adj_king(SIZE * SIZE, vector<int>());

void build_pieces() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            int pos = i * SIZE + j;
            for (int a = 0; a < SIZE; a++) {
                for (int b = 0; b < SIZE; b++) {
                    // configs for rook
                    if (a == i || b == j) {
                        adj_rook[pos].push_back(a * SIZE + b);
                    }

                    // configs for bishop
                    if (abs(a - i) == abs(b - j)) {
                        adj_bishop[pos].push_back(a * SIZE + b);
                    }
                    
                    //configs for king
                    if (abs(a - i) <= 1 || abs(b - j) <=1 ) {
                        adj_king[pos].push_back(a * SIZE + b);
                    } else if (a == i + 1 && b == j + 1) {
                        adj_king[pos].push_back(a * SIZE + b);
                    } else if (a == i - 1 && b == j - 1) {
                        adj_king[pos].push_back(a * SIZE + b);
                    } else if (a == i + 1 && b == j - 1) {
                        adj_king[pos].push_back(a * SIZE + b);
                    } else if (a == i - 1 && b == j + 1) {
                        adj_king[pos].push_back(a * SIZE + b);
                    }
                }
            }
        }
    }
}

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;

    int pos_init = (r1 - 1) * SIZE + (c1 - 1);
    int pos_end = (r2 - 1) * SIZE + (c2 - 1);

    build_pieces();

    vector<int> dist(SIZE * SIZE, INF);
    dist[pos_init] = 0;
    queue<int> q;
    q.push(pos_init);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int j = 0; j < (int)adj_rook[u].size(); j++) {
            int v = adj_rook[u][j];
            if (dist[v] == INF) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    cout << dist[pos_end] << endl;

    return 0;
}