
#define TEST_PROBLEM "Ackleys"
#define N 10

#define PI 3.14159265359
#define SOL 0.0


void bounds(double lb[], double ub[])
/*Provide lower and upper bounds for each of N variables.
 Number of bounds is equal to N.*/
{
  lb[0] = -30;
  ub[0] = 30;
  lb[1] = -30;
  ub[1] = 30;
  lb[2] = -30;
  ub[2] = 30;
  lb[3] = -30;
  ub[3] = 30;
  lb[4] = -30;
  ub[4] = 30;
  lb[5] = -30;
  ub[5] = 30;
  lb[6] = -30;
  ub[6] = 30;
  lb[7] = -30;
  ub[7] = 30;
  lb[8] = -30;
  ub[8] = 30;
  lb[9] = -30;
  ub[9] = 30;

}

/*Test feasibility of x.  Return 1 if feasible, 0 if not.*/
int feasible(double x[])

{
	return 1;
}

/*Calculate objective function value of x[].*/
double objfn(double x[])
{
	int i;
	double subsum1=0., subsum2=0., sum=0.;

	for (i=0; i<N; i++)
	{
		subsum1 = subsum1 + pow(x[i],2);
		subsum2 = subsum2 + cos(2*PI*x[i]);
	}
	sum = -20.*exp(-.02*sqrt(subsum1/N))-exp(subsum2/N)+20.+exp(1);
	return (sum);

}

double nelder_objfn(const gsl_vector *x, void *data){
	
	return objfn(x->data);
}

int levermed_objfn(const gsl_vector *x, void *data, gsl_vector *f){
	return 0;
}
