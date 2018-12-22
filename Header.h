#pragma once
#include <string>
#include <cstring>
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <vector>

using namespace std;


class  Book
{
	int price;
	int number_of_pages;
	string title;
	string author;
	int year;
public:
	int code;
	Book();//конструктор
	Book(string, string, int, int, int, int);//конструктор
	~Book (){
		cout << "Object Admin was destructed" << endl;
	}
	int GetPrice();
	int GetNumberOfPages();
	int GetYear();
	string GetTitle();
	string SetAuthor();
	string GetAuthor();
	int SetPrice();
	int SetNumberOfPages();
	int SetYear();
	string SetTitle();
	;	void RandMemory();//виділення рандомої к-ті пам'яті під цілочисельний масив
};

class Admin{
	string name;
	string surname;
	string work;
	static int salary;//12
	int wallet = 0;
	static int premium;
	int age;
public:
	int cardnumber;
	Admin(string, string, string, int, int, int, int);//конструктор  4
	Admin(string);//конструктор
	Admin();//4
	Admin(const Admin &obj)//4
	{
	}
	~Admin(){
		cout << "Object Admin was destructed" << endl;
	}
	friend void ChangeWork(Admin &);//10
	string GetAdminName();
	void PayForBook(int, int, int);//отримання грошей за заяву
	void SetName(string);
	void SetName();
	void AddToBlackList(Book);//додання замовлення до чорного списку
	void MakeBook(string, string, int, int, int, int);//item 3 //додавання нової книги
	void ClassName();//метод, що повертає ім'я класу
	
	
	static int getSalary(){//12
		return salary;
	}
	void setSalary(int salary){//12
		this->salary = salary;
	}
	int getAge(){
		return age;
	}
	 static int getPremium(){
		return premium;
	}
	Admin func(){//15
		Admin admin;
		admin.setSalary(800);
		return admin;
	}
};
class ReaderStatus;
class Reader{//item 2
	string name;
	string surname;
	int cardnumber;
	int id;
	
public:
	int money;
	Reader(string, string, int, int, int);//конструктор
	~Reader(){
		cout << "Object Admin was destructed" << endl;
	}
	string GetName();
	void SetName(string);
	void SetName();
	void FindBook(Book *, Admin, int, string);//метод шукає книги за назвою
	void FindBook(Book *, Admin, int);//метод для виведення всіх книг
	void MakeOrder(Book, Admin);//метод для замовлення вибраної книги
	int getСardnumber();
	friend ReaderStatus;//11 дружній клас
};
class ReaderStatus{//11
public:
	string status;
	void setStatus(Reader &ob){
		if (ob.getСardnumber() %2==0){
			status = "twin";
		}
		else{
			status = "not twin";
		}
	}

};
class Order{
	string status;
public:
	int year;
	string month;
	int day;
	Book book;
	int code;
	explicit Order(){};
	Order(string, Book, int, int, string, int);
	Order(int year, string month, int day) :year(year), month(month), day(day){}//5 список ініціалізації
	~Order(){
		cout << "Object Admin was destructed" << endl;
	}
	void ChangeStatus(string);
	void NewOrder(Book, Admin, Reader);
};

class Bookstore{
	string name;
	string address;
	int department_number;

	vector <const Admin*> admin;
	vector <const Reader*> reader;
	vector <const Book> book;
public:
	Bookstore(vector <const Admin*> admin, vector <const Reader*> reader, vector <const Book> book, string name, string address, int department_number){
		this->admin = admin;
		this->reader = reader;
		this->book = book;
		this->name = name;
		this->address = address;
		this->department_number = department_number;
	};
	~Bookstore(){
	};
	explicit Bookstore(){};
	int getDepartment_number(){
		return department_number;
	}
	string getName(){
		return name;
	}
	string getAddress(){
		return address;
	}


};