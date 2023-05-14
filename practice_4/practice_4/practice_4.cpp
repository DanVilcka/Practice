//
//  practice_4.cpp
//  practice_4
//
//  Created by Daniil Vilchinskiy on 08.05.2023.
//

#include <iostream>
#include <fstream>
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
    struct Record records[3];

    records[0] = { "Office", "Microsoft", 4, 870.99, "11.01.2011" };
    records[1] = { "SmartSute", "Lotus", 5, 1020.99, "21.10.2012" };
    records[2] = { "StarOffice", "Sun", 4, 9.99, "21.10.2020" };

    Print_Header();
    Print_Structs(records);
    Print_Note();
    
    // Практика 4 Файлы
    // fstream
    
    
    //TODO: Текстовый
    //1. Записать 3 записи(три строки(records) из таблицы практики 0) в файл в текстовом формате.
    ofstream textFstreamFile;
    textFstreamFile.open("textFstreamFile.txt", ios_base::out);
    for(int i = 0; i < 3; i++){
        textFstreamFile << records[i].name << " ";
        textFstreamFile << records[i].product << " ";
        textFstreamFile << records[i].unitCount << " ";
        textFstreamFile << records[i].coast << " ";
        textFstreamFile << records[i].date << "\n";
    }
    textFstreamFile.close();

    //2. Считать 3 записи из файла в текстовом формате и отобразить.
    Record ReadTextRecords[3];
    ifstream textFstreamFileR;
    textFstreamFileR.open("textFstreamFile.txt", ios_base::in);
    for (int i = 0; i < 3; i++){
        textFstreamFileR >> ReadTextRecords[i].name;
        textFstreamFileR >> ReadTextRecords[i].product;
        textFstreamFileR >> ReadTextRecords[i].unitCount;
        textFstreamFileR >> ReadTextRecords[i].coast;
        textFstreamFileR >> ReadTextRecords[i].date;
    }
    textFstreamFileR.close();
    Print_Structs(ReadTextRecords);
    
    //TODO: бинарный
    ofstream binaryFstreamFile;
    binaryFstreamFile.open("binaryFstreamFile.txt", ios::binary|ios::out);
    binaryFstreamFile.write((char*)&records,sizeof(records));
    binaryFstreamFile.close();
    
    Record ReadBinaryRecords[3];
    ifstream binaryFstreamFileR;
    binaryFstreamFileR.open("binaryFstreamFile.txt", ios::binary|ios::in);
    binaryFstreamFileR.read((char*)&ReadBinaryRecords,sizeof(ReadBinaryRecords));
    binaryFstreamFileR.close();
    Print_Structs(ReadBinaryRecords);
    
    // Этап 2
    // Добавить новую запись (четвертую) в указанный существующий файл,
    // вводя данные с клавиатуры. Выполнить задание, согласно варианта
    // в указанном файле, изменения сохраняются в файле.

    Record inRecord;
        
    cout << "Введите фамилию:";
    cin >> inRecord.name;
    cout << "Введите инициалы:";
    cin >> inRecord.product;
    cout << "Введите год рожд:";
    cin >> inRecord.unitCount;
    cout << "Введите оклад:";
    cin >> inRecord.coast;
    cout << "Введите дата приема на работу (день):";
    cin >> inRecord.date;

    ofstream in;
    in.open("textFstreamFile.txt", ios::app);
    for(int i = 0; i < 1; i++){
        in << inRecord.name << " ";
        in << inRecord.product << " ";
        in << inRecord.unitCount << " ";
        in << inRecord.coast << " ";
        in << inRecord.date << "\n";
    }
    in.close();

}


