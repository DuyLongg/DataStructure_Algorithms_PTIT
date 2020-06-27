#include <iostream>
#include <vector>
using namespace std;

int main (){
	int N,K; cin >> N >> K;
	string a; cin >> a;
	vector <int> b;
	vector <int> c;
	int size = a.size();
	for (int i = 0 ; i < size ; i++){
		b.push_back(a[i]-'0');
	}
	for (int i = 0 ; i < size ; i++){
		while (K>0 && c.size() > 0 && b[i] > c[c.size()-1]){
			c.pop_back();
			K--;
		}
		c.push_back(b[i]);
	}
	for (int i = 0 ; i < c.size() ; i++){
		cout << c[i];
	}
	return 0;
}
