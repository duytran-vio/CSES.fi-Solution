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
vector<ii> a[maxN];
int h[maxN], d[maxN];
vector<int> st;

void DFS(int u){
    for(int &i = h[u]; i < a[u].size(); i++){
        int v = a[u][i].X;
        int cost = a[u][i].Y;
        if (d[cost] == 0){
            d[cost] = 1;
            DFS(v);
            st.push_back(cost);
        }
    }
}

void solve(){
    int n;
    cin >> n;
    for(int i = 0; i < (1 << n); i++){
        int u = i >> 1;
        int v = i &  ((1 << (n - 1)) - 1);
        // cout << i << " " << u << " " << v << '\n';
        a[u].push_back({v, i});
    }

    DFS(0);
    reverse(st.begin(), st.end());
    // for(int i = 0; i < st.size(); i++)
    //     cout << st[i] << '\n';
    string s = "";
    for(int i = 0; i < n; i++) 
        s += '0';
    for(int i = 1; i < st.size(); i++)
        s += (st[i] % 2 == 1) ? ('1') : ('0');
    cout << s;
}

int main(int argv, char** argc){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    open_file();
    solve();
}