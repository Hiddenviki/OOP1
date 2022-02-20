#include <sstream>
#include "Putin.h"

////////////////////////CHECK////////////////////////////////////////////////////////////////////////////////////////////

double getPrice()
{
    while (true) // цикл продолжается до тех пор, пока пользователь не введет корректное значение
    {
        cout << "Цена (в формате double): ";
        double a;
        cin >> a;

        if (cin.fail() or (a <= 0.0)) // если предыдущее извлечение оказалось неудачным,
        {
            cin.clear(); // то возвращаем cin в 'обычный' режим работы
            cin.ignore(32767,'\n'); // и удаляем значения предыдущего ввода из входного буфера
        }
        else // если всё хорошо, то возвращаем a
            return a;
    }
}
int getQuant()
{
    while (true) // цикл продолжается до тех пор, пока пользователь не введет корректное значение
    {
        cout << "Количество товара: ";
        int a;
        cin >> a;

        if (cin.fail() or (a <= 0) ) // если предыдущее извлечение оказалось неудачным
        {
            cin.clear(); // то возвращаем cin в 'обычный' режим работы
            cin.ignore(32767,'\n'); // и удаляем значения предыдущего ввода из входного буфера
        }
        else // если всё хорошо, то возвращаем a
            return a;
    }
}
int getNum()
{
    while (true) // цикл продолжается до тех пор, пока пользователь не введет корректное значение
    {
        cout << "Номер секции: ";
        int a;
        cin >> a;

        if (cin.fail() or (a <= 0)) // если предыдущее извлечение оказалось неудачным,
        {
            cin.clear(); // то возвращаем cin в 'обычный' режим работы
            cin.ignore(32767,'\n'); // и удаляем значения предыдущего ввода из входного буфера
        }
        else // если всё хорошо, то возвращаем a
            return a;
    }
}
char * getFam(){
    int i;
    char *str;
    str = new char[15];
    char *Obj = new char[15];
    do{
        cout<<"Введите название товара: ";
        cin>>str;
        for(i=0;str[i];i++)
            if((str[i]>='0' and str[i]<='9' and str[i]) or (str[i]<='/' and str[i]>='!') or (str[i]<='@' and str[i]>=':') or (str[i]<='`' and str[i]>='[') or (str[i]<='~' and str[i]>='{'))
                break;
        if(str[i])
            cout<<"___Зачем вы ввели не буквы...?___"<<endl<<"___Повторите ввод___"<<endl;
    }while(str[i]);

    for (i = 0; str[i]; i++){
        Obj[i]+=str[i];
    }
    return Obj;
}

////////////////////////MAIN FUNCTIONS///////////////////////////////////////////////////////////////////////////////////

Warehouse* AddStruct(Warehouse* Obj, int amount)
{

    if (amount == 0)
    {
        Obj = new Warehouse[amount + 1]; // выделение памяти для первой структуры
    }
    else
    {
        Warehouse* tempObj = new Warehouse[amount + 1];

        for (int i = 0; i < amount; i++)
        {
            tempObj[i] = Obj[i]; // копируем во временный объект
        }
        delete[] Obj;

        Obj = tempObj;
    }
    return Obj;
}
void setData(Warehouse* Obj, int amount)

{

    Obj[amount].quant=getQuant();
    cin.get();

    Obj[amount].price=getPrice();
    cin.get();

    Obj[amount].num=getNum();
    cin.get();

    Obj[amount].fam = new char[15];
    Obj[amount].fam = getFam(); //here

    cout << endl;
}
void showData(Warehouse* Obj, int amount)
{
    //system("cls");
    cout << "НАЗВАНИЕ " << "№ СЕКЦИИ " << "ЦЕНА " << "КОЛИЧЕСТВО " <<endl;
    for (int i = 0; i < amount; i++) {
        cout << Obj[i].fam<<" "<< Obj[i].price<<" "<<Obj[i].quant<<" "<<Obj[i].num<<endl;
    }

}


