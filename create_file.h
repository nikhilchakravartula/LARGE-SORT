#ifndef __CREATE_FILE_H__
#define __CREATE_FILE_H__

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
#include<stdbool.h>
#include<time.h>
#include<string.h>
#include "data.h"
#include "file_sort.h"
#define FILE_SIZE 8ULL*1024ULL*1024ULL*1024ULL


int new_file;
unsigned long long file_size=0;
bool flag=false;
unsigned long long a=0,b=0;

void  write_roll_and_name()
{

	if(flag==false)
	b=arr[a];
	else b=arr2[a];

	a++;

	if(a>=SIZE_ARRAY )
	{

	if(flag==true)
	{	exit(0);

	}
	flag=true;
	a=0;
	}

	int k;
	char buf[11];
	char name[11];
	
	for( k=0;k<11;k++)
	buf[k]='0';
	buf[10]=',';
	k=0;
	char* temp=buf+9;
	while(b)
	{
	*temp=b%10+'0';
	b=b/10;
	name[k]=(*temp)+'A';
	k++;
	temp--;
	}
	name[k]=',';
	
	write(new_file,temp+1,k+1);
	write(new_file,name,k+1);

	

}

void write_spec()
{
	char* s=spec[ rand()%NUM_SPECS];
	write(new_file,s,strlen(s));
	file_size+=strlen(s);

}

void write_pro()
{

	char* p=pro[rand()%NUM_PRO];
	write(new_file,p,strlen(p));
	file_size+=strlen(p);
}
int write_des()
{
	return rand()%NUM_DES;
}



void create_file_initialise()
{

new_file=open("file1.csv",O_RDONLY);
if(new_file!=-1)
{
	return;
}

		srand(time(NULL));
unsigned long long i=0,j=SIZE_ARRAY-1,temp;

	for(i=0;i<SIZE_ARRAY;i++)
	{
		arr[i]=i+1;
		arr2[i]=i+1+SIZE_ARRAY;
	}
	printf("loop done\n");
	for(i=SIZE_ARRAY-1;i>=1;i--)
	{
		j=rand()%(i+1);
		temp=arr[j];
		arr[j]=arr[i];
		arr[i]=temp;

		temp=arr2[j];
		arr2[j]=arr2[i];
		arr2[i]=temp;
		

	}

	new_file=creat("file1.csv",0644);
	char * roll;
	char comma=',';
	char newline='\n';
	while(1)
	{
		write_roll_and_name();
		write_spec();
		write_pro();
//		printf("%llu %llu\n",file_size,FILE_SIZE);
		if(file_size> FILE_SIZE){close(new_file);
		break;}
	}
	printf("file generated\n");
	new_file=open("file1.csv",O_RDONLY);
	
}




#endif
