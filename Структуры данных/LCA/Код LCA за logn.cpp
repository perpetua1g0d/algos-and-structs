const int maxn = 5e5 + 100;
vector<vector<int>> g(maxn, vector<int>()); // ������
vector<vector<int>>up(maxn, vector<int>(31)); // ������ ��� �������
vector<int> tin(maxn), tout(maxn); // tin[v] - �����, ����� ����� � �������, tout[v] - ����� �����
int timer = 0;
vector<bool> used(maxn);


void dfs(int v, int p) {
	up[v][0] = p; // �������, �� ������� ���������� 2^0 - ������ ��� ������
	used[v] = true;
	tin[v] = timer++;
	for (int i = 1; i <= 30; ++i) {
		up[v][i] = up[up[v][i - 1]][i - 1]; // ������� � ������ �� ���������� 2^(i-1) �� ���, � �� ���� ������� ������ �� ����� �� �����.
	}
	for (auto &to : g[v]) {
		if (!used[to]) {
			dfs(to, v);
		}
	}
	tout[v] = timer++;
}

bool ispar(int v, int u) {   // �������� �� ��� ���� �� ������� �������
	if (tin[v] <= tin[u] && tout[v] >= tout[u]) {  // ����� ����������, ����� ��������� � ����
		return true;
	}
	return false;
}

int lca(int v, int u) {
	if (ispar(v, u)) {
		return v;
	}
	if (ispar(u, v)) {
		return u;
	}
	for (int i = 30; i >= 0; --i) {
		if (!ispar(up[v][i], u)) {    // ������� ������� �������� � LCA � ���� �����
			v = up[v][i];         // � ����� ��������� ��������� ���� � ��������� ����
		}
	}
	return up[v][0];  // ����� �������, LCA �������� ������� ������� v.
}

// ������ ������
// ������, ���� � �������� ��� �������� ������, �� ����� ������ ������ � ��������

// ������� ���������, ������� ������ ����� ������ �� 1 �� ��������� ������.
// ��������, ����� ����� 31

for (int i = 1; i <= 30; ++i) {
		up[1][i] = 1;
	}
}

// �������� dfs �� ����� ������
dfs(root,root)

// �������� �� ������� lca(v,u).