#include<stdio.h>
#include<stdlib.h>
#include "func.h"

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
			(*f) = (*f) & (~Nth(p[m*N+i]));
}

void detectC(int *p,int n,int *f)		//Detect the constraint in the given column
{
	int j;
	FOR(j,N)
		if(p[j*N+n])
			(*f) = (*f) & (~Nth(p[j*N+n]));
}

void detectD(int *p,int no,int *f)	//Detect the constraint in the given district
{
	int m = no/3;
	int n = no%3;
	int i,j;
	FOR(i,3)
		FOR(j,3)
			if(p[j*N+i])
				(*f) = (*f) & (~Nth(p[j*N+i]));
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