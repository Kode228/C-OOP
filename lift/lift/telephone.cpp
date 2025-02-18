#include <iostream>

using namespace std;

class Lift {
private:
    int lowerFloor;   // Нижний этаж
    int upperFloor;   // Верхний этаж
    int currentFloor; // Текущий этаж
    bool isActive;    // Состояние лифта

public:
    // Конструктор
    Lift(int lower, int upper)
        : lowerFloor(lower), upperFloor(upper), currentFloor(lower), isActive(false) {
    }

    // Установка диапазона движения лифта
    void setRange(int lower, int upper) {
        lowerFloor = lower;
        upperFloor = upper;
        if (currentFloor < lowerFloor) currentFloor = lowerFloor;
        else if (currentFloor > upperFloor) currentFloor = upperFloor;
    }

    // Включение лифта
    void turnOn() {
        isActive = true;
        cout << "Лифт включен.\n";
    }

    // Выключение лифта
    void turnOff() {
        isActive = false;
        cout << "Лифт выключен.\n";
    }

    // Возвращение текущего состояния лифта
    bool isWorking() const { return isActive; }

    // Возвращение текущего положения лифта
    int getCurrentFloor() const { return currentFloor; }

    // Обработка вызова лифта на определенный этаж
    void callLift(int floor) {
        if (!isActive) {
            cout << "Лифт выключен! Включите его.\n";
            return;
        }
        if (floor < lowerFloor || floor > upperFloor) {
            cout << "Этаж вне диапазона! Выберите этаж от " << lowerFloor << " до " << upperFloor << ".\n";
            return;
        }
        currentFloor = floor;
        cout << "Лифт переместился на этаж: " << currentFloor << ".\n";
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    Lift lift(1, 10); // Создаем лифт с диапазоном от 1 до 10
    int lower, upper, floor;
    char choice;

    // Установка диапазона движения лифта
    cout << "Введите нижний этаж: ";
    cin >> lower;
    cout << "Введите верхний этаж: ";
    cin >> upper;
    lift.setRange(lower, upper);

    do {
        cout << "\nВыберите действие:\n";
        cout << "1. Включить лифт\n";
        cout << "2. Выключить лифт\n";
        cout << "3. Проверить состояние лифта\n";
        cout << "4. Проверить текущий этаж\n";
        cout << "5. Вызвать лифт на этаж\n";
        cout << "0. Выход\n";
        cout << "Ваш выбор: ";
        cin >> choice;

        switch (choice) {
        case '1':
            lift.turnOn(); // Включаем лифт
            break;
        case '2':
            lift.turnOff(); // Выключаем лифт
            break;
        case '3':
            cout << "Лифт " << (lift.isWorking() ? "работает." : "не работает.") << "\n";
            break;
        case '4':
            cout << "Текущий этаж: " << lift.getCurrentFloor() << "\n";
            break;
        case '5':
            cout << "Введите этаж для вызова лифта: ";
            cin >> floor;
            lift.callLift(floor); // Вызываем лифт на указанный этаж
            break;
        case '0':
            cout << "Выход из программы.\n";
            break;
        default:
            cout << "Неверный выбор. Попробуйте снова.\n";
        }
    } while (choice != '0');

    return 0;
}


