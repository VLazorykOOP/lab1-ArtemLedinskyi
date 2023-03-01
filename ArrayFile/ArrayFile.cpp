// ArrayFile.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <ios>
#include <vector>

#include <time.h>


using namespace std;

typedef double* pDouble;
/*
*   ConsoleInputArrayDouble
*
*/
int ConsoleInputSizeArray(const int sizeMax)
{
    int size = 0;
    do {
        cout << " Input size Array ( 0< 1 < " << sizeMax << " ) ";
        cin >> size;
    } while (size <= 0 || size >= sizeMax);
    return size;
}
/*
*   ConsoleInputArrayDouble
*
*/
int ConsoleInputArray(int sizeMax, double A[])
{
    int size = ConsoleInputSizeArray(sizeMax);
    for (int i = 0; i < size; i++) {
        cout << " Array[ " << i << "] "; cin >> A[i];
    }
    return size;
}

/*
*   RndInputArrayDouble
*
*/
int RndInputArray(int sizeMax, double A[])
{
    int size = ConsoleInputSizeArray(sizeMax);
    int r1 = 0, r2 = 0;
    srand(size);

    for (int i = 0; i < size; i++) {
        r1 = rand();
        r2 = rand();
        A[i] = 100.0 * r1;
        A[i] = A[i] / (1.0 + r2);
        cout << A[i] << "   ";
    }
    return size;
}

int ConsoleInputDynamicArrayNew(int sizeMax, pDouble& pA)
{
    int size = ConsoleInputSizeArray(sizeMax);
    pA = new double[size];
    if (pA == nullptr) { return 0; }
    for (int i = 0; i < size; i++) {
        cout << " Array[ " << i << "] "; cin >> pA[i];
    }
    return size;
}

int ConsoleInputDynamicArray_calloc(int sizeMax, pDouble& pA)
{
    int size = ConsoleInputSizeArray(sizeMax);
    pA = (double*)calloc(size, sizeof(double));      // pA = (double*)malloc(size * sizeof(double)); 
    if (pA == nullptr) { return 0; }
    for (int i = 0; i < size; i++) {
        cout << " Array[ " << i << "] "; cin >> pA[i];
    }
    return size;
}

void ConsoleInputVector(int sizeMax, vector<double>& A)
{
    int size = ConsoleInputSizeArray(sizeMax);
    double d;
    for (int i = 0; i < size; i++) {
        cout << " Array[ " << i << "] "; cin >> d; A.push_back(d);
    }
    return;
}


/*
*  WriteArrayTextFile
*
*/

void WriteArrayTextFile(int n, double* arr, const char* fileName)
{
    ofstream fout(fileName);
    if (fout.fail()) return;
    fout << n << endl;
    for (int i = 0; i < n; i++)
        fout << arr[i] << "   ";
    fout.close(); //
}
/*
*  ReadArrayTextFile
*
*/


int ReadArrayTextFile(int n, double* arr, const char* fileName)
{
    int size;
    ifstream fin(fileName);
    if (fin.fail()) return 0;
    fin >> size;
    if (size <= 0) return 0;
    if (size > n) size = n;
    for (int i = 0; i < n; i++)
        fin >> arr[i];
    fin.close();
    return size;

}


void WriteArrayBinFile(int n, double* arr, const char* fileName)
{
    //ios_base
    ofstream bfout(fileName, ios_base::binary);
    if (bfout.fail()) return;
    bfout.write((const char*)&n, sizeof(int));
    std::streamsize  cn = static_cast<std::streamsize>(n) * sizeof(double);
    bfout.write((const char*)arr, cn);
    bfout.close();
}

int ReadArrayBinFile(int n, double* arr, const char* fileName)
{
    int size = 0;
    ifstream bfin(fileName, ios_base::binary);
    if (bfin.fail()) return 0;
    bfin.read((char*)&size, sizeof(int));
    if (size <= 0) return 0;
    if (size > n) size = n;
    bfin.read((char*)arr, static_cast<std::streamsize>(size) * sizeof(double));
    bfin.close();
    // ssdhs
    return size;
}

