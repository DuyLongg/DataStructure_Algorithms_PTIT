#include <iostream>
#include <vector>
using namespace std;

int N,K;
int a[10][10];
int b[10][10] = {0};
vector <int> r;

void Nhap (){
	for (int i = 0 ; i < N ; i++){
		for (int j = 0 ; j < N ; j++){
			cin >> a[i][j];
		}
	}
}

void phongtoacot (int j){
	for (int i = 0 ; i < N ; i++){
		b[i][j] = 1;
	}
}

void giaiphongcot (int j){
	for (int i = 0 ; i < N ; i++){
		b[i][j] = 0;
	}
}

int sum = 0;
int chuoitm = 0;
vector <int> e;

void hat (){
	for (int i = 0 ; i < N ; i++){
		e.push_back(r[i]);
	}
}

void chon (int i){
	for (int j = 0 ; j < N ; j++){
		if (b[i][j] == 0){
			// chon b[i][j]
			r.push_back(j+1);
			sum = sum + a[i][j];
			phongtoacot(j);
			if (i < N-1) chon (i+1);
			if (i == N-1){
				if (sum == K){
					chuoitm++;
					hat ();		
				}
			}
			r.pop_back();
			giaiphongcot(j);
			sum = sum - a[i][j];
		}
	}
}

int main (){
	cin >> N >> K;
	Nhap();
	chon (0);
	cout << chuoitm << endl;
	int dem = 0;
	for (int i = 0 ; i < e.size() ; i++){
		dem++;
		cout << e[i] << " ";
		if (dem == N) {
			cout << endl;
			dem = 0;
		}
	}
	return 0;
}
