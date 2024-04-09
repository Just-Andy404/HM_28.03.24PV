/*
�������� ���������� "�����". ���������� ������ ������������� ��������� ����������������:
���������� ������ �� �����.
�������� ������ �� ������.
������ ������.

����� ������:
�� ��������.
�� �������������.
�� ����.
�� ������ ������ (��������, "����������� ����" ��� "��������").
�� ���� ����������� �� �����.
�� ����� ��������.

���������� ������:
�� ����.
�� ������ ������.
*/

/*
cout << "1)���������� ������ �� �����\n"
            << "2)������ ���� ����\n"
            << "3)�������� ������ �� ������\n"
            << "4)������ ������\n"
            << "5)����� ������ �� ��������\n"
            << "6)����� ������ �� �������������\n"
            << "7)����� ������ �� ����\n"
            << "8)����� ������ �� ������ ������\n"
            << "9)����� ������ �� ���� ����������� �� �����\n"
            << "10)����� ������ �� ����� ��������\n"
            << "11)���������� ������ �� ����\n"
            << "12)��\n"

            << "0)exit\n"
            << "Choice what do you need: \n";
*/


#pragma once
#include <iostream>
#include <cstring> // for strcpy
using namespace std;



struct Date {
    int year;
    int month;
    int day;
};

struct Product {
    char title[255];
    char maker[255];
    double price;
    char product_class[255];
    Date arrival_date_in_stock;
    Date shelf_life;
};

// ���������� ������ �� �����.
Product input() {
    Product aProduct;
    int day, month, year;
    cin.ignore();
    cout << "Input title: ";
    cin.getline(aProduct.title, 255);
    cout << "Input maker: ";
    cin.getline(aProduct.maker, 255);
    cout << "Input price: ";
    cin >> aProduct.price;
    cin.ignore(); 
    cout << "Input product_class: ";
    cin.getline(aProduct.product_class, 255);
    cout << "Input date of receipt into the warehouse: ";
    cin >> day >> month >> year;
    aProduct.arrival_date_in_stock = { day, month, year };
    cout << "Input date by expiration date: ";
    cin >> day >> month >> year;
    aProduct.shelf_life = { day, month, year };

    return aProduct;
}

// ����� ������ �� ������


// �������� ������ �� ������
Product remove(Product aProduct, int choice) {
    int day, month, year;
    switch (choice) {
    case 1:
        strcpy(aProduct.title, "delete info");
        break;
    case 2:
        strcpy(aProduct.maker, "delete info");
        break;
    case 3:
        aProduct.price = -1;
        break;
    case 4:
        strcpy(aProduct.product_class, "delete info");
        break;
    case 5:
        aProduct.arrival_date_in_stock.day = -1;
        aProduct.arrival_date_in_stock.month = -1;
        aProduct.arrival_date_in_stock.year = -1;
        break;
    case 6:
        aProduct.shelf_life.day = -1;
        aProduct.shelf_life.month = -1;
        aProduct.shelf_life.year = -1;
        break;
    default:
        cout << "Input only num from 1 to 6";
        break;
    }



 }





//���������� ������:�� ������ ������
void sortingOfTitle(Product aProduct[], int ROWS) {
    for (int i = 0; i < ROWS - 1; i++) {
        if (strcmp(aProduct[i].product_class, aProduct[i + 1].product_class) > 0) {
            Product temp = aProduct[i];
            aProduct[i] = aProduct[i + 1];
            aProduct[i + 1] = temp;
        }
    }
}
