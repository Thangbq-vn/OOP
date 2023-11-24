#include<bits/stdc++.h>
using namespace std;

class Tong
{
	private:
		int a;
	
	public:
		friend istream& operator >>(istream &is, Tong &p)
		{
			is >> p.a;
		}
	
		friend ostream& operator <<(ostream &os, Tong p)
		{
			os << p.a;
			return os;
		}
	
		friend Tong operator +(Tong p1, Tong p2)
		{
			Tong c;
			c.a = p1.a +p2.a;
			return c;
		}
};


int main()
{
	Tong a,b;
	
//	cout << "nhap so a: ";
	cin >> a;
//	cout << "nhap so b: ";
	cin >> b;
	Tong c = a + b;
	cout << c << endl;
	return 0;
}
