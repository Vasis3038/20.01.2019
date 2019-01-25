/*5) У исполнителя четыре команды, которым присвоены номера:
1. Прибавить 1
2. Прибавить 4
3. Прибавить 5
4. Умножить на 2
Напишите программу, находящую самую короткую программу, получающую из
числа X число Y. Программа должна выписать программу как последовательность
команд. Можно считать, что такая программа существует. Если коротких программ
несколько – выписать любую из них.*/

#include <iostream>

using namespace std;
void rec(int x, int y, int a, int op, int &n, int &ans)
{
    if(x==y)
    {
        if(a<n){n=a; ans=op;}
    }
    else
    {
        int q, w, e, r, ww=a, ee=a, rr=a;
        q=x+1; if (q<=y){ op=op*10+1; a++; rec(q,y,a,op,n, ans);op=(op-1)/10;}
        w=x+4; if (w<=y){ op=op*10+2; ww++; rec(w,y,ww,op,n, ans);op=(op-2)/10;}
        e=x+5; if (e<=y){ op=op*10+3; ee++; rec(e,y,ee,op,n, ans);op=(op-3)/10;}
        r=x*2; if (r<=y){ op=op*10+4; rr++; rec(r,y,rr,op,n, ans);op=(op-4)/10;}
    }
}
int main()
{
  int x, y, a=0, op=0, n=100000000, ans;
  cin>>x>>y;
rec(x, y,a, op, n, ans);
cout<<ans;
    return 0;
}
