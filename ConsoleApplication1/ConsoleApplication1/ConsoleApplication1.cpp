#include <iostream>
using namespace std;

class drob
{

private:
	int chisletel;
	int znamenatel;


public:

	void setdrob(int chisl, int znam) {
		if (znam == 0) {

			cout << "Ошибка: Знаменатель не может быть нулевым" << endl;

			return;

		}

	}


	void input() {

		cout << "Введите числитель и знаменатель (через пробел):";
		cin >> chisletel >> znamenatel;
		if (znamenatel == 0) {
			cout << "Ошибка: Знаменатель не можент быть нулевым." << endl;
			znamenatel = 1;// По умолчанию
		}
	}
	void display() const {
		cout << chisletel << "/" << znamenatel;
	}

	drob(int num, int denom) : chisletel(num), znamenatel(denom) {}



	void displayFraction() const {
		cout << chisletel << "/" << znamenatel << endl;
	}

	
	drob add(const drob& other) const {
		return drob(chisletel * other.znamenatel + other.chisletel * znamenatel,
			znamenatel * other.znamenatel);
	}

	drob subtract(const drob& other) const {
		return drob(chisletel * other.znamenatel - other.chisletel * znamenatel,
			znamenatel * other.znamenatel);
	}

	drob multiply(const drob& other) const {
		return drob(chisletel * other.chisletel, znamenatel * other.znamenatel);
	}


	drob divide(const drob& other) const {
		return drob(chisletel * other.znamenatel, znamenatel * other.chisletel);
	}

};

int main()
{
	setlocale(LC_ALL, "RU");
	drob frac1(1, 2); // Пример дроби 1/2
	drob frac2(3, 4); // Пример дроби 3/4

	cout << "Первая дробь: ";
	frac1.displayFraction();

	cout << "Вторая дробь: ";
	frac2.displayFraction();

	// Сложение
	drob result = frac1.add(frac2);
	cout << "Сумма: ";
	result.displayFraction();

	// Вычитание
	result = frac1.subtract(frac2);
	cout << "Разность: ";
	result.displayFraction();

	// Умножение
	result = frac1.multiply(frac2);
	cout << "Произведение: ";
	result.displayFraction();

	// Деление
	result = frac1.divide(frac2);
	cout << "Частное: ";
	result.displayFraction();

	return 0;
}










