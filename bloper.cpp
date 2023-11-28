#include <bits/stdc++.h>
using namespace std;

class BLOPER {
    int n, s, a[505], sum;
public:
    BLOPER(int n, int s) {
        this->n = n;
        this->s = s;
        this->sum = n*(n+1)/2;
    }
    void solve() {
        for (int i = n; i >= 1; i--) {
            if (sum-2*i >= s) {
                a[i] = 1;
                sum -= 2*i;
            }
        }
        if (sum == s) {
            if (a[1]) {
                for (int i = 4; i <= n; i++) {
                    if (a[1] == 0) break;
                    if (a[i])
                        for (int j = 2; j <= i/2; j++)
                            if (a[j] == 0 && a[i+1-j] == 0) {
                                a[j] = a[i+1-j] = 1;
                                a[1] = a[i] = 0;
                                break;
                            }
                }
                if (a[1]) {
                    cout << "Impossible";
                    return;
                }
            }
            cout << "1";
            for (int i = 2; i <= n; i++)
                cout << ((a[i] == 1) ? '-' : '+') << i;
        } else cout << "Impossible";
    }
};

int main() {
    int n, s;
    cin >> n >> s;
    BLOPER bloper(n, s);
    bloper.solve();
    return 0;
}

