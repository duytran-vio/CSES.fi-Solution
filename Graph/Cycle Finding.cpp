#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
typedef pair<int, int> ii;
typedef pair<long long, int> i2;

const int maxN = 1e5 + 5;
const long long INF_LL = 1e15;
vector<ii> a[maxN];
int n, m, cha[maxN], Used[maxN];

void solve(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y, w;
        cin >> x >> y >> w;
        a[x].push_back(ii(y, w));
    }

    vector<long long> d(n + 1, INF_LL);
    d[1] = 0;

    for(int i = 1; i <= n; i++){
        for(int u = 1; u <= n; u++)
        for(int k = 0; k < a[u].size(); k++){
            int v = a[u][k].X;
            int w = a[u][k].Y;
            if (d[v] > d[u] + w){
                d[v] = d[u] + w;
                cha[v] = u;
                if (i == n){
                    cout << "YES\n";
                    vector<int> res;
                    int t = v;
                    while(Used[t] == 0){
                        Used[t] = 1;
                        t = cha[t];
                    }
                    while (Used[t] == 1) {
                        Used[t] = 2;
                        res.push_back(t);
                        t = cha[t];
                    }
                    res.push_back(t);
                    reverse(res.begin(), res.end());
                    for(int j = 0; j < res.size(); j++)
                        cout << res[j] << ' ';
                    return;
                }
            }
        }
    cout << "NO";
}

int main(){
//    freopen("OB.inp", "r", stdin);
//    freopen("OB.out", "w", stdout);
    solve();
}


