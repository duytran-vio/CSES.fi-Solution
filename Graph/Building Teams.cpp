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
int T[maxN];
bool Odd;

void DFS(int u, int k){
    cerr << u << '\n';
    T[u] = k;
    for(int v : a[u]){
        if (T[v] == 0)
            DFS(v, 3 - k);
        else 
            if (T[v] == k) Odd = true;
    }
}

void solve(){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }

    for(int i = 1; i <= n; i++)
        if (T[i] == 0)
            DFS(i, 1);
    if (Odd)
        cout << "IMPOSSIBLE";
    else 
        for(int i = 1; i <= n; i++)
            cout << T[i] << ' ';
}

int main(int argv, char** argc){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    open_file();
    solve();
}