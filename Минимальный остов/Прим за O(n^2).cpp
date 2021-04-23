//#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math") 
//#pragma GCC target("avx2")
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
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <climits>

using namespace std;
#define open_streams ifstream fin("unionday.in");ofstream fout("unionday.out")
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
//const double PI = M_PI;
const int INF = 1 * 1e9;
const ll limit = 1 * 1e18;
const int mod = 1e9 + 7;
const int MOD = 1e9 + 711;
const int MOD2 = 1e9 + 933;
const int MOD3 = 1e9 + 993;
//---------------------------------------------------------------------------
const int maxn = 1e6 + 0;




int x[5001], y[5001];
bool used[5001];
double dist(int l, int r) {
	double xx = x[r] - x[l], yy = y[r] - y[l];
	return sqrt(xx*xx + yy * yy);
}
int main() {
	speed;
	open_streams;
	int n;
	fin >> n;
	for (int i = 1; i <= n; ++i) {
		fin >> x[i] >> y[i];
	}
	vector<double> mi(n + 1, INF);
	for (int i = 2; i <= n; ++i) {
		mi[i] = dist(1, i);
	}
	used[1] = true;
	double ans = 0;
	for (int t = 1; t <= n; ++t) {
		int v = -1;
		double d = INF;
		for (int i = 1; i <= n; ++i) {
			if (!used[i] && mi[i] < d) {
				v = i;
				d = mi[i];
			}
		}
		if (v == -1) {
			break;
		}
		used[v] = true;
		ans += d;
		for (int i = 1; i <= n; ++i) {
			if (!used[i]) {
				mi[i] = min(mi[i], dist(v, i));
			}
		}
	}
	fout << fixed << setprecision(10)<<ans;
	close_streams;
	cerr << "\n\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
	return 0;
}