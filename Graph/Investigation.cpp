#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
typedef pair<int, int> ii;
typedef pair<long long, int> i2;

const int maxN = 1e5 + 5;
const long long INF_LL = 1e15;
const int MOD = 1e9 + 7;
vector<ii> a[maxN];
long long d[maxN], numPath[maxN];
int minE[maxN], maxE[maxN];

void solve(){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y, w;
        cin >> x >> y >> w;
        a[x].push_back(ii(y, w));
    }

    for(int i = 1; i <= n; i++){
        d[i] = INF_LL;
        minE[i] = numPath[i] = 0;
        maxE[i] = MOD;
    }

    priority_queue< i2, vector<i2>, greater<i2> > heap;
    d[1] = minE[1] = maxE[1] = 0;
    numPath[1] = 1;
    heap.push(i2(d[1], 1));

    while (!heap.empty()){
        int u = heap.top().Y;
        long long du = heap.top().X;
        heap.pop();
        if (du != d[u]) continue;
        for(int i = 0; i < a[u].size(); i++){
            int v = a[u][i].X;
            int w = a[u][i].Y;
            if (d[v] > d[u] + w){
                d[v] = d[u] + w;
                numPath[v] = numPath[u];
                minE[v] = minE[u] + 1;
                maxE[v] = maxE[u] + 1;
                heap.push(i2(d[v], v));
            }
            else{
                if (d[v] == d[u] + w){
                    numPath[v] = (numPath[v] + numPath[u]) % MOD;
                    minE[v] = min(minE[v], minE[u] + 1);
                    maxE[v] = max(maxE[v], maxE[u] + 1);
                }
            }
        }
    }

    cout << d[n] << " " << numPath[n] << " " << minE[n] << " " << maxE[n];
}

int main(){
//    freopen("OB.inp", "r", stdin);
//    freopen("OB.out", "w", stdout);
    solve();
}


