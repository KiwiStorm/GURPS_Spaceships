#pragma once
#include <string>
#include <fstream>
#include <cmath>
#include <iostream>

typedef long long ll;

using namespace std;

int string_to_int(string s)
{
	int res = 0;
	bool negative = false;
	int i = 0;
	if (s[0] == '-')
	{
		negative = true;
		++i;
	}
	while (i < s.size())
	{
		if (s[i] > '9' || s[i] < '0')
		{
			return 0;
		}
		res *= 10;
		res += s[i] - '0';
		++i;
	}
	if (negative)
	{
		res *= -1;
	}
	return res;
}

class Crewman
{
	string path;
	int ST, HT, DX, IQ, will, perception;
	int get_skill_pure(string s);
	string get_next_tag(ifstream &in);
	void set_to_tag(ifstream &in, string tag);
	string get_intag_val(ifstream &in);
	int get_stat(string name);
public:
	void print()
	{
		cout << ST << " " << DX << " " << IQ << " " << HT << endl;
	}
	Crewman(string path);
	~Crewman() {}
};

int Crewman::get_skill_pure(string name)
{
	ifstream in(path);
	string temp_name;
	while (temp_name != name && !in.eof())
	{
		set_to_tag(in, "skill version=\"2\"");
		set_to_tag(in, "name");
		temp_name = get_intag_val(in);
	}
	if (in.eof())
	{
		return 0;
	}
	set_to_tag(in, "difficulty");
	string info = get_intag_val(in);
	int res = 0;
	res = get_stat(info);
	int i = 0;
	while (info[i] != '/')
	{
		++i;
	}
	++i;
	if (info[i] == 'A')
	{
		res--;
	}
	if (info[i] == 'H')
	{
		res -= 2;
	}
	if (info[i] == 'V')
	{
		res -= 3;
	}
	set_to_tag(in, "points");
	int points = string_to_int(get_intag_val(in));
	if (points == 0)
	{
		set_to_tag(in, "default");
		set_to_tag(in, "type");
		res = get_stat(get_intag_val(in));
		set_to_tag(in, "modifier");
		res += string_to_int(get_intag_val(in));
		return res;
	}
	if (points == 1)
	{
		return res;
	}
	if (points == 2)
	{
		return res + 1;
	}
	return res + points / 4 + 2;
}

inline string Crewman::get_next_tag(ifstream &in)
{
	string res;
	char next = in.get();
	while (!in.eof() && next != '<')
	{
		next = in.get();
	}
	if (in.eof())
	{
		return res;
	}
	next = in.get();
	while (!in.eof() && next != '>')
	{
		res += next;
		next = in.get();
	}
	return res;
}

inline void Crewman::set_to_tag(ifstream &in, string tag)
{
	string temp = get_next_tag(in);
	while (temp != tag && temp != "")
	{
		temp = get_next_tag(in);
	}
}

inline string Crewman::get_intag_val(ifstream & in)
{
	string res;
	char next = in.get();
	while (!in.eof() && next != '<')
	{
		res += next;
		next = in.get();
	}
	return res;
}

inline Crewman::Crewman(string path)
{
	this->path = path;
	ifstream in(path);
	set_to_tag(in, "ST");
	ST = string_to_int(get_intag_val(in));
	set_to_tag(in, "DX");
	DX = string_to_int(get_intag_val(in));
	set_to_tag(in, "IQ");
	IQ = string_to_int(get_intag_val(in));
	set_to_tag(in, "HT");
	HT = string_to_int(get_intag_val(in));
	set_to_tag(in, "will");
	will = string_to_int(get_intag_val(in));
	set_to_tag(in, "perception");
	perception = string_to_int(get_intag_val(in));
	print();
}

inline int Crewman::get_stat(string name)
{
	if (name[0] == 'I')
	{
		return IQ;
	}
	if (name[0] == 'D')
	{
		return DX;
	}
	if (name[0] == 'H')
	{
		return HT;
	}
	if (name[0] == 'S')
	{
		return ST;
	}
	if (name[0] == 'p')
	{
		return perception;
	}
	if (name[0] == 'w')
	{
		return will;
	}
}