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
const ll limit = 1 * 1e15;
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
double get_len(double x, double y) {
	return sqrt(x*x + y * y);
}

int main() {
	speed;
	// даны 3 три точки:
	Point A, B, C;
	cin >> A.x >> A.y; 
	cin >> B.x >> B.y; 
	cin >> C.x >> C.y;
	// АВ И АС - вектора:
	Vector AB(A, B), AC(A, C);
	// требуется найти угол между ними.
	// Находим скаляр по формуле без косинуса:
	// (a,b) = a[x]*b[x] + a[y]*b[y]
	// структура вектор уже нашла их x и y
	double dot_product = AB.x * AC.x + AB.y * AC.y;
	double Cos = dot_product / (get_len(AB.x, AB.y) * get_len(AC.x, AC.y));
	double angle = acos(Cos);
	cout << Cos;
	cerr << "\n\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
	return 0;
}