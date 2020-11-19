#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
typedef pair<int, int> ii;
typedef pair<int, ii> i2;

const int maxN = 1e5 + 5;
const long long INF_LL = 1e15;
const int MOD = 1e9 + 7;
vector<int> a[maxN];
int Low[maxN], Num[maxN], K, TP[maxN], nTP, s, t;
stack<int> st;

void DFS(int u){
    Num[u] = Low[u] = ++K;
    st.push(u);
    for(int v : a[u]){
        if (TP[v] == 0){
            if (Num[v] == 0){
                DFS(v);
                Low[u] = min(Low[u], Low[v]);
            }
            else
                Low[u] = min(Low[u], Num[v]);
        }
    }

    if (Num[u] == Low[u]){
        nTP++;
        int v;
        if (s == 0) s = u;
        else t = u;
        do{
            v = st.top();
            st.pop();
            TP[v] = nTP;
        }
        while (v != u);
    }
}

void solve(){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
    }

    for(int i = 1; i <= n; i++)
        if (Num[i] == 0){
            DFS(i);
        }
    cout << nTP << '\n';
    for(int i = 1; i <= n; i++)
        cout << TP[i] << " ";
}

int main(){
//    freopen("OB.inp", "r", stdin);
//    freopen("OB.out", "w", stdout);
    solve();
}

