#include<bits/stdc++.h>
using namespace std;
const int maxt = 840;
const int MAXN = 15005;
const int MAXT = 845;
const int MAXQ = 1e6 + 5;
const int LOG = 14;
const int MAX_DL = 8;
int n, m, q;
int t[MAXQ], yp[MAXQ], xp[MAXQ], yk[MAXQ], xk[MAXQ], wyn_kolumny[MAXQ], wyn_wiersze[MAXQ];
int modulo[MAXT][MAX_DL + 1];
vector<vector<string>>s;
vector<int>przejscie[MAXN];
int dp[MAXN][MAXT][LOG];
string skrzyzowanie;
int ind;
char lit;
void jump_pointery(int czy_kolumny, int czy_do_przodu) {
	int sz;
	if (czy_kolumny == 1)sz = m;
	else sz = n;
	for (int gl = 1; gl<LOG; ++gl) {
		for (int i = 0; i<=sz; ++i) {
			if (czy_do_przodu == 1) {
				int nast = i + (1 << gl);
				if (nast<=sz) {
					for (int k = 0; k<maxt; ++k) {
						int wewn = dp[i][k][gl - 1];
						int wewn_ind = i + (1 << (gl - 1));
						int okres = (wewn / maxt)*maxt;
						dp[i][k][gl] = dp[wewn_ind][wewn - okres][gl - 1] + okres;
					}
				}
			}
			else {
				int poprz = i - (1 << gl);
				if (poprz >= 0) {
					for (int k = 0; k<maxt; ++k) {
						int wewn = dp[i][k][gl - 1];
						int wewn_ind = i - (1 << (gl - 1));
						int okres = (wewn / maxt)*maxt;
						dp[i][k][gl] = dp[wewn_ind][wewn - okres][gl - 1] + okres;
					}
				}
			}
		}
	}
}
void kiedy_mozna_przejsc_przez_kolumne(int nr_kolumny,int liczba_wierszy){
    przejscie[nr_kolumny].clear();
    for(int j=0;j<maxt;++j){
        for (int k = 0; k<liczba_wierszy; ++k) {
             skrzyzowanie = s[k][nr_kolumny];
             ind=j%skrzyzowanie.size();
             lit = skrzyzowanie[ind];
            if (lit != '0') {
                przejscie[nr_kolumny].push_back(j);
                break;
            }
        }
    }
}
void kiedy_mozna_przejsc_przez_wiersz(int nr_wiersza,int liczba_kolumn){
    przejscie[nr_wiersza].clear();
    for(int j=0;j<maxt;++j){
        for (int k = 0; k<liczba_kolumn; ++k) {
             skrzyzowanie = s[nr_wiersza][k];
             ind=j%skrzyzowanie.size();
             lit = skrzyzowanie[ind];
            if (lit != '1') {
                przejscie[nr_wiersza].push_back(j);
                break;
            }
        }
    }
}
void preprocess(int czy_kolumny, int czy_do_przodu) {
    int sz, sz2;
	if (czy_kolumny == 1) {
		sz = m;
		sz2 = n;
	}
	else {
		sz = n;
		sz2 = m;
	}
	for (int i = 0; i<sz; ++i) {
        if(czy_do_przodu==0){
            if(czy_kolumny==1)kiedy_mozna_przejsc_przez_kolumne(i,sz2);
            else kiedy_mozna_przejsc_przez_wiersz(i,sz2);
        }
		int k = 0;
		for (int j = 0; j<przejscie[i].size(); ++j) {
			int akt = przejscie[i][j];
			while (k <= akt) {
				if (czy_do_przodu == 1)dp[i][k][0] = akt;
				else dp[i + 1][k][0] = akt;
				++k;
			}
		}
		while (k<maxt) {
			if (czy_do_przodu == 1)dp[i][k][0] = przejscie[i][0] + maxt;
			else dp[i + 1][k][0] = przejscie[i][0] + maxt;
			++k;
		}
	}
	jump_pointery(czy_kolumny, czy_do_przodu);
}
void zapytania(int czy_kolumny, int czy_do_przodu) {
	for (int z = 0; z<q; ++z) {
		int poc, kon;
		if (czy_kolumny == 1) {
			poc = xp[z];
			kon = xk[z];
			if (poc == kon) {
				wyn_kolumny[z] = t[z];
				continue;
			}
		}
		else {
			poc = yp[z];
			kon = yk[z];
			if (poc == kon) {
				wyn_wiersze[z] = t[z];
				continue;
			}
		}
		int poz = poc;
		int czas = t[z];
		if (czy_do_przodu == 1) {
			if (poc>kon)continue;
			for (int i = LOG - 1; i >= 0; --i) {
				if (poz + (1 << i) <= kon) {
					int okres = (czas / maxt)*maxt;
					czas = dp[poz][czas - okres][i] + okres;
					poz += (1 << i);
				}
			}
		}
		else {
			if (poc<kon)continue;
			for (int i = LOG - 1; i >= 0; --i) {
				if (poz - (1 << i) >= kon) {
					int okres = (czas / maxt)*maxt;
					czas = dp[poz][czas - okres][i] + okres;
					poz -= (1 << i);
				}
			}
		}
		if (czy_kolumny == 1)wyn_kolumny[z] = czas;
		else wyn_wiersze[z] = czas;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m >> q;
	s.resize(n);
	for (int i = 0; i<n; ++i) {
		s[i].resize(m);
		for (int j = 0; j<m; ++j) {
			cin >> s[i][j];
		}
	}
	for (int i = 0; i<q; ++i) {
		cin >> t[i] >> yp[i] >> xp[i] >> yk[i] >> xk[i];
	}
	for (int i = 0; i<2; ++i) {
		for (int j = 0; j<2; ++j) {
			preprocess(i, j);
			zapytania(i, j);
		}
	}
	for (int i = 0; i<q; ++i) {
		cout << max(wyn_kolumny[i], wyn_wiersze[i]) << "\n";
	}
	return 0;
}