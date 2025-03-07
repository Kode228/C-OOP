#include <iostream>
#include <fstream>
#include <cstring>
#include <limits> // Необходимо для std::numeric_limits

using namespace std;

class Contact { // Изменено на заглавную букву для соответствия стандартам
private:
    char* name; // выделение динамической памяти
    char* homePhone;
    char* workPhone;
    char* mobilePhone;
    char* additionalInfo;

public:
    // Конструктор
    Contact(const char* name, const char* homePhone, const char* workPhone,
        const char* mobilePhone, const char* additionalInfo) {
        this->name = new char[strlen(name) + 1];
        strcpy_s(this->name, strlen(name) + 1, name);

        this->homePhone = new char[strlen(homePhone) + 1];
        strcpy_s(this->homePhone, strlen(homePhone) + 1, homePhone);

        this->workPhone = new char[strlen(workPhone) + 1];
        strcpy_s(this->workPhone, strlen(workPhone) + 1, workPhone);

        this->mobilePhone = new char[strlen(mobilePhone) + 1];
        strcpy_s(this->mobilePhone, strlen(mobilePhone) + 1, mobilePhone);

        this->additionalInfo = new char[strlen(additionalInfo) + 1];
        strcpy_s(this->additionalInfo, strlen(additionalInfo) + 1, additionalInfo);
    }

    // Деструктор
    ~Contact() {
        delete[] name;
        delete[] homePhone;
        delete[] workPhone;
        delete[] mobilePhone;
        delete[] additionalInfo;
    }

    void display() const {
        setlocale(LC_ALL, "Russian");
        cout << "ФИО: " << name << "\n"
            << "Домашний телефон: " << homePhone << "\n"
            << "Рабочий телефон: " << workPhone << "\n"
            << "Мобильный телефон: " << mobilePhone << "\n"
            << "Дополнительная информация: " << additionalInfo << "\n"
            << "------------------------\n";
    }

    // Методы для получение переменных
    const char* getName() const { return name; }
    const char* getHomePhone() const { return homePhone; }
    const char* getWorkPhone() const { return workPhone; }
    const char* getMobilePhone() const { return mobilePhone; }
    const char* getAdditionalInfo() const { return additionalInfo; }
};

class PhoneBook {
private:
    Contact** contacts;
    int emcost;
    int size;

    // Добавление места для нового контакта
    void resize() {
        emcost *= 2;
        Contact** newContacts = new Contact * [emcost];
        for (int i = 0; i < size; i++) {
            newContacts[i] = contacts[i];
        }
        delete[] contacts;
        contacts = newContacts;
    }

public:
    PhoneBook() : emcost(2), size(0) {
        contacts = new Contact * [emcost];
    }

    ~PhoneBook() {
        for (int i = 0; i < size; i++) {
            delete contacts[i];
        }
        delete[] contacts;
    }

    // Добавление
    void addContact(const char* name, const char* homePhone, const char* workPhone,
        const char* mobilePhone, const char* additionalInfo) {
        if (size == emcost) {
            resize();
        }
        contacts[size++] = new Contact(name, homePhone, workPhone, mobilePhone, additionalInfo);
    }

    // Удаление
    void removeContact(const char* name) {
        for (int i = 0; i < size; i++) {
            if (strcmp(contacts[i]->getName(), name) == 0) {
                delete contacts[i];
                contacts[i] = contacts[size - 1]; // Замена удаляемого контакта последним
                size--;
                return;
            }
        }
        cout << "Контакт не найден.\n";
    }

    // Все контакты
    void displayAllContacts() const {
        for (int i = 0; i < size; i++) {
            contacts[i]->display();
        }
    }

    // Поиск контакта
    void searchContact(const char* name) const {
        for (int i = 0; i < size; i++) {
            if (strcmp(contacts[i]->getName(), name) == 0) {
                contacts[i]->display();
                return;
            }
        }
        cout << "Контакт не найден.\n";
    }

    // Данные в файл
    void saveToFile(const char* filename) const {
        ofstream file(filename);
        if (!file) {
            cout << "Ошибка открытия файла для записи.\n";
            return;
        }

        for (int i = 0; i < size; i++) {
            file << contacts[i]->getName() << "\n" // Добавлено сохранение имени
                << contacts[i]->getHomePhone() << "\n"
                << contacts[i]->getWorkPhone() << "\n"
                << contacts[i]->getMobilePhone() << "\n"
                << contacts[i]->getAdditionalInfo() << "\n";
        }
        file.close();
        cout << "Данные успешно сохранены в файл " << filename << ".\n";
    }

    
    void loadFromFile(const char* filename) {
        ifstream file(filename);
        if (!file) {
            cout << "Ошибка открытия файла для чтения.\n";
            return;
        }

        char name[100], home[20], work[20], mobile[20], info[100];
        while (file.getline(name, 100) &&
            file.getline(home, 20) &&
            file.getline(work, 20) &&
            file.getline(mobile, 20) &&
            file.getline(info, 100)) {
            addContact(name, home, work, mobile, info);
        }
        file.close();
        cout << "Данные успешно загружены из файла " << filename << ".\n";
    }
};

int main() {
    setlocale(LC_ALL, "Russian");

    PhoneBook phoneBook;
    int choice;
    char name[100], home[20], work[20], mobile[20], info[100];

    while (true) {
        cout << "1. Добавить контакт\n";
        cout << "2. Удалить контакт\n";
        cout << "3. Искать контакт\n";
        cout << "4. Показать всех контактов\n";
        cout << "5. Сохранить в файл\n";
        cout << "6. Загрузить из файла\n";
        cout << "0. Выход\n";
        cout << "Выберите действие: ";
        cin >> choice;

        cin.clear(); 
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 

        switch (choice) {
        case 1:
            cout << "Введите ФИО: ";
            cin.getline(name, 100);
            cout << "Введите домашний телефон: ";
            cin.getline(home, 20);
            cout << "Введите рабочий телефон: ";
            cin.getline(work, 20);
            cout << "Введите мобильный телефон: ";
            cin.getline(mobile, 20);
            cout << "Введите дополнительную информацию: ";
            cin.getline(info, 100);
            phoneBook.addContact(name, home, work, mobile, info);
            break;

        case 2:
            cout << "Введите ФИО для удаления: ";
            cin.getline(name, 100);
            phoneBook.removeContact(name);
            break;

        case 3:
            cout << "Введите ФИО для поиска: ";
            cin.getline(name, 100);
            phoneBook.searchContact(name);
            break;

        case 4:
            phoneBook.displayAllContacts();
            break;

        case 5:
            phoneBook.saveToFile("contacts.txt");
            break;

        case 6:
            phoneBook.loadFromFile("contacts.txt");
            break;

        case 0:
            return 0;

        default:
            cout << "Неправильный выбор.\n";
            break;
        }
    }

    return 0;
}