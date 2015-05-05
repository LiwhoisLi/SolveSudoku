#include<stdio.h>
#include<stdlib.h>
#define N 9
#define FOR(i,n) for(i=0;i<n;i++)
#define MERGE(X,Y) (X/3*3+Y/3)
#define STAT(X)		(!((X)&(X-1)))



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
			
			detectR(sudoku,m,cflags[0]+m);
			
			if(!cflags[0][m])		return -1;		
			else if(STAT(cflags[0][m]))
			{
				sudoku[m*N+n] = stat(cflags[0][m]);
				eflags[1] &= ~(1<<(n-1));
				eflags[2] &= ~(1<<(area-1));
				continue;
			}
			else	eflags[0] &= ~(1<<(m-1));
			
			
			detectC(sudoku,n,cflags[1]+n);
			
			if(!cflags[1][n])		return -1;		
			else if(STAT(cflags[1][n]))
			{
				sudoku[m*N+n] = stat(cflags[1][n]);
				continue;
			}
			
			detectD(sudoku,area,cflags[2]+area);
			
			if(!cflags[2][area])		return -1;		
			else if(STAT(cflags[2][area]))
				sudoku[m*N+n] = stat(cflags[2][area]);
		}
	
	show(sudoku);
}