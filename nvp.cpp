//#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math") 
///#pragma GCC target("avx2")
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
#define open_streams ifstream fin("olympiad.in");ofstream fout("olympiad.out")
#define close_streams fin.close();fout.close()
#define speed cout.tie(0);cin.tie(0);ios_base::sync_with_stdio(0)
#define ll long long
#define ull unsigned long long
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define mp(a,b) make_pair(a,b)
#define pb push_back
#define UNIQ(a) a.resize(unique(all(a)) - a.begin())
#define eps 1e-6
//const double PI = M_PI;
const int INF = INT_MAX;
const ll limit = 6LL * 1e18;
const int MOD = 1e9 + 711;
const int MOD2 = 1e9 + 933;
//---------------------------------------------------------------------------
const int mod = 1e9 + 7;
const int maxn = 1e4 + 100;



signed main() {
	speed;
	int n;
	cin >> n;
	vector<int> a(n), dp(n + 2,INF);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	dp[0] = -INF;
	for (int i = 0; i < n; ++i) {
		int pos = upper_bound(all(dp), a[i]) - dp.begin();
		if (dp[pos] == INF) {
			dp[pos] = a[i];
		}
		else {
			if (dp[pos + 1] == INF && (dp[pos] > a[i])) {
				dp[pos] = a[i];
			}
		}
	}
	int ans = n;
	for (int i = 1; i <= n; ++i) {
		if (dp[i] == INF) {
			break;
		}
		else {
			ans = n - i;
		}
	}
	cout << ans;
	return 0;
}
