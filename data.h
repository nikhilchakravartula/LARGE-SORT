#ifndef __DATA_H__
#define __DATA_H__
#define NUM_SPECS 7
#define MAX_FD 2040
#define SIZE_ARRAY 100000000ULL
#define NUM_DES 4
#define NUM_PRO 4
#define MAX_HEAP_SIZE 1+(RUN_SIZE/50)
char* spec[NUM_SPECS]={"Computer Science and Engineering,","Electrical and Electronic Engineering,","Electronic and Communication Engineering,","Mechanical Engineering,","Civil Engineering,","Metallurgical Engineering,","Chemical Engineering,"};

char * des[NUM_DES]={"PROFESSOR,","ASSISTANT-PROFESSOR,","TEACHING-ASSISTANT,","LECTURER,"};

char* pro[NUM_PRO]={"Machine Learning\n","Operating System\n","DataBase Management System\n","Application\n"};

unsigned long long  arr[SIZE_ARRAY],arr2[SIZE_ARRAY];

#endif
