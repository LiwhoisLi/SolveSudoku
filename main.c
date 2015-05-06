#include<stdio.h>
#include<stdlib.h>
#include "func.h"


int main(int argc, char *argv[])
{
	if(argc!=2)
	{
		printf("Usage: ./sudoku [datafilename]\n");
		return -1;
	}
	
	int sudoku[N*N];
	int count[N*N];
	int cflags[3][N];
	int eflags[3]={0x1ff,0x1ff,0x1ff};
	int area;
	int m,n;
	int tflag;
	
	readso(argv[1],sudoku);
	
	show(sudoku);
	
	FOR(m,3)
		FOR(n,N)
			cflags[m][n] = 0x1ff;
	FOR(m,N)
		FOR(n,N)
		{
			if(sudoku[m*N+n]) continue;
			
			area = MERGE(m,n);
			
			
			if((eflags[0]>>m)%2)
				detectR(sudoku,m,cflags[0]+m);
			if((eflags[1]>>n)%2)
				detectC(sudoku,n,cflags[1]+n);
			if((eflags[2]>>area)%2)
				detectD(sudoku,area,cflags[2]+area);
			
			tflag = cflags[0][m]&cflags[1][n]&cflags[2][area];
			
			
			if(!tflag)	
			{
				show(sudoku);
				printf("%x %x  error\n",cflags[0][m],cflags[1][n]);
				return -1;		
			}
			else if(STAT(tflag))
			{
				sudoku[m*N+n] = stat(tflag)+1;
				
				eflags[0] |= Nth(m);
				eflags[1] |= Nth(n);
				eflags[2] |= Nth(area);
			}
			else
			{
				eflags[0] &= ~Nth(m);
				eflags[1] &= ~Nth(n);
				eflags[2] &= ~Nth(area);
			}
		}
	
	show(sudoku);
}