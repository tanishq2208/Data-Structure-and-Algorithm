#include<stdio.h>
#include<math.h>

int largestSqr(int x)
{
    double a=x;
    int p=(int)sqrt(a);
    int i;
    for(i=p;i>=2;i--)
    {
        if(x%(p*p) == 0)
        {
            return p*p;
        }
    }
}

int F(int x)
{
    int a = largestSqr(x);
    if(x/a > 1)
    return 1;
    else
    return 0;
}

int main()
{
    int t,n,count,j;
    scanf("%d",&t);
    while(t--)
    {
        count=0;
        scanf("%d",&n);
        int arr[n],i;
        for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
        
        for(i=0;i<n-1;i++)
        {
            for(j=i+1;j<n;j++)
            if(F(arr[i]*arr[j])==1)
            count++;
        }
        printf("%d",count);
    }
}