#include <iostream>
using namespace std;

//Khai bao cau truc
struct Node
{
	int value;
	Node* next;
};

//Khoi tao ds rong
void init(Node* head)
{
	head = NULL;
}

bool isempty(Node* head)
{
	if (head == NULL) return true;
	return false;
}

Node* createNode(int x)
{
	Node* p = new Node;
	p->value = x;
	p->next = NULL;
	return p;
}

void output(Node* head)
{
	Node* p = head;
	while (p != NULL)
	{
		cout << p->value << "\t";
		p = p->next;
	}
}

// Them vao dau ds
void addfirst(Node* &head, int x)
{
	Node* p = createNode(x);
	p->next = head;
	head = p;
}

// Them vao cuoi ds
void addlast(Node*& head, int x)
{
	Node* p = createNode(x);

	if (head == NULL)
	{
		head = p;
	}
	else
	{
		// Xac dinh Node cuoi cung
		Node* last = head;
		while (last->next != NULL)
		{
			last = last->next;
		}

		// Them ptu vao cuoi
		last->next = p;
	}
}

// Tim kiem phan tu
Node *search(Node*& head, int ptu)
{
	Node* p = head;
	while (p != NULL && p->value != ptu)
	{
		p = p->next;
	}
	// Tra ve NULL khi ko tim thay, tra ve dia chi khi pyu ton tai
	return p;
}

// Xoa phan tu dau ds
int deletefirst(Node*& head)
{
	if (head != NULL)
	{
		Node* p = head;
		head = p->next;
		p->next = NULL;
		delete(p);
		return 1;
	}
	return 0;
}

// Xoa phan tu cuoi
int deletelast(Node*& head)
{
	if (head != NULL)
	{
		// Xac dinh ptu cuoi va ptu ke cuoi ds
		Node* last = head;
		Node *prev = NULL;
		while (last->next != NULL)
		{
			prev = last;
			last = last->next;
		}

		if (prev == NULL)
		{
			deletefirst(head);
		}
		else
		{
			// Xoa ptu cuoi ds
			prev->next = NULL;
			delete(last);
		}
		return 1;
	}
	return 0;
}

// Tim ptu trong ds roi xoa ptu do
int searchanddelete(Node*& head, int ptu)
{
	if (head != NULL)
	{
		Node* p = head;
		Node* prev = NULL;
		while (p != NULL && p->value != ptu)
		{
			prev = p;
			p = p->next;
		}
		
		if (p != NULL) // Tim thay phan tu can xoa
		{
			// Ds chi co 1 phan tu
			if (prev == NULL)
			{
				deletefirst(head);
			}
			else
			{
				prev->next = p->next;
				p->next = NULL;
				delete(p);
			}
		}
		return 1;
	}
	return 0;
}

// Ds co thu tu
void sort(Node*& head)
{
	for (Node *p = head; p->next != NULL; p = p->next)
	{
		Node *min = p;
		for (Node *q = p->next; q != NULL; q = q->next)
		{
			if (q->value < min->value)
			{
				min = q;
			}
		}
		int tmp = min->value;
		min->value = p->value;
		p->value = tmp;
	}
}

int main() {
	Node* head = NULL;
	int x = 0;
	bool check = true;
	int op = 0;


	// lam menu de goi tao 1 node moi
	while(check)
	{
		cout << "\n=============MENU===========\n";
		cout << " 0. Kt ds rong\n";
		cout << " 1. Khoi tao ds\n";
		cout << " 2. Xuat ds\n";
		cout << " 3. Them 1 phan tu vao dau ds\n";
		cout << " 4. Them 1 phan tu vao cuoi ds\n";
		cout << " 5. Tim kiem phan tu\n";
		cout << " 6. Xoa phan tu dau cua ds\n";
		cout << " 7. Xoa phan tu cuoi cua ds\n";
		cout << " 8. Tim phan tu trong ds roi xoa\n";
		cout << " 9. Ds co thu tu\n";

		cout << "***Nhan phim bat ky bat ky de thoat chuong trinh\n\n";
		cout << "===>Lua chon cua ban: ";
		cin >> op;
		switch(op)
		{
		case 0:
		{
			if (isempty(head))
			{
				cout << "DS rong!\n";
			}
			else
			{
				cout << "DS khac rong!\n";
			}
			break;
		}
		case 1:
		{
			init(head);
			break;
		}
		case 2:
		{
			output(head);
			cout << endl;
			break;
		}
		case 3:
		{
			cout << "Nhap phan tu can them: ";
			cin >> x;
			addfirst(head, x);
			break;
		}
		case 4:
		{
			cout << "Nhap phan tu can them: ";
			cin >> x;
			addlast(head, x);
			break;
		}
		case 5:
		{
			cout << "Nhap phan tu can tim kiem: ";
			cin >> x;
			if (search(head, x) != NULL)
			{
				cout << "Phan tu co trong ds: " << search(head, x) << endl;
			}
			else
			{
				cout << "Khong tim thay phan tu!\n";
			}
			break;
		}
		case 6:
		{
			if (deletefirst(head) != 0)
			{
				cout << "Xoa thanh cong!\n";
			}
			else
			{
				cout << " Ds rong1 Vui long khoi tao ds moi!\n";
			}
			break;
		}
		case 7:
		{
			if (deletelast(head) != 0)
			{
				cout << "Xoa thanh cong!\n";
			}
			else
			{
				cout << " Ds rong1 Vui long khoi tao ds moi!\n";
			}
			break;
		}
		case 8:
		{
			cout << "Nhap phan tu: ";
			cin >> x;
			if (searchanddelete(head, x) != 0)
			{
				cout << "Tim thay ptu va da xoa!\n";
			}
			else
			{
				cout << "Ko tim thay ptu trong ds!\n";
			}
			break;
		}
		case 9:
		{
			sort(head);
			break;
		}
		default:
		{
			check = false;
			break;
		}
		}
	}

	system("pause");
	return 0;
}