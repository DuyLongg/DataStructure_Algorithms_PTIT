#include <iostream>
using namespace std;

int main (){
	int N; cin >> N;
	int i_min,j_min;
	i_min = j_min = 1000001;
	while (N--){
		int a,b;
		cin >> a >> b;
		if (a<i_min) i_min = a;
		if (b<j_min) j_min = b;
	}
	cout << i_min*j_min << endl;
	return 0;
}
