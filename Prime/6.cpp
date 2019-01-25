/*6) У исполнителя четыре команды, которым присвоены номера:
1. Прибавить 2
2. Прибавить 4
3. Прибавить 5
4. Умножить на 3
Напишите программу, находящую самую короткую программу, получающую из
числа X число Y, такую, что в промежуточных действиях обязательно появляется
число Z. Программа должна выписать программу, как последовательность команд.
Если такой программы нет – выписать NO. Если коротких программ несколько –
выписать любую из них.*/

#include <iostream>

using namespace std;
void rec(int x, int y, int a, int op, int &n, int &ans, int z, bool imeecaliZ)
{if(x==z)imeecaliZ=1;
    if(x==y)
    {
        if(a<n && imeecaliZ==1){n=a; ans=op;}
    }
    else
    {
        int q, w, e, r, ww=a, ee=a, rr=a;
        q=x+2; if (q<=y){ op=op*10+1; a++; rec(q,y,a,op,n, ans,z, imeecaliZ);op=(op-1)/10;}
        w=x+4; if (w<=y){ op=op*10+2; ww++; rec(w,y,ww,op,n, ans,z,imeecaliZ);op=(op-2)/10;}
        e=x+5; if (e<=y){ op=op*10+3; ee++; rec(e,y,ee,op,n, ans,z,imeecaliZ);op=(op-3)/10;}
        r=x*3; if (r<=y){ op=op*10+4; rr++; rec(r,y,rr,op,n, ans,z,imeecaliZ);op=(op-4)/10;}
    }
}
int main()
{
  int x, y, a=0, op=0, n=999999, ans, z;
  bool imeecaliZ=0;
  cin>>x>>y>>z;
rec(x, y,a, op, n, ans,z, imeecaliZ);
if (n!=999999)cout<<ans;else cout<<"NO";
    return 0;
}
