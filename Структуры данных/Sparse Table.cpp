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
#define open_streams ifstream fin("longpath.in");ofstream fout("longpath.out")
#define close_streams fin.close();fout.close()
#define speed cout.tie(0);cin.tie(0);ios_base::sync_with_stdio(0)
#define pus system("pause");
#define ll long long
#define ull unsigned long long
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define mp(a,b) make_pair(a,b)
#define eps 1e-9
const double PI = M_PI;
const int INF = 1 * 1e9;
const ll limit = 1 * 1e16;
const int MOD1 = 1e9 + 711;
const int MOD2 = 1e9 + 933;
const int MOD3 = 1e9 + 993;
const int maxn = 1e6 + 100;

int n;
void build_sparse(vector<vector<int>> &sp,vector<int> &a) {
	for (int i = 0; i < n; ++i) {
		sp[0][i] = a[i];
	}
	for (int i = 1; (1 << i) <= n; ++i) {
		for (int j = 0; j + (1 << i) <= n; ++j) {
			sp[i][j] = min(sp[i - 1][j], sp[i - 1][j + (1 << i)/2]);
		}
	}
}
void build_log(map<int, int> &p) {
	for (int i = 0; i <= 30; ++i) {
		int k = (1 << i);
		p[k] = i;
	}
}
int get_log(map<int, int> &p, int k) {
	return p.upper_bound(k)->second - 1;
}
int main() {
	speed;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	vector<vector<int>> sp(20, vector<int>(n));
	map<int, int> p;
	build_log(p);
	build_sparse(sp, a);
	int q;
	cin >> q;
	while (q--) {
		int l, r;
		cin >> l >> r;
		int Log = get_log(p, r - l + 1);
		int mi1 = sp[Log][l];
		int mi2 = sp[Log][r - (1 << Log) + 1];
		cout << min(mi1, mi2) << '\n';
	}
	cerr << "\n\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
	return 0;
}