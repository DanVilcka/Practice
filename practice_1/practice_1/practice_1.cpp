//
//  practice_1.cpp
//  practice_1
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

void Print_Table1(){
    cout << endl;
    cout << "Таблица после выполнения задания" << endl;
}

void Filter(struct Record* records){
    int max = 0;
    int min = 100000;
    int sup = 3;

    for(int i = 0; i <= 2; i++){
        if(records[i].date.year > max){
            max = i;
        }
    }

    for(int i = 0; i <= 2; i++){
        if(records[i].date.year < min){
            min = i;
        }
    }



    records[sup] = records[max];
    records[max] = records[min];
    records[min] = records[sup];


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
    
    Filter(records);

    Print_Table1();
    Print_Header();
    Print_Structs(records);
    Print_Note();
}

