//#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector") 
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define _CRT_SECURE_NO_WARNINGS // - for VisualStudio: do not disturb about warnings
#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <fstream>
#include <cmath>
#include <deque>
#include <list>
#include <stack>
#include <queue>
#include <iomanip>
#include <cassert>
#include <functional>
#include <ctime>

using namespace std;
#define open_streams ifstream fin("ladder.in");ofstream fout("ladder.out")
#define close_streams fin.close();fout.close()
#define speed cout.tie(0);cin.tie(0);ios_base::sync_with_stdio(0)
#define pus system("pause");
#define ll long long
#define ull unsigned long long
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define mp(a,b) make_pair(a,b)
#define pb(X) push_back(X)
#define eps 1e-9
const double PI = M_PI;
const int INF = 1 * 1e9;
const ll limit = 1 * 1e12;
const int MOD1 = 1e9 + 711;
const int MOD2 = 1e9 + 933;
const int MOD3 = 1e9 + 993;

const int maxn = 1e6 + 100;


int main() {
	speed;
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	int sq = sqrt(n + .0);
	++sq;
	vector<int> d(sq);
	for (int i = 0; i < n; ++i) {
		int dev = i / sq;
		d[dev] = max(d[dev], a[i]);
	}
	int q;
	cin >> q;
	while (q--) {
		int l, r;
		cin >> l >> r;
		--l;
		--r;
		int mx = a[l];
		for (int i = l; i <= r; ++i) {
			mx = max(mx, a[i]);
			if (i%sq == 0 && (i + sq <= r)) {
				mx = max(mx, d[i / sq]);
				i += sq - 1;
			}
		}
		cout << mx << ' ';
	}
	cerr << "\n\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
	return 0;
}