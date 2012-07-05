#include <omp.h>
#include <stdio.h>
#define N 1000

main ()
{

int i;
float a[N], b[N];

#pragma omp parallel shared(a,b) private(i)
  {
  	int tid;
    
      #pragma omp single private(i,tid)
	  {

	  	for(i=0; i<N; ++i)
	  	{
	  		tid=omp_get_thread_num();
	  		printf("a,%d : thread %d\n",i,tid);
	  		a[i]=i*i*3.065;
	  	}
	
		for(i=0; i<N; ++i)
	  	{
	  		tid=omp_get_thread_num();
	  		printf("a,%d : thread %d\n",i,tid);
	  		b[i]=(6.77+i)*3.45;
	  	} 		
	  }
  }
  
}

