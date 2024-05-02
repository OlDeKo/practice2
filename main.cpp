#include <iostream>
#include <locale>
using namespace std;
int section(int mas[], int nachalo, int end) {
    int point = mas[nachalo];
    int count = 0;
    for (int i = nachalo + 1; i <= end; i++) {
        if (mas[i] <= point)
            count++;}
    int in = nachalo + count;
    swap(mas[in], mas[nachalo]);
    int i = nachalo, j = end;
    while (i < in && j > in) {
        while (mas[i] <= point)
            i++;
        while (mas[j] > point)
            j--;
        if (i < in && j > in)
            swap(mas[i++], mas[j--]);}
    return in;}
void sortirovka(int mas[], int start, int end) {
    if (start >= end)
        return;
    int p = section(mas, start, end);
    sortirovka(mas, start, p - 1);
    sortirovka(mas, p + 1, end);}
void sort(int*, int, int, int);
void _sortirovka_(int* arr, int low, int high) {
    int mid;
    if (low < high) {
        mid = (low + high) / 2;
        _sortirovka_(arr, low, mid);
        _sortirovka_(arr, mid + 1, high);
        sort(arr, low, high, mid);}}
void sort(int* arr, int low, int high, int mid) {
    int i, j, k, c[50];
    i = low;
    k = low;
    j = mid + 1;
    while (i <= mid && j <= high) {
        if (arr[i] < arr[j]) {
            c[k] = arr[i];
            k++;
            i++;}
        else {
            c[k] = arr[j];
            k++;
            j++;}}
    while (i <= mid) {
        c[k] = arr[i];
        k++;
        i++;}
    while (j <= high) {
        c[k] = arr[j];
        k++;
        j++;}
    for (i = low; i < k; i++)
        arr[i] = c[i];}
int main() {
    setlocale(LC_ALL, "rus");
    int n;
    do {  cout << "количество элементов: ";
        cin >> n;
        if (n <= 0)
            cout << "ошибка" << endl;
    } while (n <= 0);
    int mas[100];
    cout << "введите элементы: ";
    for (int i = 0; i < n; i++)
        cin >> mas[i];
    int vibor;
    do { cout << "1 быстрая" << endl << "2 слиянием" << endl;
        cin >> vibor;
        if (vibor != 1 && vibor != 2)
            cout << "ошибка" << endl;
    } while (vibor != 1 && vibor != 2);
    switch (vibor) {
    case 1:
        sortirovka(mas, 0, n - 1);
        cout << "отсортированные элементы: ";
        for (int i = 0; i < n; i++)
            cout << mas[i] << " ";
        break;
    case 2:
        _sortirovka_(mas, 0, n - 1);
        cout << "отсортированные элементы: ";
        for (int i = 0; i < n; i++)
            cout << mas[i] << " ";
        break;}}