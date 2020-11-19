#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
typedef pair<int, int> ii;
typedef pair<int, ii> i2;

const int maxN = 2e5 + 5;
const long long INF_LL = 1e15;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 100;

struct Node{
    long long L, R, val, sum;
    Node(){};
    Node(long long _L, long long _R, long long _val, long long _sum){
        L = _L;
        R = _R;
        val = _val;
        sum = _sum;
    }
};

Node IT[maxN * 4];

Node Merge(Node A, Node B){
    Node res;
    res.L = max(A.L, A.sum + B.L);
    res.R = max(B.R, B.sum + A.R);
    res.sum = A.sum + B.sum;
    res.val = max(A.val, max(B.val, A.R + B.L));
    return res;
}

void update(int k, int l, int r, int u, int x){
    if (u < l || u > r) return;
    if (l == r) {
        IT[k] = Node(x, x, x, x);
        return;
    }
    int mid = (l + r) / 2;
    update(k * 2, l, mid, u, x);
    update(k * 2 + 1, mid + 1, r, u, x);
    IT[k] = Merge(IT[k * 2], IT[k * 2 + 1]);
}

void solve(){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        update(1, 0, n - 1, i, x);
    }
    while (m--){
        int i, x;
        cin >> i >> x;
        i--;
        update(1, 0, n - 1, i, x);
        cout << max(IT[1].val, 0LL) << '\n';
    }
}


int main(){
//    freopen("OB.inp", "r", stdin);
//    freopen("OB.out", "w", stdout);
    solve();
}

