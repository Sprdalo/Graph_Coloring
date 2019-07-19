#include <bits/stdc++.h>

using namespace std;

#define int ll
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<double> vd;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<pi> vp;
typedef vector<pl> vpl;

vi e[200000], dis(200000), col(200000);
vb vis(200000);

void dfs(int x = 1, int d = 0){
    
    vis[x] = 1;
    dis[x] = d;

    for (auto& i : e[x]){
        if (vis[i]) continue;

        dfs(i, d + 1);
    }
}

signed main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr); 
    cout.tie(nullptr); 
    cerr.tie(nullptr);    

    int n;
    cin >> n;

    for (int i = 0; i < n - 1; ++i){
        int u, v;
        cin >> u >> v;

        e[u].push_back(v);
        e[v].push_back(u);
    }

    dfs();

    int c = 0;
    for (int i = 1; i <= n; ++i)
        if (dis[i] % 2) ++c;

    bool mark = (n - c > c);

    for (int i = 1; i <= n; ++i){
        if (dis[i] % 2 == mark) col[i] = 1;
    }

    for (int i = 1; i <= n; ++i)
        cout << col[i] << ' ';
    cout << '\n';
}
