/************************************************************************/
/*                                                                      */
/*  HOMEWORK:   5                                                       */
/*                                                                      */
/*  Name:   <Amber Crosson>                                             */
/*                                                                      */
/*  Class:  C Programming, Cybercourse,                                 */
/*                                                                      */
/*  Date:   10/15/2012                                                  */
/*                                                                      */
/*  Description:  Program which determines both overtime hours and      */
/*                gross pay, and outputs a formatted answer, all using  */
/*                a loop, conditional statements, functions, and        */
/*                an array of structs.                                  */
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

        float Calc_OT_Pay (float wage, float OT_hours, float OT_rate)
        {
                /**************************************************************************/
                /*                        Function Calc_OT_Pay                         	  */
                /*                                                                        */
                /*  Purpose:     This function will calculate the OT pay for an	          */
                /*               employee.  	                                          */
                /*                                                                        */
                /*  Parameters:  wage 	  (float) - rate of pay for the employee          */
                /*               OT_hours (float) - # of hours the employee worked        */
		/*		 OT_rate  (float) - factor of multiplication for OT pay   */
                /*                                                                        */
                /*  Returns:     overtime pay for the employee (float)			  */
                /**************************************************************************/
		
		float OT_pay;
				
		OT_pay = wage * OT_rate * OT_hours;

		return(OT_pay);

        }



        float Calc_Gross_Pay (float wage, float total_hours, float ot_hours, float std, float ot_rate)
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
		/*		 ot_rate      (float) - factor of mult. for OT pay 	  */
                /*                                                                        */
                /*  Returns:     gross pay (including any overtime pay) for the employee  */
                /**************************************************************************/

		float employee_OT_pay;		//place-holder for OT hours' pay only
		float employee_reg_pay;		//place-holder for regular hours' pay only
		float gross_pay; 		//gross pay for the given employee: sum of Reg and OT pay

		employee_OT_pay = Calc_OT_Pay (wage, ot_hours, ot_rate);
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


	struct employee
	{
	     int id;
	     float wage;
	     float hours;
	     float ot;
	     float gross;
	};


        int main()
        {

		#define STD_HOURS 40.0		//Typical hours in a work week
		#define OT_RATE 1.5		//Factor of multiplication for overtime pay
		#define NUM_WORKERS 5		//How many workers are there?
	
             	/* Declare variables */
		int count = 0;			// Current iteration of the loop, initialized at 0
	
		struct employee emps [NUM_WORKERS] = 	//Struct of employees, initialized with id and wage information
		{
			98401, 10.60, 0, 0, 0,
			526488, 9.75, 0, 0, 0,
                        765349, 10.5, 0, 0, 0, 
			634645, 12.25, 0, 0, 0,
                        127615, 8.35, 0, 0, 0
                };
	
		/*---------------Collect information, calculate wages-------------------------------------*/		

		while (count < NUM_WORKERS)
		{
			/*prompt for hours worked*/
			
			emps[count].hours = Prompt_Hours (emps[count].id);
			
			 /* determine hours past 40 worked */
			
			emps[count].ot = Calc_OT (emps[count].hours, STD_HOURS);

			 /* calculate gross pay */

			emps[count].gross = Calc_Gross_Pay (emps[count].wage, emps[count].hours, emps[count].ot, STD_HOURS, OT_RATE);

			count++;	//Increment count
		}

		/*-----------------Collected all information, calculated all wages-------------------------------*/

		count = 0;		//Reinitialize count

	        /*----------------print out employee information to the screen-----------------------------------*/

		printf ("\t----------------------------------------------------------\n");
		printf ("\tClock #	Wage	Hours	OT	Gross\n");
		printf ("\t----------------------------------------------------------\n");


		while (count < NUM_WORKERS)
		{
			Print_Out (emps[count].id, emps[count].wage, emps[count].hours, emps[count].ot, emps[count].gross);

			count += 1;
		}
               return (0);                    
        }

