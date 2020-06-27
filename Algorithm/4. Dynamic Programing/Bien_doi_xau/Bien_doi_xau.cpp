#include <bits/stdc++.h>
using namespace std;

int T,F[105][105]; // F[M][N] la so phep it nhat voi M phan tu s1 va N phan tu s2
// F[i][j] la so phep it nhat voi i phan tu s1 va j phan tu s2
// Neu s1[i] == s2[j] thi F[i][j] = F[i-1][j-1];
// else thi F[i][j] = min (F[i][j-1],F[i-1][j],F[i-1][j-1]) + 1
// F[0][i] = F[i][0] = i; 
string s1,s2;

int Solve (){
	memset (F,0,sizeof(F));
	int s1_size = s1.size();
	int s2_size = s2.size();
	int size_max = max (s1_size,s2_size);
	for (int i = 1 ; i <= size_max ; i++) F[0][i] = F[i][0] = i;
	for (int i = 1 ; i <= s1_size ; i++){
		for (int j = 1 ; j <= s2_size ; j++){
			if (s1[i-1] == s2[j-1]) F[i][j] = F[i-1][j-1];
			else F[i][j] = min (F[i-1][j-1], min (F[i][j-1],F[i-1][j])) + 1;
		}
	}
	return F[s1_size][s2_size];
}

int main (){
	cin >> T;
	while (T--){
		cin >> s1 >> s2;
		cout << Solve() << endl;
	}
	return 0;
}
