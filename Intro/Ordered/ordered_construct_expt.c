#include <omp.h>
#include<stdio.h>
#define CHUNKSIZE 100
#define N 1000

main ()  
{

int i, chunk,tid;
float c[N];

chunk = CHUNKSIZE;

//for (i=0; i < N; i++)
    //c[i] = i*3.0;

#pragma omp parallel shared(c,chunk) private(i,tid)
  {
	tid=omp_get_thread_num();

  #pragma omp for schedule(dynamic,chunk) nowait ordered
  for (i=0; i < N; i++)
  {
  	#pragma omp ordered
	  	printf("%d : %d\n",i,tid);
		c[i] = i*3.0;
  }

  }  /* end of parallel section */
}
