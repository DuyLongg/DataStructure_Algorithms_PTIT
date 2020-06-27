#include <bits/stdc++.h>
using namespace std;

class List{
	private:	// Data		
		typedef struct node{
			int Data;
			int Pow;
			node* next;
		}* nodePtr;
								
		nodePtr head;
		nodePtr cur;
		nodePtr temp;		
	public:		// Function
		List ();
		void AddNode (int addData, int addPow);
		void PrintList ();
		void addPoly (List &P2, List &P3);
};

List::List(){
	head = NULL;
	temp = NULL;
	cur  = NULL;
}

void List::AddNode(int addData, int addPow){
	nodePtr n = new node;
	n->next = NULL;
	n->Data = addData;
	n->Pow = addPow;
	
	if (head != NULL){
		cur = head;
		while (cur->next != NULL){
			cur = cur->next;
		}
		cur->next = n;
	} else head = n;
	
}

void List::PrintList(){
	cur = head;
	while (cur->next != NULL){
		cout << cur->Data << "*x^" << cur->Pow;
		cur = cur->next;
		if (cur->next != NULL) cout << " + ";
	}
	cout << endl;
}

void List::addPoly (List &P2, List &P3){
	nodePtr cur1 = head; // P1.head
	nodePtr cur2 = P2.head;
	nodePtr cur3 = P3.head;
	while (cur1->next && cur2->next){
		if (cur1->Pow > cur2->Pow){
			cur3->Data = cur1->Data;
			cur3->Pow  = cur1->Pow;
			cur1 = cur1->next;
		} else if (cur1->Pow < cur2->Pow){
			cur3->Data = cur2->Data;
			cur3->Pow  = cur2->Pow;
			cur2 = cur2->next;		
		} else {
			cur3->Data = cur1->Data + cur2->Data;
			cur3->Pow  = cur1->Pow;
			cur1 = cur1->next;
			cur2 = cur2->next;
		}
		cur3->next = new node;
		cur3 = cur3->next;
		cur3->next = NULL;
	}
	while (cur1->next || cur2->next){
		if (cur1->next){
			cur3->Data = cur1->Data;
			cur3->Pow = cur1->Pow;
			cur1 = cur1->next;
		}
		if (cur2->next){
			cur3->Data = cur2->Data;
			cur3->Pow = cur2->Pow;
			cur2 = cur2->next;			
		}
		cur3->next = new node;
		cur3 = cur3->next;
		cur3->next = NULL;		
	}
}

List Create_poly(string S){
	int N = S.length();
	List P;
	for (int i = 0 ; i < N ; i++){
		int heso = 0, mu = 0;
		if (S[i] >= '0' && S[i] <= '9'){
			if (i == 0 || S[i-1] != '^'){
				while (S[i] != '*'){
					heso = heso*10+S[i]-'0';
					i++;
				}
			}
			i = i + 3;
			while (S[i] != ' ' && i < N){
				mu = mu*10+S[i]-'0';
				i++;
			}
			P.AddNode(heso,mu);
		}
	}
	return P;
}

int T;
string S1,S2;

int main (){
	cin >> T; cin.ignore();
	while (T--){
		getline(cin,S1);
		getline(cin,S2);
		List P1 = Create_poly(S1); P1.AddNode(0,0);
		List P2 = Create_poly(S2); P2.AddNode(0,0);	
	//	P1.PrintList();
	//	P2.PrintList();
		List P3; P3.AddNode(0,0);
		P1.addPoly(P2, P3);
		P3.PrintList();
	}
	return 0;
}
