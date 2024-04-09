/*
Создайте приложение "Склад". Приложение должно реализовывать следующую 
функциональность:
Добавление товара на склад.
Удаление товара со склада.
Замена товара.

Поиск товара:
По названию.
По производителю.
По цене.
По группе товара (например, "Минеральная вода" или "Консервы").
По дате поступления на склад.
По сроку годности.

Сортировка товара:
По цене.
По группе товара.
*/


#include <iostream>
#include <cstring>
#include "Header.h"
using namespace std;

int Menu() {
    int choice;
    cout << "1)Добавление товара на склад\n"
        << "2)Печать всех книг\n"
        << "3)Удаление товара со склада\n"
        << "4)Замена товара\n"
        << "5)Поиск товара по названию\n"
        << "6)Поиск товара По производителю\n"
        << "7)Поиск товара По цене\n"
        << "8)Поиск товара По группе товара\n"
        << "9)Поиск товара По дате поступления на склад\n"
        << "10)Поиск товара По сроку годности\n"
        << "11)Сортировка товара По цене\n"
        << "12)Сортировка товара По группе товара\n"
        << "0)exit\n"
        << "Choice what do you need: \n";
    cin >> choice;
    return choice;
}

void Print(Product aProduct) {
    cout << "Title: " << aProduct.title << endl;
    cout << "Maker: " << aProduct.maker << endl;
    cout << "Price: " << aProduct.price << endl;
    cout << "Product class: " << aProduct.product_class << endl;
    cout << "Date of receipt into the warehouse: " << aProduct.arrival_date_in_stock.day << "." <<
        aProduct.arrival_date_in_stock.month << "." << aProduct.arrival_date_in_stock.year << endl;
    cout << "Date by expiration date: " << aProduct.shelf_life.day << "." <<
        aProduct.shelf_life.month << "." << aProduct.shelf_life.year << endl;
}
// Поиск товара: По названию
void searchOfTitle(Product aProduct[], int size, const char* whichTitle) {
    bool found = false;
    for (int i = 0; i < size; ++i) {
        if (strcmp(aProduct[i].title, whichTitle) == 0) {
            Print(aProduct[i]);
            found = true;
        }
    }
    if (!found) {
        cout << "No books found for author: " << whichTitle << endl;
    }
}

//Поиск товара: По производителю
void searchOfMaker(Product aProduct[], int size, const char* whichMaker) {
    bool found = false;
    for (int i = 0; i < size; ++i) {
        if (strcmp(aProduct[i].maker, whichMaker) == 0) {
            Print(aProduct[i]);
            found = true;
        }
    }
    if (!found) {
        cout << "No books found for maker: " << whichMaker << endl;
    }
}

//Поиск товара: По цене
void searchOfPrice(Product aProduct[], int size, int whichPrice) {
    bool found = false;
    for (int i = 0; i < size; ++i) {
        if (aProduct[i].price == whichPrice) {
            Print(aProduct[i]);
            found = true;
        }
    }
    if (!found) {
        cout << "No books found for price: " << whichPrice << endl;
    }
}

//Поиск товара: По группе товара
void searchOfProductClass(Product aProduct[], int size, const char* whichProductClass) {
    bool found = false;
    for (int i = 0; i < size; ++i) {
        if (strcmp(aProduct[i].product_class, whichProductClass) == 0) {
            Print(aProduct[i]);
            found = true;
        }
    }
    if (!found) {
        cout << "No books found for maker: " << whichProductClass << endl;
    }
}

//Поиск товара: По дате поступления
void searchOfdate(Product aProduct[], int size, int whichDay, int whichMonth, int whichYear) {
    bool found = false;
    for (int i = 0; i < size; ++i) {
        if (aProduct[i].arrival_date_in_stock.day == whichDay) {
            if (aProduct[i].arrival_date_in_stock.month == whichMonth) {
                if (aProduct[i].arrival_date_in_stock.year == whichYear) {
                    Print(aProduct[i]);
                    found = true;
                }
            }
        }
    }
    if (!found) {
        cout << "No books found for price: " << whichDay << "." << whichMonth << "." << whichYear << endl;
    }
}

