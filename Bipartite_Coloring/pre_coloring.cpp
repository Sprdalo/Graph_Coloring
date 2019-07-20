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

vi e[2000];

signed main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr); 
    cout.tie(nullptr); 
    cerr.tie(nullptr);    

    int n1, n2, m, k;
    cin >> n1 >> n2 >> m >> k;

    int n = n1 + n2;
    for (int i = 0; i < m; ++i){
        int u, v;
        cin >> u >> v;

        e[u].push_back(v);
        e[v].push_back(u);
    }

    vp a;
    for (int i = 1; i <= n; ++i){
        int l = e[i].size();

        a.push_back({l, i});
    }    

    sort(a.begin(), a.end());

    for (auto& i : a)
        cout << i.second << ' ';
    cout << '\n';

    sort(a.rbegin(), a.rend());
    
    for (auto& i : a)
        cout << i.second << ' ';
    cout << '\n';
}
