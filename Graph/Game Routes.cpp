#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
typedef pair<int, int> ii;
typedef pair<long long, int> i2;

const int maxN = 1e5 + 5;
const long long INF_LL = 1e15;
const int MOD = 1e9 + 7;
vector<int> a[maxN];
int indeg[maxN], d[maxN];

void solve(){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
        indeg[y]++;
    }

    queue<int> que;

    for(int i = 2; i <= n; i++){
        if (indeg[i] == 0){
            que.push(i);
        }
    }
    que.push(1);
    d[1] = 1;

    while(!que.empty()){
        int u = que.front();
        que.pop();
        for(int v : a[u]){
            d[v] = ((long long)d[v] + d[u]) % MOD;
            if (--indeg[v] == 0){
                que.push(v);
            }
        }
    }

    cout << d[n] << '\n';
}

int main(){
    freopen("OB.inp", "r", stdin);
    freopen("OB.out", "w", stdout);
    solve();
}

