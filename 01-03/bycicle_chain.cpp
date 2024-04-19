#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> m;
    int b[m];
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    int temp, r = 0, count = 0, n_index = 0;
    while (n_index < n) {
        for (int i = 0; i < m; i++) {
            if (b[i] % a[n_index] == 0) {
                temp = b[i] / a[n_index];
                if (temp == r) {
                    count++;
                } else if (temp > r) {
                    r = temp;
                    count = 1;
                }
            }
        }
        n_index++;
    }
    
    cout << count << endl;

    return 0;
}