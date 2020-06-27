#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
vector <char> p;
int soxautm = 0;
void Sinh(int a[], int N){
	for (int i = N-1 ; i >= 0 ; i--){
		if (a[i] == 0){
			a[i] = 1;
			for (int j = i+1 ; j < N ; j++){
				a[j] = 0;
			}
			break;
		}
	}	
}

void push (int a[], int N){
	for (int i = 0 ; i < N ; i++){
		if (a[i] == 0) p.push_back('A');
		else p.push_back('B');
	}
	p.push_back('\n');
	soxautm++;
}

void show (vector <char> &b){
	cout << soxautm << endl;
	for (int i = 0 ; i < b.size() ; i++){
		cout << b[i];
	}
}

int main (){
	int N,K; cin >> N >> K;
	int a[N] = {0};
	if (N == K) {
		push (a,N);
		show (p);
		return 0;
	}
	long long sl = pow (2, N) - 1;
	while (sl--){
		int dem = 0;
		Sinh (a,N);
		for (int i = 0 ; i < N ; i++){
			if (a[i] == 0) dem++;
			else dem = 0;
			if (dem == K){
				if (i == N-1){
					push (a,N);
				} else if (a[i+1] == 1){
					int dem1 = 0;
					for (int j = i+2 ; j < N ; j++){
						if (a[j] == 0) dem1++;
						else dem1 = 0;
						if (dem1 == K) {
							i = N;
							break;
						}
					}
					push (a,N);
				} else break;
			}
		}
	}
	show (p);	
	return 0;
}
