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

signed main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr); 
    cout.tie(nullptr); 
    cerr.tie(nullptr);    

    int n;
    cin >> n;

    cout << n / 3 + min(n % 3, 1ll) << '\n';
    for (int i = 0; i < n; ++i){
        if (i % 3){
            cout << "0 ";
            continue;
        }

        if (i % 2)
            cout << "1 ";
        else
            cout << "2 ";
    }
    cout << '\n';
}
