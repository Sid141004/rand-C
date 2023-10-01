#include<stdio.h>
int main(){
int a[] = {12,48,28,90,77};
int key = 90 , n=5;
int low = 0;
int high = n-1;
while(low<=high)
{
    printf("here\n");
    int mid=(low+high)/2;
    if(a[mid]==key)
    {
        printf("FOUND AT %d",mid);
        break;
    }
    else if(key > a[mid])
    {
        low=mid;
        mid=(low+high)/2;
        continue;
    }
    else
    {
        high = mid;
        mid=(low+high)/2;
        continue;
    }
}
}
