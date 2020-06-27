#include <iostream>
using namespace std;

int main (){
	int N; cin >> N;
	int a[N];
	for (int i = 0 ; i < N ; i++) cin >> a[i];
	for (int i = 0 ; i < N-1 ; i++){
		int min = a[i];
		int index_min = i;
		for (int j = i+1 ; j < N ; j++){
			if (a[j] < min){
				min = a[j];
				index_min = j;
			}
		} 
		swap(a[i],a[index_min]);
		cout << "Buoc " << i+1 << ": ";
		for (int i = 0 ; i < N ; i++) cout << a[i] << " ";
		cout << endl;
	}
	return 0;	
}
