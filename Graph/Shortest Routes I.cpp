#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
typedef pair<int, int> ii;
typedef pair<long long, int> i2;

const int maxN = 1e5 + 5;
const long long INF_LL = 1e15;
vector<ii> a[maxN];
int n, m;

void Dijstra(int s, vector<ii> a[], vector<long long> &d){
    for(int i = 1; i <= n; i++)
        d[i] = INF_LL;
    priority_queue<i2, vector<i2>, greater<i2> > heap;
    d[s] = 0;
    heap.push(i2(d[s], s));
    while(!heap.empty()){
        int u = heap.top().Y;
        long long du = heap.top().X;
        heap.pop();
        if (du != d[u]) continue;
        for(int i = 0; i < a[u].size(); i++){
            int v = a[u][i].X;
            int w = a[u][i].Y;
            if(d[v] > d[u] + w){
                d[v] = d[u] + w;
                heap.push(i2(d[v], v));
            }
        }
    }
}

void solve(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y, w;
        cin >> x >> y >> w;
        a[x].push_back(ii(y, w));

    }

    vector<long long> d(n + 1);
    Dijstra(1, a, d);
    for(int i = 1; i <= n; i++)
        cout << d[i] << ' ';
}

int main(){
//    freopen("OB.inp", "r", stdin);
//    freopen("OB.out", "w", stdout);
    solve();
}


