#include<iostream>
using namespace std;
using ll = long long;

void nhap(ll a[], int& n, ll b[], int& m);
void sapxep(ll a[], int n, ll b[], int m);
void xuatmang(ll a[], int n);

int main() {
	int n, m;
	ll a[1000000], b[1000000];
	nhap(a, n, b, m);
	sapxep(a, n, b, m);
	return 0;
}
void nhap(ll a[], int& n, ll b[], int &m) {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}
}

void xuatmang(ll a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i];
		if (i != n - 1) {
			cout << " ";
		}
	}
}

void sapxep(ll a[], int n, ll b[], int m) {
	int ia = 0, ib = 0, sizeC = 0;
	ll c[1000000];
	while (ia < n && ib < m) {
		if (a[ia] < b[ib]) {
			if (sizeC == 0 || c[sizeC - 1] != a[ia]) {
				c[sizeC++] = a[ia];
			}
			ia++;
		}
		else {
			if (sizeC == 0 || c[sizeC - 1] != b[ib]) {
				c[sizeC++] = b[ib];
			}
			ib++;
		}
	}
	while (ia < n) {
		if (sizeC == 0 || c[sizeC - 1] != a[ia]) {
			c[sizeC++] = a[ia];
		}
		ia++;
	}
	while (ib < m) {
		if (sizeC == 0 || c[sizeC - 1] != b[ib]) {
			c[sizeC++] = b[ib];
		}
		ib++;
	}
	xuatmang(c, sizeC);
}
/*
* full 10/10 testcase uteoj, 100/100
* note: ko chay dc tren visual 2022, nhung tren uteoj lai full
*/