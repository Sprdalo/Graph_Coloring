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

int s; 
vi e[2000], a, c(2000);
vb vis(2000), seen(2000);

void dfs(int x){
    vis[x] = 1;
    a.push_back(x);

    int l = e[x].size();
    if (l == 1){
        s = x;
    }

    for (auto& i : e[x]){
        if (!vis[i]) dfs(i);
    }
}

void init(){
    a.clear();
    s = 0;

    for (int i = 0; i < 2000; ++i)
        seen[i] = 0;
}

int put(){
    int sol = 0;

    vi g = {s};
    seen[s] = 1;
    int x = e[s][0];
    while(1){

        g.push_back(x);
        seen[x] = 1;

        int l = e[x].size();
        if (l == 1) break;

        for (auto& i : e[x])
            if (!seen[i]){
                x = i;
                break;
            }
    }

    int n = g.size();
    for (int i = 0; i < n; ++i){
        if (i % 3 == 1){
            c[g[i]] = (i % 2) + 1;
            ++sol;
        } else {
            c[g[i]] = 0;
        }
    }

    if (n % 3 == 1){
        ++sol;
        c[g[n - 1]] = (n % 2) + 1;
    }

    return sol;
}

//Pretpostavka da je ciklus parne duzine
int ciklus(){
    int sol = 0;

    vi g;
    int x = a[0];
    while(1){

        g.push_back(x);
        seen[x] = 1;

        int l = e[x].size();
        if (l == 1) break;

        bool ok = 0;
        for (auto& i : e[x])
            if (!seen[i]){
                x = i;
                ok = 1;
                break;
            }

        if (!ok) break;
    }       

    int n = g.size();
    for (int i = 0; i < n; ++i){
        if (i % 3){
            c[g[i]] = 0;
            continue;
        }

        c[g[i]] = (i % 2) + 1;
        ++sol;
    }

    return sol;
}

signed main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr); 
    cout.tie(nullptr); 
    cerr.tie(nullptr);    

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i){
        int u, v;
        cin >> u >> v;

        e[u].push_back(v);
        e[v].push_back(u);
    }

    int sol = 0;
    for (int i = 1; i <= n; ++i){
        if (vis[i]) continue;

        init();
        dfs(i);

        if (s){
            sol += put();
        } else {
            sol += ciklus();
        }
    }

    cout << sol << '\n';
    for (int i = 1; i <= n; ++i)
        cout << c[i] << ' ';
    cout << '\n';
}
