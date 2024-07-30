#include <iostream>
#include <string>
using namespace std;

struct VIDEO
{
	string tenphim;
	string theloai;
	string tendaodien;
	int nam;
};

struct DSVIDEO
{
	VIDEO* dsvideo;
	int n;
};

//Nhap thong tin 1bo phim
void Nhap1bo(VIDEO& phim)
{
	cout << "===============================\n";
	cin.ignore();
	cout << "Nhap ten phim: ";
	getline(cin, phim.tenphim);
	cout << "Nhap the loai: ";
	getline(cin, phim.theloai);
	cout << "Nhap ten dao dien: ";
	getline(cin, phim.tendaodien);
	cout << "Nhap nam san xuat: ";
	cin >> phim.nam;
}

// Xuat thong tin 1 video
void Xuat1bo(VIDEO phim)
{
	cout << "\n===============================\n";
	cout << "Ten phim: " << phim.tenphim << endl;
	cout << "Theo loai: " << phim.theloai << endl;
	cout << "Ten dao dien: " << phim.tendaodien << endl;
	cout << "Nam san xuat: " << phim.nam << endl;
	cout << "===============================\n";
}

// nhap n bo phim
void Nhapnds(DSVIDEO& bophim)
{
	cout << "Nhap so bo phim: ";
	cin >> bophim.n;
	while (bophim.n <= 0)
	{
		cout << "Nhap lai! n = ";
		cin >> bophim.n;
	}

	bophim.dsvideo = new VIDEO[bophim.n];
	for (int i = 0; i < bophim.n; i++)
	{
		Nhap1bo(bophim.dsvideo[i]);
	}
}

// Xuat ds video
void Xuatds(DSVIDEO bophim)
{
	for (int i = 0; i < bophim.n; i++)
	{
		Xuat1bo(bophim.dsvideo[i]);
	}
}

void HUYCPD(DSVIDEO& bophim)
{
	delete[]bophim.dsvideo;
	bophim.dsvideo = NULL;
}

void Searchds(DSVIDEO bophim, string tendaodien)
{
	bool kt = false;
	for (int i = 0; i < bophim.n; i++)
	{
		if (bophim.dsvideo[i].tendaodien == tendaodien)
		{
			Xuat1bo(bophim.dsvideo[i]);
			kt = true;
		}
	}
	if (kt == false)
	{
		cout << "Tim khong thay!\n";
	}
}

// Sap xep bo phim co nam san xuat tang dan
void sapxep(DSVIDEO& bophim)
{
	for (int i = 0; i < bophim.n - 1; i++)
	{
		for (int j = i; j < bophim.n; j++)
		{
			if (bophim.dsvideo[i].nam > bophim.dsvideo[j].nam)
			{
				swap(bophim.dsvideo[i], bophim.dsvideo[j]);
			}
		}
	}
}

int main() {
	VIDEO phim;
	DSVIDEO bophim;

	bool check = true;
	int op = 0;
	while (check)
	{
		cout << "====================MENU================\n";
		cout << " 1. Nhap thong tin 1 bo phim\n";
		cout << " 2. Nhap thong tin n bo phim\n";
		cout << " 3. Xuat thong tin n bo phim\n";
		cout << " 4. Tim va xuat ds bo phim cua dao dien\n";
		cout << " 5. Sap xep tang dan theo nam\n";

		cout << "****Nhan 1 phim bat ky de ket thuc chuong trinh\n\n";
		cout << "===>Lua chon cua ban: ";
		cin >> op;

		switch (op)
		{
		case 1:
		{
			Nhap1bo(phim);
			Xuat1bo(phim);
			break;
		}
		case 2:
		{
			Nhapnds(bophim);
			break;
		}
		case 3:
		{
			cout << "\t\tDS THONG TIN CAC BO PHIM\n";
			Xuatds(bophim);
			break;
		}
		case 4:
		{
			string tendaodien;
			cin.ignore();
			cout << "Nhap ten tac gia: ";
			getline(cin, tendaodien);
			cout << "\n\t\tDS TAC PHAM CUA DAO DIEN " << tendaodien << endl;
			Searchds(bophim, tendaodien);
			break;
		}
		case 5:
		{
			cout << "\t\tDS SAU KHI SAP XEP\n";
			sapxep(bophim);
			Xuatds(bophim);
			break;
		}
		default:
		{
			check = false;
			break;
		}
		}
	}

	HUYCPD(bophim);
	system("pause");
	return 0;
}