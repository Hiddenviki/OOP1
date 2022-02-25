#include "Putin.h"


void showMenu(int* a){
    cout<<endl;
    cout << "____________________МЕНЮ____________________" << endl;
    cout << " 1.      Вывести новое" << endl;
    cout << " 2.      Добавить новый товар" << endl;
    cout << " 3.      Найти товар по его названию" << endl;
    cout << " 4.      Найти все новые товары из одной секции" << endl;
    cout << " 5.      Рассортировать товары по уменьшению количества" << endl;
    cout << " 6.      Сохранить все новые товары на диск и выйти из программы" << endl;
    cout<<endl;
    cout << "Введите число [1 , 6]" << endl;

    cin >> *(a);
}



int sponsorAmount=0; //количество структур

int main()
{
    //SetConsoleCP(1251);
    //setlocale(LC_ALL, "Russian");




    Warehouse* MyLittleLetters=0; //указатель на начало массива структур (вроде)
    ReadDataFromDisk(MyLittleLetters, sponsorAmount,"file.txt"); //сразу считываю данные на диске и выделяю под них память

    int YesOrNot = 0; //  продолжить или остановить ввод данных

    cout<<"Можете ввести новый товар "<<endl;

    do
    {
        MyLittleLetters = AddStruct(MyLittleLetters, sponsorAmount); //указали на номер последней структуры в массиве
        setData(MyLittleLetters, sponsorAmount);
        sponsorAmount++;
        cout << "Продолжить ввод данных? (1 - да, 0 - нет): "; //ну типо любое кроме нуля это ДА
        cin >> YesOrNot;
        cin.get();

    } while (YesOrNot != 0);

    showData(MyLittleLetters, sponsorAmount);
    int a;
    do {
        showMenu(&a);
        switch (a)
        {
            case 1: //вывести то что написали щас
                showData(MyLittleLetters, sponsorAmount);
                //system("cls");
                break;

            case 2: //добавить новый товар
                MyLittleLetters = AddStruct(MyLittleLetters, sponsorAmount);
                setData(MyLittleLetters, sponsorAmount);
                sponsorAmount++;
                //system("cls");
                break;

            case 3: //Найти товар по названию
                SearchByFam(MyLittleLetters, sponsorAmount);
                //system("cls");
                break;

            case 4: //Найти все товары секции
                SearchByNum(MyLittleLetters, sponsorAmount);
                //system("cls");
                break;

            case 5: //Рассортировать товары по уменьшению их количества
                Sort(MyLittleLetters, sponsorAmount);
                //system("cls");
                break;

            case 6: //Сохранить всё и завершить работу
                SaveDataOnDisk(MyLittleLetters, sponsorAmount, "file.txt");
                //system("cls");
                break;

            default:
                cout<<"Неверно введен номер действия"<<endl;
                //system("cls");
                //system("pause");
                break;

        }
        //if (c != 6)
        //system("pause");
    } while (a != 6);

    return 0;
}
