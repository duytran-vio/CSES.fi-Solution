#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
typedef pair<int, int> ii;

const int maxN = 6e5 + 5;

struct Query{
    int k, X, Y;
    Query(){};
    Query(int _k, int _X, int _Y) : k(_k), X(_X), Y(_Y) {};
};

int IT[maxN * 4];

void update(int k, int l, int r, int i, int val){
    if (i < l || i > r) return;
    if (l == r) {
        IT[k] += val;
        return;
    }
    int mid = (l + r) / 2;
    update(k * 2, l, mid, i, val);
    update(k * 2 + 1, mid + 1, r, i, val);
    IT[k]  = IT[k * 2] + IT[k * 2 + 1];
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
    vector<int> a(n);
    vector<int> c;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        c.push_back(a[i]);
    }
    vector<Query> q(m);
    for(int i = 0; i < m; i++){
        char ch;
        int x, y, k;
        cin >> ch >> x >> y;
        if (ch == '!') {
            q[i] = Query(0, x, y);
            c.push_back(y);
        }
        else {
            q[i] = Query(1, x, y);
            c.push_back(x);
            c.push_back(y);
        }
    }
    sort(c.begin(), c.end());
    c.resize(unique(c.begin(), c.end()) - c.begin());

    int p = c.size();
    for(int i = 0; i < n; i++){
        a[i] = lower_bound(c.begin(), c.end(), a[i]) - c.begin();
        update(1, 0, p, a[i], 1);
    }
    for(int i = 0; i < m; i++){
        if (q[i].k == 0)
            q[i].Y = lower_bound(c.begin(), c.end(), q[i].Y) - c.begin();
        else {
            q[i].X = lower_bound(c.begin(), c.end(), q[i].X) - c.begin();
            q[i].Y = lower_bound(c.begin(), c.end(), q[i].Y) - c.begin();
        }
    }

    for(int i = 0; i < m; i++){
        int k = q[i].k, x = q[i].X, y = q[i].Y;
        if (k == 0){
            x--;
            update(1, 0, p, a[x], -1);
            update(1, 0, p, y, 1);
            a[x] = y;
        }
        else {
            int res = get(1, 0, p, x, y);
            cout << res << '\n';
        }
    }
}


int main(){
//    freopen("OB.inp", "r", stdin);
//    freopen("OB.out", "w", stdout);
    solve();
}

