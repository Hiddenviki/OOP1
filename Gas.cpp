
#include "Putin.h"
#include <sstream>
#include "StreamTable.h"


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

    StreamTable st(std::cout);
    st.AddCol(5);
    st.AddCol(15);
    st.AddCol(10);
    st.AddCol(10);

    st.MakeBorderExt(true);
    st.SetDelimRow(true, '-');//st.SetDelimRow(false);//без символов-разделителей строк
    st.SetDelimCol(true, '|');//st.SetDelimCol(false);//без символов-разделителей строк


    //заголовок и значения выводятся одинаково
    st << "PRODUCT" << "SECTION" << "PRICE" << "AMOUNT";
    for (int i = 0; i < amount; i++) {
        st << Obj[i].fam  << Obj[i].num << Obj[i].price << Obj[i].quant;
    }

}


void SearchByNum(Warehouse* Obj, int amount)
{
    int s;
    cout << "Введите номер секции:" << endl;
    cin>>s;

    StreamTable st(std::cout);
    st.AddCol(5);
    st.AddCol(15);
    st.AddCol(10);
    st.AddCol(10);

    st.MakeBorderExt(true);
    st.SetDelimRow(true, '-');//st.SetDelimRow(false);//без символов-разделителей строк
    st.SetDelimCol(true, '|');//st.SetDelimCol(false);//без символов-разделителей строк
    st << "PRODUCT" << "SECTION" << "PRICE" << " AMOUNT";

    for (int i = 0; i < amount; i++)
    {
        if (Obj[i].num == s)
        {
            st << Obj[i].fam  << Obj[i].num << Obj[i].price << Obj[i].quant;
        }
    }
} //найти все товары заданной секции
void SearchByFam(Warehouse* Obj, int amount)
{
    char s[32];
    cout << "Введите название товара:" << endl;
    cin.get();
    cin.getline(s, 32, '\n');

    StreamTable st(std::cout);
    st.AddCol(5);
    st.AddCol(15);
    st.AddCol(10);
    st.AddCol(10);

    st.MakeBorderExt(true);
    st.SetDelimRow(true, '-');//st.SetDelimRow(false);//без символов-разделителей строк
    st.SetDelimCol(true, '|');//st.SetDelimCol(false);//без символов-разделителей строк
    st << "PRODUCT" << "SECTION" << "PRICE" << " AMOUNT";

    for (int i = 0; i < amount; i++)
    {
        if (strcmp(Obj[i].fam, s) == 0)
        {
            st << Obj[i].fam  << Obj[i].num << Obj[i].price << Obj[i].quant;
        }
        //cout << "-----------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    }
} //найти товар по названию

void Sort(Warehouse* Obj, int amount)
{
    // сортировка пузырьком
    Warehouse tmp;

    for (int i = amount - 1; i >= 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            // сравниваем элементы массива структур по сумме баллов студента
            if (Obj[j].num > Obj[j + 1].num)
            {
                tmp = Obj[j];
                Obj[j] = Obj[j + 1];
                Obj[j + 1] = tmp;
            }
        }
    }

    // в цикле выводим в консоль отсортированный массив структур
    StreamTable st(std::cout);
    st.AddCol(5);
    st.AddCol(15);
    st.AddCol(10);
    st.AddCol(10);

    st.MakeBorderExt(true);
    st.SetDelimRow(true, '-');//st.SetDelimRow(false);//без символов-разделителей строк
    st.SetDelimCol(true, '|');//st.SetDelimCol(false);//без символов-разделителей строк


    //заголовок и значения выводятся одинаково
    st << "PRODUCT" << "SECTION" << "PRICE" << "AMOUNT";
    for (int i = 0; i < amount; i++) {
        st << Obj[i].fam  << Obj[i].num << Obj[i].price << Obj[i].quant;
    }
}

////////////////////////SIDE HOES///////////////////////////////////////////////////////////////////////////////////////

