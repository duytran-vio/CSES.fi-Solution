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
int trace[maxN];

void Truyvet(int u, vector<int> &res){
    if (u == -1) return;
    Truyvet(trace[u], res);
    res.push_back(u);
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

    queue<int> que;
    que.push(1);
    trace[1] = -1;
    while(!que.empty()){
        int u = que.front();
        que.pop();
        if (u == n) break;
        for(int v : a[u]){
            if (trace[v] == 0) {
                que.push(v);
                trace[v] = u;
            }
        }
    }

    if (trace[n] == 0){
        cout << "IMPOSSIBLE";
        return;
    }

    vector<int> res;
    Truyvet(n, res);
    cout << res.size() << '\n';
    for(int i = 0; i < res.size(); i++)
        cout << res[i] << ' ';
}

int main(int argv, char** argc){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    open_file();
    solve();
}