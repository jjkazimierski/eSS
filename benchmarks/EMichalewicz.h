
#define TEST_PROBLEM "EMichalewicz"
#define N 5

#define PI 3.14159265359
#define SOL -4.6877


void bounds(double lb[], double ub[])
/*Provide lower and upper bounds for each of N variables.
 Number of bounds is equal to N.*/
{
  lb[0] = 0;
  ub[0] = PI;
  lb[1] = 0;
  ub[1] = PI;
  lb[2] = 0;
  ub[2] = PI;
  lb[3] = 0;
  ub[3] = PI;
  lb[4] = 0;
  ub[4] = PI;
  
}

/*Test feasibility of x.  Return 1 if feasible, 0 if not.*/
int feasible(double x[])

{
	return 1;
}

/*Calculate objective function value of x[].*/
double objfn(double x[])
{

	int j;
	double y[10];
	double cost,sint,sum=0.,m=10.;


	cost = cos(PI/6.);
	sint = sin(PI/6.);

	for (j=0; j<N-1; j+=2 )		/* Corrects errors in original
ICEO test bed */
	{
	    y[j] = x[j]*cost - x[j+1]*sint;
	    y[j+1] = x[j]*sint + x[j+1]*cost;
	}

	if (j==N-1)  y[j]=x[j];

	for (j=0; j<N; j++)
	{
		sum -= sin(y[j]) * pow(sin((j+1)*y[j]*y[j]/PI),2.0*m);

	}

        //        for (j=0; j<N; j++) printf(" %f", y[j]);
        //for (j=0; j<N; j++) printf(" %f", x[j]);
        //printf(" %f", sum);
	return(sum);

}

double nelder_objfn(const gsl_vector *x, void *data){
	
	return objfn(x->data);
}

