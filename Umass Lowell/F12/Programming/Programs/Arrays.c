/************************************************************************/
/*                                                                      */
/*  HOMEWORK:   3                                                       */
/*                                                                      */
/*  Name:   <Amber Crosson>                                             */
/*                                                                      */
/*  Class:  C Programming, Cybercourse,                                 */
/*                                                                      */
/*  Date:   09/23/2012                                                  */
/*                                                                      */
/*  Description:  Program which determines both overtime hours and      */
/*                gross pay, and outputs a formatted answer, all using  */
/*                a loop, conditional statements, and arrays            */
/*                                                                      */
/************************************************************************/

        #include <stdio.h>

        int main()
        {

		#define STD_HOURS 40.0
		#define NUM_WORKERS 5

             	/* Declare variables */
		int count = 1;									// Current iteration of the loop, initialized at 1
		int employee_clock [NUM_WORKERS] = {98401, 526488, 765349, 34645, 127615}; 	// prompt within loop; display 6 digits
		float employee_wage [NUM_WORKERS] = {10.6, 9.75, 10.5, 12.25, 8.35};	 	// Prompt within loop; truncate to two decimals
		float employee_hours [NUM_WORKERS]; 						// Prompt within loop
		float employee_OT [NUM_WORKERS];						// Hours worked over STD_HOURS
		float employee_OT_pay [NUM_WORKERS];						// [Hours over STD_HOURS] * (1.5 wage)
		float employee_reg_pay [NUM_WORKERS];						// [Hours up to STD_HOURS] * (1 wage)
		float employee_gross [NUM_WORKERS]; 						// to be calculated: OT pay + reg pay
	

		
		/*---------------Collect information, calculate wages-------------------------------------*/		

		while (count <= NUM_WORKERS)
		{
			printf ("How many hours did employee %i work this week? \n", employee_clock[count-1]); // input number of hours worked
			scanf ("%f", &employee_hours[count-1]);							//assign #hours to array
			
			 /* determine hours past 40 worked */
			
			employee_OT[count-1] = employee_hours[count-1] - STD_HOURS; 

	                 /* calculate gross pay */

			if (employee_OT[count-1] > 0)
			{
				employee_reg_pay[count-1] = employee_wage[count-1] * (STD_HOURS);
				employee_OT_pay[count-1] = employee_wage[count-1] * 1.5 * employee_OT[count-1];
				
				employee_gross[count-1] = employee_OT_pay[count-1] + employee_reg_pay[count-1];
			}
			else
			{
				employee_OT[count-1] = 0;
				employee_gross[count-1] = employee_wage[count-1] * employee_hours[count-1];
			}

			count++;
		}

		/*-----------------Collected all information, calculated all wages-------------------------------*/

		count = 1;

	        /*----------------print out employee information to the screen-----------------------------------*/

		printf ("\t----------------------------------------------------------\n");
		printf ("\tClock #	Wage	Hours	OT	Gross\n");
		printf ("\t----------------------------------------------------------\n");


		while (count <= NUM_WORKERS)
		{
			printf ("\t%06i	%5.2f	%5.1f	%5.1f	%7.2f\n", employee_clock[count-1], employee_wage[count-1], employee_hours[count-1], employee_OT[count-1], employee_gross[count-1]);

			count += 1;
		}
               return (0);                    
        }

