#ifndef HEAP_H_INCLUDED
#define HEAP_H_INCLUDED
#include<limits.h>
#include<stdio.h>
#include<stdbool.h>
typedef struct
{
    unsigned long long data;
    int fd;
     char str[200];
   
}heap_node;


unsigned long long cursize=0,maxsize;

unsigned long long left(unsigned long long i)
{
    return 2*i+1;
}
unsigned long long right(unsigned long long i)
{
    return 2*i+2;
}
unsigned long long parent(unsigned long long i)
{
return (i-1)/2;
}

void swap(heap_node* arr,unsigned long long i,unsigned long long j)
{
    heap_node t=arr[i];
    arr[i]=arr[j];
    arr[j]=t;
}

void heapify(heap_node arr[],unsigned long long i)
{
    unsigned long long r=right(i),l=left(i),smallest=i;

    if(l<=cursize && arr[l].data<arr[smallest].data)
        smallest=l;
    if(r<=cursize && arr[smallest].data>arr[r].data)
        smallest=r;
    if(smallest!=i){
    swap(arr,i,smallest);
    heapify(arr,smallest);
    }

}
void heap_initialise(unsigned long long size)
{
    cursize=0;
    maxsize=size;
}

void heap_insert(heap_node* arr,heap_node* node)
{

    arr[cursize]=(*node);
    cursize++;
//	printf("insert %llu\n",node->data);

unsigned long long temp=cursize-1;
    while(temp!=0 && ( arr[temp].data < arr[parent(temp)].data) )
    {
        swap(arr,temp,parent(temp));
        temp=parent(temp);
    }
    free(node);



}

bool heap_empty()
{
    return (unsigned long long)-1 ==cursize;
}

heap_node pop_min(heap_node* arr)
{

    if(cursize==0)
    {
        cursize-=1;
        return arr[0];

    }
    else
    {
        heap_node t=arr[0];
	cursize-=1;
        arr[0]=arr[cursize];
        heapify(arr,0);
        return t;
    }


}


void heap_print(heap_node* arr)
{
	for(int i=0;i<cursize;i++)
	{
		printf("%s\n",arr[i].str);

	}



}
#endif // HEAP_H_INCLUDED
