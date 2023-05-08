//
//  practice_3.cpp
//  practice_3
//
//  Created by Daniil Vilchinskiy on 24.04.2023.
//

#include <iostream>
using namespace std;

struct Date
{
    unsigned short day;
    unsigned short month;
    unsigned short year;
};

struct Record
{
    char name[17];
    char product[12];
    unsigned short unitCount;
    float coast;
    struct Date date;
};

struct node {
    Record data;
    struct node* next;
};

struct node* myHead;
int countItem = 0;


void Print_Line(){
    cout << endl;
        cout.width(79); cout.fill('-');
    cout << "-" << endl;
    cout.fill(' ');
}

void Print_Header(){
    Print_Line();
    
    cout.width(91); cout << left << "| Офисные пакеты"; cout << "|";
    
    Print_Line();
    
    cout.fill(' ');
    cout << left << "| Наименование ";
    cout << left << "| Производитель";
    cout << left << "| Количество сост. частей";
    cout << left << "| Цена($)";
    cout << left << "| Дата релиза |";
    
    Print_Line();
}

void Print_Structs(struct Record* records){
    for (int i = 0; i <= 2 ; i++) {
        
        cout << "|";
        cout.width(14);
        cout << left << records[i].name;
        
        cout << "|";
        cout.width(14);
        cout << left << records[i].product;
        
        cout << "|";
        cout.width(24);
        cout << left << records[i].unitCount;
        
        cout << "|";
        cout.width(8);
        cout << left << records[i].coast;
        
        cout << "|";
        if(records[i].date.month < 10){
            cout << left << records[i].date.day << ".0" << records[i].date.month << "." << records[i].date.year;
        } else {
            cout << left << records[i].date.day << "." << records[i].date.month << "." << records[i].date.year;
        }
        cout.width(3);
        cout.fill(' ');
        cout << " ";
        cout << "|" << endl;
    }
}

void Print_Note(){
    cout.width(79); cout.fill('-'); cout << "-" << endl;
    cout.width(125); cout.fill(' '); cout << left << "|Примечание: возможно бесплатно получить продукт StarOffice через Internet"; cout << "|";
    Print_Line();
}

void Print_Table(){
    cout << endl;
    cout << "Изначальная таблица" << endl;
}

void addItem(Record data)
{
    struct node* newItem = new node();
    newItem->data = data;
    if (countItem == 0) {
        newItem->next = NULL;
    }
    else
    {
        newItem->next = myHead;
    }
    myHead = newItem;
    countItem++;
}

void insertItem(int index, Record data) {
    if (not (index >= 0 and index <= countItem and countItem >= 0))
        return;
    if (index == 0) {
        addItem(data);
    }
    else {
        struct node* current = myHead;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        struct node* newItem = new node();
        newItem->data = data;
        newItem->next = current->next;
        current->next = newItem;
        countItem++;
    }
}

void editItem(int index, Record data) {
    if (index >= 0 and index < countItem and countItem>0) {
        struct node* current = myHead;
        for (int i = 0; i < index; i++) {
            current = current->next;
            //cout << "+" << current->data;
        }
        current->data = data;
    }
    else {
        cout << endl << "Ошибка индекс не в диапазоне";
    }
}

void deleteItem(int index) {
    if (index >= 0 and index < countItem and countItem>0) {
        struct node* current = myHead;
        struct node* old;
        if (index == 0) {
            old = myHead;
            myHead = current->next;
            delete old;
            countItem--;
        }
        else {
            int i = 0;
            while (current) {
                if (i == index - 1) {
                    old = current->next->next;
                    delete current->next;
                    current->next = old;
                    countItem--;
                    break;
                }
                i++;
                current = current->next;
            }
        }
    }

}


int main()
{
    struct Record records[10];

    records[0] = { "Office", "Microsoft", 4, 870.99, { 12, 1, 2011 } };
    records[1] = { "SmartSute", "Lotus", 5, 1020.99,  { 21, 10, 2012 } };
    records[2] = { "StarOffice", "Sun", 4, 9.99, { 21, 10, 2020 } };

    Print_Table();
    Print_Header();
    Print_Structs(records);
    Print_Note();
    
    cout << "Практика 3 Динамический список"<<endl;
    addItem(records[0]);
    addItem(records[1]);
    addItem(records[2]);
    Print_Table();
    Print_Header();
    Print_Structs(records);
    Print_Note();
    struct Record newRecord = { "Русаков", "А.М.", 1984, 712.50, {01,02,2023} };
    insertItem(1, newRecord);
    Print_Table();
    Print_Header();
    Print_Structs(records);
    Print_Note();
    deleteItem(3);
    Print_Table();
    Print_Header();
    Print_Structs(records);
    Print_Note();
    struct Record editRecord = { "Мерсов", "А.А.", 1962, 2000.75, {01,02,2023} };
    editItem(1, editRecord);
    Print_Table();
    Print_Header();
    Print_Structs(records);
    Print_Note();
}


