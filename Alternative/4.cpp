/*4) В процессе ремонта в Лаборатории Информационных Технологий строителям
необходимо заменить поврежденные напольные плитки в коридоре лаборатории,
который имеет размер 2 × n метров. В распоряжении строителей есть неограниченный
запас плиток двух размеров: 1 × 2 метра и 1 × 1 метр. При этом плитки размером 1 × 2
метра перед укладкой разрешается поворачивать на 90 градусов и размещать как вдоль,
так и поперек коридора.
Строители уже начали ремонт и уложили в некоторых местах пола коридора k
плиток размером 1 × 1. Для завершения ремонта прорабу необходимо подготовить план
дальнейших работ. Для этого ему надо решить, каким образом уложить плитки на места,
где они еще не уложены. Это можно сделать различными способами и прораб хочет
перебрать все варианты и выбрать самый удачный. Перед тем как это сделать, прораб
хочет знать, какое количество вариантов ему придется рассмотреть. Это число требуется
найти по модулю 109
+ 7.
Требуется написать программу, которая по заданной длине коридора n и
расположению плиток, которые уже уложены, определяет количество способов укладки
плиток на оставшиеся места. Ответ необходимо вывести по модулю 109
+ 7.
Формат входных данных
Первая строка входного файла содержит два целых числа: n — длину коридора и k
— количество уже уложенных единичных плиток (1 ≤ n ≤ 106
, 0 ≤ k < 2n).
Последующие k строк содержат по два целых числа xi и yi
, которые задают позиции
уже уложенных единичных плиток, i-я плитка уложена на xi-м метре коридора в yi-м ряду
(1 ≤ xi ≤ n, 1 ≤ yi ≤ 2).
*/
#include <iostream>

using namespace std;
bool craft(bool** &B, int g)
{
     B = new bool *[g];

     for (int i=0; i<g; i++)
        B[i]=new bool [2];
     return B;
}
void rewrite(bool** &A, int &m)
{
    m--;
        bool **B;
        craft(B, m);
        for (int i=0; i<m; i++)
{
    for (int g=0; g<2; g++)
    {
        B[i][g]=A[i+1][g];
    }
}
  for(int e=0; e<m+1; e++) delete[] A [e];
        delete []A;
        A=B;
    }
void rone(bool** &B, int &g)
{
    g--;
    bool** A;
    craft(A, g);
       for(int q=0; q<g; q++)
        {
            for(int w=0; w<2; w++)
            {
                    A[q][w]=B[q+1][w];
            }
        }
         for(int e=0; e<=g; e++) delete[] B [e];
        delete []B;
        B=A;
}

