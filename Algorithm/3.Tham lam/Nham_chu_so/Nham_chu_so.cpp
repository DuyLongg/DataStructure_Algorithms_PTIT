#include <iostream>
using namespace std;

int main (){
	string A,B;
	cin >> A >> B;
	int min1 = 0, min2 = 0, max1 = 0, max2 = 0;
	for (int i = 0 ; i < A.size() ; i++){
		min1 = min1*10 + (A[i]-'0');
		if (A[i]=='6') min1--;
		max1 = max1*10 + (A[i]-'0');
		if (A[i]=='5') max1++;
	}
	for (int i = 0 ; i < B.size() ; i++){
		min2 = min2*10 + (B[i]-'0');
		if (B[i]=='6') min2--;
		max2 = max2*10 + (B[i]-'0');
		if (B[i]=='5') max2++;
	}
	cout << min1+min2 << " " << max1+max2;
	return 0;
}
