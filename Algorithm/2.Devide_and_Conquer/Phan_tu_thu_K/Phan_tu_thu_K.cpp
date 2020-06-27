#include <bits/stdc++.h>
#define ll long long
using namespace std;

void connect (ll A[],int first , int mid, int last){
	vector <ll> C;
	int i = first, j = mid+1;
	while (i <= mid && j <= last){
		if (A[i] < A[j]){
			C.push_back(A[i]);
			i++;
		} else {
			C.push_back(A[j]);
			j++;
		}
	}
	while (i <= mid) {
		C.push_back(A[i]);
		i++;
	}
	while (j <= last){
		C.push_back(A[j]);
		j++;
	}
	int idx = 0;
	for (int i = first ; i <= last ; i++){
		A[i] = C[idx];
		idx++;
	}
}

void merge_sort(ll A[], int first, int last){
	if (first != last){
		int mid = (first+last)/2;
		merge_sort (A,first,mid);
		merge_sort (A,mid+1,last);
		connect (A,first,mid,last);
	}
}

int main (){
	int T; cin >> T;
	while (T--){
		ll M,N,K; cin >> M >> N >> K;
		ll A[M+N];
		for (int i = 0 ; i < M+N ; i++) cin >> A[i];
		merge_sort(A,0,M+N-1);
		cout << A[K-1] << endl;
	}
	return 0;
}
