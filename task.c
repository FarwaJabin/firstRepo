#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>
#include<sys/wait.h>

int main()
{
	int array[1000], i = 0;
	array[0] = 1;
 	for(i = 0; i < 1000; i++)
	{
		array[i] =array[i-1] +1;
		printf("%d\n", array[i]);
		//array[i] = rand() % 9+1;
	}
	
	int fd1[2], fd2[2], fd3[2], fd4[2], fd5[2];
	int fd6[2], fd7[2], fd8[2], fd9[2], fd10[2];
	
	pipe(fd1);
	pipe(fd2);
	pipe(fd3);
	pipe(fd4);
	pipe(fd5);
	pipe(fd6);
	pipe(fd7);
	pipe(fd8);
	pipe(fd9);
	pipe(fd10);

	int cpid1 = fork();	
	if(cpid1==0)
	{
		printf("%s\n", "I am child1");
		int sum1 = 0;
		for(i = 0; i < 100; i++)                 
			sum1 = sum1 + array[i];
		write(fd1[1], &sum1, sizeof(sum1));	
	}
	else
	{
		int cpid2 = fork();	
		if(cpid2 == 0)
		{
		printf("%s\n", "I am child2");
		int sum2 = 0;
		for(i = 100; i < 200; i++)
			sum2 = sum2 + array[i];
		write(fd2[1], &sum2, sizeof(sum2));
		}	
	else
	{
		int cpid3 = fork();	
		if(cpid3 == 0)
		{
		printf("%s\n", "I am child3");
		int sum3 = 0;
		for(i = 200; i < 300; i++)
			sum3 = sum3 + array[i];
		write(fd3[1], &sum3, sizeof(sum3));
		}
	else
	{
		int cpid4 = fork();	
		if(cpid4 == 0)
		{
		printf("%s\n", "I am child4");
		int sum4 = 0;
		for(i = 300; i < 400; i++)
			sum4 = sum4 + array[i];
		write(fd4[1], &sum4, sizeof(sum4));
		}
	else
	{
		int cpid5 = fork();	
		if(cpid5 == 0)
		{
		printf("%s\n", "I am child5");
		int sum5 = 0;
		for(i = 400; i < 500; i++)
			sum5 = sum5 + array[i];
		write(fd5[1], &sum5, sizeof(sum5));
		}
	else
	{
		int cpid6 = fork();	
		if(cpid6 == 0)
		{
		printf("%s\n", "I am child6");
		int sum6 = 0;
		for(i = 500; i < 600; i++)
			sum6 = sum6 + array[i];
		write(fd6[1], &sum6, sizeof(sum6));
		}
	else
	{
		int cpid7 = fork();	
		if(cpid7 == 0)
		{
		printf("%s\n", "I am child7");
		int sum7 = 0;
		for(i = 600; i < 700; i++)
			sum7 = sum7 + array[i];
		write(fd7[1], &sum7, sizeof(sum7));
		}
	else
	{
		int cpid8 = fork();	
		if(cpid8 == 0)
		{
		printf("%s\n", "I am child8");
		int sum8 = 0;
		for(i = 700; i < 800; i++)
			sum8 = sum8 + array[i];
		write(fd8[1], &sum8, sizeof(sum8));
		}
	else
	{
		int cpid9 = fork();	
		if(cpid9 == 0)
		{
		printf("%s\n", "I am child9");
		int sum9 = 0;
		for(i = 800; i < 900; i++)
			sum9 = sum9 + array[i];
		write(fd9[1], &sum9, sizeof(sum9));
		}	
	else
	{
		int cpid10 = fork();	
		if(cpid10 == 0)
		{
		printf("%s\n", "I am child10");
		int sum10 = 0;
		for(i = 900; i < 1000; i++)
			sum10 = sum10 + array[i];
		write(fd10[1], &sum10, sizeof(sum10));	
		}
	}	
	}	
	}	
	}	
	}	
	}	
	}	
	}
	}
	//else
	{
		wait(NULL);
		wait(NULL);
		wait(NULL);
		wait(NULL);
		wait(NULL);
		wait(NULL);
		wait(NULL);
		wait(NULL);
		wait(NULL);
		wait(NULL);

		int s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, s8 = 0, s9 = 0, s10 = 0;
		read(fd1[0], &s1, sizeof(s1));
		read(fd2[0], &s2, sizeof(s2));
		read(fd3[0], &s3, sizeof(s3));
		read(fd4[0], &s4, sizeof(s4));
		read(fd5[0], &s5, sizeof(s5));
		read(fd6[0], &s6, sizeof(s6));
		read(fd7[0], &s7, sizeof(s7));
		read(fd8[0], &s8, sizeof(s8));
		read(fd9[0], &s9, sizeof(s9));
		read(fd10[0], &s10, sizeof(s10));
		
			printf("%s %d\n", "Sum by child1 = ", s1);
			printf("%s %d\n", "Sum by child2 = ", s2);
			printf("%s %d\n", "Sum by child3 = ", s3);
			printf("%s %d\n", "Sum by child4 = ", s4);
			printf("%s %d\n", "Sum by child5 = ", s5);
			printf("%s %d\n", "Sum by child6 = ", s6);
			printf("%s %d\n", "Sum by child7 = ", s7);
			printf("%s %d\n", "Sum by child8 = ", s8);
			printf("%s %d\n", "Sum by child9 = ", s9);
			printf("%s %d\n", "Sum by child10 = ", s10);
			printf("%s\n", "I am Parent");
			printf("%s %d\n", "Total sum of all childs = ", s1+s2+s3+s4+s5+s6+s7+s8+s9+s10);
	}

		
	return 0;
}
