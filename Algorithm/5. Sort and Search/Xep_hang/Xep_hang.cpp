#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main (){
	int N; cin >> N;
	vector <pair<int,int> > a;
	int b,c;
	for (int i = 0 ; i < N ; i++) {
		cin >> b >> c;
		a.push_back(make_pair(b,c));
	} 
	sort (a.begin(),a.end());
	int tg=0;
	for (int i = 0 ; i < N ; i++){
		if (a[i].first <= tg) tg = tg + a[i].second;
		else tg = a[i].first + a[i].second;
	} cout << tg << endl;
	return 0;
}
