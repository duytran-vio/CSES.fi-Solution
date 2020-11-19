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
vector<int> a[maxN],ra[maxN];
int d[maxN], TP[maxN], nTP, Used[maxN], trace[maxN], pos[maxN], L[maxN], R[maxN], csize[maxN];
int order;
void DFS(int u, int root){
    L[u] = ++order;
    TP[u] = nTP;
    trace[u] = root;
    for(int v : ra[u]){
        d[v] = d[u] + 1;
        DFS(v, root);
    }
    R[u] = order;
}

void solve(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        a[i].push_back(x);
        ra[x].push_back(i);
    }

    for(int i = 1; i <= n; i++){
        if (TP[i]) continue;
        nTP++;
        int u = i;
        while(Used[u] == 0){
            Used[u] = 1;
            u = a[u][0];
        }

        vector<int> c;
        int k = 0;
        while(trace[u] == 0){
            c.push_back(u);
            trace[u] = u;
            TP[u] = nTP;
            pos[u] = k;
            u = a[u][0];
            k++;
        }

        for(int u : c){
            csize[u] = c.size();
            for(int v : ra[u]){
                if (trace[v] == 0){
                    d[v] = 1;
                    DFS(v, u);
                }
            }
        }
    }

    for(int i = 1; i <= n; i++){

        int res;
        int e = trace[i];
        res = d[i] + csize[e];
        cout << res << ' ';
    }
}

int main(int argv, char** argc){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    open_file();
    solve();
}