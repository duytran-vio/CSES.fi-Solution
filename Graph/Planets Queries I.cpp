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
const int maxN = 2e5 + 5;
vector<int> a[maxN];
int rmq[maxN][30];

void solve(){
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        rmq[i][0] = x;
    }

    for(int j = 1; j < 30; j++)
    for(int i = 1; i <= n; i++)
        rmq[i][j] = rmq[rmq[i][j - 1]][j - 1];
    for(int i = 0; i < m; i++){
        int x, k;
        cin >> x >> k;
        for(int j = 29; j >= 0; j--)
            if ((k >> j) & 1 == 1)
                x = rmq[x][j];
        cout << x << '\n';
    }
}

int main(int argv, char** argc){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    open_file();
    solve();
}