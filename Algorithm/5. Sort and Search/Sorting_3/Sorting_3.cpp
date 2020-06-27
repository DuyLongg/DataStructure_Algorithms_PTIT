#include <iostream>
#include <algorithm>
using namespace std;

int T,N,A[1005];

int min_Swap (){
	int swaps = 0;
	for (int i = 0 ; i < N ; i++){
		if (A[i] == i+1) continue;
		swap(A[i],A[A[i]-1]);
		swaps++;
		i--;
	}
	return swaps;
}

int main (){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--){
		cin >> N;
		for (int i = 0 ; i < N ; i++) cin >> A[i];
		cout << min_Swap() << endl;
	}
	return 0;
}
