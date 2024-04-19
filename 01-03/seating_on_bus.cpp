#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, cheio = 1;
    cin >> n >> m;

    if (m != 4 * n) {
        cheio = 0;
    }

    int inicio = 1, meio = (2 * n) + 1;
    for (int i = 0; i < m; i++) {
        if (i == (m - 1) && cheio != 1) {
            cout << inicio;
            break;
        } 
        if (i % 2 == 0) {
            cout << meio++ << ' ';
        } else {
            cout << inicio++ << ' ';
        }
    }
    cout << endl;

    return 0;
}