void rtwo(bool** &B, int &g)
{
    B[1][1]=1;
g--;
bool** M;
craft(M, g);
      for(int q=0; q<g; q++)
        {
            for(int w=0; w<2; w++)
            {
                    M[q][w]=B[q+1][w];
            }
        }

         for(int e=0; e<=g; e++) delete[] B [e];
        delete []B;
        B=M;
}
void loneforOO(bool** &B, int &g)
{
    B[0][0]=1;
    bool **A;
    craft(A, g);
           for(int q=0; q<g; q++)
        {
            for(int w=0; w<2; w++)
            {
                    A[q][w]=B[q][w];
            }
        }
            for(int e=0; e<g; e++) delete[] B [e];
        delete []B;
        B=A;
}
  void ltwovertforOO(bool** &B, int &g)
{
        B[1][0]=1;
        B[0][0]=1;
bool** M;
craft(M, g);
      for(int q=0; q<g; q++)
        {
            for(int w=0; w<2; w++)
            {
                    M[q][w]=B[q][w];
            }
        }

         for(int e=0; e<g; e++) delete[] B [e];
        delete []B;
        B=M;
}

 void ltwogorforOO(bool** &B, int &g)
{
    g--;
    bool **A;
    craft(A, g);
           for(int q=0; q<g; q++)
        {
            for(int w=0; w<2; w++)
            {
                    A[q][w]=B[q+1][w];
            }
        }
            for(int e=0; e<=g; e++) delete[] B [e];
        delete []B;
        B=A;
}
 void ltwovertforOI(bool** &B, int &g)
 {
    B[1][0]=1;
g--;
bool** M;
craft(M, g);
      for(int q=0; q<g; q++)
        {
            for(int w=0; w<2; w++)
            {
                    M[q][w]=B[q+1][w];
            }
        }

         for(int e=0; e<=g; e++) delete[] B [e];
        delete []B;
        B=M;
}
void rec(bool** &A,int &m, int &answer)
{
    if(m==1)
    {
        if(A[0][0]==1 && A[0][1]==1)
        {
            m=0;
answer++;
        }
        else

        if(A[0][0]==1 || A[0][1]==1) {answer++; m=0;}

        else{ m=0;answer++;answer++;}
    }
    else{
               if(A[0][0]==0)
               {
                   if (A[0][1]==0 && A[1][0]==0 && A[1][1]==1)
                   {
                        int mi=m;
                        bool **Ai;
                        craft(Ai, mi);
                        int mu=m;
                        bool **Au;
                        craft(Au, mu);
                        for (int i=0; i<mi; i++)
                        {
                            for (int g=0; g<2; g++) {Ai[i][g]=A[i][g];
                                                        Au[i][g]=A[i][g];}
                        }
                        rone(A, m);
                        ltwogorforOO(Ai, mi);
                        ltwovertforOI(Au,mu);
                        if(m==0 || mi==0 || mu==0){answer++;}
                                while (m!=0)
                                    rec(A, m, answer);
                                while (mi!=0)
                                    rec(Ai, mi, answer);
                                while (mu!=0)
                                    rec(Au, mu, answer);
                   }
                        else
                           if (A[0][1]==0 && A[1][0]==0)
                           {
                              // cout<<endl;

                                int mi=m;
                                bool **Ai;
                                craft(Ai, mi);
                                int mu=m;
                                bool **Au;
                                craft(Au, mu);

                                for (int i=0; i<mi; i++)
                                {
                                    for (int g=0; g<2; g++) {Ai[i][g]=A[i][g];
                                                             Au[i][g]=A[i][g];}
                                }


                                loneforOO(A, m);
                                        /*for (int i=0; i<mu; i++)
                                {
                                    for (int g=0; g<2; g++) {cout<<A[i][g];}
                                    cout<<endl;
                                }
                                cout<<endl;*/
                                ltwogorforOO(Ai, mi);
                               /*     for (int i=0; i<mi; i++)
                                {
                                    for (int g=0; g<2; g++) {cout<<Ai[i][g];}
                                    cout<<endl;
                                }
                                cout<<endl;*/
                                ltwovertforOO(Au, mu);
                                                           /*      for (int i=0; i<mu; i++)
                                {
                                    for (int g=0; g<2; g++) {cout<<Au[i][g];}
                                    cout<<endl;
                                }
                                cout<<endl;*/
                                if(m==0 || mi==0 || mu==0){/*cout<<"f"*/;answer++;}

                                while (m!=0)
                                    //cout<<3;
                                    rec(A, m, answer);

                                while (mi!=0)
                                    rec(Ai, mi, answer);
                                while (mu!=0)
                                    rec(Au, mu, answer);
                               //������� ��� �������, � ������� �������
                           }
                           else
                           if(A[0][1]==0)
                           {
                                int mi=m;
                                bool **Ai;
                                craft(Ai, mi);

                                for (int i=0; i<mi; i++)
                                {
                                    for (int g=0; g<2; g++) Ai[i][g]=A[i][g];
                                }
                                loneforOO(A, m);
                                ltwogorforOO(Ai, mi);
                                if(m==0 || mi==0){/*cout<<"f";*/ answer++;}//���������� � ���������

                                while (m!=0)
                                    rec(A, m, answer);
                                while (mi!=0)
                                    rec(Ai, mi, answer);
                               //������� ��� �������, � ������� �������
                           }
                           else
                              if(A[1][0]==0)
                           {
                                int mi=m;
                                bool **Ai;
                                craft(Ai, mi);

                                for (int i=0; i<mi; i++)
                                {
                                    for (int g=0; g<2; g++) Ai[i][g]=A[i][g];
                                }
                                loneforOO(A, m);
                                ltwovertforOI(Ai, mi);
                                if(m==0 || mi==0){/*cout<<"f";*/answer++;}//���������� � ���������

                                while (m!=0)
                                    rec(A, m, answer);
                                while (mi!=0)
                                    rec(Ai, mi, answer);
                               //������� ��� �������, � ������� �������
                           }
                           else
                            {
                            rewrite(A,m);
                           rec(A, m, answer);
                           }

               }
               else//������ ����� ���� ���� ������(=1), � ������ ������
                {
                            if(A[0][0]==1 && A[0][1]==1)
                            { rewrite(A, m);
                                rec(A, m, answer);
                            }
                            else{

                            if(m==0){/*cout<<"f";*/answer++;}
                            else
                            {
                                int mi=m;
                                bool **Ai;
                                craft(Ai, mi);

                                for (int i=0; i<mi; i++)
                                {
                                    for (int g=0; g<2; g++) Ai[i][g]=A[i][g];
                                }
                                rone(A, m);

                                rtwo(Ai, mi);

                                if(m==0 || mi==0){/*cout<<"f";*/ answer++;}//���������� � ���������

                                while (m!=0)

                                    rec(A, m, answer);
                                while (mi!=0)
                                    rec(Ai, mi, answer);
                            }
                }}

    }
}
void share(bool** &A, int n, int ch, int &answ)
{
    if(ch==1)
{
    //cout<<" work0 ";
    ch--;
   // cout<<" rec ";
                int ans=0;
                 rec(A, n, ans);
                 answ=answ*ans;
    share(A, n, ch, answ);
}
else
    {
    int i=0;
        while(ch>0)
        {
            if(A[i][0]==1 && A[i][1]==1)
               {
                  //cout<< " work1 ";
                  bool **Ai;
                  int ni=i;
                  craft(Ai, ni);
                     for(int r=0; r<ni; r++)
                     {
                         for(int g=0; g<2; g++)
                         {
                             Ai[r][g]=A[r][g];
                         }
                     }
                // cout<<" rec ";
                 int ans=0;
                 rec(Ai, ni, ans);
                 answ=answ*ans;

                   bool **Au;
         int nu=n-i-1, l=i+1;

                     craft(Au, nu);
                    for(int r=0; r<nu; r++)
                     {
                         for(int g=0; g<2; g++)
                         {
                             Au[r][g]=A[l][g];
                         }
                         l++;
                     }

                  ch--;
                  if (ch==1) {share(Au, nu, ch, answ); break;}
                  else share(Au, nu, ch, answ);
                  ch=0;
               }

               else
            {

            if(A[i][0]==1 && A[i+1][1]==1 || A[i+1][0]==1 && A[i][1]==1)
            {
               // cout<< " work2 ";
                ch--;
                bool **Ai;
                int ni=i+1;
                 craft(Ai, ni);
                 for(int r=0; r<ni; r++)
                 {
                     for(int g=0; g<2; g++)
                     {
                         Ai[r][g]=A[r][g];
                     }
                 }

               //  cout<<" rec ";
                 int ans=0;
                 rec(Ai, ni, ans);
                 answ=answ*ans;

                 bool **Au;
                 int nu=n-i-1, l=i+1;
                     craft(Au, nu);
                    for(int r=0; r<nu; r++)
                     {
                         for(int g=0; g<2; g++)
                         {
                             Au[r][g]=A[l][g];
                         }
                         l++;
                     }


                if (ch==1) {share(Au, nu, ch, answ); break;}
                else share(Au, nu, ch, answ);
                ch=0;
            }
            }
        i++;
        }
    }
}

