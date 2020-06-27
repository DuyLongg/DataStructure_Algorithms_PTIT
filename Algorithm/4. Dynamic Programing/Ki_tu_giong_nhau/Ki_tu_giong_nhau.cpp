#include <bits/stdc++.h>
using namespace std;

int T,N,X,Y,Z,F[105]; // F[N] la thoi gian it nhat voi N phan tu giong nhau
// F[i] la thoi gian it nhat voi i phan tu giong nhau
// Neu i le thi chi co 2 cach la i-1 insert va i+1 delete ( ma i+1 delete  = (i+1)/2 copy + 1 delete)
// Neu i chan thi co 3 cach i-1 insert, i/2 copy
// F[1] = time of insert
int Solve (){
	memset (F,0,sizeof(F));
	F[1] = X;
	for (int i = 2 ; i <= N ; i++){
		if (i%2) F[i] = min (F[i-1] + X, F[(i+1)/2] + Z + Y);
		else F[i] = min (F[i-1] + X, F[i/2] + Z); 
	}
	return F[N];
}

int main (){
	cin >> T;
	while (T--){
		cin >> N;
		cin >> X >> Y >> Z;	
		cout << Solve() << endl;
	}
	return 0;
}
