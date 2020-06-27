#include <bits/stdc++.h>
#define DB double
using namespace std;
int N;
bool condition (const pair<DB,DB> &i, const pair <DB,DB> &j) {return i.second < j.second;}	// Set up new condition for sort_function

DB Cal_distance (pair <DB,DB> Point_1, pair <DB,DB> Point_2){
	return sqrt((Point_2.first-Point_1.first)*(Point_2.first-Point_1.first) + (Point_2.second-Point_1.second)*(Point_2.second-Point_1.second));
}

DB Brute_force (pair<DB,DB> A[], int first, int last){		// Solve problem in mini_size	
	DB d_min = DBL_MAX;										// DBL_MAX (hang so macro): la so doulbe lon nhat ma may tinh co the bieu dien | FLT_MAX (float_max) | LDLB_MAX (long double max)
    for (int i = first; i <= last - 1; i++)
        for (int j = i + 1; j <= last; j++)
            d_min = min(d_min, Cal_distance(A[i], A[j]));
    return d_min;
}

DB ClosetPair(pair<DB,DB> A[],int first, int last){
	if (last-first <= 3) return Brute_force(A,first,last);	// Brute_force used solve in case have at least 3 points
	int mid = (last+first)/2;				// A[mid] la toa do x trung vi 
	DB d_Lmin = ClosetPair(A,first,mid-1);		// Devide and Conquer
	DB d_Rmin = ClosetPair(A,mid+1,last);		// ------------------
	DB d_min = min(d_Lmin,d_Rmin);				// d_min la distance nho nhat duoc tim thay o 2 ben duong thang trung vi
	vector < pair<DB,DB> > Points_Posible;	// chua cac diem nam trong khoang [limit_l,limit_R]
	DB limit_L = A[mid].first - d_min;     // limit_L la toa do gioi han trai
	DB limit_R = A[mid].first + d_min;     // limit_R la toa do gioi han phai
	int mid_fake = mid-1;
	while (mid_fake >= first && A[mid_fake].first > limit_L){   // tim tat ca Points Posible trong khoang tu [limit_L, x)  -  x la trung vi
		Points_Posible.push_back(A[mid_fake]);
		mid_fake--;
	}
	while (mid <= last && A[mid].first < limit_R){		// tim tat ca Points Posible trong khoang tu [x, limit_R]  -  x la trung vi
		Points_Posible.push_back(A[mid]);
		mid++;
	}
	sort (Points_Posible.begin(),Points_Posible.end(),condition);	// sap xep lai theo y - coordinate
	for (int i = 0 ; i < Points_Posible.size() ; i++){
		int j = 1;
		while (i+j < Points_Posible.size() && Points_Posible[i].second + d_min > Points_Posible[i+j].second){
			d_min = min(d_min, Cal_distance(Points_Posible[i],Points_Posible[i+j]));
			j++;
		}
	}
	return d_min;
}

int main (){
	int T; cin >> T;
	while (T--){
		cin >> N;
		pair <DB,DB> A[N];
		for (int i = 0 ; i < N ; i++) cin >> A[i].first >> A[i].second;
		sort (A,A+N); 												// sap xep lai theo x - coordinate
		cout << setprecision(6) << fixed << ClosetPair(A,0,N-1) << endl;
	}
	return 0;
}
