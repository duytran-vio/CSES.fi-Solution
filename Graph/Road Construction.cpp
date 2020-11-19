#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
typedef pair<int, int> ii;
typedef pair<int, ii> i2;

const int maxN = 1e5 + 5;
const long long INF_LL = 1e15;
const int MOD = 1e9 + 7;
vector<ii> canh;
int root[maxN];

int findroot(int x){
    if (root[x] < 0) return x;
    return root[x] = findroot(root[x]);
}

void Union(int s, int t){
//    s = findroot(s);
//    t = findroot(t);
//    if (s == t) return;
    if (root[s] > root[t]) swap(s, t);
    root[s] += root[t];
    root[t] = s;
}

void solve(){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        canh.push_back({x, y});
    }
    for(int i = 1; i <= n; i++)
        root[i] = -1;

    int cnt = n, res = 0;
    for(int i = 0; i < m; i++){
        int s = findroot(canh[i].X);
        int t = findroot(canh[i].Y);
        if (s != t){
            cnt--;
            res = max(res, abs(root[s]) + abs(root[t]));
            Union(s, t);
        }
        cout << cnt << " " << res << '\n';
    }
}

int main(){
//    freopen("OB.inp", "r", stdin);
//    freopen("OB.out", "w", stdout);
    solve();
}

