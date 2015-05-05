#include<stdio.h>
#include<stdlib.h>
#include "func.h"


int main()
{
	int sudoku[N*N];
	int count[N*N];
	int cflags[3][N];
	int eflags[3]={0x1ff,0x1ff,0x1ff};
	int area;
	int m,n;
	
	readso(sudoku);
	
	FOR(m,3)
		FOR(n,N)
			cflags[m][n] = 0x1ff;
	FOR(m,N)
		FOR(n,N)
		{
			if(sudoku[m*N+n]) continue;
			
			area = MERGE(m,n);
			
			if(eflags[0]==(eflags[1]|Nth(m)))
				detectR(sudoku,m,cflags[0]+m);
			
			if(!cflags[0][m])		return -1;		
			else if(STAT(cflags[0][m]))
			{
				sudoku[m*N+n] = stat(cflags[0][m]);
				eflags[0] |= Nth(m);
				eflags[1] &= ~Nth(n);
				eflags[2] &= ~Nth(area-1);
				continue;
			}
			
			
			
			if(eflags[1]==(eflags[1]|Nth(n)))
				detectC(sudoku,n,cflags[1]+n);
			
			if(!cflags[1][n])		return -1;		
			else if(STAT(cflags[1][n]))
			{
				sudoku[m*N+n] = stat(cflags[1][n]);
				eflags[0] &= ~Nth(m);
				eflags[1] |= Nth(n);
				eflags[2] &= ~Nth(area);
				continue;
			}
			
			if(eflags[1]==(eflags[2]|Nth(area)))
				detectD(sudoku,area,cflags[2]+area);
			
			if(!cflags[2][area])		return -1;		
			else if(STAT(cflags[2][area]))
			{
				sudoku[m*N+n] = stat(cflags[2][area]);
				eflags[0] &= ~Nth(m);
				eflags[1] &= ~Nth(n);
				eflags[2] |= Nth(area);
			}
		}
	
	show(sudoku);
}