//Сортировка товара:По цене
void sortingOfTitle(Product aProduct[], int ROWS) {
    for (int i = 0; i < ROWS - 1; i++) {
        if (aProduct[i].price < aProduct[i + 1].price) {
            Product temp = aProduct[i];
            aProduct[i] = aProduct[i + 1];
            aProduct[i + 1] = temp;
        }
    }
}

//Сортировка товара:По группе товара
void sortingOfTitle(Product aProduct[], int ROWS) {
    for (int i = 0; i < ROWS - 1; i++) {
        if (strcmp(aProduct[i].product_class, aProduct[i + 1].product_class) > 0) {
            Product temp = aProduct[i];
            aProduct[i] = aProduct[i + 1];
            aProduct[i + 1] = temp;
        }
    }
}


int main()
{
    setlocale(LC_ALL, "ru");
    const int N = 255;
    int howManyItems = 1;
    int choice;
    Product* storage = new Product[howManyItems];
    while (true) {
        choice = Menu();
        switch (choice) {
        case 0:
            exit(0);
        case 1:
            Product newItem = input(); 
            Product* newStorage = new Product[howManyItems + 1]; 
            for (int i = 0; i < howManyItems; ++i) {
                newStorage[i] = storage[i]; 
            }
            newStorage[howManyItems] = newItem; 
            delete[] storage;
            storage = newStorage; 
            howManyItems++; 
            break;
        case 2:
            for (int i = 0; i < howManyItems; i++) {
                Print(storage[i]);
            }
            break;
        case 3:
            int deleteItem;
            cout << "Введите номер товара для удаления: ";
            cin >> deleteItem;
            if (deleteItem >= 0 && deleteItem < 7) {
                for (int i = 0; i < howManyItems; i++) {
                    storage[i] = storage[i + 1];
                }
                howManyItems--;
                cout << "Товар успешно удален." << endl;
            }
            else {
                cout << "Неверный номер товара." << endl;
            }
            break;

        case 4:
            int changeItem;
            cout << "Введите номер товара для изменения: ";
            cin >> changeItem;
            Product newItem = input();
            Product* newStorage = new Product[howManyItems + 1];
            for (int i = 0; i < howManyItems; ++i) {
                newStorage[i] = storage[changeItem];
            }
                cout << "Товар успешно изменен." << endl;
            
            break;
        /*case 5:
            char whichTitle[255];
            cout << "Введите название товара: ";
            cin.ignore();
            cin.getline(whichTitle, 255);
            for (int i = 0; i < howManyItems; i++) {
                searchOfTitle(storage, sizeof(storage->title) / sizeof(storage->title[0]), whichTitle);
            }

            break;

        case 6:
            char whichMaker[255];
            cout << "write which maker are you interested: ";
            cin.ignore();
            cin.getline(whichTitle, 255);
            searchOfMaker(storage, sizeof(storage->title) / sizeof(storage->title[0]), whichTitle);
        case 7:
            int price;
            cout << "write which price are you interested: ";
            cin >> price;
            searchOfPrice(storage, sizeof(storage->title) / sizeof(storage->title[0]), price);
        case 8:
            char whichProductClass[255];
            cout << "write which Product Class are you interested: ";
            cin.ignore();
            cin.getline(whichProductClass, 255);
            searchOfProductClass(storage, sizeof(storage->title) / sizeof(storage->title[0]), whichProductClass);
        case 9:
            int day = 0;
            int month = 0;
            int year = 0;
            cout << "write what day are you interesting: ";
            cin >> day;
            cout << "write what month are you interesting: ";
            cin >> month;
            cout << "write what year are you interesting: ";
            cin >> year;
            searchOfdate(storage, sizeof(storage->title) / sizeof(storage->title[0]), day, month, year);
        case 10:
            int day = 0;
            int month = 0;
            int year = 0;
            cout << "write what day are you interesting: ";
            cin >> day;
            cout << "write what month are you interesting: ";
            cin >> month;
            cout << "write what year are you interesting: ";
            cin >> year;
            searchOfdate(storage, sizeof(storage->title) / sizeof(storage->title[0]), day, month, year);*/


        default:
            cout << "Invalid choice." << endl;
            break;
        }
    }
    return 0;
}