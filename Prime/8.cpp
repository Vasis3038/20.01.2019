/*8) У исполнителя Множик есть три команды:
1. умножь на 5,
2. подели на 15,
3. умножь на 6.
Напишите программу, которая находит, сколько различных чисел может получить
исполнитель из числа X программами, состоящими не более из N команд. Вторая
команда выполняется, только если ей подается число кратное 15 (в противном
случае программа завершается аварийно). */

#include <iostream>

using namespace std;
void rec(int x, int y, int a, int &k)
{


  if(a<=y) {k++;

    int q, w, e;
    q=x*5;  a++; rec(q, y, a, k); a--;
    if(x%15==0){w=x/15; a++; rec(w, y, a, k);a--;}
    e=x*6; a++; rec(e, y, a, k);a--;
    }}




int main()
{
    int x, y, a=0, k=0;
    cin>>x>>y;
    rec(x, y, a, k);
    cout<<k;
    return 0;
}

