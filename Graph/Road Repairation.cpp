#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
typedef pair<int, int> ii;
typedef pair<int, ii> i2;

const int maxN = 1e5 + 5;
const long long INF_LL = 1e15;
const int MOD = 1e9 + 7;
vector<i2> canh;
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
        int x, y, w;
        cin >> x >> y >> w;
        canh.push_back(i2(w, {x, y}));
    }

    sort(canh.begin(), canh.end());
    for(int i = 1; i <= n; i++)
        root[i] = -1;

    long long res = 0;
    int cnt = 0;
    for(int i = 0; i < m; i++){
        int s = findroot(canh[i].Y.X);
        int t = findroot(canh[i].Y.Y);
        if (s != t){
//            cerr << s << " " << t << '\n';
            cnt ++;
            res += canh[i].X;
            Union(s, t);
        }
    }
    if (cnt == n - 1)
        cout << res;
    else
        cout << "IMPOSSIBLE";
}

int main(){
//    freopen("OB.inp", "r", stdin);
//    freopen("OB.out", "w", stdout);
    solve();
}
