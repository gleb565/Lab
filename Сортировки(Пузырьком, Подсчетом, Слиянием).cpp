#include <iostream>
#include <string>
#include <time.h>
#include <regex>

using namespace std;

void error() {
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());
	cout << "Вы должны вводить только действительные числа!" << endl;
}
void task_1();
void task_2();
void task_3();


int main() {
	setlocale(LC_ALL, "RU");
	int program = 0;
	cout << "Введите номер задания от 1 до 3" << endl;
	while (1 < program < 3) {
		cout << "Введите номер программы:" << endl;
		cin >> program;
		if (cin.fail() == true || (cin.peek() != '\n')) {
			error();
		}
		else {
			if (program < 1)
				cout << "Вы должны вводить числа от 1 до 3!" << endl;
			if (program > 3)
				cout << "Вы должны вводить числа от 1 до 3!" << endl;
			switch (program) {
			case(1):
				task_1();
				break;
			case(2):																// Выбор заданий
				task_2();
				break;
			case(3):
				task_3();
				break;
			}
		}

	}
	return 0;
}

// задание 1

void bubble(int mass[], int size) {											// Данная функция используется в первом задании
	for (int a = 0; a < size; a++) {
		for (int b = 0; b < size - 1; b++) {								// Сортировка пузырьком
			if (mass[b] > mass[b + 1])
				swap(mass[b], mass[b + 1]);
		}
	}
}

void task_1() {
	cout << "Выберете 1, чтобы получить рандомный массив и выполнить его сортировку." << endl;
	cout << "Выберете 2, чтобы записать массив самому.Сортировка выполнится автоматически." << endl;		// Выбор заполнения массива
	int numbers = 0;
	int arr[100] = {};
	int a[100] = {};
	while (0 < numbers < 3) {
		cout << "Введить номер:" << endl;
		cin >> numbers;
		if (cin.fail() == true || (cin.peek() != '\n')) {
			error();
		}
		else {
			if (numbers < 1)
				cout << "Вы должны вводить числа от 1 до 2!" << endl;
			if (numbers > 3)
				cout << "Вы должны вводить числа от 1 до 2!" << endl;
			switch (numbers) {
			case(1):
				int size;
				cout << "Введите количество элементов в массиве:" << endl;				// Пользователь вводит размер массива
				cin >> size;
				if (cin.fail() == true || (cin.peek() != '\n')) {
					error();
				}
				else {
					srand(time(NULL));
					for (int i = 0; i < size; i++) {						// Заполнение массива рандомными числами
						arr[i] = 1 + rand() % 100;
					}
					cout << "Исходный массив:" << endl;						// Вывод исходного массива
					for (int j = 0; j < size; j++) {
						cout << arr[j] << " ";
					}
					cout << endl;
					bubble(arr, size);										// Сортировка пузырьком
					cout << "Отсортированный массив:" << endl;
					for (int n = 0; n < size; n++) {						// Вывод отсортированного массива
						cout << arr[n] << " ";
					}
					cout << endl;
					break;
				}
			case(2):
				int razm;
				cout << "Введите количество элементов в массиве:" << endl;
				cin >> razm;
				if (cin.fail() == true || (cin.peek() != '\n')) {							// Пользовательвводит количество элементов в массиве
					error();
				}
				else {
					for (int m = 0; m < razm; m++) {
						int z;
						cout << "Введите " << m + 1 << " число в массиве" << endl;			// Заполнение массива в ручную
						cin >> z;
						a[m] = z;
					}
					cout << "Исходный массив:" << endl;
					for (int h = 0; h < razm; h++) {				// Вывод получившегося массива
						cout << a[h] << " ";
					}
					cout << endl;
					bubble(a, razm);								// Сортировка пузырьком
					cout << "Отсортированный массив:" << endl;
					for (int v = 0; v < razm; v++) {
						cout << a[v] << " ";						// Вывод отсортированного массива
					}
					cout << endl;
					break;
				}
			}


		}
		break;
	}
}

// задание 2

int find_index(string str[], string s) {			// Данная функция используется во 2 задании
	int index = -1;
	for (int i = 0; i < 26; i++) {					//Нахождение индекса элемента
		if (str[i] == s)
			index = i;
	}
	return index;
}

void couting_sort(string str[], int size) {
	string mass[26] = { "a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z" };
	int count[26] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	string new_arr[100];
	int index;

	for (int i = 0; i < size; i++) {
		index = find_index(mass, str[i]);			// Подсчет по индексам		
		if (index != -1) {
			count[index] += 1;
		}
	}

	int c = 0;
	for (int l = 0; l < 26; l++) {
		if (count[l] != 0) {
			if (count[l] >= 2) {
				for (int f = 0; f < count[l]; f++) {			// Сортировка подсчетом
					new_arr[c] = mass[l];
					c += 1;
				}
			}
			else {
				new_arr[c] = mass[l];
				c += 1;
			}
		}
	}
	cout << "Отсортированный массив: " << endl;						// Вывод отсортированного массива
	for (int k = 0; k < 100; k++) {
		cout << new_arr[k] << " ";
	}
	cout << endl;
}

