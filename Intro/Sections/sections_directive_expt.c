#include <omp.h>
#include <stdio.h>
#define N 1000000

int i;
float a[N], b[N], c[N], d[N], e[N];

main ()
{

/* Some initializations */
for (i=0; i < N; i++) {
  a[i] = i * 1.5;
  b[i] = i + 22.35;
  }

#pragma omp parallel shared(a,b,c,d,e) private(i)
  {
  	int tid;

  #pragma omp sections nowait private(tid)
    {
    
    for (i=0; i < N; i++)
    {
      //tid=omp_get_thread_num();
      //printf("e,%d : %d\n",i,tid);
      e[i] = a[i] + 2*b[i];
    }

    #pragma omp section
    for (i=0; i < N; i++)
    {
      //tid=omp_get_thread_num();
      //printf("c,%d : %d\n",i,tid);
      c[i] = a[i] + b[i];
    }

    #pragma omp section
    for (i=0; i < N; i++)
    {
       //tid=omp_get_thread_num();
      //printf("d,%d : %d\n",i,tid);
       d[i] = a[i] * b[i];
    }

    }  /* end of sections */

  }  /* end of parallel section */

//for (i=0; i < N; i++)
	//printf("%d :: c : %f :: d : %f\n",c[i],d[i]);

}

