#include <bits/stdc++.h>
using namespace std;

int T,N,M;

class List{
	private:	// Data		
		typedef struct node{
			int Data;
			node* next;
		}* nodePtr;
								
		nodePtr head;	// tro vi tri dau list
		nodePtr temp;	// dung la con tro da nang
		nodePtr last;	// tro vi tri cuoi cung cua list
		nodePtr nodeX;	// tro vao node can xoa
		nodePtr newNode;// tro vao node moi can them vao
	public:		// Function
		List ();
		void AddNode (int stt);
		void DeleteNode (nodePtr tmp);
		void Noi ();
		void Exe ();
};

List::List(){
	head = NULL;
	temp = NULL;
	last = NULL;
	nodeX = NULL;
	newNode = NULL;
}

void List::AddNode(int stt){
	newNode = new node;
	newNode->Data = stt;
	newNode->next = NULL;
	if (head != NULL){
		last->next = newNode;
		last = last->next;
	} else {
		head = newNode;
		last = newNode;
	}
}

void List::DeleteNode(nodePtr tmp){
	nodeX = tmp->next;
	tmp->next = nodeX->next;
	delete(nodeX);
}

void List::Noi(){
	last->next = head;
}

void List::Exe(){
	temp = head;
	int size_list = N;
	while (temp != temp->next){ // Linked List chi con 1 phan tu thi dung
		if (M%N==0){
			nodePtr pre = temp;
			pre = pre->next;
			while (pre->next != temp) pre = pre->next;
			temp = pre;
		} else {
			for (int i = 2 ; i <= M%N ; i++) temp = temp->next;		
		}
		DeleteNode(temp); 	// delete node ke tiep tmp
		N--;
		temp = temp->next;
	}
	cout << temp->Data << endl;	
}


int main (){
	cin >> T;
	while (T--){
		cin >> N >> M;
		if (N == 1) {
			cout << 1 << endl;
			continue;
		}
		List A;
		for (int i = 1 ; i <= N ; i++) A.AddNode(i);
		A.Noi();
		A.Exe();
	}
	return 0;
}
