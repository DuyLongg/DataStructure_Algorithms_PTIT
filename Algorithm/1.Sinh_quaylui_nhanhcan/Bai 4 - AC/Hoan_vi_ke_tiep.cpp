#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main (){
	int T = 0;
	cin >> T;
	while (T--){
		int stt; cin >> stt;
		string a;
		cin >> a;
		vector <int> b;
		for (int i = 0 ; i < a.size() ; i++) b.push_back(a[i] - '0');
		int pic1 = 0;
		int pic2 = 0;
		for (int i = b.size()-2 ; i >= 0 ; i--){
			if (b[i] < b[i+1]){
				pic1 = i;
				pic2 = i+1;
				int min = b[i+1];
				for (int j = i+2 ; j < b.size() ; j++){
					if (b[j] > b[i] && b[j] <= min) {
						min = b[j];
						pic2 = j;
					}
				}
				swap(b[pic1], b[pic2]);
				reverse(b.begin() + pic1 + 1, b.end());
				cout << stt << " ";
				for (int i = 0 ; i < b.size() ; i++){
					cout << b[i];
				}
				cout << endl;
				break;
			}
		}
		if (pic1 == 0 && pic2 == 0) cout << stt << " " << "BIGGEST" << endl;
	}
	return 0;
}
