/*
Варіант 2. Створити динамічний клас Book, що містить динамічний масив Authors,
де інформація про автора містить (П.І.Б., кількість книжок, рік народження),
а також всю необхідну інформацію про книжку.
Клас повинен містити наступні операції:
add_author() – додавання авторів;
del_author() – видалення авторів;
count_authors() – підраховує кількість авторів.
Також потрібно реалізувати масив книжок та friend-функції введення/виведення інформації в каталог.

*/
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <Windows.h>
using namespace std;

class Book
{
public:

	class Authors
	{
	public:
		Authors(string name, string lastname);

		bool operator==(Authors& other);
		string Getdata() { return name + " " + lastname + ", " + to_string(kst_book) + " books, " + to_string(Birthday.tm_mday) + "." + to_string(Birthday.tm_mon) + "." + to_string(Birthday.tm_year); }
	private:
		string name;
		string lastname;
		int kst_book;
		tm Birthday;
	};

	void insetup(string path = "filename.txt", ofstream::openmode mode = 1);
	string outsetup(string path = "filename.txt");

	void add_author(Authors& ptr);

	void del_author(Authors& autor);
	void del_author(int num);
	int count_authors();


private:
	vector<Authors> auth_list;
};


void Book::insetup(string path, ofstream::openmode mode)
{
	ifstream buf(path);
	string str;
	getline(buf, str);
	buf.close();
	if (str != "Всі дані в черзі:")
	{
		ofstream insetup(path);
		if (!insetup.is_open())
		{
			cout << "Помилка запису у файл." << endl;
			return;
		}
		insetup << "Всі дані в черзі:" << endl;
		insetup.close();
	}


	ofstream insetup(path, fstream::app);
	if (!insetup.is_open())
	{
		cout << "Помилка запису у файл." << endl;
		return;
	}

	for (auto& el : auth_list)
	{
		insetup << el.Getdata() << endl;
	}

	insetup << "----------------------------------" << endl;
	insetup.close();
}

string Book::outsetup(string path)
{
	string out = "";
	string buf = "";
	ifstream outsetup(path);
	if (!outsetup.is_open())
	{
		cout << "Помилка читання файлу." << endl;
		return "";
	}

	while (!outsetup.eof())
	{
		getline(outsetup, buf);
		out += buf + "\n";
		buf = "";
	}
	outsetup.close();
	return out;
}


void Book::add_author(Authors& ptr)
{
	auth_list.push_back(ptr);
}


void Book::del_author(Authors& autor)
{
	for (size_t i = 0; i < auth_list.size(); i++)
	{
		auto scroll = auth_list.begin();

		if (*scroll == autor)
		{
			auth_list.erase(scroll);
		}

		scroll++;
	}
}

void Book::del_author(int num)
{
	auth_list.erase(auth_list.begin() + num);
}

int Book::count_authors()
{
	return auth_list.size();
}

Book::Authors::Authors(string name, string lastname)
{
	this->name = name;
	this->lastname = lastname;
	this->kst_book = rand() % 10;
	Birthday.tm_year = 1900 + rand() % 121;
	Birthday.tm_mon = rand() % 12;
	Birthday.tm_mday = 1 + rand() % 31;
}

bool Book::Authors::operator==(Authors& other)
{
	return (this->name == other.name && this->lastname == other.lastname && this->kst_book == other.kst_book);
}


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Book one;
	Book::Authors aut1("Kolya", "Skripchenko");
	Book::Authors aut2("Badim", "Verezaniuk");

	one.add_author(aut1);
	one.add_author(aut2);

	one.insetup();
	cout << one.outsetup();

	cout << "kst author: " << one.count_authors() << endl;
}