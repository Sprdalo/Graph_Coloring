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
 
vi e[200];
vector<vi> a, s;
vi mark(200, 0), c(200, 0);
 
void F(int k, int n)
{
    if (k > n)
    {
        vi tmp;
        for (int i = 1; i <= n; i++)
        {
            tmp.push_back(mark[i]);
        }
        a.push_back(tmp);
        return;
    }
    mark[k] = 0;
    F(k + 1, n);
    mark[k] = 1;
    F(k + 1, n);
    mark[k] = 2;
    F(k + 1, n);
}
 
bool ok(int n){
    for (int i = 1; i <= n; ++i){
            for (auto& j : e[i]){
                if (c[j] && c[i])
                    return 0;
            }
    }
 
    for (int i = 1; i <= n; ++i){
        for (auto& j : e[i]){
            int l1 = e[i].size(), l2 = e[j].size();
 
            //dva susedna prazna lista/koren
            if ((l1 == 1 || l2 == 1) && (!c[i] && !c[j])) return 0;
 
            for (auto& k : e[j]){
                if (k == i) continue;
                if (!c[i] && !c[j] && !c[k]) return 0;
 
                if (c[i] && c[k] && c[i] != c[k]) return 0;
 
                for (auto& l : e[k]){
                    if (l == j) continue;
 
                    if (!c[j] && !c[k] && !c[l]) return 0;
 
                    if (c[i] == c[l] && c[i]) return 0;
                }
            }
        }
    }
 
    return 1;
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
 
    F(1, n);
 
    for (auto& i : a){
        for (int j = 0; j < n; ++j){
            c[j + 1] = i[j];
        }
 
        if (ok(n)){
            s.push_back(i);
        }
    }
 
    int sol = INT32_MAX, cnt = 0;
    vi rez(2000, 0);
    for (auto& i : s){
        int t = 0;
        for (auto& j : i){
            if (c[j]) ++t;
        }
        rez[cnt++] = t;
 
        if (t < sol){
            sol = t;
        }
    }
 
    for (int i = 0; i < s.size(); ++i){
        if (rez[i] == sol){
            for (auto& j : s[i]){
                cout << j << ' ';
            }
            cout << '\n';
        }
    }
}
