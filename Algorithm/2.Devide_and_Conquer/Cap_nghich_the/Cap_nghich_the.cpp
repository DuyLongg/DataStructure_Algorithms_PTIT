#include <iostream>
#include <vector>
#define ll long long
using namespace std;

ll N = 0,socapNT = 0;

void connect (ll a[], int mid, int first, int last){
	int i = first, j = mid+1;
	vector <ll> c;
	while (i<=mid && j<=last){
		if (a[i] <= a[j]) {
			c.push_back(a[i]);
			i++;
		} else {
			c.push_back(a[j]);
			j++; socapNT = socapNT + mid - i + 1;
		}
	}
	while (i==mid+1 && j<=last) {
		c.push_back(a[j]);
		j++;
	}
	while (j==last+1 && i<=mid){
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

int main (){
	int T; cin >> T;
	while (T--){
		cin >> N;
		ll a[N];
		for (int i = 0 ; i < N ; i++) cin >> a[i];
		merge_sort(a,0,N-1);
		cout << socapNT << endl;
		N = 0;
		socapNT = 0;
	}
	return 0;
}
