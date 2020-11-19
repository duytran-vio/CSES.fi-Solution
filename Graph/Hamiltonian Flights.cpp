#include <bits/stdc++.h>
using namespace std;

void open_file(){
    #ifdef INOUT
        freopen("OB.inp", "r", stdin);
        freopen("OB.out", "w", stdout);
    #endif
}

typedef pair<int, int> ii;
typedef pair<long long, int> i2;
#define X first
#define Y second 
const int maxN = 2e6 + 5;
const int MOD = 1e9 + 7;
int a[50][50];

long long f[maxN][21];

int addbit(int n, int i){
    return n | (1 << (i - 1));
}

int bit0(int n, int i){
    return n ^ (1 << (i - 1));
}

void solve(){
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        a[x][y] += 1;
    }

    for(int i = 2; i <= n; i++){
        if (a[1][i] == 0) continue;
        int state = addbit(1, i);
        f[state][i] = a[1][i];
    }

    for(int state = (1 << 3) - 1; state < (1 << n); state++){
        if (state % 2 == 0) continue;
        for(int i = 2; i <= n; i++){
            if (((state >> i - 1) & 1) == 0) continue;
            // cout << state << " " << i << " ------ \n";
            int pre = bit0(state, i);
            // cout << "pre : " << pre << '\n';
            for(int k = 2; k <= n; k++)
                if (a[k][i] && ((pre >> k - 1) & 1)){
                    // cout << k << " " << i << " " << pre << " " << f[pre][k] << '\n';
                    f[state][i] = (f[state][i] + f[pre][k])  % MOD * a[k][i] % MOD;
                }
            // cout << "result : " << f[state][i] << '\n';
        }
    }

    cout << f[(1 << n) - 1][n];
}

int main(int argv, char** argc){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    open_file();
    solve();
}