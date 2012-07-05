#include <omp.h>
#include<stdio.h>

#define N 10000000 

int x[N];
main()
{

int i,tid;
for(i=0; i<N; ++i)
	x[i]=0;

#pragma omp parallel shared(x) private(i,tid)
  {

	tid=omp_get_thread_num();
	
	if(tid==0)
		++x[0];
	else
		for(i=0; i<N; ++i)
			++x[i];
	
	printf("Part 1 : End of thread %d\n",tid);
	
	if(tid==0)
		++x[0];
	else
		for(i=0; i<N; ++i)
			++x[i];
	
	printf("Part 2 : End of thread %d\n",tid);
	
  }  /* end of parallel section */

}
