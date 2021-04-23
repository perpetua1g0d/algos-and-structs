
ПОСТРОЕНИЕ:

void build(vector<int> & a, vector < ll > & t, int l, int r, int v)
{
	if (l == r)
	{
		t[v] = a[l];
		return;
	}
	int m = l + (r - l) / 2;
	build(a, t, l, m, 2 * v + 1);
	build(a, t, m + 1, r, 2 * v + 2);
	t[v] = t[2 * v + 1] +  t[2 * v + 2];
}
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
ПОИСК МИНИМАЛЬНОГО ЭЛЕМЕНТА НА ОТРЕЗКЕ:

ll get_min(vector<ll> & t, int l, int r, int L, int R, int v)
{
	if (r < L || l > R)
	{
		return inf;
	}
	if (l >= L && r <= R)
	{
		return t[v];
	}
	int m = l + (r - l) / 2;
	return min( get_min(t, l, m, L, R, 2 * v + 1) , get_min(t, m + 1, r, L, R, 2 * v + 2) );
}
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
ИЗМЕНЕНИЕ ЭЛЕМЕНТА:

void change(vector<int> & a, vector<ll> & t, int pos, ll x,int v,int l, int r)
{
	if (l == r)
	{
		t[v] = x;
		return;
	}
	int m = l + (r - l) / 2;
	if (pos <= m)
	{
		change(a, t, pos, x, 2 * v + 1, l, m);
	}
	else
	{
		change(a, t, pos, x, 2 * v + 2, m + 1, r);
	}
	t[v] = min(t[2 * v + 1], t[2 * v + 2]);
}
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
ПОИСК К-ТОГО НУЛЯ:

int kth_zero(vector<int> &t, int l, int r, int v,int k) // поиск позиции к-того нуля
{
	if (k > t[v])
	{
		return -1;
	}
	if (l == r)
	{
		return l;
	}
	int m = l + (r - l) / 2;
	if (k <= t[v*2+1])
	{
		return get_pos(t, l, m, 2 * v + 1, k);
	}
	else
	{
		return get_pos(t, m + 1, r, 2 * v + 2, k - t[v * 2 + 1]);
	}
}
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
ПРИБАВЛЕНИЕ НА ОТРЕЗКЕ:

vector<ll> t(4*n),c(4*n);

void push(int v) {
	c[v * 2 + 1] += c[v];
	c[v * 2 + 2] += c[v];
	c[v] = 0;
}
void add_segm (int v,int l, int r,int ql,int qr,int val){
	if (l > qr || r < ql) {
		return;
	}
	if (l >= ql && r <= qr) {
		c[v] += val;
		return;
	}
	int m = l + (r - l) / 2;
	push(v);
	add_segm(2 * v + 1, l, m, ql, qr, val);
	add_segm(2 * v + 2, m+1, r, ql, qr, val); 
	t[v] = t[v * 2 + 1] + t[v * 2 + 2] + c[v * 2 + 1] * (m - l + 1) + c[v * 2 + 2] * (r - m);
	// Умножение на длину отрезков делается только для запросов суммы, для всех остальных запросов этого делать не нужно.
}
ll get_sum(int v, int l, int r, int ql, int qr) {
	if (l > qr || r < ql) {
		return 0;
	}
	if (l >= ql && r <= qr) {
		return t[v] + c[v] * (r - l + 1);
	}
	push(v);
	int m = l + (r - l) / 2;
	ll res = get_sum(2 * v + 1, l, m, ql, qr) + get_sum(2 * v + 2, m + 1, r, ql, qr);
	t[v] = t[v * 2 + 1] + t[v * 2 + 2] + c[v * 2 + 1] * (m - l + 1) + c[v * 2 + 2] * (r - m);
	// Умножение на длину отрезков делается только для запросов суммы, для всех остальных запросов этого делать не нужно.
	return res;
}
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
ПРИСВОЕНИЕ НА ОТРЕЗКЕ:

ll t[4 * n], c[4 * n], a[4 * n];
bool isch[4 * n];
void push(int v) {
	if (isch[v]) {
		isch[v] = false;
		c[v * 2 + 1] = c[v];
		c[v * 2 + 2] = c[v];
		isch[v * 2 + 1] = true;
		isch[v * 2 + 2] = true;
	}
}
void update_segm(int v, int l, int r, int ql, int qr, int val) {
	if (l > qr || r < ql) {
		return;
	}
	if (l >= ql && r <= qr) {
		c[v] = val;
		isch[v] = true;
		return;
	}
	push(v);
	int m = l + (r - l) / 2;
	update_segm(2 * v + 1, l, m, ql, qr, val);
	update_segm(2 * v + 2, m+1, r, ql, qr, val);
	ll c1 = isch[2 * v + 1] ? c[v * 2 + 1] * (m - l + 1) : t[v * 2 + 1];
	ll c2 = isch[2 * v + 2] ? c[v * 2 + 2] * (r - m) : t[v * 2 + 2];
	t[v] = c1 + c2;
// Умножение на длину отрезков делается только для запросов суммы, для всех остальных запросов этого делать не нужно.
}
ll get_sum(int v, int l, int r, int ql, int qr) {
	if (l > qr || r < ql) {
		return 0;
	}
	if (l >= ql && r <= qr) {
		return isch[v] ? c[v] * (r - l + 1) : t[v];
	}
	push(v);
	int m = l + (r - l) / 2;
	ll res = get_sum(2 * v + 1, l, m, ql, qr) + get_sum(2 * v + 2, m + 1, r, ql, qr);
	ll c1 = isch[2 * v + 1] ? c[v * 2 + 1] * (m - l + 1) : t[v * 2 + 1];
	ll c2 = isch[2 * v + 2] ? c[v * 2 + 2] * (r - m) : t[v * 2 + 2];
	t[v] = c1 + c2;
	return res;
// Умножение на длину отрезков делается только для запросов суммы, для всех остальных запросов этого делать не нужно.
}
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~