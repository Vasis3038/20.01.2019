/*13) Напишите переборную программу, находящую для заданной последовательности
длины N целых чисел необходимо: максимальное произведение двух её
элементов, номера которых различаются не менее чем на 5. Программа может
быть неэффективной*/
#include <iostream>

using namespace std;
int minssum(int *A, int N)
{
    int ans=A[0]*A[1];
    for(int i=0; i<N-5; i++)
    {
        for(int g=5; i+g<N; g++)
        {
            if(A[i]*A[i+g]>ans)ans=A[i]*A[i+g];
        }
    }
    return ans;
}

int main()
{
    int N, ans=1;
    cin>>N;
    int* A=new int [N];
    for(int i=0; i<N; i++)cin>>A[i];

    cout<<minssum(A, N);

    return 0;
}
