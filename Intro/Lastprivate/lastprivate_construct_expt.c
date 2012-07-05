#include <omp.h>
#include <stdio.h>
#define N 1000000

int x,y,z;
main ()
{

#pragma omp parallel
  {

  #pragma omp sections nowait lastprivate(x,y)
    {
    
    #pragma omp section
    {	x=23; y=24; z=25; }

    #pragma omp section
    {	x=45; y=46; z=47; }

    #pragma omp section
    {	x=93; /*y=94; z=95;*/ }

    }  /* end of sections */
	
	//printf("(x,y,z)=(%d,%d,%d)\n",x,y,z);
  }  /* end of parallel section */
  
  printf("(x,y,z)=(%d,%d,%d)\n",x,y,z);

}

