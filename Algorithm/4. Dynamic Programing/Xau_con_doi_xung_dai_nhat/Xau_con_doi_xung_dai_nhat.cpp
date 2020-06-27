// L[i][j] = 1/0 neu A[i...j] la xau con doi dung dai nhat trong khoang tu A[i] -> A[j] / nguoc lai. Tinh L[1][N] 
// A[i...j] la xau con doi xung neu A[i] == A[j] && A[i+1...j-1] la xau con doi xung
// Truy hoi: L[i][j] = L[i+1][j-1] && A[i] == A[j].		
// DK1: j > 0 de L[i+1][j-1] khong bi loi . Trong TH j = 0 thi L[0][0] = 1 va (L[i][0] = 0 voi i > 0)
// DK2: Vi i <= j neu i+1 <= j-1 <=> i+2 <= j. Neu j = i+2 (dau bang xay ra) thi L[i+1][j-1] -> L[i+1][i+1] <=> L[i][i]. => Vi L[i][i] khong tinh duoc theo CT nen ta can set up truoc
// Made by TDL
#include <bits/stdc++.h>
using namespace std;

string S;
int maxL,L[1002][1002], N;

int main (){
	int T; cin >> T;
	while (T--){
		maxL = 1;
		memset(L,0,sizeof(L));
		cin >> S; N = S.size();
		for (int i = 0 ; i < N ; i++) L[i][i] = 1;
		// Set up substring 2 lengths
		for (int i = 0 ; i < N-1 ; i++){
			L[i][i+1] = (S[i]==S[i+1]);
			if (L[i][i+1]) maxL = 2;
		} 
		// Set up substring i lenths  3 <= i <= N
		int i = 3;
		int start,end;
		while (i <= N){
			for (int a = 0 ; a < N-i+1 ; a++){
				L[a][a+i-1] = (L[a+1][a+i-2] && (S[a]==S[a+i-1]));
				if (L[a][a+i-1] && i > maxL) maxL = i;
			}
			i++;
		}
		cout << maxL << endl;
	}
	return 0;
}
