#include <iostream>
using namespace std;

int N,K,S,dem=0;
int A[100] = {0};

void Cal(){
	int sum = 0;
	for (int i = 1 ; i <= K ; i++) sum = sum + A[i];
	if (sum==S) dem++;
}

void Back_track (int i){
	for (int j = A[i-1]+1 ; j <= N-K+i ; j++){
		A[i] = j;
		if (i==K) Cal();
		else Back_track(i+1);
	}
}

int main (){
	while (true){
		cin >> N >> K >> S;
		if (N==0 && K==0 && S==0) return 0;
		if (K > N) 	{
			cout << 0 << endl;
			continue;
		}
		Back_track(1);
		cout << dem << endl;
		dem = 0;
	}
	return 0;
}
