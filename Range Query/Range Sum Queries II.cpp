#include <bits/stdc++.h>
using namespace std;

void open_file(){
    #ifdef INOUT
        freopen("OB.inp", "r", stdin);
        freopen("OB.out", "w", stdout);
    #endif
}

const int maxN = 2 * 1e5 + 5;
long long IT[maxN * 4];

void update(int k, int l, int r, int u, int val){
    if (u < l || u > r) return;
    if (l == r) {
        IT[k] = val;
        return;
    }

    int mid = (l + r) / 2;
    update(k * 2, l, mid, u, val);
    update(k * 2 + 1, mid + 1, r, u, val);

    IT[k] = IT[k * 2] + IT[k * 2 + 1];
}

long long get(int k, int l, int r, int u, int v){
    if (v < l || u > r) return 0;
    if (u <= l && r <= v) return IT[k];
    int mid = (l + r) / 2;
    long long L = get(k * 2, l, mid, u, v);
    long long R = get(k * 2 + 1, mid + 1, r, u, v);
    return L + R; 
}

void solve(){
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        update(1, 0, n - 1, i, a[i]);
    }

    for(int i = 0; i < q; i++){
        int l, r, k;
        cin >> k >> l >> r;
        if (k == 1){
            l--;
            update(1, 0, n - 1, l, r);
        }
        else {
            l--;r--;
            cout << get(1, 0, n - 1, l, r) << '\n';
        }
    }
    
}

int main(int argc, char** argv){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

    open_file();
    solve();
}