// DS LIEN KET KEP
#include <iostream>
using namespace std;

// Khai bao cau truc
struct Node
{
	int value; // Thong tin ptu
	Node* next, * previous; // Dia chi ptu phia sau va phia trc no
};

// Khai bao ds first = head
Node* first, * last;

// Khai bao ds rong
void init()
{
	first = NULL;
	last = NULL;
}

// Kt ds rong
bool isempty()
{
	if (first == NULL) return true;
	return false;
}

// Duyet ds = Xuat ptu trong ds
// Duyet tu dau den cuoi
void output_first()
{
	Node* p = first;
	while (p != NULL)
	{
		cout << p->value << "\t";
		p = p->next;
	}
}

// Them ptu vao dau ds
void addfirst(int x)
{
	Node* p = new Node;
	p->value = x;
	p->next = first;
	p->previous = NULL;
	if (first != NULL)
	{
		first->previous = p;
	}
	else
	{
		last = p;
	}
	first = p;
}

// Them vao cuoi ds
void addlast(int x)
{
	Node* p = new Node;
	p->value = x;
	p->previous = last;
	p->next = NULL;
	if (last != NULL)
	{
		last->next = p;
	}
	else
	{
		first = p;
	}
	last = p;
}

// Xoa ptu dau ds
int deletefirst()
{
	if (first != NULL)
	{
		Node* p = first;
		first = first->next;
		delete p;
		if (first != NULL)
		{
			first->previous = NULL;
		}
		else
		{
			last = NULL;
		}
		return 1;
	}
	return 0;
}

// Xoa phan tu cuoi ds
int deletelast()
{
	if (first != NULL)
	{
		Node* p = last;
		last = last->previous;
		if (first != NULL)
		{
			last->next = NULL;
		}
		else
		{
			first = NULL;
		}
		delete p;
		return 1;
	}
	return 0;
}

// Tim 1 ptu trong ds, neu co xoa ptu do

// Tim ptu gan bang lon hon hoac bang x nhap vao. R them ptu vao trc x

int main() {
	Node* first = NULL;
	bool check = true;
	int op = 0;
	int x = 0;

	while (check)
	{
		cout << "\n==============MENU==============\n";
		cout << " 1. Kt ds rong\n";
		cout << " 2. Khoi tao ds\n";
		cout << " 3. Xuat hay duyet ds\n";
		cout << " 4. Them 1 phan tu vao dau ds\n";
		cout << " 5. Them 1 phan tu vao cuoi ds\n";
		cout << " 6. Xoa phan tu dau ds\n";
		cout << " 7. Xoa phan tu cuoi ds\n";

		cout << "****Nhan 1 phim bat ky de ket thuc chuong trinh\n\n";
		cout << "===>Lua chon cua ban: ";
		cin >> op;
		switch (op)
		{
		case 1:
		{
			if (isempty())
			{
				cout << "DS rong!\n";
			}
			else
			{
				cout << "DS khac rong!\n";
			}
			break;
		}
		case 2:
		{
			init();
			break;
		}
		case 3:
		{
			output_first();
			cout << endl;
			break;
		}
		case 4:
		{
			cout << "Nhap phan tu can them: ";
			cin >> x;
			addfirst(x);
			break;
		}
		case 5:
		{
			cout << "Nhap phan tu can them: ";
			cin >> x;
			addlast(x);
			break;
		}
		case 6:
		{
			if (deletefirst() != 0)
			{
				cout << " Da xoa thanh cong!\n";
			}
			else
			{
				cout << " Xoa ko thanh cong!\n";
			}
			break;
		}
		case 7:
		{
			if (deletelast() != 0)
			{
				cout << " Da xoa thanh cong!\n";
			}
			else
			{
				cout << " Xoa ko thanh cong!\n";
			}
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