void SearchByNum(Warehouse* Obj, int amount)
{
    int s;
    cout << "Введите номер секции:" << endl;
    cin>>s;
    cout << "№ПИСЬМА " << "ОЦЕНКА ПИСЬМА" << "ИНДЕКС ОТПРАВИТЕЛЯ" << "ФАМИЛИЯ ОТПРАВИТЕЛЯ" <<endl;
    for (int i = 0; i < amount; i++)
    {
        if (Obj[i].num == s)
        {
            cout << Obj[i].fam << Obj[i].num << Obj[i].price << Obj[i].quant<<endl;
        }
    }
} //найти все товары заданной секции
void SearchByFam(Warehouse* Obj, int amount)
{
    char s[32];
    cout << "Введите название товара:" << endl;
    cin.get();
    cin.getline(s, 32, '\n');

    cout << "ОЦЕНКА ПИСЬМА" << "ИНДЕКС ОТПРАВИТЕЛЯ" << "ФАМИЛИЯ ОТПРАВИТЕЛЯ" <<endl;
    for (int i = 0; i < amount; i++)
    {
        if (strcmp(Obj[i].fam, s) == 0)
        {
            cout << Obj[i].fam << Obj[i].num << Obj[i].price << Obj[i].quant<<endl;
        }
        cout << "-----------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    }
} //найти товар по названию

void Copy(Warehouse d_n, Warehouse d_o){

    d_n.fam = d_o.fam;
    d_n.price = d_o.price;
    d_n.quant = d_o.quant;
    d_n.num = d_o.num;

} //та копировалка которая для конкретных элементов
void Sort(Warehouse* Obj, int amount){

    Warehouse buf; //некая переменная временного характера

    //мой любимый пузырек
    for (int i=0; i<amount; i++){
        for (int j=i+1; j<amount; j++){
            if (Obj[i].quant > Obj[j].quant){
                Copy(buf,Obj[j]);
                Copy(Obj[j],Obj[i]);
                Copy(Obj[i],buf);
            }
        }
    }
    cout<<"Данные отсортированы"<<endl;

    cout << "НАЗВАНИЕ ТОВАРА" << "НОМЕР СЕКЦИИ" << "ЦЕНА" << "КОЛИЧЕСТВО ТОВАРА" <<endl;
    for (int i = 0; i < amount; i++) {
        cout << Obj[i].fam << Obj[i].num << Obj[i].price << Obj[i].quant<<endl;
    }


}

////////////////////////SIDE HOES///////////////////////////////////////////////////////////////////////////////////////

//При каждом запуске программы все сохранённые данные автоматически считываются с диска//
void ReadDataFromDisk(string fileName){
    cout << "НАЗВАНИЕ " << "№ СЕКЦИИ " << "ЦЕНА " << "КОЛИЧЕСТВО " <<endl;
    string line;
    ifstream myfile (fileName);
    if (myfile.is_open())
    {
        while (! myfile.eof() )
        {
            getline (myfile,line);
            cout << line << endl;
        }
        myfile.close();
    }
}



//ne robit(((

//    //поток для чтения
//    ifstream reading("file.txt");
//
//    ifstream in(fileName);
//    string s;
//    while (in.peek() != EOF) {
//        getline(in, s);
//        amount++;
//    } //считаю количество структур (строк) в файле
//
//    if (reading){
//        //выделяем память
//        Obj = new Warehouse[amount];
//
//        for (int i =0; i < amount; i++) {
//            reading >> Obj[i].fam ;
//            reading >> Obj[i].price;
//            reading >> Obj[i].quant;
//            reading >> Obj[i].num;
//        }
//
//        cout << "Данные считаны с диска."<<endl;
//    }
//    else
//        cout<<"Ошибка открытия диска."<<endl;
//
//    reading.close();
//
//    cout << "НАЗВАНИЕ ТОВАРА" << "НОМЕР СЕКЦИИ" << "ЦЕНА" << "КОЛИЧЕСТВО ТОВАРА" <<endl;
//    for (int i = 0; i < amount; i++) {
//        cout << Obj[i].fam << Obj[i].num << Obj[i].price << Obj[i].quant<<endl;
//    }
//
//}

//При каждом закрытии программы все сохранённые данные автоматически записываются на диск//
void SaveDataOnDisk(Warehouse* Obj, int amount, string fileName){

    //поток для !записи!
    ofstream record(fileName, ios::app);

    if (record)
    {
        for (int i=0; i<amount; i++)
        {
            record << Obj[i].fam<<" "<< Obj[i].price<<" "<<Obj[i].quant<<" "<<Obj[i].num<<endl;
        }
    }

    else{
        cout<<"ОШИБКА ЗАПИСИ ДАННЫХ НА ДИСК"<<endl;
    }
    record.close();
}


