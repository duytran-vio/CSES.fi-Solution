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
vector<ii> a[maxN];
vector<long long> f[maxN];
void solve(){
    int n, m, K;
    cin >> n >> m >> K;
    for(int i = 0; i < m; i++){
        int x, y, w;
        cin >> x >> y >> w;
        a[x].push_back(ii(y, w));
    }
    priority_queue<i2, vector<i2>, greater<i2> > heap;
    heap.push(i2(0, 1));
    while (!heap.empty()){
        int u = heap.top().Y;
        long long du = heap.top().X;
        heap.pop();
        if (f[u].size() >= K) continue;
        f[u].push_back(du);
        for(int i = 0; i < a[u].size(); i++){
            int v = a[u][i].X;
            int w = a[u][i].Y;
            if (f[v].size() < K) heap.push(i2(du + w, v));
        }
    }
    
    for(int i = 0; i < f[n].size(); i++)
        cout << f[n][i] << ' ';
}

int main(int argv, char** argc){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    open_file();
    solve();
}