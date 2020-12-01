//#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector") 
////#pragma GCC target("sse,sse2,sse3,ssse3,sse4") // RE
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
#define open_streams ifstream fin("brackets.in");ofstream fout("brackets.out")
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
const ll limit = 1 * 1e12;
const int mod = 1e9 + 9;
const int MOD = 1e9 + 711;
const int MOD2 = 1e9 + 933;
const int MOD3 = 1e9 + 993;
//---------------------------------------------------------------------------
const int maxn = 5e5 + 10;




struct node {
	int key, prior, size;
	node *left, *right;
	node(int n_key = 0) {
		left = nullptr;
		right = nullptr;
		size = 1;
		key = n_key;
		prior = ((rand() << 15) | rand());
	}
};
int size(node *root) {
	if (root == nullptr) {
		return 0;
	}
	return root->size;
}
void upd(node *root) {
	if (root == nullptr) {
		return;
	}
	root->size = size(root->left) + size(root->right) + 1;
}
node *merge(node *root1, node *root2) {
	if (root1 == nullptr) {
		return root2;
	}
	if (root2 == nullptr) {
		return root1;
	}
	if (root1->prior < root2->prior) {
		root1->right = merge(root1->right, root2);
		upd(root1);
		return root1;
	}
	else {
		root2->left = merge(root1, root2->left);
		upd(root2);
		return root2;
	}
}
pair<node*, node*> split(node *root, int k) {
	if (root == nullptr) {
		return { nullptr,nullptr };
	}
	if (root->key < k) {
		auto p = split(root->right, k);
		root->right = p.first;
		upd(root);
		return { root,p.second };
	}
	else {
		auto p = split(root->left, k);
		root->left = p.second;
		upd(root);
		return { p.first,root };
	}
}
pair<node*, node*> split_size(node*root, int k) {
	if (root == nullptr) {
		return mp(nullptr, nullptr);
	}
	if (size(root->left) >= k) {
		auto p = split_size(root->left, k);
		root->left = p.second;
		upd(root);
		return mp(p.first, root);
	}
	else {
		auto p = split_size(root->right, k - size(root->left) - 1);
		root->right = p.first;
		upd(root);
		return { root,p.second };
	}
}
node *insert(node *root, node *v) {
	if (root == nullptr) {
		return v;
	}
	if (v == nullptr) {
		return root;
	}
	if (v->prior < root->prior) {
		auto p = split(root, v->key);
		v->left = p.first;
		v->right = p.second;
		upd(v);
		return v;
	}
	if (v->key < root->key) {
		root->left = insert(root->left, v);
	}
	else {
		root->right = insert(root->right, v);
	}
	upd(root);
	return root;
}
bool find(node *root, int key) {
	if (root == nullptr) {
		return false;
	}
	if (root->key == key) {
		return key;
	}
	if (key < root->key) {
		return find(root->left, key);
	}
	else {
		return find(root->right, key);
	}
}
int find_kth(node *root, int id) {
	if (root == nullptr) {
		return -INF;
	}
	if (size(root->left) == id) {
		return root->key;
	}
	if (size(root->left) > id) {
		return find_kth(root->left, id);
	}
	return find_kth(root->right, id - size(root->left) - 1);
}
int find_id(node *root, int key) {
	if (root == nullptr) {
		return 0;
	}
	if (root->key == key) {
		return size(root->left);
	}
	if (key < root->key) {
		return find_id(root->left, key);
	}
	else {
		return find_id(root->right, key) + size(root->left) + 1;
	}
}
node *erase(node *root, int key) {
	if (root == nullptr) {
		return root;
	}
	if (root->key == key) {
		return merge(root->left, root->right);
	}
	if (key < root->key) {
		root->left = erase(root->left, key);
	}
	else {
		root->right = erase(root->right, key);
	}
	upd(root);
	return root;
}
node *root = nullptr;
void write(node *root) {
	if (root == nullptr) {
		return;
	}
	write(root->left);
	cout << root->key << ' ';
	write(root->right);
}
mt19937 mersenne(static_cast<unsigned int>(time(0)));
int main() {
	speed;
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		if (s == "add") {
			int key;
			cin >> key;
			node *v = new node(key);
			root = insert(root, v);
		}
		if (s == "erase") {
			int key;
			cin >> key;
			root = erase(root, key);
		}
		if (s == "write") {
			write(root);
			cout << '\n';
		}
		if (s == "kth") {
			int id;
			cin >> id;
			cout << find_kth(root, id) << '\n';
		}
		if (s == "id") {
			int key;
			cin >> key;
			cout << find_id(root, key) << '\n';
		}
	}
	cerr << "\n\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
	return 0;
}
