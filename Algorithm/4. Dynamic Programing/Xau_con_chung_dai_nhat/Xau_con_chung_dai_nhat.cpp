#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

ll C[1000][1000];
int T; 
string A,B;
int A_size,B_size;

int main (){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	while (T--){
		cin >> A >> B;
		A = "0" + A;
		B = "0" + B;
		A_size = A.size();
		B_size = B.size();
		memset(C,0,sizeof(C));
		for (int i = 1 ; i < A_size ; i++){
			for (int j = 1 ; j < B_size ; j++){
				if (A[i] == B[j]) C[i][j] = C[i-1][j-1]+1;
				else C[i][j] = max(C[i-1][j],C[i][j-1]);
			}
		}
		cout << C[A_size-1][B_size-1] << endl;
	}
	return 0;
}
