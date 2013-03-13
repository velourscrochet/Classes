/************************************************************************/
/*                                                                      */
/*  HOMEWORK:   4                                                       */
/*                                                                      */
/*  Name:   <Amber Crosson>                                             */
/*                                                                      */
/*  Class:  C Programming, Cybercourse,                                 */
/*                                                                      */
/*  Date:   10/08/2012                                                  */
/*                                                                      */
/*  Description:  Program which determines both overtime hours and      */
/*                gross pay, and outputs a formatted answer, all using  */
/*                a loop, conditional statements, functions, and arrays */
/*                                                                      */
/************************************************************************/

        #include <stdio.h>

	float Prompt_Hours (int emp_clock)
	{
		/**************************************************************************/
		/*                        Function Prompt_Hours                           */
		/*                                                                        */
		/*  Purpose:     This function will prompt for hours worked by a given    */
		/*               employee. It will print the employee clock, and 	  */
		/*               provide a prompt.			                  */
		/*                                                                        */
		/*  Parameters:  emp_clock (int) -  Which employee in the array is it?	  */
		/*                                                                        */
		/*  Returns:     hours worked (float) - What was the prompt response? 	  */
		/**************************************************************************/
	
		float hours_worked;	//hours worked by the employee in question

		printf ("How many hours did employee %i work this week? \n", emp_clock); // input number of hours worked
		scanf ("%f", &hours_worked);

		return (hours_worked);


	}


        float Calc_OT (float hours, float std)
        {
                /**************************************************************************/
                /*                        Function Calc_OT	                          */
                /*                                                                        */
                /*  Purpose:     This function will calculate the overtime worked by      */
                /*               an employee.                                             */
                /*                                                                        */
                /*  Parameters:  hours (float) - # of hours the employee worked           */
		/*		 std   (float) - # of hours worked in a standard week     */
                /*                                                                        */
                /*  Returns:     Hours over Standard # worked (float)			  */
                /**************************************************************************/

		float OT;	//hours over standard

		OT = hours - std; 
		
		if (OT>0)
		{
			return (OT);
		}
		else
		{	
			return (0);
		}
        }

        float Calc_OT_Pay (float wage, float OT_hours)
        {
                /**************************************************************************/
                /*                        Function Calc_OT_Pay                         	  */
                /*                                                                        */
                /*  Purpose:     This function will calculate the OT pay for an	          */
                /*               employee.  	                                          */
                /*                                                                        */
                /*  Parameters:  wage 	  (float) - rate of pay for the employee          */
                /*               OT_hours (float) - # of hours the employee worked        */
                /*                                                                        */
                /*  Returns:     overtime pay for the employee (float)			  */
                /**************************************************************************/
		
		float OT_pay;
	
		OT_pay = wage * 1.5 * OT_hours;

		return(OT_pay);

        }



        float Calc_Gross_Pay (float wage, float total_hours, float ot_hours, float std)
        {
                /**************************************************************************/
                /*                        Function Calc_Gross_Pay                         */
                /*                                                                        */
                /*  Purpose:     This function will calculate the gross pay for an        */
                /*               employee.  It will add to the gross pay any overtime     */
                /*               pay if necessary.                                        */
                /*                                                                        */
                /*  Parameters:  wage         (float) - rate of pay for the employee      */
                /*               total_hours  (float) - # of hours the employee worked    */
                /*               ot_hours     (float) - # of hours the employee worked    */
                /*               std          (float) - standard number of hrs/work week  */
                /*                                                                        */
                /*  Returns:     gross pay (including any overtime pay) for the employee  */
                /**************************************************************************/

		float employee_OT_pay;		//place-holder for OT hours' pay only
		float employee_reg_pay;		//place-holder for regular hours' pay only
		float gross_pay; 		//gross pay for the given employee: sum of Reg and OT pay

		employee_OT_pay = Calc_OT_Pay (wage, ot_hours);
		employee_reg_pay = wage * (total_hours - ot_hours);

		
		gross_pay = employee_reg_pay + employee_OT_pay;
		

		return (gross_pay);
        }

        int Print_Out (int emp_clock, float wage, float hours, float ot_hours, float gross_pay)
        {
                /**************************************************************************/
                /*                        Function Print_Out                              */
                /*                                                                        */
                /*  Purpose:     This function will format and print the results of the   */
                /*               calculations for employee pay.                           */
                /*                                                                        */
                /*  Parameters:  emp_clock (int)  - Employee clock		          */
		/*		 wage      (float) - rate of pay for the employee  	  */
                /*               hours     (float) - # of hours the employee worked       */
		/*		 ot_hours  (float) - # of OT hours worked		  */
                /*               gross_pay (float) - overtime pay for the employee        */
                /*                                                                        */
                /*  Returns:     gross pay (including any overtime pay) for the employee  */
                /**************************************************************************/

		printf ("\t%06i	%5.2f	%5.1f	%5.1f	%7.2f\n", emp_clock, wage, hours, hours, gross_pay);


        }





        int main()
        {

		#define STD_HOURS 40.0
		#define NUM_WORKERS 5

             	/* Declare variables */
		int count = 0;									// Current iteration of the loop, initialized at 1
		int employee_clock [NUM_WORKERS] = {98401, 526488, 765349, 34645, 127615}; 	// prompt within loop; display 6 digits
		float employee_wage [NUM_WORKERS] = {10.6, 9.75, 10.5, 12.25, 8.35};	 	// Prompt within loop; truncate to two decimals
		float employee_total_hours [NUM_WORKERS]; 					// Prompt within loop
		float employee_OT_hours [NUM_WORKERS];						// Hours worked over STD_HOURS
		float employee_gross_pay [NUM_WORKERS]; 					// to be calculated: OT pay + reg pay
	

		
		/*---------------Collect information, calculate wages-------------------------------------*/		

		while (count < NUM_WORKERS)
		{
			/*prompt for hours worked*/
			
			employee_total_hours[count] = Prompt_Hours (employee_clock[count]);
			
			 /* determine hours past 40 worked */
			
			employee_OT_hours[count] = Calc_OT (employee_total_hours[count], STD_HOURS);

			 /* calculate gross pay */

			employee_gross_pay[count] = Calc_Gross_Pay (employee_wage[count], employee_total_hours[count], employee_OT_hours[count], STD_HOURS);

			count++;
		}

		/*-----------------Collected all information, calculated all wages-------------------------------*/

		count = 0;

	        /*----------------print out employee information to the screen-----------------------------------*/

		printf ("\t----------------------------------------------------------\n");
		printf ("\tClock #	Wage	Hours	OT	Gross\n");
		printf ("\t----------------------------------------------------------\n");


		while (count < NUM_WORKERS)
		{
			Print_Out (employee_clock[count], employee_wage[count], employee_total_hours[count], employee_OT_hours[count], employee_gross_pay[count]);

			count += 1;
		}
               return (0);                    
        }

