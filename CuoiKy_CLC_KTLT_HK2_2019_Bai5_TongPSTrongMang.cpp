#include<iostream>
using namespace std;
struct PHANSO
{
	int tu, mau;
};
void nhap1PS(PHANSO& a);
void nhap(PHANSO k[], int& n);
void rutgon1PS(PHANSO &a);
void TongPSTrongMang(PHANSO k[], int n);
int main() {
	PHANSO k[100];
	int n;
	nhap(k, n);
	TongPSTrongMang(k, n);
	return 0;
}
void nhap1PS(PHANSO& a) {
	cin >> a.tu >> a.mau;
	if (a.mau == 0) {
		return;
	}
}
void rutgon1PS(PHANSO &a) {
	if (a.mau < 0) {
		a.tu = -a.tu;
		a.mau = -a.mau;
	}
	int x = max(a.tu, a.mau);
	int y = min(a.tu, a.mau);
	int w = 0;
	w = __gcd(x,y);
	a.tu /= w;
	a.mau /= w;
}
void nhap(PHANSO k[], int& n) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		nhap1PS(k[i]);
	}
}
void TongPSTrongMang(PHANSO k[], int n) {
	PHANSO b[100];
	int sizeB = 0;
	PHANSO Tong;
	Tong.tu = 0;
	Tong.mau = 1;
	for (int i = 0; i < n; i++) {
		rutgon1PS(k[i]);
		b[sizeB++] = k[i];
	}
	for (int i = 0; i < sizeB; i++) {
		Tong.mau *= b[i].mau;
	}
	for (int i = 0; i < sizeB; i++) {
		int h = Tong.mau / b[i].mau;
		b[i].tu *= h;
		Tong.tu += b[i].tu;
		h = 0;
	}
	rutgon1PS(Tong);
	cout << Tong.tu << " " << Tong.mau;
}
