#include<iostream>
#include<cmath>
using namespace std;
struct PHANSO
{
	int tu, mau;
};
void nhapPS(PHANSO k[], int& n, double& x);
void nhap1PS(PHANSO& a);
double rutgonvachiaPS(PHANSO& a);
void VitriPSganxnhat(PHANSO k[], int n, double x);
int main() {
	PHANSO k[100];
	int n;
	double x;
	nhapPS(k, n, x);
	VitriPSganxnhat(k,n,x);
	return 0;
}
void nhapPS(PHANSO k[], int& n, double& x) {
	cin >> n >> x;
	for (int i = 0; i < n; i++) {
		nhap1PS(k[i]);
	}
}
void nhap1PS(PHANSO& a) {
	cin >> a.tu >> a.mau;
}
double rutgonvachiaPS(PHANSO &a) {
	if (a.mau < 0) {
		a.tu = -a.tu;
		a.mau = -a.mau;
	}
	int x = max(a.tu, a.mau);
	int y = min(a.tu, a.mau);
	int tam = 0;
	for (int i = 1; i <= x; i++) {
		if (y % i == 0 && x % i == 0) {
			tam = i;
		}
	}
	a.tu /= tam;
	a.mau /= tam;
	double t = (1.0) * a.tu / a.mau;
	return t;
}
void VitriPSganxnhat(PHANSO k[], int n, double x) {
	double r = rutgonvachiaPS(k[0]);
	double w = abs(r - x);
	double b[100];
	int sizeB = 0;
	for (int i = 0; i < n; i++) {
		double y = rutgonvachiaPS(k[i]);
		double c = abs(y - x);
		b[sizeB++] = c;
	}
	if (sizeB > 0) {
		double min = b[0];
		int tam = 0;
		for (int i = 1; i < sizeB; i++) {
			if (b[i] < min) {
				min = b[i];
				tam = i;
			}
		}
		cout << tam;
	}
}
/*
* input 
* 4 1.33
* 3 9
* 4 6
* 10 12
* 5 7
* output
* 2 
* note: full testcase 250/250 uteoj
*/