#include <bits/stdc++.h>
using namespace std;

void chuyen(int n, char a, char c){
	cout << "Chuyen dia thu " << n << " tu coc " << a << " sang coc " << c << endl;
}
	
void thaphanoi(int n, char a, char c, char b){
	if (n==1) chuyen(1, a, c);
	else{
		thaphanoi(n-1, a, b, c);
		chuyen(n, a, c);
		thaphanoi(n-1, b, c,a);
	}
}

int main (){
	int sodia;
	cout << "So dia can chuyen: ";
	cin >> sodia;
	cout << "Cac buoc chuyen nhu sau:\n" << endl;
	thaphanoi(sodia,'a','c','b');
	return 0;
}
