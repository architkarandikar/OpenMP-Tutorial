#include <omp.h>
#include<stdio.h>

main()
{

int x,tid;
x = 0;

#pragma omp parallel shared(x) private(tid) 
  {

	tid=omp_get_thread_num();
	  #pragma omp critical
	  {
	  x*=4;
	  printf("Stage 1, thread %d\n",tid);
	  x=x+1;
	  printf("Stage 2, thread %d\n",tid);
	  x*=2;
	  printf("Stage 3, thread %d\n",tid);
	  x+=3;
	  printf("Stage 4, thread %d\n\n",tid);
	  }

  }  /* end of parallel section */
 
printf("%d\n",x);

}
