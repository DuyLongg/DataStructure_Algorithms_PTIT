#include <bits/stdc++.h>
#define ll long long
using namespace std;

void Quick_sort (ll A[], int first, int last){
	int i = first, j = last;
	int key = A[first];
	do{
		while (A[i] < key) i++;
		while (A[j] > key) j--;
		if (i<=j){
			swap(A[i],A[j]);
			i++; j--;
		}
	} while (i<=j);
	if (i < last) Quick_sort(A,i,last);
	if (j > first) Quick_sort(A,first,j);
}

ll Kanguru(ll A[], int N){
	int mid = N/2; int count = 0;
	int i = 1 , j = mid+1;
	while (i <= mid && j <= N){ 
		if (2*A[i] <= A[j]){
			count++; i++; j++;
		} else j++;
	}
	return count;
}

int main (){
	int T; cin >> T;
	while (T--){
		int N; cin >> N;
		ll A[N];
		for (int i = 1 ; i <= N ; i++) cin >> A[i];
		Quick_sort(A,1,N);
		cout << N-Kanguru(A,N) << endl;
	}
	return 0;
}
