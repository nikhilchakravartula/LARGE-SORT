#include<stdio.h>
#include<stdlib.h>
#include "heap.h"
#include "create_file.h"
#include "file_sort.h"

int main()
{

create_file_initialise();
if(new_file==-1){perror("file error\n");
return 0;
}
printf("entering sort\n");
sort(new_file);

return 0;
}
