#include<stdio.h>
int main()
{
    int n,m=0;
    scanf("%d%d",&n,&m);
    int arr[1000]={0};
    int arr1[1000]={0};
    int i,j=0;
    for(i=0;i<n;i++)
    {
        
        scanf("%d",&arr[i]);
        
    }
    for(i=0;j<m;j++)
    {
        
        scanf("%d",&arr1[j]);
        
    }
    i,j=0;
    while(i<n&&j<m)
    {
        
        if(arr[i]<=arr1[j])
        {
            printf("%d ",arr[i]);
           i++;
        }
            
        else if(arr1[j]<arr[i])
        {
             printf("%d ",arr1[j]);
            j++;
        }
    }
    
       if(i==n)
       {
           for(;j<m;j++)
           {
                printf("%d ",arr1[j]);
           }
       }
       else{
           for(;i<n;i++)
           {
                printf("%d ",arr[i]);
           }
       }
  
    return 0;
}