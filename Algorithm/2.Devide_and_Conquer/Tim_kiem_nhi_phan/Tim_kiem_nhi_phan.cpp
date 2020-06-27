#include <iostream>
using namespace std;

void Nhap(int a[],int N){
	for (int i = 0 ; i < N ; i++){
		cin >> a[i];
	}
}

int BinarySearch (int a[], int K, int first, int last){
	if (first == last-1) {
		if (a[first] == K) return first;
		else if (a[last] == K) return last;
		else return -1;
	}
	int mid = (first+last)/2; 
	if (a[mid] == K) return mid;
	else if (a[mid] < K){
		first = mid;
		BinarySearch(a,K,first,last);
	} else {
		last = mid;
		BinarySearch(a,K,first,last);
	}
}

int main (){
	int T; cin >> T;
	while (T--){
		int N,K; 
		cin >> N >> K;
		int a[N];
		Nhap(a,N);
		int vt = BinarySearch(a,K,0,N-1)+1;
		if (vt) cout << vt << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
