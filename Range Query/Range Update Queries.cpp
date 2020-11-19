#include <bits/stdc++.h>
using namespace std;

void open_file(){
    #ifdef INOUT
        freopen("OB.inp", "r", stdin);
        freopen("OB.out", "w", stdout);
    #endif
}

struct Node{
    long long val, lazy;
    Node(){};
    Node(long long x, long long y){
        val = x;
        lazy = y;
    }
};

const    int maxN = 2 * 1e5 + 5;
Node IT[maxN * 4];

void down(int k, int l, int r){
    if (IT[k].lazy == 0) return;
    long long t =  IT[k].lazy;
    IT[k].val += t;
    IT[k].lazy = 0;
    if (l != r){
        IT[k * 2].lazy += t;
        IT[k * 2 + 1].lazy += t;
    }
}

void update(int k, int l, int r, int u, int v, int x){
    down(k, l, r);
    if (v < l || u > r) return;
    if (u <= l && r <= v) {
        IT[k].lazy += x;
        down(k, l, r);
        return ;
    }

    int mid = (l + r) / 2;
    update(k * 2, l, mid, u, v, x);
    update(k * 2 + 1, mid + 1, r, u, v, x);
}

long long get(int k, int l, int r, int u){
    down(k, l, r);
    if (u < l || u > r) return 0;
    if (l == r) return IT[k].val;
    int mid = (l + r) / 2;
    long long L = get(k * 2, l, mid, u);
    long long R = get(k * 2 + 1, mid + 1, r, u);
    return max(L, R);
}

void solve(){
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        update(1, 0, n - 1, i, i, a[i]);
    }
    for(int i = 0; i < q; i++){
        int k;
        cin >> k;
        if (k == 1){
            int l, r, x;
            cin >> l >> r >> x;
            l--;r--;
            update(1, 0, n - 1, l, r, x);
        }
        else {
            int x;
            cin >> x;
            x--;
            cout << get(1, 0, n - 1, x) << '\n';
        }
    }
}

int main(int argv, char** argc){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    open_file();
    solve();
}