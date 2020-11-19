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
vector<int> a[maxN];
int n, m, cost[maxN], Num[maxN], Low[maxN], K, TP[maxN], nTP, indeg[maxN];
long long p[maxN], f[maxN];
stack<int> st;

void DFS(int u){
    Low[u] = Num[u] = ++K;
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
        do{
            v = st.top();
            st.pop();
            TP[v] = nTP;
            p[nTP] += cost[v];
        }
        while (v != u);
    }
}

vector<ii> canh;

void solve(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> cost[i];
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
        canh.push_back({x, y});
    }

    for(int i = 1; i <= n; i++)
        if (Num[i] == 0)
            DFS(i);
    for(int i = 1; i <= n; i++)
        a[i].clear();
    for(int i = 0; i < m; i++){
        int s = TP[canh[i].X];
        int t = TP[canh[i].Y];
        if (s != t){
            a[s].push_back(t);
            indeg[t]++;
        }
    }

    queue<int> que;
    for(int i = 1; i <= nTP; i++)
        if (indeg[i] == 0)
            que.push(i);
    
    long long res = 0;

    while(!que.empty()){
        int u = que.front();
        que.pop();
        f[u] += p[u];
        res = max(res, f[u]);
        for(int v : a[u]){
            f[v] = max(f[v], f[u]);
            
            if (--indeg[v] == 0){
                que.push(v);
            }
        }
    }

    cout << res;
}

int main(int argv, char** argc){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    open_file();
    solve();
}