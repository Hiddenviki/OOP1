//
// Created by Виктория Веселкова on 19.02.2022.
//

#ifndef LAB11_PUTIN_H
#define LAB11_PUTIN_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Warehouse {
    char* fam; //название товара
    double price; //цена товара
    int quant; //количество товара
    int num; //номер секциi
};

//ПОЗЕРЫ
Warehouse* AddStruct(Warehouse* Obj, int amount);
void setData(Warehouse* Obj, int amount);
void showData(Warehouse* Obj, int amount);


void SearchByNum(Warehouse* Obj, int amount);
void SearchByFam(Warehouse* Obj, int amount);

void Copy(Warehouse d_n, Warehouse d_o); //та копировалка которая для конкретных элементов
void Sort(Warehouse* Obj, int amount);


//void ReadDataFromDisk(Warehouse* Obj, int amount, string fileName);
void ReadDataFromDisk(Warehouse* Obj, int amount, string fileName);
void SaveDataOnDisk(Warehouse* Obj, int amount, string fileName);


#endif //LAB11_PUTIN_H
