#include<stdio.h>
#include<stdlib.h>
#define N 9
#define FOR(i,n) for(i=0;i<n;i++)
#define MERGE(X,Y) (X/3*3+Y/3)
#define STAT(X)		(!((X)&(X-1)))

void readso(int *p)
{
	int m,n;
	FOR(m,N)
		FOR(n,N)
			scanf("%d",p+m*N+n);
}

void detectR(int *p,int m,int *f)		//Detect the constraint in the given row
{
	int i;
	FOR(i,N)
		if(p[m*N+i])
			*f= (*f) & (~(1<<(p[m*N+i]-1)));
}

void detectC(int *p,int n,int f)		//Detect the constraint in the given column
{
	int j;
	FOR(j,N)
		if(p[j*N+n])
			*f= (*f) & (~(1<<(p[j*N+n]-1)));
}

void detectD(int *p,int no,int *f)	//Detect the constraint in the given district
{
	int m = no/3;
	int n = no%3;
	int i,j;
	FOR(i,3)
		FOR(j,3)
			if(p[+j*N+i])
				*f= (*f) & (~(1<<(p[j*N+i]-1)));
}

int stat(int n)
{
	int i=0;
	while(n=(n>>1))
		i++;
	return i;
}

void show(int *p)
{
	int m,n;
	FOR(m,N)
	{
		FOR(n,N)
			printf("%d ",p[m*N+n]);
		printf("\n");
	}
}