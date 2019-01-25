/*18) Дед Мороз и Снегурочка приходят на детские утренники с мешком конфет. Дед
Мороз делит конфеты поровну между всеми присутствующими детьми (детей на
утреннике никогда не бывает больше 100), а оставшиеся конфеты отдает
Снегурочке. Снегурочка каждый раз записывает в блокнот количество полученных
конфет. Если конфеты разделились между всеми детьми без остатка, Снегурочка
ничего не получает и ничего не записывает. Когда утренники закончились, Деду
Морозу стало интересно, какое число чаще всего записывала Снегурочка. Дед
Мороз и Снегурочка — волшебные, поэтому число утренников N, на которых они
побывали, может быть очень большим. Напишите программу, которая будет
решать эту задачу.
Описание входных данных
В первой строке вводится одно целое положительное число — количество
утренников N. Каждая из следующих N строк содержит два целых числа: сначала
D — количество пришедших на очередной утренник детей, а затем K – количество
конфет в мешке Деда Мороза на этом утреннике. Гарантируется выполнение
следующих соотношений:
1 ≤ N ≤ 10000
1 ≤ D ≤ 100 (для каждого D)
D ≤ K ≤ 1000 (для каждой пары D, K)
Описание выходных данных
Программа должна вывести одно число — то, которое Снегурочка записывала
чаще всего. Если несколько чисел записывались одинаково часто, надо вывести
большее из них. Если Снегурочка ни разу ничего не записывала, надо вывести
ноль.*/

#include <iostream>
using namespace std;

int main()
{
    int D,k,N;
        cin>>N;
    int b[N],a[N];
    for (int i=1;i<=N;i++)
    {
        b[i]=0;
    }
int ans;
    for (int i=1; i<=N; i++)
    {
            cin>>D;
            cin>>k;
        if ((k%D)==0)
        {
         a[i]=0;
        }
        else
        {
            ans=k%D;
            b[ans]++;
            a[i]=ans;
        }
         D=0;
         k=0;
   }
   int lypa;
   lypa=b[1];

    for (int i=1;i<=N;i++)
    {
        if (b[i]>lypa)
            lypa=b[i];
    }

    for (int i=N;i>=1;i--)
    {
            if (b[i]==lypa)
            cout<<a[i];

    }
    return 0;
}