//При каждом запуске программы все сохранённые данные автоматически считываются с диска
void ReadDataFromDisk(Warehouse* Obj, int amount,string fileName) {

    cout << "Данные с диска: " << endl;
    string line;
    ifstream myfile(fileName);
    if (myfile.is_open()) {
        while (!myfile.eof()) {
            getline(myfile, line);
            cout << line << endl;
        }
        myfile.close();
    }


/////////////////////////////////////////////////////////
//
//    ifstream fin;
//    fin.open(fileName);
//
//    string buffer; // буфер для строк из файла
//    string tmp;
//    int pos = 0;
//
//    if (!fin.is_open()) {
//        cout << "ERROR! Файл не открылся!" << endl;
//    } else {
//        cout << "Файл открылся" << endl;
//
//        while (fin.peek() != EOF) {
//            getline(fin, buffer);
//            AddStruct(Obj, amount);
//            amount++;
//        } //считаю количество строк в файле и выделяю память под каждую структуру
//
//        buffer=""; //немного так сказать почистила тут
//
//        while (!fin.eof())
//        {
//            for (int struct_number=0; struct_number<amount; struct_number++){
//                tmp = "";
//                getline(fin,buffer);
//
//
//                for (char j : buffer){
//                    if (!isspace(j)) {
//                        tmp += j;
//                    } //мне не нужны пробелы
//
//                    else{
//
//                        if (pos == 0){
//                            char* d = new char[buffer.length()];
//                            Obj[struct_number].fam =d;
//                            pos++;
//                            tmp = "";
//                        }
//
//                        else if (pos == 1){
//                            double a = atof(buffer.c_str()); //price2
//                            Obj[struct_number].price = a;
//                            pos++;
//                            tmp = "";
//                        }
//
//                        else if (pos==2){
//                            int b =atoi(buffer.c_str()); //quant3
//                            Obj[struct_number].quant = b;
//                            pos++;
//                            tmp = "";
//
//                        }
//
//                        else if (pos==3){
//                            int c=atoi(buffer.c_str()); //num4
//                            Obj[struct_number].num = c;
//                            pos++;
//                            tmp = "";
//                        }
//                    }
//
//                }
//
//            }
//
//        }
//
//    }
//    fin.close();
//
//    cout<<"Данные с диска:"<<endl;
//    cout << "НАЗВАНИЕ " << "№ СЕКЦИИ " << "ЦЕНА " << "КОЛИЧЕСТВО " <<endl;
//    for (int i = 0; i < amount; i++) {
//        cout << Obj[i].fam<<" "<< Obj[i].price<<" "<<Obj[i].quant<<" "<<Obj[i].num<<endl;
//    }
////////////////////////////////////////////////
//
//    ifstream reading("file.txt");
//
//    ifstream in(fileName);
//    string s;
//    while (in.peek() != EOF) {
//        getline(in, s);
//        amount++;
//    } //считаю количество структур (строк) в файле
//
//    FILE* file = fopen("file.txt","r");
//    if (file == NULL){
//        cout<< "NO DATA";
//    }
//
//    char buffer[amount];
//    fgets(buffer,amount,file);
//
//    while(!feof(file)){
//        for (int i=0; i<amount; i++) {
//            Warehouse Obj[i];
//            sscanf(buffer, "%s %le %d %d", Obj[i].fam, &Obj[i].price, &Obj[i].quant, &Obj[i].num);
//            fgets(buffer,amount,file);
//        }
//    }
//    fclose(file);
//    reading.close();
//    cout << "НАЗВАНИЕ " << "№ СЕКЦИИ " << "ЦЕНА " << "КОЛИЧЕСТВО " <<endl;
//    for (int i = 0; i < amount; i++) {
//        cout << Obj[i].fam<<" "<< Obj[i].price<<" "<<Obj[i].quant<<" "<<Obj[i].num<<endl;
//    }


}

//При каждом закрытии программы все сохранённые данные автоматически записываются на диск
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

    else
    {
        cout<<"ОШИБКА ЗАПИСИ ДАННЫХ НА ДИСК"<<endl;
    }
    record.close();
}