void task_2() {
	srand(time(NULL));
	string str[26] = { "a","b","c","d","e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z" };
	cout << "Введите 1, чтобы сгенерировать массив автоматически и произвести его сортировку" << endl;
	cout << "Введите 2, чтобы ввести массив в ручную. Сортировка выполнится автоматически." << endl;
	int numbers = 0;
	while (0 < numbers < 3) {
		cout << "Введить номер:" << endl;
		cin >> numbers;
		if (cin.fail() == true || (cin.peek() != '\n')) {
			error();
		}
		else {
			string arr[100] = {};
			if (numbers < 1)
				cout << "Вы должны вводить числа от 1 до 2!" << endl;
			if (numbers > 3)
				cout << "Вы должны вводить числа от 1 до 2!" << endl;
			switch (numbers) {
			case(1):
				int razm;
				cout << "Введите количество элементов в массиве:" << endl;				// Пользователь вводит количество элементов в массиве
				cin >> razm;
				if (cin.fail() == true || (cin.peek() != '\n')) {  
					error();
				}
				else {
					for (int i = 0; i < razm; i++) {				// Заполнение массива рандомными элементами
						arr[i] = str[int(rand() % 25 + 1)];
					}
					cout << "Исходный массив:" << endl;            // Вывод исходного массива
					for (int j = 0; j < razm; j++) {
						cout << arr[j] << " ";
					}
					cout << endl;
					couting_sort(arr, razm);						// Сортировка подсчетом
					break;													
				}
			
			case(2):
				regex r("[abcdefghijklmnopqrstuvwxyz]");
				int raz;
				cout << "Введите количество элементов в массиве: " << endl;
				cin >> raz;
				if (cin.fail() == true || (cin.peek() != '\n')) {
					error();
				}
				else {
					string a[100];
					string b;
					for (int i = 0; i < raz; i++) {
						cout << "Введите " << i + 1 << " элемент в массиве" << endl;			// Пользователь вводит количество элементов в массиве
						cin >> b;
						while (!regex_match(b, r)) {
							cout << "Вы должны вводить только маленькие английские буквы!" << endl;  // Проверка на ввод только заданных символов
							cin >> b;
						}
						a[i] = b;
					}
					cout << "Исходный массив: " << endl;								// Вывод исходного массива
					for (int j = 0; j < raz; j++) {
						cout << a[j] << " ";
					}
					cout << endl;
					couting_sort(a, raz);												// Сортировка подсчетом
					break;
				}
			}

		}
		break;
	}
}


// задание 3

void Merge(int mass[], int sub[], int left, int cent, int right)
{
	int k = left, i = left, j = cent + 1;

	while (i <= cent && j <= right)
	{
		if (mass[i] <= mass[j]) {
			sub[k++] = mass[i++];
		}
		else {
			sub[k++] = mass[j++];
		}
	}

	while (i <= cent) {
		sub[k++] = mass[i++];
	}

	for (int i = left; i <= right; i++) {
		mass[i] = sub[i];
	}
}

void mergesort(int mass[], int sub[], int left, int right)
{

	if (right <= left) {
		return;
	}


	int cent = (left + ((right - left) >> 1));


	mergesort(mass, sub, left, cent);
	mergesort(mass, sub, cent + 1, right);
	Merge(mass, sub, left, cent, right);
}

void task_3() {
	srand(time(NULL));
	int number = 0;
	cout << "Введите 1, чтобы сгенерировать массив автоматически" << endl;
	cout << "Введите 2, чтобы ввести массив с консоли" << endl;
	while (1 < number < 3) {
		cout << "Введите номер действия:" << endl;
		cin >> number;
		if (cin.fail() == true || (cin.peek() != '\n')) {
			error();
		}
		else {
			if (number < 1)
				cout << "Вы должны вводить только числа от 1 до 2" << endl;
			if (number > 2)
				cout << "Вы должны вводить только числа от 1 до 2" << endl;
			switch (number) {
			case(1):
				int razm;
				int arr[100];
				int sub[100];
				cout << "Введите количество элементов в массиве:" << endl;
				cin >> razm;
				if (cin.fail() == true || (cin.peek() != '\n')) {
					error();
				}
				else {
					for (int i = 0; i < razm; i++) {
						sub[i] = arr[i] = 1 + rand() % 100;
					}
					cout << "Исходный массив:" << endl;
					for (int j = 0; j < razm; j++) {
						cout << arr[j] << " ";
					}
					cout << endl;
					mergesort(arr, sub, 0, razm - 1);
					cout << "Отсортированный массив: " << endl;
					for (int n = 0; n < razm; n++) {
						cout << arr[n] << " ";
					}
					cout << endl;
					break;
				}
			case(2):
				int size;
				int num[100];
				int ds[100];
				cout << "Введите количество элементов в массиве:" << endl;
				cin >> size;
				if (cin.fail() == true || (cin.peek() != '\n')) {							// Пользовательвводит количество элементов в массиве
					error();
				}
				else {
					for (int m = 0; m < size; m++) {
						int z;
						cout << "Введите " << m + 1 << " число в массиве" << endl;			// Заполнение массива в ручную
						cin >> z;
						ds[m] = num[m] = z;
					}
					cout << "Исходный массив:" << endl;
					for (int h = 0; h < size; h++) {				// Вывод получившегося массива
						cout << num[h] << " ";
					}
					cout << endl;
					mergesort(num, ds, 0, size - 1);
					cout << "Отсортированный массив: " << endl;
					for (int g = 0; g < size; g++) {
						cout << num[g] << " ";
					}
					cout << endl;
					break;
				}
			}
		}
		break;
	}
}


