#define N 9
#define FOR(i,n) for(i=0;i<n;i++)
#define MERGE(X,Y) (X/3*3+Y/3)
#define STAT(X)		(!((X)&(X-1)))
#define Nth(n)		(1<<(n-1))



void readso(int*);
void detectR(int*,int,int*);
void detectC(int*,int,int*);
void detectD(int*,int,int*);
int stat(int);
void show(int*);