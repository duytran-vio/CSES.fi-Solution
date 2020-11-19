#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
typedef pair<int, int> ii;
typedef pair<int, ii> i2;

const int maxN = 2e5 + 5;
const long long INF_LL = 1e15;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 100;

int p[maxN][20];
vector<int> a[maxN];


void solve(){
    int n, m;
    cin >> n >> m;
    for(int i = 2; i <= n; i++)
        cin >> p[i][0];
    for(int j = 1; j < 20; j++)
        for(int i = 1; i <= n; i++)
            p[i][j] = p[p[i][j - 1]][j - 1];
    while(m--){
        int v, k;
        cin >> v >> k;
        for(int i = 19; i >= 0; i--)
            if ((k >> i) & 1)
                v = p[v][i];
        cout << ((v == 0) ? -1 : v) << '\n';
    }
}

int main(){
//    freopen("OB.inp", "r", stdin);
//    freopen("OB.out", "w", stdout);
    solve();
}
