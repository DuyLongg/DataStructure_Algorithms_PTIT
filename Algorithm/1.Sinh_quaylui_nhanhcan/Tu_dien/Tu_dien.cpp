#include <bits/stdc++.h>
using namespace std;

int K,M,N; 
string dic[150];
char matrix[100][100];
int check[100][100] = {0};
int dem = 0;
string str = "";

void Input(){
	for (int i = 1 ; i <= K ; i++) cin >> dic[i];
	for (int i = 1 ; i <= M ; i++){
		for (int j = 1 ; j <= N ; j++){
			cin >> matrix[i][j];
		}
	}
}

void In(int n){
	cout << dic[n] << " ";
	dem++;
}

void Compare_str(){
	for (int i = 1 ; i <= K ; i++){
		if (str.compare(dic[i])==0) In(i);
	}
}

void Try (int i, int j){
	check[i][j] = 1;
	str.push_back(matrix[i][j]);
	Compare_str();
		if (i-1 >= 1 && j-1 >= 1 && check[i-1][j-1] == 0) Try (i-1,j-1);
		if (i-1 >= 1 && check[i-1][j] == 0) Try (i-1,j);
		if (i-1 >= 1 && j+1 <= N && check[i-1][j+1] == 0) Try (i-1,j+1);
		if (j-1 >= 1 && check[i][j-1] == 0) Try (i,j-1);
		if (j+1 <= N && check[i][j+1] == 0) Try (i,j+1);
		if (i+1 <= M && j-1 >= 1 && check[i+1][j-1] == 0) Try (i+1,j-1);
		if (i+1 <= M && check[i+1][j] == 0) Try (i+1,j);
		if (i+1 <= M && j+1 <= N && check[i+1][j+1] == 0) Try (i+1,j+1);
	str.pop_back();
	check[i][j] = 0;
}

void Reset(){
	dem = 0;
	for (int i = 0 ; i < 150 ; i++)	dic[i] = "";
}

int main (){
	int T; cin >> T;
	while (T--){
		cin >> K >> M >> N;
		Input();
		for (int m = 1 ; m <= M ; m++){
			for (int n = 1 ; n <= N ; n++) Try (m,n);
		}
		if (dem == 0) cout << -1;
		cout << endl;
		Reset();
	}
	return 0;
}
