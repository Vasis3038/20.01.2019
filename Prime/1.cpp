/*1) У исполнителя Удвоитель-Утроитель три команды, которым присвоены номера:
1. прибавь 1
2. умножь на 2
3. умножь на 3.
Первая из них увеличивает на 1 число на экране, вторая увеличивает это число в
2 раза, третья – в 3 раза. Программа для Удвоителя-Утроителя — это
последовательность команд. Напишите программу вычисляющую, сколько
существует программ, которые число X преобразуют в число Y.*/

#include <iostream>

using namespace std;
void rec(int x, int y, int &a)
{

    if(x==y) a++;
    else
    {
    int q, w, e;
    q=x+1; if(x<=y)     rec(q, y, a);
    w=x*2;   if(x<=y)   rec(w, y, a);
    e=x*3;  if(x<=y)  rec(e, y, a);
    }
}
int main()
{
    int x, y, a=0;
    cin>>x>>y;
    rec(x, y, a);
    cout<<a;
    return 0;
}

