#include <bits/stdc++.h>
using namespace std;

int N,A[100005];

int main (){
	cin >> N;
	for (int i = 1 ; i <= N ; i++) cin >> A[i];
	cout << 1 << " ";
	int kq = 1;
	int id = 0;
	A[0] = INT_MAX;
	stack <int> B;
	B.push(1);
	for (int i = 2 ; i <= N ; i++){
		if (A[i] < A[i-1]) {
			cout << 1 << " ";
			B.push(1);
			id = i-1;
		} else {
			int dem = 1 + B.top();
			while (A[id] <= A[i]){
				dem++; id--;
			}
			B.push(dem);
			cout << dem << " ";
		}
	}
	cout << endl;
	return 0;
}
