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
const int maxN = 1e3 + 5;
const int MOD = 1e9 + 7;
const int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
const int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
ii Start;
int d[maxN][maxN];
int cnt[maxN][maxN];

bool inside(int x, int y){
    return (0 < x) && (x <= 8) && (0 < y) && (y <= 8);
}

void DFS(ii u, int K){
    d[u.X][u.Y] = K;
    for(int i = 0; i < 8; i++){
        int x = u.X + dx[i];
        int y = u.Y + dy[i];
        if (inside(x, y)) cnt[x][y]--;
    }

    if (K == 64){
        for(int i = 1; i <= 8; i++){
            for(int j = 1; j <= 8; j++)
                cout << d[i][j] << ' ';
            cout << '\n';
        }
        exit(0);
    }
    vector<ii> c;
    for(int i = 0; i < 8; i++){
        int x = u.X + dx[i];
        int y = u.Y + dy[i];
        if (inside(x, y) && d[x][y] == 0)
            c.push_back(ii(x, y));
    }

    sort(c.begin(), c.end(),[&](ii A, ii B){
        return cnt[A.X][A.Y] < cnt[B.X][B.Y];
    });

    for(int i = 0; i < c.size(); i++)
        DFS(c[i], K + 1);
    for(int i = 0; i < 8; i++){
        int x = u.X + dx[i];
        int y = u.Y + dy[i];
        if (inside(x, y)) cnt[x][y]++;
    }
    d[u.X][u.Y] = 0;
}

void solve(){
    cin >> Start.Y >> Start.X;
    for(int i = 1; i <= 8; i++)
    for(int j = 1; j <= 8; j++)
    for(int k = 0; k < 8; k++)
        cnt[i][j]  += inside(i + dx[k], j + dy[k]);
    // for(int i = 1; i <= 8; i++){
    //     for(int j = 1; j <= 8; j++)
    //         cout << cnt[i][j] << ' ';
    //     cout << '\n';
    // }
    DFS(Start, 1);
}

int main(int argv, char** argc){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    open_file();
    solve();
}