#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void error() {
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());
	cout << "Вы должны вводить только действительные числа!" << endl;
}									
void Delete_Product();										// Скелет функции
void search();

struct Product {
	string name;
	string type;										// Массив структур, используемый для добавления товаров
	string count;
	string data;
};

struct YourStruct {
	string name;
	string type;										// Массив структур, используемый для работы с товарами
	string count;
	string data;
};

int main() {
	setlocale(LC_ALL, "RU");
	cout << "Добро пожаловать!" << endl;
	cout << "Если вы хотите добавить товар - 1" << endl;
	cout << "Если вы хотите удалить товар - 2" << endl;
	cout << "Если вы хотите найти товар в базе данных - 3" << endl;
	cout << "Если вы законили работу - 4" << endl;
	int program = 0;
	while (1 < program < 5) {
		cout << "Введите номер действия: " << endl;
		cin >> program;
		if (cin.fail() == true || (cin.peek() != '\n')) {
			error();
		}
		else {
			if (program < 1)
				cout << "Вы должны вводить числа от 1 до 4!" << endl;
			if (program > 4)
				cout << "Вы должны вводить числа от 1 до 4!" << endl;
			switch (program) {
			case(1):
				add();
				break;
			case(2):
				Delete_Product();												// Выбор возможных программ
				break;
			case(3):
				search();
				break;
			case(4):
				exit(0);
				break;
			}

		}
	}
	return 0;
}

void add() {														// Добавление товаров в файл
	string Name, Type, Count, Data;
	cout << "Введите название товара: " << endl;
	cin >> Name;
	cout << "Введите тип товара: " << endl;
	cin >> Type;
	cout << "Введите количество товара: " << endl;
	cin >> Count;
	cout << "Введите дату поставки товара: " << endl;
	cin >> Data;
	ofstream file("Product_DataBase.txt", ios_base::app);				// Открытие файла на добавление новых элементов
		if (file.is_open()) {
			Product product;
			product.name = Name;
			product.type = Type;
			product.count = Count;
			product.data = Data;
			file << product.name + ' ';
			file << "!" + product.type + ' ';							// Добавление новых элементов в файл
			file << "!" + product.count + ' ';
			file << "!" + product.data + ' ';
			file << endl;
			file.close();
			cout << "Вы успешно добавили товар!" << endl;
		}
		else {
			cout << "В данный момент невозможно произвести добавление товаров!" << endl;
		}
	}

void Delete_Product() {										// Удаление товаров из файла
	ifstream file("Product_DataBase.txt");
	const int SIZE = 100;
	YourStruct arr[SIZE];
	string Name;
	if (file.is_open()) {
		for (int i = 0; i < SIZE; i++) {
			file >> arr[i].name >> arr[i].type >> arr[i].count >> arr[i].data;							// Заполнение массива структур из файла 
		}
		file.close();
		bool blank = false;
		cout << "Для того, чтобы удалить товар введите его название: " << endl;
		cin >> Name;
		ofstream file("Product_DataBase.txt", ios_base::out);										// Открытие файла и его очистка
		if (file.is_open()) {
			for (int j = 0; j < SIZE; j++) {
				if (arr[j].name == Name) {
					arr[j].name = "";																// Удаление элементов
					arr[j].type = "";
					arr[j].count = "";
					arr[j].data = "";
					ofstream file("Product_DataBase.txt", ios_base::app);							// Добавление  испраленных элементов в очищеннный файл
					if (file.is_open()) {
						for (int i = 0; i < SIZE; i++) {
							file << arr[i].name + ' ' << arr[i].type + ' ' << arr[i].count + ' ' <<arr[i].data + ' ';
							file << endl;
						}
						file.close();
					}

					blank = true;
					cout << "Удаление объекта произошло успешно!" << endl;
				}
			}
			if (!blank) {
				cout << "Данного товара не существует!" << endl;
			}
			file.close();
		}

	}
	else {
		cout << "В данный момент невозможно произвести удаление товара!" << endl;
	}
}

