#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main (){
	int N; cin >> N;
	ll A[100005];
	for (int i = 0 ; i < N ; i++) cin >> A[i];
	sort (A,A+N);
	for (int i = 0 ; i < N ; i++) cout << A[i] << " ";
	cout << endl;
	return 0;
}
