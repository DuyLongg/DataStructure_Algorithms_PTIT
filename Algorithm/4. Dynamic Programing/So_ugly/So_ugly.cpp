#include <bits/stdc++.h>
using namespace std;

long long T,N,ugly[10005];

void UGLY (){
	int x2,x3,x5;
	ugly[1] = 1;
	x2 = x3 = x5 = 1;
	for (int i = 2 ; i <= 10005 ; i++){
		ugly[i] = min (ugly[x2] * 2, min (ugly[x3] * 3, ugly[x5] * 5));
		if (ugly[i] == ugly[x2] * 2) x2++;
		if (ugly[i] == ugly[x3] * 3) x3++;
		if (ugly[i] == ugly[x5] * 5) x5++;
	}
}

int main (){
	cin >> T;
	UGLY();
	while (T--){
		cin >> N;
		cout << ugly[N] << endl;
	}
	return 0;
}
