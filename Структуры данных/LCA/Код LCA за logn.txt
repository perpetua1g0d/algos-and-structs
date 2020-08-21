const int maxn = 5e5 + 100;
vector<vector<int>> g(maxn, vector<int>()); // дерево
vector<vector<int>>up(maxn, vector<int>(31)); // массив для бинапов
vector<int> tin(maxn), tout(maxn); // tin[v] - время, когда зашли в вершину, tout[v] - когда вышли
int timer = 0;
vector<bool> used(maxn);


void dfs(int v, int p) {
	up[v][0] = p; // вершина, до которой расстояние 2^0 - всегда наш предок
	used[v] = true;
	tin[v] = timer++;
	for (int i = 1; i <= 30; ++i) {
		up[v][i] = up[up[v][i - 1]][i - 1]; // заходим в предка на расстоянии 2^(i-1) от нас, и от него находим предка на таком же расст.
	}
	for (auto &to : g[v]) {
		if (!used[to]) {
			dfs(to, v);
		}
	}
	tout[v] = timer++;
}

bool ispar(int v, int u) {   // является ли уже одна из веришин предком
	if (tin[v] <= tin[u] && tout[v] >= tout[u]) {  // можно порисовать, чтобы убедиться в этом
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
		if (!ispar(up[v][i], u)) {    // сначала смотрим картинку с LCA в этой папке
			v = up[v][i];         // и потом двоичными подъемами идем в последний ноль
		}
	}
	return up[v][0];  // таким образом, LCA является предком вершины v.
}

// строим дерево
// кстати, если в запросах нет удаления вершин, то можно решить задачу в оффлайне

// Находим константу, которая всегда будет больше на 1 от логарифма вершин.
// Например, пусть будет 31

for (int i = 1; i <= 30; ++i) {
		up[1][i] = 1;
	}
}

// вызываем dfs от корня дерева
dfs(root,root)

// отвечаем на запросы lca(v,u).