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
using namespace std;

class Book
{
public:

	class Authors
	{
	public:
		Authors(string name, string lastname)
		{
			this->name = name;
			this->lastname = lastname;

		}

		bool operator==(Authors& other)
		{
			return (this->name == other.name && this->lastname == other.lastname && this->kst_book == other.kst_book);
		}

	private:
		string name;
		string lastname;
		int kst_book;
		tm Birthday;
	};

	void add_author(Authors& ptr)
	{
		auth_list.push_back(ptr);
	}

	void del_author(Authors& autor)
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
	void del_author(int num)
	{
		auth_list.erase(auth_list.begin() + num);
	}

	int count_authors()
	{
		return auth_list.size();
	}


private:
	vector<Authors> auth_list;
};



int main()
{
	Book one;
	Book::Authors aut1("Kolya", "Skripchenko");
	Book::Authors aut2("Badim", "Verezaniuk");

	one.add_author(aut1);
	one.add_author(aut2);


	cout << "kst author: " << one.count_authors() << endl;
}



