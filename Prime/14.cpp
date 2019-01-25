/*14) Напишите программу, находящую для заданной последовательности длины N
неотрицательных целых чисел необходимо: максимальную сумму двух её
элементов, номера которых различаются не менее чем на 5. Программа должна
быть эффективной по времени и памяти*/


#include <iostream>

using namespace std;
int minssum(int *A, int N)
{
    int maxl=0, maxr=0, left=0, right=N-1;
    int ans=0;
    while(left<=N/2-3)
    {
        if (A[left]>maxl)maxl=A[left];
        left++;

    }
        while(right>=N/2+2)
    {
        if (A[right]>maxr)maxr=A[right];
        right--;

    }
    ans=maxr+maxl;


    int i=-2;
    while(i!=2)
    {
         left=0, right=N-1;
            while((N/2+i)-left>=5)
            {
                if((A[left]+A[N/2+i])>ans) ans=A[left]+A[N/2+i];
                left++;

            }
                while((right-A[N/2+i])>=5)
            {
                if((A[right]+A[N/2+i])>ans) ans=A[right]+A[N/2+i];
                right--;
            }
            i++;
    }



    return ans;
}

int main()
{
    int N, ans=1;
    cin>>N;
    if (N<6)cout<<"NO";
    else{
    int* A=new int [N];
    for(int i=0; i<N; i++)cin>>A[i];

    cout<<minssum(A, N);
delete[]A;}
    return 0;
}
