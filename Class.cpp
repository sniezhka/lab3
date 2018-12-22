#include "Header.h"

Admin::Admin(string name, string surname, string work, int cardnumber, int salary, int age, int premium){//конструктор
	this->name = name;
	this->surname = surname;
	this->work = work;
	this->cardnumber = cardnumber;
	this->salary = salary;
	this->age = age;
	this->premium = premium;
}
Admin::Admin(string name){//конструктор
	this->name = name;
}
void Admin::AddToBlackList(Book book){// додати невиплачене замовлення до чорного списку
	cout << "Замовлення додано в чорний список" << endl;
}
void Admin::SetName(){
	this->name = "Anonym";
}
void Admin::MakeBook(string author, string name, int year, int number_of_pages, int price, int code){//додати нової книги
	Book book(author, name, year, number_of_pages, price, code); //item 3 //item 6
	ofstream file("Books.data", ios::app);//item 5
	file.write((char *)&book, sizeof(Book));
	file.close();
}
void Admin::ClassName(){// item 4 //повернення classname
	cout << typeid(*this).name();
}
string Admin::GetAdminName(){
	return name;
}
void Admin::SetName(string name){
	this->name = name;
}
void Admin::PayForBook(int cardnumber, int price, int money){ //отримання грошей за замовлення
	if (cardnumber == this->cardnumber){
		if (money >= price){
			money -= price;
			this->wallet += price;
			cout << "Ваше замовлення сплачено\n";
		}
		else{
			cout << "Ви не маєте достатньо грошей\n";
		}
	}
	else{
		cout << "Номер картки не правильний\n";
	}
}
void ChangeWork(Admin &ob){//10 дружня ф-ія
	ob.work = "Senioradmin";
}
Book::Book(string author, string title, int year, int number_of_pages, int price, int code){//конструктор
	this->author = author;
	this->title = title;
	this->year = year;
	this->number_of_pages = number_of_pages;
	this->price = price;
	this->code = code;
}
Book::Book(){//перезавантажений конструктор
	this->author = "Author";
	this->title = "Title";
	this->number_of_pages = 0;
	this->price = 0;
	this->year = 0;
}
int Book::GetPrice(){//get метод
	return price;
}
int Book::GetNumberOfPages(){//get метод
	return number_of_pages;
}
int Book::GetYear(){//get метод
	return year;
}
string Book::GetTitle(){//get метод
	return title;
}
string Book::GetAuthor(){//get метод
	return author;
}
void Book::RandMemory(){//виділення рандомої к-ті пам'яті під цілочисельний масив
	srand(time(0));
	int size = rand() % 100;
	int * mem = new int[size];
	for (int i = 0; i < size; i++){
		mem[i] = rand() % 100;
	}
	/* Отсортируем массив по убыванию */
	for (int i = 1; i < size; ++i)
	{
		for (int r = 0; r < size - i; r++)
		{
			if (mem[r] < mem[r + 1])
			{
				// Обмен местами
				int temp = mem[r];
				mem[r] = mem[r + 1];
				mem[r + 1] = temp;
			}
		}
	}
}
Reader::Reader(string name, string surname, int cardnumber, int money, int id){
	this->name = name;
	this->surname = surname;
	this->cardnumber = cardnumber;
	this->money = money;
	this->id = id;
}

void Reader::MakeOrder(Book book, Admin admin){
	Order order("Notpayed", book, 0, 2000, "", 23);
	cout << "Ви хочите зробити замовлення?" << endl;
	char yes_or_no;
	int how_many_times = 0;;

	cin >> yes_or_no;
	if (yes_or_no == 'y'){
		order.NewOrder(book, admin, (*this));
	}
	else if (yes_or_no == 'n'){
		cout << "Замовлення не зроблено!" << endl;

	}
}
void Reader::FindBook(Book *mass, Admin admin, int count, string title){
	ifstream file("Books.data");//item 5
	bool is_exist = 0;
	char yes_or_no;
	for (int i = 0; i < count; i++){
		file.read((char *)&mass[i], sizeof(Book));
		if (mass[i].GetTitle() == title){
			cout << "Ви хочете зробити замовлення? y/n\n";
			cin >> yes_or_no;
			if (yes_or_no == 'y'){
				MakeOrder(mass[i], admin);
				is_exist = 1;
				break;
			}
			else break;
		}
	}
	file.close();
	if (is_exist != 1){
		cout << "На жаль, ми не маємо цієї книги";
	}
}
void Reader::FindBook(Book *mass, Admin admin, int count){
	ifstream file("Books.data");//item 5
	for (int i = 0; i < count; i++){
		file.read((char *)&mass[i], sizeof(Book));
	}
	file.close();
}
string Reader::GetName(){
	return name;
}
void Reader::SetName(string name){
	this->name = name;
}
int Reader::getСardnumber(){
	return cardnumber;
}



Order::Order(string status, Book book, int code, int year, string month, int day){
	this->status = status;
	this->book = book;
	this->code = code;
	this->year = year;
	this->month = month;
	this->day = day;
}
void Order::ChangeStatus(string status){
	this->status = status;
	if (status == "Payed"){
		ofstream file("PayedOrders.data");
		file.write((char *)&(*this), sizeof(Order));
		file.close();
	}
	else if (status == "Notpayed"){
		ofstream file("NotPayedOrders.data");
		file.write((char *)&(*this), sizeof(Order));
		file.close();
	}
	else if (status == "Blacklisted"){
		fstream file("Blacklist.data");
		file.write((char *)&(*this), sizeof(Order));
		file.close();
	}
	else{
		cout << "Error" << endl;
	}
}

void Order::NewOrder(Book book, Admin admin, Reader reader){
	Order order("Notpayed", book, 0, 2000, "", 24);
	cout << "Замовлення зроблено! " << endl;
	char yes_or_no;
	bool activ = true;
	int how_many_times = 0;;
	while (activ){
		cout << "Ви хочите оплатити замовлення? y/n\n";
		cin >> yes_or_no;
		if (yes_or_no == 'y'){

			admin.PayForBook(admin.cardnumber, book.GetPrice(), reader.money);
		}

		else if (yes_or_no == 'n'){
			cout << "Ваше замовлення не оплачено\n";
			admin.AddToBlackList(book);
		}
		else if (how_many_times < 3){
			cout << "Спробуйте ще раз";
		}
		else{
			admin.AddToBlackList(book);
			activ = false;
		}
	}
	
}