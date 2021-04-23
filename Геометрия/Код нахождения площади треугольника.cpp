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
#define eps 1e-6
const double PI = M_PI;
const int INF = -1 * 1e9;
const ll limit = -1 * 1e16;
const int MOD1 = 1e9 + 711;
const int MOD2 = 1e9 + 933;
const int MOD3 = 1e9 + 993;

const int maxn = 1e6 + 100;


struct Point {
	double x, y;
	Point(double x0 = 0, double y0 = 0) {
		x = x0;
		y = y0;
	}
};
struct Vector {
	double x, y;
	Vector(Point A, Point B) {
		x = B.x - A.x;
		y = B.y - A.y;
	}
};
int main() {
	speed;
	Point A, B, C;
	cin >> A.x >> A.y;
	cin >> B.x >> B.y;
	cin >> C.x >> C.y;
	Vector ab(A, B);
	Vector bc(B, C);
	double ans = ab.x * bc.y - bc.x * ab.y;
	ans /= 2;
	cout << fixed << setprecision(5) << fabs(ans);
	cerr << "\n\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
	return 0;
}