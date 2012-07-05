#include<omp.h>
#include<stdio.h>

main()
{
	int x,y,z,tid;
	x=3;y=5,z=4;
	
	#pragma omp parallel firstprivate(x,y) private(z,tid)
	{
		tid=omp_get_thread_num();
		
		printf("A : In thread %d : (x,y,z)=(%d,%d,%d).\n",tid,x,y,z);
		++x; ++y; ++z;
		printf("B : In thread %d : (x,y,z)=(%d,%d,%d).\n",tid,x,y,z);
	}
}
