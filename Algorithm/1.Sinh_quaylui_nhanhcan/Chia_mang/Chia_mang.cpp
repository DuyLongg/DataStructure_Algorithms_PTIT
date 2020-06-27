#include <iostream>
using namespace std;

int A[101];
bool Find_subset(int Idx_start, int K, int key, bool daxet[], int sum,int N);

void Input (int N){
	for (int i = 0 ; i < N ; i++) cin >> A[i];
}

int Sum_all(int N){
	int sum = 0;
	for (int i = 0 ; i < N ; i++){
		sum = sum + A[i];
	}
	return sum;
}

bool Par_subset(int sum, int K,int N){
	bool daxet[N];
	return sum%K==0 && Find_subset(0,K,sum/K,daxet,0,N);
}

bool Find_subset(int Idx_start, int K, int key, bool daxet[], int sum,int N){
	if (K==1) return true;
	if (sum==key) return Find_subset(0, K-1, key, daxet,0,N);
	for (int i = Idx_start ; i < N ; i++){
		if (!daxet[i]){
			if (sum+A[i] > key) continue;
			daxet[i] = true;
			if (Find_subset(i+1,K,key,daxet,sum+A[i],N)) return true;
			daxet[i] = false;
		}
	}
	return false;
}

int main (){
	int T; cin >> T;
	while (T--){
		int N,K; cin >> N >> K;
		Input (N);
		cout << Par_subset(Sum_all(N),K,N) << endl;
	}
	return 0;
}
