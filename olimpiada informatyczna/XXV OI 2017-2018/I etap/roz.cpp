//Kamil Kotowicz
#include <iostream>
#include<algorithm>
#include<string.h>
#include<set>
using namespace std;
const int BASE = 4096;
int tab[3001][3001];
int d[2 * BASE];
int n, m, k, xx;
long long x;
int poczatek, koniec;
long long maks;
long long suma;
multiset<pair<int,int>>poc[100001];
#ifdef _WIN32
#define getc_unlocked getc
#endif // _WIN32
inline void read(int *n) {
	register char c = 0;
	while (c < 33) c = getc_unlocked(stdin);
	(*n) = 0;
	while (c > 32) { (*n) = (*n) * 10LL + (c - 48); c = getc_unlocked(stdin); }
}
inline void dodaj(int a, int b) {
	if (a > b)return;
	a += BASE;
	b += BASE;
	++d[a];
	if (a != b)++d[b];
	while (a/2!=b/2) {
		if (a %2==0)++d[a + 1];
		if (b % 2 == 1)++d[b - 1];
		a /= 2;
		b /= 2;
	}
}
inline void usun(int a, int b) {
	if (a > b)return;
	a += BASE;
	b += BASE;
	--d[a];
	if (a != b)--d[b];
	while (a/2!=b/2) {
		if (a %2==0)--d[a + 1];
		if (b % 2 == 1)--d[b - 1];
		a /= 2;
		b /= 2;
	}
}
inline long long zapytanie(int a) {
	a += BASE;
	long long wynik = 0;
	while (a > 0) {
		wynik += d[a];
		a >>= 1;
	}
	return wynik;
}
inline void INSERT(int a, int b, int c) {
 	auto it = poc[c].lower_bound(make_pair(a, b));
	if (poc[c].size() == 0) {
		dodaj(a, b);
		poc[c].insert(make_pair(a, b));
		return;
	}
	if (it == poc[c].end()) {
		koniec = b;
		if (it == poc[c].begin()) {
			poczatek = a;
		}
		else {
			--it;
			poczatek = (*it).second + 1;
		}
	}
	else if (it == poc[c].begin()) {
		if ((*it).first == a && (*it).second == b) {
			poc[c].insert(make_pair(a, b));
			return;
		}
		poczatek = a;
		koniec = (*it).first - 1;
	}
	else {
		if ((*it).first == a && (*it).second == b) {
			poc[c].insert(make_pair(a, b));
			return;
		}
		koniec = (*it).first - 1;
		--it;
		poczatek = (*it).second + 1;
	}
	if (a > poczatek)poczatek = a;
	if (b < koniec)koniec = b;
	dodaj(poczatek, koniec);
	poc[c].insert(make_pair(a, b));
}
inline void ERASE(int a, int b, int c) {
	if (a>b)return;
	auto it = poc[c].find(make_pair(a, b));
	poc[c].erase(it);
	if (poc[c].size() == 0) {
		usun(a, b);
		return;
	}
	it = poc[c].lower_bound(make_pair(a, b));
	if (it == poc[c].end()) {
		koniec = b;
		if (it == poc[c].begin()) {
			poczatek = a;
		}
		else {
			--it;
			poczatek = (*it).second + 1;
		}
	}
	else if (it == poc[c].begin()) {
		if ((*it).first == a && (*it).second == b)return;
		poczatek = a;
		koniec = (*it).first - 1;
	}
	else {
		if ((*it).first == a && (*it).second == b)return;
		koniec = (*it).first - 1;
		--it;
		poczatek = (*it).second + 1;
	}
	if (a > poczatek)poczatek = a;
	if (b < koniec)koniec = b;
	usun(poczatek, koniec);
}
int main() {
	ios::sync_with_stdio(false);
	read(&m);
	read(&n);
	read(&k);
	//cin>>m>>n>>k;
	for (int i = 0; i<m; ++i) {
		for (int j = 0; j<n; ++j) {
			read(&xx);
			//cin>>xx;
			tab[i][j] = xx;
		}
	}
	for (int i = 0; i<k; ++i) {
		for (int j = 0; j<n; ++j) {
			x = tab[i][j];
			INSERT(max(j - k + 1, 0), min(j, n - k), x);
		}
	}
	for (int i = 0; i <= n - k; ++i) {
		x = zapytanie(i);
		suma += x;
		maks = max(maks, x);
	}
	for (int i = k; i<m; ++i) {
		for (int j = 0; j < n; ++j) {
			x = tab[i - k][j];
			ERASE(max(j - k + 1, 0), min(j, n - k), x);
		}
		for (int j = 0; j < n; ++j) {
			x = tab[i][j];
			INSERT(max(j - k + 1, 0), min(j, n - k), x);
		}
		for (int i = 0; i <= n - k; ++i) {
			x = zapytanie(i);
			suma += x;
			maks = max(maks, x);
		}
	}
	cout << maks << " " << suma;
}