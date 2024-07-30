#include<iostream>
using namespace std;

#define Max 100
int a[Max] = { 0 };
int n = 0;

void intput(int a[], int& n)
{
	cout << "Nhap n: ";
	cin >> n;
	while (n > 100 || n < 1)
	{
		cout << "Nhap lai! n = ";
		cin >> n;
	}
	for (int i = 0; i < n; i++)
	{
		cout << "a[" << i << "] = ";
		cin >> a[i];
	}
}

void output(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "\t" << a[i];
	}
	cout << endl;
}

// Tim kiem 1 phan tu co trong danh sach/ko
int search(int a[], int n, int x)
{
	int i = 0;
	while (i < n && a[i] != x)
	{
		i++;
	}
	if (i == n)
		return -1;
	return 1;
}

//Them 1 phan tu vao cuoi danh sach
void addlast(int a[], int& n, int y)
{
	a[n] = y;
	n++;
}

//Xoa phan tu cuoi danh sach
void deletelast(int a[], int& n)
{
	n--;
}

//Xoa tai vi tri thu i
int deletevt(int a[], int& n, int i)
{
	if (i >= 0 && i < n)
	{
		for (int j = i; j < n - 1; j++)
		{
			a[j] = a[j + 1];
		}
		n--;
		return 1;
	}
	return 0;
}

//Them phan tu tai vi tri thu i
int addvt(int a[], int& n, int i, int x)
{
	if (i >= 0 && i < n)
	{
		n++;
		for (int j = n; j >= i + 1; j--)
		{
			a[j] = a[j - 1];
		}
		a[i] = x;
		return 1;
	}
	return 0;
}

//Kt phan tu ton tai trong ds. Neu co thi xoa phan tu do
void deleteptu(int a[], int& n, int x)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] == x)
		{
			for (int j = i; j < n - 1; j++)
			{
				a[j] = a[j + 1];
			}
			n--;
		}
	}
}

int main() {
	bool check = true;
	int op = 0;

	while (check == true)
	{
		cout << "===============MENU===============\n";
		cout << " 1. Nhap ds\n";
		cout << " 2. Xuat ds\n";
		cout << " 3. Tim phan tu\n";
		cout << " 4. Them phan tu vao cuoi ds\n";
		cout << " 5. Xoa phan tu cuoi ds\n";
		cout << " 6. Xoa phan tu tai vi tri i\n";
		cout << " 7. Them phan tu tai vi tri i\n";
		cout << " 8. Kiem tra phan tu ton tai hay ko. Neu co xoa phan tu\n";
		cout << "*****Nhan phim ngau nhien de thoat chuong trinh\n";
		cout << "\n==>Lua chon: "; cin >> op;
		switch (op)
		{
		case 1:
		{
			intput(a, n);
			break;
		}
		case 2:
		{
			output(a, n);
			break;
		}
		case 3:
		{
			int x = 0;
			cout << "Nhap phan tu can tim: ";
			cin >> x;
			if (search(a, n, x) == 1)
			{
				cout << x << " Co trong danh sach\n";
			}
			else
			{
				cout << x << " Ko tim thay trong danh sach\n";
			}
			break;
		}
		case 4:
		{
			int y = 0;
			cout << "Nhap phan tu them vao cuoi ds: ";
			cin >> y;
			addlast(a, n, y);
			cout << "DS sau kh them: \n";
			output(a, n);
			break;
		}
		case 5:
		{
			cout << "Mang sau khi xoa phan tu cuoi trong ds: \n";
			deletelast(a, n);
			output(a, n);
			break;
		}
		case 6:
		{
			int i = 0;
			cout << "Nhap vi tri can xoa: ";
			cin >> i;
			if (deletevt(a, n, i) == 1)
			{
				cout << "Ds sau khi xoa phan tu thu " << i << ":\n";
				output(a, n);
			}
			else
			{
				cout << "Vi tri ko hop le!\n";
			}
			break;
		}
		case 7:
		{
			int vt = 0;
			int k = 0;
			cout << "Nhap phan tu can them: "; cin >> k;
			cout << "Nhap vi tri them phan tu: "; cin >> vt;
			if (addvt(a, n, vt, k) == 1)
			{
				cout << "Ds sau khi them: \n";
				output(a, n);
			}
			else
			{
				cout << "Vi tri ko hop le!\n";
			}
			break;
		}
		case 8:
		{
			int ptu = 0;
			cout << "Nhap phan tu can xoa: "; cin >> ptu;
			if (search(a, n, ptu) == 1)
			{
				deleteptu(a, n, ptu);
				cout << "Ds sau khi xoa phan tu " << ptu << ":\n";
				output(a, n);
			}
			else
			{
				cout << "Ko tim thay phan tu!\n";
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