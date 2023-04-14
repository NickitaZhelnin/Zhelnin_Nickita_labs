#include<iostream>
#include<string>
#include<random>
#include<time.h>
using namespace std;

string name[10] = {"Иван", "Андрей", "Антон", "Амин", "Роберт", "Георгий", "Борис", "Владислав", "Дмитрий", "Никита"};
string patronymic[10] = {"Иванович", "Андреевич", "Антонович", "Сергеевич", "Робертович", "Георгиевич", "Борисович", "Владиславович", "Дмитриевич", "Ильич"};
string surname[10] = {"Карпов", "Афанасьев", "Власов","Маслов","Исаков","Тихонов","Аксёнов","Гаврилов","Родионов","Котов"};
string dates[10] = {"12.12.2011","18.05.1030","09.01.2000","21.03.2003","19.10.2010","23.09.2009","24.10.2010","25.11.2011","26.12.2012","27.01.1988"};
string adress[10] = {"Уральская 2","Петрова 23","Солнечная 34","Еремова 8","Васина 43","Кутакбетова 333","Магомедовна 777","Щукина 25","Язь 93","Волжская 12"};
int coll_num = 0;
struct Human
{
	Human()
	{
		full_name = "NULL";
		date = "NULL";
		adress = "NULL";
	}
	string full_name;
	string date;
	string adress;
};
struct hash_table
{
	Human*array;
	hash_table(int size)
	{
		array = new Human[size];
	}
	~hash_table()
	{
		delete[]array;
	}
	void find_index(string adress, const int size);
	void add(Human tmp, const int size);
};
void show_table(hash_table*table, const int size);
void show(const Human tmp);
Human creator();
string get_random_name(); string get_random_birthday(); string get_random_adress(); 
void print_Humans(const Human* const array, const int size);
int get_random_num();
int get_sum_id(string str);
int hash_function(string str, const int size);
void fill_creator(Human*array, const int count);
void hash_table::find_index(string adress, const int size)
{
	int hash = hash_function(adress, size);
	int index = hash;
	while (array[index].adress != adress && index < size)
	{
		index++;
	}
	if (index >= size)
	{
		index = 0;
		while (array[index].adress != adress && index < hash)
		{
			index++;
		}
		if (index >= hash)
		{
			cout << "Человека с адресом: " << adress << " нет" << endl;
		}
		else
		{
			cout << "Человек с адресом: " << adress << " найден с индексом: " << index << endl;
		}
	}
	else
	{
		cout << "Человек с адресом: " << adress << " найден с индексом: " << index << endl;
	}
}
void hash_table::add(Human tmp, const int size)
{
	int index = hash_function(tmp.adress, size);
	int hash = index;
	if (array[index].full_name == "NULL")
	{
		array[index] = tmp;
		return;
	}
	else
	{
		while (index < size)
		{
			if (array[index].full_name == "NULL")
			{
				array[index] = tmp;
				return;
			}
			index++;
			coll_num++;
		}
		if (index >= size)
		{
			index = 0;
			coll_num++;
			while (index < hash)
			{
				if (array[index].full_name == "NULL")
				{
					array[index] = tmp;
					return;
				}
				index++;
				coll_num++;
			}
		}
	}
}
Human creator()
{
	Human tmp;
	tmp.full_name = get_random_name();
	tmp.date = get_random_birthday();
	tmp.adress = get_random_adress();
	return tmp;
}
string get_random_name()
{
	return(surname[get_random_num()] + " " + name[get_random_num()] + " " + patronymic[get_random_num()]);
}
string get_random_birthday()
{
	return dates[get_random_num()];
}
string get_random_adress()
{
	return adress[get_random_num()];
}
void show(const Human tmp)
{
	cout << "ФИО:           " << tmp.full_name<<endl;
	cout << "Дата рождения: " << tmp.date << endl;
	cout << "Адрес:    " << tmp.adress << endl;
}
void print_Humans(const Human* const array, const int size)
{
	for (int i = 0; i < size; i++)
	{
		show(array[i]);
	}
}
void fill_creator(Human*array, const int count)
{
	for (int i = 0; i < count; i++)
	{
		array[i] = creator();
	}
}
int get_random_num()
{
	return rand() % 10;
}
int get_sum_id(string str)
{
	int sum = adress[get_random_num()].length();
	return sum;
}
int hash_function(string str, const int size)
{
	double a = 0.618*get_sum_id(str);
	double c = size * (a - static_cast<int>(a));
	return static_cast<int>(c);
}
void show_table(hash_table*table, const int size)
{
	for (int i = 0; i < size; i++)
	{
		show(table->array[i]);
	}
}
int main()
{
	srand(time(0));
	setlocale(LC_ALL, "Rus");
	int size;
		cout << "Введите количество элементов в массиве(не менее 100): ";
		cin >> size;
	cout << endl;
	Human*array = new Human[size];
	hash_table table(size);
	fill_creator(array, size);
	for (int i = 0; i < size; i++)
	{
		table.add(array[i], size);
	}
	show_table(&table, size);
	table.find_index("Еремова 8", size);
	cout << endl << "===============" << endl;
	cout << "Кол-во колллизий для " << size << " записей равно " << coll_num << endl;
	delete[] array;
	return 0;
}