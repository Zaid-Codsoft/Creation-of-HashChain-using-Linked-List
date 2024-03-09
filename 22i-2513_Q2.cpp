// Name : zaid , Section SE-A , Roll No : 22i-2513
#include<iostream>
#include<string>
using namespace std;
template<typename T>
class Node
{
public:
	T data;
	T chainData;
	Node<T>* next;
	Node<T>* chainNext;
	Node() {
		chainNext = nullptr;
		next = nullptr;
		
	}
	
};

template<typename T>
class CircularLinkedList {
private: 
	Node<T>* head;
public:
	CircularLinkedList():head(nullptr){}
	Node<T>* Insert(T val ) {
		Node<T>* newNode = new Node<T>();
		newNode->data = val;

		if (!head) {
			head = newNode;
			head->next = head;
			return head;
		}

		Node<T>* Current = head;
		
		while (Current->next != head) {
			Current = Current->next;
		}
		Current->next = newNode;
		newNode->next = head;
		return newNode;

	}
	

	void insertInChain(T val) {
		


		if (!head) {
			cout << "List is empty" << endl;
			return;
		}
		Node<T>* current = head;
		Node<T>* newNode = new Node<T>();
		newNode->chainData = val;
		
		
		bool duplicate = false;
		do {
			if (current->data[0] == newNode->chainData[0]) {
				
				Node<T>* Ccurrent = current->chainNext;
				
				while (Ccurrent) {
					if (Ccurrent->chainData == newNode->chainData) {
						duplicate = true;
						break;
					}
					Ccurrent = Ccurrent->chainNext;
				}
				if (!duplicate) {
					if (!current->chainNext) {
						current->chainNext = newNode;
					}
					else {
						Node<T>* Temp = current->chainNext;
						current->chainNext = newNode;
						newNode->chainNext = Temp;
					}
				}
				break;
			}
			current = current->next;
		} while (current != head);

		if (duplicate) {
			cout << "Duplicate data : \"" << val <<" \" Not inserted" << endl;
		}
		else {
			cout << "Inserted data : " << val << endl;
		}
		
	}
	


	void DisplayChain(Node<T>* curr) {
		Node<T>* current = curr->chainNext;
		cout << " ( ";
		while (current != nullptr) {
			cout<<"[" << current->chainData << "] ";
			current=current->chainNext;
		}
		cout << ") ";

	}

	void display() {
		if (!head) {
			cout << "List is empty" << endl;
			return;
		}
		Node<T>* current = head;
		do {
			cout << current->data << " ";
			if (current->chainNext != nullptr) {
				DisplayChain(current);
			}
			current = current->next;
		}
			
		while (current != head);
		
	
	}
};

int main(){
	CircularLinkedList<string> obj;
	for (char c = 'A'; c <= 'Z'; ++c) {
		string S ;
		S.push_back(c);
		obj.Insert(S); 
	}
	for (char cha = 'a'; cha <= 'z'; ++cha) {
		string S;
		S.push_back(cha);
		obj.Insert(S); 
	}

	char Choice;
	do {
		cout << "\n								......MENU OF CIRCULAR CHAIN.......\n";
		cout << "1. Insert Data In Chain\n";
		cout << "2. Display\n";
		cout << "3. Exit\n";
		cout << "Select your Choice : ";
		cin >> Choice;

		switch (Choice) {
		case '1': {
			string newData;
			cout << "Write Sentence to Store In Chain : ";
			cin.ignore(); 
			getline(cin, newData); 
			
			obj.insertInChain(newData);
			break;
		}
		case '2':
			cout << "Current Content :\n\n";
			obj.display();

			break;
		case '3':
			cout << "Closing the Program...  Byeee Byeee ... Happy Coding\n";
			break;
		default:
			cout << "Invalid selection! Please Try Later Go To Sleep Now.\n";
		}
	} while (Choice != '3');
	
	
	
}