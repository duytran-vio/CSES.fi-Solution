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
int f[maxN], trace[maxN];
bool Done;

void Print(int u, int v){
    if (u == v){
        cout << u << ' ';
        return;
    }
    Print(trace[u], v);
    cout << u << ' ';
}

void DFS(int u){
    if (Done) return;
    for(int v : a[u]){
        if (trace[v] == 0){
            trace[v] = u;
            f[v] = f[u] + 1;
            DFS(v);
        }
        else {
            if (f[u] - f[v] > 1 && !Done) {
                cout << f[u] - f[v] + 2 << '\n'; 
                Print(u, v); 
                cout << v;
                Done = true;
            }
        }
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

    for(int i = 1; i <= n; i++){
        if (trace[i] == 0){
            trace[i] = -1;
            DFS(i);
        }
    }
    if (!Done){
        cout << "IMPOSSIBLE";
    }
}

int main(int argv, char** argc){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    open_file();
    solve();
}