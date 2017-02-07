Problem Statement:
The task is to sort a large 10GB file using linux system calls and c library functions.
The file is named as "file1.csv" and the metadata is as follows.

RollNumber, Name , Specialisation, ProjectInvolved


Points to be noted:
I used external sorting to complete this. I created the file,then divided it into several temporary files each of 1MB, sorted them using heap-sort,finally 
merged all the sorted files using N-way merge.If due to some external power failure or shutdown, the process is terminated before completion, it continues from the point where it has left off the next time
when it is run again, although there might be some re-doing of some steps.

Unique roll numbers are created using Fisher-Yates shuffling algorithm and name of the student is chosen at random based on the roll number. Although the names seemed 
meaningless to me, i felt atleast someone in this world might have it :P .You can also change the file size that has to created by modifying FILE_SIZE macro in "create_file.h". 
It is suggested to take a look at "data.h". Care has to be taken while modifying MAX_FD macro in "data.h". It is the maximum open file descriptors a process
can have in its running environment. It depends on the system on which the process is running. So,it is advised to increase or decrease it as needed, else get ready to
brace for the impact of the program's crash-landing. The RUN_SIZE in "file_sort.h" cannot exceed 10^6(creates 977KB ,approx 1MB individual files). However, you can reduce it to 16 * 1024 for dividing the file 
into 16KB individual files, similarly 8 * 1024 for working with individual 8KB files.

This program may take a lot of time depending on the system's resources. On an 8GB ram with Intel-Xeon 2.40 GHz processor, it took 3 days flat to complete.If its not for system calls,
the same task can be achieved in much lesser time. Many temporary files are created in the process to hold the current status of the sort. Make sure you have enough space on the disk 
, say probably 15GB. These temporary files are deleted after they are dealt with. So, all that remains after running the program is the sorted version of
file1.csv.

