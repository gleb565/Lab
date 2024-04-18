#include <iostream>
#include <string>
#include <fstream>

using namespace std;


void error() {
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());
	cout << "Вы должны вводить только действительные числа!" << endl;
}						
void Entrance();													// Скелет функции
void registration();
void repassword();

struct User {
	string name;													// Массив структур для регистрации
	string login;
	string password;
};

struct YourStruct {													// Массив структур для записи в файл
	string name;
	string login;
	string password;
};


int main() {
	setlocale(LC_ALL, "RU");
	cout << "Войти - 1" << endl;
	cout << "Регистрация - 2" << endl;
	cout << "Забыли пароль - 3" << endl;
	cout << "Закончить работу с программой - 4" << endl;					// Возможности доступные пользователю
	int program = 0;
	while (0 < program < 5) {
		cout << "Введите номер действия: " << endl;
		cin >> program;
		if (cin.fail() == true || (cin.peek() != '\n')) {
			error();
		}
		else {
			if (program > 5) {
				cout << "Вы должны вводить числа от 1 до 3!" << endl;								
			}
			if (program < 1) {
				cout << "Вы должны вводить числа от 1 до 3!" << endl;
			}
			switch (program) {
			case(1):
				Entrance();													// Выбор функций
				break;
			case(2):
				registration();
				break;
			case(3):
				repassword();
				break;
			case(4):
				exit(0);
				break;
			}

				
		}
	}
	return 0;
}

void Entrance() {															// Функция входа
	string Login, Password;
	const int SIZE = 100;
	YourStruct arr[SIZE];
	ifstream file("DataBase.txt");											// Чтение данных в массив структур
	if (file.is_open()) {
		for (int i = 0; i < SIZE; i++) {
			file >> arr[i].name >> arr[i].login >> arr[i].password;
		}
		file.close();														// Закрытие файла
		bool blank = false;
		bool b = true;
		while (b) {
			cout << "Введите логин: " << endl;
			cin >> Login;
			cout << "Введите пароль: " << endl;
			cin >> Password;
			for (int i = 0; i < SIZE; i++) {
				if (("!" + Login) == arr[i].login || ("!" + Password) == arr[i].password) {					// Сравнение массива структур и строк, введенных пользователем
					cout << "Поздравляю," << arr[i].name << ", вы успешно вошли в систему" << endl;
					b = false;
					blank = true;
				}
			}
			if (!blank) {
				cout << "Вы ввели что-то не так!" << endl;
			}
		}
		
			
	}
	else {
		cout << "Технические неполадки, повторите попытку позже!" << endl;
	}
}
	

void registration() {							// Функция регистрации
	string Name, Login, Password;
	cout << "Введите свое имя: " << endl;
	cin >> Name;
	cout << "Введите свой логин: " << endl;
	cin >> Login;
	cout << "Введите пароль: " << endl;
	cin >> Password;
	ofstream file("DataBase.txt", ios_base::app);			// Запись данных в файл
	if (file.is_open()) {
		User user;
		user.name = Name;
		user.login = Login;
		user.password = Password;
		file << user.name + ' ';
		file << "!" + user.login + ' ';
		file << "!" + user.password + ' ';
		file << endl;
		file.close();
		cout << "Регистрация завершена!" << endl;

	}
	else {
		cout << "Регистрация в данный момент невозможно" << endl;
	} 
}

void repassword() {										// Функция смены пароля
	ifstream file("DataBase.txt");
	const int SIZE = 100;
	YourStruct arr[SIZE];
	string Login, Password;
	if (file.is_open()) {
		for (int i = 0; i < SIZE; i++) {
			file >> arr[i].name >> arr[i].login >> arr[i].password;			// считывание данных из файла в массив структур
		}
		file.close();
		bool blank = false;
		cout << "Для того, чтобы сменить пароль, введите логин: " << endl;
		cin >> Login;
		cout << "Введите новый пароль: " << endl;
		cin >> Password;
		ofstream file("DataBase.txt", ios_base::out);					// Очистка данных, хранящихся в файле
		if (file.is_open()) {
			for (int j = 0; j < SIZE; j++) {
				if ("!" + Login == arr[j].login) {
					arr[j].password = "!" + Password;					// Смена пароля
					ofstream file("DataBase.txt", ios_base::app);		
					if (file.is_open()) {
						for (int i = 0; i < SIZE; i++) {
							file << arr[i].name + ' ' << arr[i].login + ' ' << arr[i].password + ' ';					// Запись данных обратно в файл, но уже с новым паролем
							file << endl;
						}
					}

					blank = true;
					cout << "Поздравляю," << arr[j].name << ", вы сменили пароль! Постарайтесь больше его не забывать!" << endl;
				}
			}
			if (!blank) {
				cout << "Данного логина не существует, попробуйте зарегистрироваться!" << endl;
			}
		}
		file.close();
	}
	else {
		cout << "Технические неполадки! Повторите попытку позже!" << endl;
	}
}