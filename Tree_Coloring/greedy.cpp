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

set<int> e[1000];
set<pi> a;
vb l(1000, 0);
vi d(1000, 0);
vb vis(1000, 0);

void obrisi(int x){
	a.erase({-d[x], x});

	if (l[x]){
		int y = *e[x].begin();
		e[y].erase(x);

		a.erase({-d[y], y});
		--d[y];
		a.insert({-d[y], y});

		e[y].erase(x);
	} else {
		for (auto& i : e[x]){
			e[i].erase(x);
			int len = e[i].size();

			if (len == 1){
				int y = *e[i].begin();

				a.erase({-d[y], y});
				++d[y];
				a.insert({-d[y], y});
			}
		}
	}

	e[x].clear();
}

void ispisi(int n){
	for (int i = 1; i <= n; ++i){
		cout << "ZA " << i << ": ";

		for (auto& j : e[i])
			cout << j << ' ';
		cout << '\n';
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

		e[u].insert(v);
		e[v].insert(u);
	}

	for (int i = 1; i <= n; ++i){
		int tmp = e[i].size();

		if (tmp == 1)
			l[i] = 1;
		else 
			continue;

		for (auto& j : e[i]){
			++d[j];
		}
	}

	for (int i = 1; i <= n; ++i){
		a.insert({-d[i], i});
	}

	int cnt = 0;
	while(cnt != n){
		int x = (*a.begin()).second;
		stack<int> q;
		q.push(x);

		for (auto& i : e[x]){
			int len = e[i].size();

			if (len <= 2)
				q.push(i);
		}

		vis[x] = 1;
		while(!q.empty()){
			int y = q.top();
			q.pop();

			obrisi(y);
			++cnt;
		}
	}

	for (int i = 1; i <= n; ++i)
		if (vis[i])
			cout << i << ' ';
	cout << '\n';
}
