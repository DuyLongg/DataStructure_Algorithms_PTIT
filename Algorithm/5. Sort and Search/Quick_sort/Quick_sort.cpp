#include <iostream>
using namespace std;

int T,N,A[1000005];

void Quick_sort (int A[], int first, int last){
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

int main (){
	cin >> T;
	while (T--){
		cin >> N;
		for (int i = 0 ; i < N ; i++) cin >> A[i];
		Quick_sort(A,0,N-1);
		for (int i = 0 ; i < N ; i++) cout << A[i] << " ";
		cout << endl;
	}
	return 0;
}
