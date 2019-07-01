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

vi e[3000], boje(3000, 0), d(3000, 0), leaf;
vb vis(3000, 0);
int sol = INT32_MAX;

void cl(){
	for (auto& i : d) i = 0;
	for (int i = 0; i < 3000; ++i) vis[i] = 0;
}

void dfs(int x){
	vis[x] = 1;

	int l = e[x].size();
	if (l == 1)
		leaf.push_back(x);

	for (auto& i : e[x]){
		if (vis[i]) continue;

		d[i] = d[x] + 1;
		dfs(i);
	}
}

bool valid(vi b){
	bool ok = 1;
	for (auto& i : leaf){
		if (b[i]) continue;

		if (b[e[i][0]]) continue;
		ok = 0;
	}

	return ok;
}

void solve(int root, int n){
	vi b(3000, 0);
	cl();

	dfs(root);

	for (int k = 0; k < 3; ++k){
	
		for (auto& i : b) i = 0;
		int res = 0;
		for (int i = 1; i <= n; ++i){
			if (d[i] % 3 == k){
				b[i] = (d[i] % 2) + 1;
				++res;
			}
		}

		if (valid(b) && res < sol){
			sol = res;
			boje = b;
		}
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

	for (int i = 1; i <= n; ++i){
		solve(i, n);
	}

	cout << sol << '\n';
	for (int i = 1; i <= n; ++i)
		cout << boje[i] << ' ';
	cout << '\n';
}
