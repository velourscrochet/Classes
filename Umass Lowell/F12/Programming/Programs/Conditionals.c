/************************************************************************/
/*                                                                      */
/*  HOMEWORK:   1                                                       */
/*                                                                      */
/*  Name:   <Amber Crosson>                                             */
/*                                                                      */
/*  Class:  C Programming, Cybercourse,                                 */
/*                                                                      */
/*  Date:   09/23/2012                                                  */
/*                                                                      */
/*  Description:  Program which determines both overtime hours and      */
/*                gross pay, and outputs a formatted answer, all using  */
/*                a loop and conditional statements                     */
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
		float employee_OT;
		float employee_OT_pay;	//Hours over 40 * (1.5 wage)
		float employee_reg_pay;	//Hours up to 40 * (1 wage)
		float employee_gross; 	//to be calculated: OT pay + reg pay
	
		#define STD_HOURS 40.0

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

			 /* determine hours past 40 worked */
			employee_OT = employee_hours - STD_HOURS; 

	                 /* calculate gross pay */

			if (employee_OT > 0)
			{
				employee_reg_pay = employee_wage * employee_hours;
				employee_OT_pay = employee_wage * 1.5 * employee_OT;
				
				employee_gross = employee_OT_pay;
			}
			else
			{
				employee_gross = employee_wage * employee_hours;
			}

        	         /* print out employee information to the screen */
			printf ("\t----------------------------------------------------------\n");
			printf ("\tClock #	Wage	Hours	OT	Gross\n");
			printf ("\t----------------------------------------------------------\n");
			printf ("\t%06i	%5.2f	%5.1f	%5.1f	%7.2f\n", employee_clock, employee_wage, employee_hours, employee_OT, employee_gross);

			count++;
		}

	       /* end the loop */
               return (0);                    
        }