void ch(bool ** &A, int &n, int &ch)
{


    for(int i=0; i<n; i++)
    {
            if(A[0][0]==1 && A[0][1]==1)
    {

        bool **B;
        craft(B, n-1);
        n=n-1;
        for (int g=0; g<n; g++)
        {
            for(int j=0; j<2; j++) B[g][j]=A[g+1][j];
        }
        for(int e=0; e<=n+1; e++) delete[] A [e];
        delete []A;
        A=B;

    }
        if(A[n-1][0]==1 && A[n-1][1]==1)
    {
        bool **B;
        craft(B, n-1);
        n=n-1;
        for (int g=0; g<n; g++)
        {
            for(int j=0; j<2; j++) B[g][j]=A[g][j];
        }
        for(int e=0; e<=n+1; e++) delete[] A [e];
        delete []A;
        A=B;

    }
        if(A[i][0]==1 && A[i][1]==1)
        {
            if(A[i+1][0]!=1 || A[i+1][1]!=1)
            {
            if(i!=0 || i!=n-1)ch++;
            }
        }

        else

            if (A[i][0]==1 && A[i+1][1]==1)
            {if(A[i+2][0]!=1 && A[i+1][0]!=1)
            {
                ch++;
            }}
        else
        {
         if (A[i][1]==1 && A[i+1][0]==1)
            {if(A[i+2][1]!=1 && A[i+1][1]!=1)
            {
                ch++;
            }}
        }
    }
    ch++;
}
int main()
{
    bool **A;
    int n, k;
    cin>>n>>k;
    craft(A, n);
 for(int i=0; i<n; i++)
{
     for(int g=0; g<2; g++)
        A[i][g]=0;
 }

  for (int i = 0; i<k; i++)
 {
     int r=0;
     int e=0;
     cin>>r>>e;
        A[r-1][e-1]=1;
 }
int e=0;
ch(A, n, e);
  for (int i = 0; i<n; i++)
 {
     for (int g=0; g<2;g++)
     {cout<<A[i][g];}
     cout<<endl;
 }
cout<<endl;
int answ=1;
if(e>1)
{
share(A, n, e, answ);
}
else
{
    rec(A, n, answ);
    answ--;
}
answ=answ%(1000000000+7);
cout<<answ;
    return 0;
}

