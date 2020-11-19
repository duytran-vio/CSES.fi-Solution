#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
typedef pair<int, int> ii;
typedef pair<long long, int> i2;

const int maxN = 1e5 + 5;
const long long INF_LL = 1e15;
vector<int> a[maxN];
int indeg[maxN], cha[maxN], d[maxN];

void Truyvet(int u){
    if (u == 1){
        cout << u << ' ';
        return;
    }
    Truyvet(cha[u]);
    cout << u << ' ';
}

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
        d[i] = -1e9;
        if (indeg[i] == 0){
            que.push(i);
        }
    }
    que.push(1);
    d[1] = 0;

    while(!que.empty()){
        int u = que.front();
        que.pop();
        for(int v : a[u]){
            if (d[v] < d[u] + 1){
                d[v] = d[u] + 1;
                cha[v] = u;
            }
            if (--indeg[v] == 0){
                que.push(v);
            }
        }
    }

    if (d[n] <= 0) cout << "IMPOSSIBLE";
    else{
        cout << d[n] + 1 << '\n';
        Truyvet(n);
    }
}

int main(){
//    freopen("OB.inp", "r", stdin);
//    freopen("OB.out", "w", stdout);
    solve();
}


