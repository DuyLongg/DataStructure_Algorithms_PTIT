#include <bits/stdc++.h>
using namespace std;

int A[1000];

int max_A (int fi, int la){
	if (fi >= la-1) return max(A[fi],A[la]);
	int mid = (fi+la)/2;
	return max (max_A(fi,mid),max_A(mid+1,la));
}

int main (){
	int N;
	cout << "So phan tu cua mang A: ";
	cin >> N;
	cout << "Nhap mang A: ";
	for (int i = 1 ; i <= N ; i++) cin >> A[i];
	cout << "Max cua mang A = " << max_A(1,N) << endl;
	return 0;
}