void search() {												// Поиск нужных товаров в файле
	cout << "Обычный поиск - 1" << endl;
	cout << "Продвинутый  поиск - 2" << endl;
	cout << "Выберете номер поиска: " << endl;				// Выбор поиска
	int program;
	cin >> program;
	if (cin.fail() == true || (cin.peek() != '\n')) {
		error();
	}
	else {
		if (program < 1)
			cout << "Вы должны вводить числа от 1 до 2!" << endl;			
		if (program > 2)
			cout << "Вы должны вводить числа от 1 до 2!" << endl;
		ifstream file("Product_DataBase.txt");
		const int SIZE = 100;
		YourStruct arr[SIZE];
		string Name,Type;
		bool rev = false;
		bool blank = false;
		cout << "Введите название товара, который хотите найти: " << endl;								
		cin >> Name;
		switch (program) {
		case(1):																					// Обычный поиск
			if (file.is_open()) {
				for (int i = 0; i < SIZE; i++) {
					file >> arr[i].name >> arr[i].type >> arr[i].count >> arr[i].data;					// Заполнение массива структур из файла
				}
				for (int j = 0; j < SIZE; j++) {
					if (arr[j].name == Name) {
						cout << arr[j].name << " " << arr[j].type << " " << arr[j].count << " " << arr[j].data << " " << endl;  // Поиск товара по названию
						blank = true;
					}
				}
					
				if (!blank) {											// Если товар не был найден
					cout << "Такого товара нет в базе данных!" << endl;
					cout << "Если хотите добавить его, то введите 1" << endl;
					cout << "Если нет, то введите 2" << endl;
					cout << "Введите номер: " << endl;
					int choice;
					cin >> choice;
					if (cin.fail() == true || (cin.peek() != '\n')) {
						error();
					}
					else {
						if (program < 1)
							cout << "Вы должны вводить числа от 1 до 2!" << endl;
						if (program > 2)
							cout << "Вы должны вводить числа от 1 до 2!" << endl;
						switch (choice) {
						case(1):
							add();												// Добавление товара
							break;
						case(2):												// Выход
							break;
						}
					}
				}
				file.close();
			}
			break;
		case(2):																// Продвинутый поиск
			if (file.is_open()) {
				for (int i = 0; i < SIZE; i++) {
					file >> arr[i].name >> arr[i].type >> arr[i].count >> arr[i].data;						// Заполнение массива структур из файла
				}
				for (int j = 0; j < SIZE; j++) {
					if (arr[j].name == Name) {
						cout << arr[j].name << " " << arr[j].type << " " << arr[j].count << " " << arr[j].data << " " << endl;				// Поиск товара по названию
						blank == true;
					}
				}
				if (!blank) {	// Если товар не был найден, то выполняется поиск похожих товаров по типу
					cout << "Товаров с данным именем найдено не было. Сейчас мы произведем сортировку по типу и найдем похожие товары" << endl;	
					cout << "Введите тип искомова вами товара: " << endl;										
					cin >> Type;
					for (int a = 0; a < SIZE; a++) {
						if (arr[a].type == "!" + Type) {				// Поиск товаров по типу
							cout << arr[a].name << " " << arr[a].type << " " << arr[a].count << " " << arr[a].data << " " << endl;
							rev = true;
						}
					}
				}
				if (!rev) {														// Если и по типу нет похожих товаров, то их можно добавить
					cout << "Мы не нашли совпадений даже по типу товаров" << endl;
					cout << "Если хотите добавить его, то введите 1" << endl;
					cout << "Если нет, то 2" << endl;
					cout << "Введите номер  " << endl;
					int choice;
					cin >> choice;
					if (cin.fail() == true || (cin.peek() != '\n')) {
						error();
					}
					else {
						if (program < 1)
							cout << "Вы должны вводить числа от 1 до 2!" << endl;
						if (program > 2)
							cout << "Вы должны вводить числа от 1 до 2!" << endl;
						switch (choice) {
						case(1):
							add();									// Добавление товара 
							break;
						case(2):									// Выход
							break;
						}
					}
				}

			}
			break;
		}
	}
}

