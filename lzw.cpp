#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>
using namespace std;
#pragma warning(disable:4996)
string dic[30];
int n;
fstream in("in2.txt");
fstream out("out2.txt");
int find(string s)
{
	int temp = -1;
	for (int i = 0; i<30; i++)
	{
		if (dic[i] == s) temp = i + 1;
	}
	return temp;
}
void init()
{
	dic[0] = "a";
	dic[1] = "b";
	dic[2] = "c";
	dic[3] = "d";
	for (int i = 4; i<30; i++)
	{
		dic[i] = "";
	}
}
void code(string str)
{
	init();
	char temp[2];
	temp[0] = str[0];
	temp[1] = '\0';
	string w = temp;
	int i = 1;
	int j = 3;
	cout << "\n  编码为：";
	out << "\n  编码为：";
	for (;;)
	{
		char t[2];
		t[0] = str[i];
		t[1] = '\0';
		string k = t;
		if (k == "")

		{
			cout << " " << find(w);
			out << " " << find(w);
			break;
		}
		if (find(w + k)>-1)
		{
			w = w + k;
			i++;
		}
		else
		{
			cout << " " << find(w);
			out << " " << find(w);
			string wk = w + k;
			dic[j++] = wk;
			w = k;
			i++;
		}
	}
	cout << endl;
	out << endl;
	for (i = 0; i<j; i++)
	{
		cout << setw(45) << i + 1 << setw(12) << dic[i] << endl;
		out << setw(45) << i + 1 << setw(12) << dic[i] << endl;
	}
	cout << endl;
	out << endl;
}
void decode(int c[])
{
	init();
	int pw, cw;
	cw = c[0];
	int j = 2;
	cout << "\n  译码为：";
	out << "\n  译码为：";
	cout << dic[cw - 1];
	out << dic[cw - 1];
	for (int i = 0; i<n - 1; i++)
	{
		pw = cw;
		cw = c[i + 1];
		if (cw <= j + 1)
		{
			cout << dic[cw - 1];
			out << dic[cw - 1];
			char t[2];
			t[0] = dic[cw - 1][0];
			t[1] = '\0';
			string k = t;
			j++;
			dic[j] = dic[pw - 1] + k;
		}
		else
		{
			char t[2];
			t[0] = dic[pw - 1][0];
			t[1] = '\0';
			string k = t;
			j++;
			dic[j] = dic[pw - 1] + k;
			cout << dic[cw - 1];
			out << dic[cw - 1];
		}
	}
	cout << endl;
	out << endl;
	for (int i = 0; i<j + 1; i++)
	{
		cout << setw(45) << i + 1 << setw(12) << dic[i] << endl;
		out << setw(45) << i + 1 << setw(12) << dic[i] << endl;
	}
	cout << endl;
	out << endl;
}
void main()
{
	char str[100];
	while (!in.eof())
	{
		cout << "\n\n\ta.编码\tb.译码\n\n";
		cout << "请选择：";
		char cha;
		cin >> cha;
		if (cha == 'a')
		{
			in.getline(str, 100);
			cout << "\n要编码的字符串(由a,b,c,d组成)：";
			cout << str;
			code(str);
		}
		else
		{
			int c[30];
			cout << "\n消息序列长度是：";
			cin >> n;
			cout << "\n消息码字依次是：";
			for (int i = 0; i<n; i++)
			{
				cin >> c[i];
			}
			decode(c);
		}
	}
	in.close();
	out.close();
}
