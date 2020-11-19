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
const int maxN = 1e5 + 5;
const long long INF = 1e15;
vector<int> a[maxN];
bool visit[maxN];
vector<int> res;
bool check;
int inPath[maxN];

void DFS(int u){
    visit[u] = true;
    inPath[u] = 1;
    for(int v : a[u]){
        if (!visit[v]){
            DFS(v);
        }
        else 
            if (inPath[v] == 1) {
                check = true;
            }
    }
    res.push_back(u);
    inPath[u] = 0;
}

void solve(){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
    }

    for(int i = 1; i <= n; i++)
        if (!visit[i])
            DFS(i);
    reverse(res.begin(), res.end());
    if (check) cout << "IMPOSSIBLE";
    else
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