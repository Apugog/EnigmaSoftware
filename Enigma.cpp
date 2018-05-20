# include <iostream>;
# include <conio.h>;
using namespace std;
const int r = 3;
const int c = 26;
class Machinery
{
	int g = 0, h = 0;
public:
	void turnwheel(int B[r][c], int R)
	{
		int temp = B[R][c - 1];
		for (int i = c-1; i > 0; i--)
		{
			B[R][i] = B[R][i - 1];
		}
		B[R][0] = temp;
	}
	int input()
	{
		char I;
		cout << "Enter your letter to be coded or decoded\n";
		cin >> I;
		int C = I;
		if (C >= 97 && C <= 122)
			C = C - 96;
		else if (C >= 65 && C <= 90)
			C = C - 64;
		else
			cout << "Invalid Input enter characters only";
		return C;

	}
	void counter(int B[r][c])
	{
		turnwheel(B, 0);
		g++;
		if (g == c)
		{
			turnwheel(B, 1);
			g = 0;
			h++;
			if (h == c)
			{
				turnwheel(B, 2);
				h = 0;
			}
		}
	}
	void wheel_setting(int B[r][c])
	{
		int D;
		for (int i = 0; i < r; i++)
		{
			
			cout << "Enter the value Wheel no." << " " << i + 1 << "\n";
			cin >> D;
			for (int j = 0; j < D; j++)
			{
				turnwheel(B, i);
			}
		}
	}
	void output(int ch)
	{
		switch (ch)
		{
		case 1:cout << "A";
			break;
		case 2:cout << "B";
			break;
		case 3:cout << "C";
			break;
		case 4:cout << "D";
			break;
		case 5:cout << "E";
			break;
		case 6:cout << "F";
			break;
		case 7:cout << "G";
			break; 
		case 8:cout << "H";
			break;
		case 9:cout << "I";
			break;
		case 10:cout << "J";
			break;
		case 11:cout << "K";
			break;
		case 12:cout << "L";
			break;
		case 13:cout << "M";
			break;
		case 14:cout << "N";
			break;
		case 15:cout << "O";
			break;
		case 16:cout << "P";
			break;
		case 17:cout << "Q";
			break;
		case 18:cout << "R";
			break;
		case 19:cout << "S";
			break;
		case 20:cout << "T";
			break;
		case 21:cout << "U";
			break;
		case 22:cout << "V";
			break;
		case 23:cout << "W";
			break;
		case 24:cout << "X";
			break;
		case 25:cout << "Y";
			break;
		case 26:cout << "Z";
			break;
		default:cout << "Program error!!" << "\n";
		}
	}
	int operate_en(int B[r][c], int c)
	{
		int a, b, e;
		a = B[0][c - 1];
		b = B[1][a - 1];
		e = B[2][b - 1];
		return e;
	}
	int operate_de(int B[r][c], int c)
	{
		int a, b, e;
		a = search(B,c,2);
		b = search(B,a,1);
		e = search(B,b,0);
		return e;
	}
	int search(int B[r][c], int j, int k)
	{
		int x;
		for (int p = 0; p < c; p++)
		{
			if (B[k][p] == j)
				x = p + 1;
		}
		return x;
	}
};



int main() 
{
	char z;
	Machinery ob;
	system("cls");
	int A[3][26] = { { 12,6,10,3,2,13,8,26,1,5,14,9,19,20,18,15,16,23,21,22,11,7,24,25,4,16 },
	                 { 13,12,11,9,8,7,6,10,21,3,25,5,17,18,14,20,22,19,2,1,15,16,26,24,4,23 },
	                 { 11,12,13,17,3,5,22,6,7,9,15,10,8,16,18,19,21,2,20,23,24,14,26,25,1,4 } };
	ob.wheel_setting(A);
	cout << "Encryption or Decryption E/D??" << "\n";
	cin >> z;
	int k = 1;
	while (k)
	{
		int C, D;
		char F;
		C = ob.input();
		ob.counter(A);
		if (z == 'E' || z == 'e')
			D = ob.operate_en(A, C);
    else 
		if(z == 'D' || z == 'd')
			D = ob.operate_de(A, C);
		cout << "After codeing or decodeing:";
		ob.output(D);
		cout << "\n Wamt to Enter again Y/N??\n";
		cin >> F;
		if (F == 'Y'|| F=='y')
			k = 1;
		else
			k = 0;

	}
	
	system("pause");
	return 0;
}
