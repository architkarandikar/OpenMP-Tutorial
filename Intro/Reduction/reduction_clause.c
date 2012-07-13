#include <omp.h>
#include <stdio.h>

main ()  {

int   i, n, chunk, tid;
float a[100], b[100], result;

/* Some initializations */
n = 100;
chunk = 10;
result = 0.0;
for (i=0; i < n; i++)
  {
  a[i] = i * 1.0;
  b[i] = i * 2.0;
  }

#pragma omp parallel for      \
  default(shared) private(i,tid)  \
  schedule(static,chunk)      \
  reduction(+:result)  

  for (i=0; i < n; i++)
  {
    result = result + (a[i] * b[i]);
    tid = omp_get_thread_num();
    printf("%d %d : %f\n",i,tid,result);
  }

printf("Final result= %f\n",result);

}

