#include <bits/stdc++.h>
using namespace std;

void open_file(){
    #ifdef INOUT
        freopen("OB.inp", "r", stdin);
        freopen("OB.out", "w", stdout);
    #endif
}

struct Node{
    int val, pos;
    Node(){};
    Node(int x, int y){
        val = x;
        pos = y;
    }
};

const   int maxN = 2 * 1e5 + 5;
int IT[maxN * 4];


void update(int k, int l, int r, int u, int x){
    if (u < l || u > r) return;
    if (l == r) {
        IT[k] = x;
        return;
    }

    int mid = (l + r) / 2;
    update(k * 2, l, mid, u, x);
    update(k * 2 + 1, mid + 1, r, u, x);

    IT[k] = IT[k * 2] + IT[k * 2 + 1];
}

int get(int k, int l, int r, int x){
    // cout << l << " " << r << '\n';
    if (IT[k] < x) return -1;
    if (l == r) return l;
    int mid = (l + r) / 2;
    if (IT[k * 2] >= x) return get(k * 2, l, mid, x);
    return get(k * 2 + 1, mid + 1, r, x - IT[k * 2]); 
}

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        update(1, 0, n - 1, i, 1);
    }
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        int k = get(1, 0, n - 1, x);
        cout << a[k] << ' ';
        update(1, 0, n - 1, k, 0);
    }
}

int main(int argv, char** argc){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    open_file();
    solve();
}