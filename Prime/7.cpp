/*7) У исполнителя Множик есть три команды:
1. умножь на 8,
2. подели на 2,
3. умножь на 4
Напишите программу, которая находит, сколько различных чисел может получить
исполнитель из числа X программами, состоящими ровно из N команд. Вторая
команда выполняется, только если ей подается четное число (в противном случае
программа завершается аварийно). */

#include <iostream>

using namespace std;
void rec(int x, int y, int a, int &k)
{


    if(a==y) {k++;}
    else
    {
    int q, w, e;
    q=x*8;  a++; rec(q, y, a, k); a--;
    if(x%2==0){w=x/2; a++; rec(w, y, a, k);a--;}
    e=x*4; a++; rec(e, y, a, k);a--;
    }
    }



int main()
{
    int x, y, a=0, k=0;
    cin>>x>>y;
    rec(x, y, a, k);
    cout<<k;
    return 0;
}