void ShowMainMenu()
{
    cout << "    Main Menu  \n";
    cout << "    1.  Task 1  \n";
    cout << "    2.  Task 2  \n";
    cout << "    3.  Task 3  \n";
}

void MenuTask()
{
    cout << "     Menu Task   \n";
    cout << "    1.  Local array  \n";
    cout << "    2.  Dynamic array 1 \n";
    cout << "    3.  Dynamic array 2  new \n";
    cout << "    4.  Dynamic array : vector \n";
    cout << "    5.  Exit \n";
}

void MenuInput()
{
    cout << "     Menu Input   \n";
    cout << "    1.  Console all \n";
    cout << "    2.  Console - size, array - random \n";
    cout << "    3.  File 1.txt \n";
    cout << "    4.  bb    \n";
    cout << "    5.  Exit \n";
}


/*
* Задано одновимірний масив А розміру 2N.
* Побудувати два масиви В і С розміру N,
* включивши  у масив В елементи масиву А з парними індексами,
* а у С - з непарними.
*****************
*  A - in
*  B, C - out
*/
void  TestVariant(int N, double* A, double* B, double* C) {
    for (int i = 0; i < N; i++) {
        B[i] = A[2 * i];
        C[i] = A[2 * i + 1];
    }
}
/*
*  Task  Var
*
*
*/
void TaskV()
{
    char ch = '5';
    do {
        system("cls");
        MenuTask();
        ch = getchar();
        getchar();
        switch (ch) {
        case '1': cout << " 1 "; break;
        case '2': cout << " 2 "; break;
            //
        case '5': return;
        }
        cout << " Press any key and enter\n";
        ch = getchar();
    } while (ch != 27);

}

