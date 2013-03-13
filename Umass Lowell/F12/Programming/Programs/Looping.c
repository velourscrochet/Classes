/************************************************************************/
/*                                                                      */
/*  HOMEWORK:   1                                                       */
/*                                                                      */
/*  Name:   <Amber Crosson>                                             */
/*                                                                      */
/*  Class:  C Programming, Cybercourse,                                 */
/*                                                                      */
/*  Date:   09/17/2012                                                  */
/*                                                                      */
/*  Description:  Program which determines gross pay and outputs        */
/*                a formatted answer, all using a loop                  */
/*                                                                      */
/************************************************************************/

        #include <stdio.h>

        int main()
        {

             	/* Declare variables */
		int number_of_workers; 	//Prompt for the number of workers, to govern the loop
		int count = 1;		//Current iteration of the loop, initialized at 1
		int employee_clock; 	//prompt within loop; display 6 digits
		float employee_wage; 	//Prompt within loop; truncate to two decimals
		float employee_hours; 	//Prompt within loop
		float employee_gross; 	//to be calculated
		
		
		printf ("Enter number of employees:\n");
		scanf  ("%d", &number_of_workers);
		
		while (count <= number_of_workers)
		{
			printf ("Enter clock number for employee %i\n", count);
			scanf ("%d", &employee_clock);
			printf ("Enter hourly wage for employee %i\n", count);
			scanf ("%f", &employee_wage);
			printf("Enter hours worked by employee %i\n", count);
			scanf ("%f", &employee_hours);


	                 /* calculate gross pay */

			employee_gross = employee_wage * employee_hours;

        	         /* print out employee information to the screen */
			printf ("\t----------------------------------------------------------\n");
			printf ("\tClock #    Wage      Hours    Gross\n");
			printf ("\t----------------------------------------------------------\n");
			printf ("\t%06i     %5.2f    %5.1f    %7.2f\n", employee_clock, employee_wage, employee_hours, employee_gross);

			count++;
		}

	       /* end the loop */
               return (0);                    
        }

