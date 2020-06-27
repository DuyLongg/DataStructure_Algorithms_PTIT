#include <iostream>
#define ll long long
using namespace std;

int N;
void repair_heap (int size_heap, ll A[]);

void insert_heap (ll tmp, ll A[], int index){
	A[index] = tmp;
	while (index > 0 && A[index] > A[(index-1)/2]){
		swap(A[index],A[(index-1)/2]);
		index = (index-1)/2;
	}
}

void heap_sort (ll A[]){
	int size_heap = N-1;
	while (size_heap > 0){
		swap (A[0],A[size_heap]);
		size_heap--;
		repair_heap(size_heap,A);
	}
}

void repair_heap (int size_heap, ll A[]){
	int node = 0;
	int node_con;
	while (size_heap > 0 && node <= (size_heap-1)/2){
		node_con = 2*node+1;
		if (node_con < size_heap) if (A[node_con] < A[node_con+1]) node_con++;// chon node con lon hon
		if (A[node] < A[node_con]) {
			swap (A[node], A[node_con]);
			node = node_con;
		} else break;
	}
}

int main (){
	cin >> N;
	ll A[N];
	ll tmp;
	for (int i = 0 ; i < N ; i++){
		cin >> tmp;
		insert_heap(tmp,A,i);
	}		
	heap_sort(A);
	for (int i = 0 ; i < N ; i++) cout << A[i] << " ";
	cout << endl;
	return 0;
}