void ArrayLocal()
{
    double A[1000], B[500], C[500];
    int n;
    char ch = '5';
    do {
        system("cls");
        MenuTask();
        ch = getchar();
        getchar();
        switch (ch) {
        case '1': cout << " 1 "; break;
        case '2': cout << " 2 "; break;
            //
        case '5': return;
        }
        cout << " Press any key and enter\n";
        ch = getchar();
    } while (ch != 27);

}
void task1() {
    double A[100];
    double B[100];
    int i, j;
    int n;
    int bN = 0;//Рахунок,що буде рахувати скільки елементів в масиві В
    cout << "Enter lenght:";//Ввід значень 
    cin >> n;
    ReadArrayTextFile(n, A, "1ReadArrayA.txt");
    WriteArrayBinFile(n, A, "Write1task.bin");
    if (n == 0) {
        n = RndInputArray(100, A);
        WriteArrayTextFile(n, A, "1ReadArrayA.txt");
        WriteArrayBinFile(n, A, "Write1task.bin");
    }
    for (int i = 0; i < n; i++) {
        cout << "Enter Number : ";//Вввід
        cin >> A[i];
        WriteArrayTextFile(A[i] "1ReadArrayA.txt");
    }
    for (i = 0; i < n; i++) {//Цикл,у якому,якщо значення,що будуть більше за 10 зберігатимуться у В
        if (A[i] > 10) {
            B[bN++] = A[i];
        }
    }
    for (j = 0; j < bN; j++) {//Вивід 
        cout << B[j] << "" << endl;
    }
    WriteArrayTextFile(B[j], "1ReadArrayA.txt");
    WriteArrayBinFile(B[j] "Write1task.bin");
    return;
}
void task2() {
    double* A;
    int n, i;
    int* T1;//умова задачі
    int* T2;//умова задачі
    int index;
    int min;
    int min_index = 0;
    T1 = new int;
    T2 = new int;
    A = new double[100];
    cout << "Enter lenght of Array :";//Ввід довжини масиву
    cin >> n;
    ReadArrayTextFile(n, A, "2ReadArrayA.txt");
    WriteArrayBinFile(n, A, "Write2task.bin");
    if (n == 0) {
        n = RndInputArray(100, A);
        WriteArrayTextFile(n, A, "2ReadArrayA.txt");
        WriteArrayBinFile(n, A, "Write2task.bin");
    }
    for (i = 0; i < n; i++) {//Ввід чисел,що будуть знаходяться в масиві
        cout << "Enter Number :";
        cin >> A[i];
    }
    cout << "Enter T1 :";//Значення для Т1
    cin >> *T1;
    cout << "Enter T2 :";//Значення для Т1
    cin >> *T2;
    for (i = 0; i < n; i++) {//Записує в index перший елемент масиву,що більше за T2
        if (A[i] > *T2) {
            index = i;
            break;
        }
    }
    min = A[index];
    for (i = index - 1; i >= 0; i--) {//Знаходить найменший елемент в діапазоні до першого елемента,що більше за Т2
        if (A[i] < min) {
            min = A[i];
            min_index = i;
        }
    }
    if (min < *T1) {
        cout << "min element is " << min << "\t" << "index of min element :" << min_index;
    }
    else;
    WriteArrayTextFile(min, min_index, "2ReadArrayA.txt");
    WriteArrayBinFile(min, min_index, "Write2task.bin");
    delete[]A;
    delete T1;
    delete T2;
    return;
}
void task3() {
    double A[150], B[150], C[300];
    int n, m, i, j, k;
    int sum = 0;
    cout << "Enter the Size for First Array: ";//ввід данних
    cin >> n;
    if (n == 0) {
        n = RndInputArray(100, A);
        WriteArrayTextFile(n, A, "1ReadArrayA.txt");
        WriteArrayBinFile(n, A, "Write1task.bin");
    }
    for (i = 0; i < n; i++)
    {
        cout << "Enter Number for First Array:";//ввід данних
        cin >> A[i];
        C[i] = A[i];
    }
    k = i;//Рахунок
    cout << "\nEnter the Size for Second Array: ";//ввід данних
    cin >> m;
    if (m == 0) {
        m = RndInputArray(100, B);
        WriteArrayTextFile(m, B, "3ReadArrayB.txt");
        WriteArrayBinFile(m, B, "Write3task.bin");
    }
    for (i = 0; i < m; i++)
    {
        cout << "Enter Number for Second Array :";//ввід данних
        cin >> B[i];
        C[k] = B[i];
        k++;
    }
    cout << "\n C: \n";//Вивід масиву 
    for (i = 0; i < k; i++) {
        cout << C[i] << "\t";
    }
    cout << endl;
    ReadArrayTextFile(n, A, "3ReadArrayA.txt");
    ReadArrayTextFile(n, B, "3ReadArrayB.txt");
    ReadArrayTextFile(n, C, "3ReadArrayC.txt");
    WriteArrayBinFile(n, A, "Write3task.bin");
    WriteArrayBinFile(n, B, "Write3task.bin");
    WriteArrayBinFile(n, C, "Write3task.bin");
    for (i = 0; i < k - 1; i++) {//bubble sort
        for (j = 0; j < k - i - 1; j++) {
            if (C[j] > C[j + 1]) {
                swap(C[j], C[j + 1]);
            }
        }
    }
    cout << "C : \t" << endl;
    for (i = 0; i < k; i++) {//Вивід відсортованого масиву
        cout << C[i] << "\t";
    }
    for (i = 0; i < k; i++) {//Сума елементів серед масиву 
        sum += C[i];
    }
    cout << endl;
    cout << "Sum A+B\t" << sum << endl;//Вивід відповіді 
    WriteArrayBinFile(sum ,"Write3task.bin");
    WriteArrayTextFile(sum ,"1ReadArrayA.txt");
    return;
}

int main() {
    ShowMainMenu();
    cout << "Choose Task which one do you want to watch :";
    int c;
    cin >> c;
    if (c == 1) {
        task1();
    }
    else if (c == 2) {
        task2();
    }
    else if (c == 3) {
        task3();
    }
    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
