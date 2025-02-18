#include <iostream>

using namespace std;

class Fraction {
private:
    int numerator;
    int denominator;

    
    int gcd(int a, int b) const {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

   
    void reduce() {
        int gcd_value = gcd(numerator, denominator);
        numerator /= gcd_value;
        denominator /= gcd_value;
               if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
    }

public:
    
    Fraction(int numerator = 0, int denominator = 1) : numerator(numerator), denominator(denominator) {
        reduce();
    }

   
    void input() {
        cin >> numerator >> denominator;
        reduce();
    }

    // Сложение
    Fraction operator+(const Fraction& other) const {
        return Fraction(numerator * other.denominator + other.numerator * denominator, denominator * other.denominator);
    }

    // Вычитание
    Fraction operator-(const Fraction& other) const {
        return Fraction(numerator * other.denominator - other.numerator * denominator, denominator * other.denominator);
    }

    // Умножение
    Fraction operator*(const Fraction& other) const {
        return Fraction(numerator * other.numerator, denominator * other.denominator);
    }

    // Деление
    Fraction operator/(const Fraction& other) const {
        return Fraction(numerator * other.denominator, denominator * other.numerator);
    }

   
    void output() const {
        cout << numerator << "/" << denominator << endl;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    Fraction fraction1, fraction2;

    cout << "Введите первую дробь (числитель и знаменатель через пробел): ";
    fraction1.input();

    cout <<  "Введите вторую дробь (числитель и знаменатель через пробел): ";
    fraction2.input();

    Fraction sum = fraction1 + fraction2;
    Fraction difference = fraction1 - fraction2;
    Fraction product = fraction1 * fraction2;
    Fraction quotient = fraction1 / fraction2;

    cout << "Сумма: ";
    sum.output();

    cout << "Разность: ";
    difference.output();

    cout << "Произведение: ";
    product.output();

    cout << "Частное: ";
    quotient.output();

    return 0;
}

