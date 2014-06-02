#include <math.h>

#define TEST_PROBLEM "STChebychev9"
#define N 9

#define PI 3.14159265359
#define SOL 0 


void bounds(double lb[], double ub[])
/*Provide lower and upper bounds for each of N variables.
 Number of bounds is equal to N.*/
{
	int i;

	for (i=0; i<N; i++)
	{
		lb[i] = -129;
		ub[i] = 129;
	}

}

/*Test feasibility of x.  Return 1 if feasible, 0 if not.*/
int feasible(double x[])

{
	return 1;
}

/*Calculate objective function value of x[].*/
double objfn(double x[])
{
	int i, j, m=60;
	double sum=0.0;
	double d=72.661;
	double u=0.0, v=0.0, w=0.0;
	double p1, p2, p3=0.0;
	double pj;

	for (i=0; i<N; i++) u+= pow(1.2,N-i-1)*x[i];
	if (u < d)
	{
		p1 = (u-d)*(u-d);
	}
	else p1 = 0;

	for (i=0; i<N; i++) v+= pow(-1.2,N-i-1)*x[i];
	if (v < d)
	{
		p2 = (v-d)*(v-d);
	}
	else p2 = 0;

	for (j=0; j<=m; j++) 
	{
		w = 0.0;
		for (i=0; i<N; i++) {
                  w+= pow(2.0/m*j,N-i-1)*x[i];
                  //                  printf(">> %f %f\n", 2.0/m*j, pow(2.0/m*j,N-i-1));
                }
		if (w>1) pj = (w-1)*(w-1);
		else if (w<-1) pj = (w+1)*(w+1);
		else pj = 0.0;
                //                printf("j %d %f %f\n", j, w, pj);
		p3 += pj;
	}

	sum = p1+p2+p3;
               // printf("%f %f %f %f %f\n", u, p1, v, p2, p3);

    return (sum);

}

double nelder_objfn(const gsl_vector *x, void *data){
	
	return objfn(x->data);
}

int levermed_objfn(const gsl_vector *x, void *data, gsl_vector *f){
	return 0;
}
