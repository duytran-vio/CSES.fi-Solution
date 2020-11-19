#include <bits/stdc++.h>
using namespace std;

void open_file(){
    #ifdef INOUT
        freopen("OB.inp", "r", stdin);
        freopen("OB.out", "w", stdout);
    #endif
}

typedef pair<int, int> ii;
#define X first
#define Y second 

const int maxN = 1e5 + 5;
vector<int> a[maxN];
vector<ii> canh;
int TP[maxN], p[maxN];

void DFS(int u, int k){
    TP[u] = k;
    p[k] = u;
    for(int v : a[u]){
        if (TP[v] == 0)
            DFS(v, k);
    }
}

void solve(){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        x--;y--;
        a[x].push_back(y);
        a[y].push_back(x);
    }

    int cnt = 0;
    for(int i = 0; i < n; i++){
        if (TP[i] == 0){
            cnt++;
            DFS(i, cnt);
        }
    }

    cout << cnt - 1 << '\n';
    for(int i = 1; i < cnt; i++)
        cout << p[i] + 1 << " " << p[i + 1] + 1 << '\n';
}

int main(int argv, char** argc){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    open_file();
    solve();
}