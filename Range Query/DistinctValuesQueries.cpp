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
const int maxN = 2e5 + 5;
const int INF = 2e9 + 100;
int a[maxN], d[maxN], IT[maxN * 4];
struct DATA{
    int X, Y, pos;
    DATA(){};
};

void update(int k, int l, int r, int u, int val){
    if (u < l || u > r) return;
    if (l == r){
        IT[k] = val;
        return;
    }
    int mid = (l + r) / 2;
    update(k * 2, l , mid, u, val);
    update(k * 2 + 1, mid + 1, r, u, val);
    IT[k] = IT[k * 2] + IT[k * 2 + 1];
}

int get(int k, int l, int r, int u, int v){
    if (v < l || u > r) return 0;
    if (u <= l && r <= v) return IT[k];
    int mid = (l + r) / 2;
    int L = get(k * 2, l, mid, u, v);
    int R = get(k * 2 + 1, mid + 1, r, u, v);
    return L + R;
}

void solve(){
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    vector<DATA> Q(m);
    for(int i = 0; i < m; i++){
        cin >> Q[i].X >> Q[i].Y;
        Q[i].pos = i;
    }

    sort(Q.begin(), Q.end(), [&] (DATA A, DATA B){
        return A.Y < B.Y;
    });

    vector<int> c;
    for(int i = 1; i <= n; i++)
        c.push_back(a[i]);
    sort(c.begin(), c.end());
    c.resize(unique(c.begin(), c.end()) - c.begin());
    
    int k = 1;
    vector<int> res(m);
    for(int i = 0; i < m; i++){
        while (k <= Q[i].Y){
            int t = lower_bound(c.begin(), c.end(), a[k]) - c.begin();
            if (d[t] != 0){
                update(1, 1, n, d[t], 0);
            }
            update(1, 1, n, k, 1);
            d[t] = k;
            k++;
        }
        res[Q[i].pos] = get(1, 1, n, Q[i].X, Q[i].Y);
    }

    for(int i = 0; i < m; i++)
        cout << res[i] << '\n';
}

int main(int argv, char** argc){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    open_file();
    solve();
}