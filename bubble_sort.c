#include <stdio.h>

int pop_dupe(int arr[],int x); //removes duplicates
void bubble_sort_array(int arr[],int x);

int main(int argc, char* argv[]){
    int temp;
    int i=0;
    int arr[1000];

    do{
        scanf("%d",&temp);
        if(temp!=-1){
            arr[i++]=temp;
        }
    }while(temp!=-1);
    
    bubble_sort_array(arr,i);
    i = pop_dupe(arr,i);

    for(int j=0;j<i;j++)
    {
       printf("%d\n",arr[j]);
    }
    return 0;
}

int pop_dupe(int arr[],int x){
    int temp[x];
    int i;
    int y = 0;

    for(i=0;i<x-1;i++){
       if(arr[i]!=arr[i+1])
       temp[y++]=arr[i];
    }
    temp[y++]=arr[x-1];
    for(i=0;i<y;i++)
    {
       arr[i]=temp[i];
    }

    return y;
}

void bubble_sort_array(int arr[],int x){
    int i;
    int j;

    for(i=0;i<x-1;i++){
       for(j=i+1;j<x;j++){
           if(arr[i]>arr[j]){
               int temp=arr[i];
               arr[i]=arr[j];
               arr[j]=temp;
           }
       }
    }
}
