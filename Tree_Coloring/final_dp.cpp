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

int n;
vi e[2000], p(2000), g[2000];
queue<int> q;
vb vis(2000);

bool done(int x){
	for (auto& i : e[x])
		if (!vis[i]) return 0;
	return 1;
}

struct dpr{
	int x; //1
	int y; //0

	bitset<100> b1, b0;
};

dpr dp[2000];

bool ok(int x){
	bool k = 0;
	for (auto& i : e[x]){
		k |= dp[x].b0[i];
	}

	return k;
}

vb seen(2000);
void dfs(int x){
	seen[x] = 1;

	for (auto& i : g[x]){
		if (seen[i]){
			continue;
		}

		e[x].push_back(i);
		p[i] = x;
		dfs(i);
	}
}

signed main()
{
	ios_base::sync_with_stdio(false); 
	cin.tie(nullptr); 
	cout.tie(nullptr); 
	cerr.tie(nullptr);	

	cin >> n;

	for (int i = 0; i < n - 1; ++i){
		int u, v;
		cin >> u >> v;

		g[u].push_back(v);
		g[v].push_back(u);
	}

	int root = 1;
	dfs(root);

	for (int i = 1; i <= n; ++i){
		int l = e[i].size();

		if (l == 0) q.push(i);
	}

	int cnt = 0;
	while (!q.empty()){
		++cnt;

		if (cnt == n){
			break;
		}

		int x = q.front(), l = e[x].size();
		q.pop();
		vis[x] = 1;

		if (l == 0){

			dp[x].x = 1;
			dp[x].y = 0;

			if (done(p[x]))
				q.push(p[x]);

			dp[x].b1[x] = 1;
			dp[x].b0[x] = 0;

			continue;
		}

		//Ako ga bojimo
		dp[x].x = 1;
		dp[x].b1[x] = 1;
		for (auto& i : e[x]){
			int a = dp[i].x, b = dp[i].y;

			if (a > b){
				dp[x].x += b;
				dp[x].b1 |= dp[i].b0;
			} else {
				dp[x].x += a;
				   dp[x].b1 |= dp[i].b1;
			}
		}

		//Ako ga ne bojimo
		dp[x].y = 0;
		dp[x].b0 = 0;
		for (auto& i : e[x]){
			int a = dp[i].x, b = dp[i].y;

			//Ako je svejedno optimalno da mu uzmem klinca
			if (a <= b){
				dp[x].y += a;
				dp[x].b0 |= dp[i].b1;
				continue;
			}

			//Ako mi se bas uzima njegov klinac
			if (a > b){	//Nepotreban if ali zbog infrastruktue :)
				if (ok(i)){
					dp[x].y += b;
					dp[x].b0 |= dp[i].b0;
				} else {
					dp[x].y += a;
					dp[x].b0 |= dp[i].b1;
				}
			}
		}

		if (done(p[x])) q.push(p[x]);
	}

	int sol = 0;
	bool mark = 0;
	bitset<100> k = 0;
	for (auto& i : e[root]){
		int a = dp[i].x, b = dp[i].y;

		if (a <= b){
			mark = 1;
			sol += a;
			k |= dp[i].b1;
		} else {
			sol += b;
			k |= dp[i].b0;
		}
	}

	if (!mark){
		++sol;
		k[root] = 1;
	} 

	cout << sol << '\n';
}
