#include <omp.h>
#include<stdio.h>
#define CHUNKSIZE 100
#define N 1000

main ()  
{

int i, chunk;
float a[N], b[N], c[N];

/* Some initializations */
for (i=0; i < N; i++)
{
  a[i] = i * 1.0;
  b[i] = i * 2.0;
 }
chunk = CHUNKSIZE;

#pragma omp parallel shared(a,b,c,chunk) private(i)
  {

  #pragma omp for schedule(dynamic,chunk) nowait
  for (i=0; i < N; i++)
    c[i] = a[i] + b[i];

  }  /* end of parallel section */

for (i=0; i < N; i++)
	printf("%f\n",c[i]);
}
