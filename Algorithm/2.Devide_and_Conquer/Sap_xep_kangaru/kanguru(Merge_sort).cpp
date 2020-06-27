#include <bits/stdc++.h>
#define ll long long
using namespace std;

void connect (ll a[], int mid, int first, int last){
	int i = first, j = mid+1;
	vector <ll> c;
	while (i<=mid && j<=last){
		if (a[i] < a[j]) {
			c.push_back(a[i]);
			i++;
		} else {
			c.push_back(a[j]);
			j++;
		}
	}
	while (j<=last) {
		c.push_back(a[j]);
		j++;
	}
	while (i<=mid){
		c.push_back(a[i]);
		i++;
	}
	int index = 0;
	for (int r = first ; r <= last ; r++) {
		a[r] = c[index];
		index++;
	}
}

void merge_sort(ll a[], int first, int last){
	if (first!=last){
		int mid = (first+last)/2;
		merge_sort(a,first,mid);
		merge_sort(a,mid+1,last);
		connect(a,mid,first,last);
	}
}

ll Kanguru(ll A[], int N){
	int mid = (N-1)/2; int count = 0; //1 2 3 4 5 6 7 8 9
	int i = 0 , j = mid+1;
	while (i <= mid && j < N){ 
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
		for (int i = 0 ; i < N ; i++) cin >> A[i];
		merge_sort(A,0,N-1);
		cout << N-Kanguru(A,N) << endl;
	}
	return 0;
}
