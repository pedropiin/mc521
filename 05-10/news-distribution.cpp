#include <bits/stdc++.h>;

using namespace std;

typedef long long ll;

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    UnionFind cnjts(n + 1);
    while (m--) {
        int size, first, novo;
        cin >> size;
        if (size == 0) {
            continue;
        }
        cin >> first;
        for (int i = 1; i < size; i++) {
            cin >> novo;
            cnjts.unionSet(first, novo);
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << cnjts.sizeOfSet(i) << " ";
    }
    cout << endl;

    return 0;
}