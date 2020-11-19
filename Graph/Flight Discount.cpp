#include <bits/stdc++.h>
using namespace std;

void open_file(){
    #ifdef INOUT
        freopen("OB.inp", "r", stdin);
        freopen("OB.out", "w", stdout);
    #endif
}

typedef pair<int, int> ii;
typedef pair<long long, ii> i2;
#define X first
#define Y second 
const int maxN = 1e5 + 5;
const long long INF = 1e15;
vector<ii> a[maxN];
long long d[maxN][2];

void solve(){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y, w;
        cin >> x >> y >> w;
        a[x].push_back(ii(y, w));
        // a[y].push_back(ii(x, w));
    }

    for(int i = 1; i <= n; i++)
        d[i][0] = d[i][1] = INF;
    d[1][0] = d[1][1] = 0;
    priority_queue< i2, vector<i2>, greater<i2> > heap;
    heap.push(i2(d[1][0], {1, 0}));
    heap.push(i2(d[1][1], {1, 1}));
    while(!heap.empty()){
        int u = heap.top().Y.X;
        long long du = heap.top().X;
        int tick = heap.top().Y.Y;
        heap.pop();
         
        if (du != d[u][tick]) continue;
        //cout << u << " " << du << " " << tick << '\n';
        for(int i = 0; i < a[u].size(); i++){
            int v = a[u][i].X;
            int w = a[u][i].Y;
            if (tick == 0){
                if (d[v][0] > du + w){
                    d[v][0] = du + w;
                    heap.push(i2(d[v][0], {v, 0}));
                }
                if (d[v][1] > du + w / 2){
                    d[v][1] = du + w / 2;
                    heap.push(i2(d[v][1], {v, 1}));
                }
            }
            else 
                if (d[v][1] > du + w){
                    d[v][1] = du + w;
                    heap.push(i2(d[v][1], {v, 1}));
                }
        }
    }

    // for(int i = 1; i <= n; i++)
    //     cout << d[i][0] << " " << d[i][1] << '\n';

    cout << min(d[n][0], d[n][1]);
}

int main(int argv, char** argc){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    open_file();
    solve();
}