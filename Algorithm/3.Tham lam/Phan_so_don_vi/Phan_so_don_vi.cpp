#include <bits/stdc++.h>
using namespace std;

int main (){
	int T; cin >> T;
	while (T--){
		long long tu,mau; cin >> tu >> mau;
		while (true){
			if (mau%tu==0) {
				cout << "1/" << mau/tu << endl;
				break;
			}
			else {
				long long tmp = mau/tu+1;
				cout << "1/" << tmp << " + ";
				tu = tu*tmp - mau;
				mau = mau * tmp;
			}
		}
	}
	return 0;
}
