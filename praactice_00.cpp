//
//  main.cpp
//  Practice
//
//  Created by Daniil Vilchinskiy on 24.04.2023.
//


#include <iostream>
using namespace std;




struct Record
{
    char name[17];
    char product[12];
    unsigned short unitCount;
    float coast;
    char date[11];
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
        cout.width(13);
        cout << left << records[i].date;
        
        cout << "|" << endl;
    }
}

void Print_Note(){
    cout.width(79); cout.fill('-'); cout << "-" << endl;
    cout.width(125); cout.fill(' '); cout << left << "|Примечание: возможно бесплатно получить продукт StarOffice через Internet"; cout << "|";
    Print_Line();
}

int main()
{
    struct Record records[10];

    records[0] = { "Office", "Microsoft", 4, 870.99, "11.01.2011" };
    records[1] = { "SmartSute", "Lotus", 5, 1020.99, "21.10.2012" };
    records[2] = { "StarOffice", "Sun", 4, 9.99, "21.10.2020" };

    Print_Header();
    Print_Structs(records);
    Print_Note();
}
