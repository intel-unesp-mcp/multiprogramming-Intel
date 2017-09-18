#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <unistd.h>

int main() {
    int thid; char hn[600], i;
    double res, p[100];
	
    #pragma omp parallel
    {
        thid=omp_get_thread_num();
        gethostname(hn,600);
        printf("P1 hello from thread %d hostname %s\n",thid, hn);
    }

    res = 0;
	
    #pragma omp for
    for ( i = 0 ; i < 100 ; i++ ) { 
      p[i] = i/0.855;
    }

    #pragma omp for
    for ( i = 0 ; i < 100 ; i++ ) { 
      res = res + p[i];
    }

    printf("sum of vector elements: %f", res);  
}
