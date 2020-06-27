#include <iostream>
#include <vector>
#define ll long long
using namespace std;

ll N,T,A[1000005];

void connect (ll a[], ll mid, ll first, ll last){
	ll i = first, j = mid+1;
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

void merge_sort(ll a[], ll first, ll last){
	if (first!=last){
		int mid = (first+last)/2;
		merge_sort(a,first,mid);
		merge_sort(a,mid+1,last);
		connect(a,mid,first,last);
	}
}

int main (){
	cin >> T;
	while (T--){
		cin >> N;
		for (int i = 0 ; i < N ; i++) cin >> A[i];
		merge_sort(A,0,N-1);
		for (int i = 0 ; i < N ; i++) cout << A[i] << " ";
		cout << endl;
	}
	return 0;
}
