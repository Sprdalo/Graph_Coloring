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

vi e[200], a, b;
vb vis(200);

void dfs(int x, int d){
    vis[x] = 1;

    if (d)
        a.push_back(x);
    else
        b.push_back(x);

    for (auto& i : e[x]){
        if (vis[i]) continue;

        dfs(i, (d + 1) % 2);
    }
}

const int MAX_N = 30;

bool mark[MAX_N + 1];
vector<vi> ar;

void F(int k, int n){
    if (k > n){
        vi tmp;
        for (int i = 1; i <= n; i++){
            tmp.push_back(mark[i]);
        }
        ar.push_back(tmp);
        return;
    }
    mark[k] = false;
    F(k + 1, n);
    mark[k] = true;
    F(k + 1, n);
}


signed main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr); 
    cout.tie(nullptr); 
    cerr.tie(nullptr);    

    int n, m;
    cin >> n >> m;

    F(1, n);

    for (int i = 0; i < m; ++i){
        int u, v;
        cin >> u >> v;

        e[u].push_back(v);
        e[v].push_back(u);
    }

    dfs(1, 1);
    
    int sol = INT32_MAX;
    vi res;
    vector<vi> k;
    for (auto& c : ar){
        vi t;
        
        for (int i = 0; i < n; ++i){
            if (c[i])
                t.push_back(i + 1);
        }   

        vb v(200, 0);
        for (auto& x : t){
            v[x] = 1;

            for (auto& i : e[x])
                v[i] = 1;
        }

        bool ok = 1;
        for (int i = 1; i <= n; ++i){
            if (!v[i]){
                ok = 0;
                break;
            }
        }

        if (!ok) continue;

        k.push_back(t);
        int x = t.size();
        if (sol > x){
            sol = x;
        }
    }

    for (auto& t : k){
        int l = t.size();

        if (l == sol){
            for (auto& i : t)
                cout << i << ' ';
            cout << '\n';
        }
    }
}
