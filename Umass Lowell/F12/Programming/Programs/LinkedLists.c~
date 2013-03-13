#include <stdio.h>
#include <stdlib.h>   /* for malloc */
#include <ctype.h>
 
struct employee
{
	char  first_name [10];
	char last_name  [10];
	long  id_number;
	float wage;
	float hours;
	float overtime;
	float gross;

	struct employee *next;
};


/*-----------------------------------------------------------------------------*/
/*                                                                             */
/* FUNCTION:  prompt_data                                                      */
/*                                                                             */
/* DESCRIPTION:  This function will calculate an employee's gross pay          */
/*                                                                             */
/* PARAMETERS:   emp1 - pointer to a linked list                               */	
/*                                                                             */
/* OUTPUTS:      gross_pay                                                     */
/*                                                                             */
/* CALLS:        calc_OT_pay                                                   */
/*                                                                             */
/*-----------------------------------------------------------------------------*/
char prompt_data (struct employee *emp1)
{

    char   answer[80];       /* to see if the user wants to add more employees */
    char   value;             /* gets the first character of answer */

	struct employee *current_ptr;

	current_ptr = emp1;

       /* Read in Employee Information */
        printf("\nEnter employee ID: ");
        scanf("%ld", & emp1 -> id_number);

        printf("\nEnter employee last name: ");
        scanf("%s", emp1 -> last_name);

        printf("\nEnter employee first name: ");
        scanf("%s", emp1 -> first_name);
 
        printf("\nEnter employee weekly wage: ");
        scanf("%f", & emp1 -> wage);

        printf("\nEnter employee hours worked: ");
        scanf("%f", & emp1 -> hours);
 
        printf("Would you like to add another employee? (y/n): ");
        scanf("%s", answer);
 
	value = toupper(answer[0]);	//Let "value" = upper case, first character of response

	return(value);

}



/*-----------------------------------------------------------------------------*/
/*                                                                             */
/* FUNCTION:  calc_OT                                                          */
/*                                                                             */
/* DESCRIPTION:  This function will calculate the OT worked by an employee     */
/*                                                                             */
/* PARAMETERS:   emp1 - pointer to a linked list                               */	
/*                                                                             */
/* OUTPUTS:      OT_worked                                                     */
/*                                                                             */
/* CALLS:        None                                                          */
/*                                                                             */
/*-----------------------------------------------------------------------------*/
float calc_OT (float hours, float std)
{
	float OT;	// overtime worked by the employee

	OT =  hours - std; 
	
	if (OT>0)
	{
		return (OT);
	}
	else
	{	
		return (0);
	}


}



/*-----------------------------------------------------------------------------*/
/*                                                                             */
/* FUNCTION:  calc_OT_pay                                                      */
/*                                                                             */
/* DESCRIPTION:  This function will calculate an employee's overtime pay       */
/*                                                                             */
/* PARAMETERS:   emp1 - pointer to a linked list                               */	
/*                                                                             */
/* OUTPUTS:      OT_pay                                                        */
/*                                                                             */
/* CALLS:        None                                                          */
/*                                                                             */
/*-----------------------------------------------------------------------------*/
float calc_OT_pay (float wage, float std, float rate)
{
	float OT_pay;
				
	OT_pay = wage * rate * std;

	return(OT_pay);
}



/*-----------------------------------------------------------------------------*/
/*                                                                             */
/* FUNCTION:  calc_pay	                                                       */
/*                                                                             */
/* DESCRIPTION:  This function will calculate an employee's gross pay          */
/*                                                                             */
/* PARAMETERS:   emp1 - pointer to a linked list                               */	
/*                                                                             */
/* OUTPUTS:      gross_pay                                                     */
/*                                                                             */
/* CALLS:        calc_OT_pay                                                   */
/*                                                                             */
/*-----------------------------------------------------------------------------*/
void calc_pay (struct employee *emp1, float std, float rate)
{
	float employee_OT_pay;		//place-holder for OT hours' pay only
	float employee_reg_pay;		//place-holder for regular hours' pay only
	float gross_pay; 		//gross pay for the given employee: sum of Reg and OT pay

	employee_OT_pay = calc_OT_pay(emp1->wage, std, rate);
	employee_reg_pay = emp1->wage * (emp1->hours - emp1->overtime);

	emp1->gross = employee_reg_pay + employee_OT_pay;

}


 
/*-----------------------------------------------------------------------------*/
/*                                                                             */
/* FUNCTION:  print_list                                                       */
/*                                                                             */
/* DESCRIPTION:  This function will print the contents of a linked             */
/*               list.  It will traverse the list from beginning to the        */
/*               end, printing the contents at each node.                      */
/*                                                                             */
/* PARAMETERS:   emp1 - pointer to a linked list                               */
/*                                                                             */
/* OUTPUTS:      None                                                          */
/*                                                                             */
/* CALLS:        None                                                          */
/*                                                                             */
/*-----------------------------------------------------------------------------*/
void print_list(struct employee *emp1)
{
        struct employee *tmp;   /* tmp pointer value to current node */
        int i = 0;              /* counts the nodes printed          */

	printf ("\t---------------------------------------------------------------\n");
	printf ("\tName		Clock #		Wage	Hours	   OT	  Gross\n");
	printf ("\t---------------------------------------------------------------\n");
 
        /* Start a beginning of list and print out each value               */
        /* loop until tmp points to null (remember null is 0 or false)      */
        for(tmp = emp1; tmp ; tmp = tmp->next)
        {
            i++; 				//tally number of nodes (employees)

	/*Print out each employee's information*/
	printf ("\t%s %s	%06ld		%5.2f	%5.1f	%5.1f	%7.2f\n", tmp->first_name, tmp->last_name, tmp->id_number, tmp->wage, tmp->hours,tmp->overtime, tmp->gross);		


        }
 
        printf("\n\nTotal Number of Employees = %d\n", i);
 
}
 

/*----------------------------------------------------------------------------*/
/*                                                                            */
/* FUNCTION:  main                                                            */
/*                                                                            */
/* DESCRIPTION:  This function will prompt the user for an employee           */
/*               id and wage until the user indicates they are finished.      */
/*               At that point, a list of id and wages will be                */
/*               generated.                                                   */
/*                                                                            */
/* PARAMETERS:   None                                                         */
/*                                                                            */
/* OUTPUTS:      None                                                         */
/*                                                                            */
/* CALLS:        print_list                                                   */
/*                                                                            */
/*----------------------------------------------------------------------------*/
int main ()
{
 
	char   answer[80];       /* to see if the user wants to add more employees */
	int    more_data = 1;    /* flag to check if another employee is to be processed */
	char   newEmployee;             /* gets the first character of answer */

	#define STD_HOURS 40.0		//Typical hours in a work week
	#define OT_RATE 1.5		//Factor of multiplication for overtime pay
 
	struct employee *current_ptr,   /* pointer to current node */
        		*head_ptr;       /* always points to first node */
 
   /* Set up storage for first node */
	head_ptr = (struct employee *) malloc (sizeof(struct employee));
	current_ptr = head_ptr;
 
	while (more_data)
	{
		/* Read in Employee Information */
		newEmployee = prompt_data (current_ptr);

		current_ptr->overtime = calc_OT(current_ptr->hours, STD_HOURS);			

		calc_pay(current_ptr, STD_HOURS, OT_RATE);


		if (newEmployee != 'Y')
		   {
		   current_ptr->next = (struct employee *) NULL;
		   more_data = 0; 
		   }
		else
		   {
		   /* set the next pointer of the current node to point to the new node */
		   current_ptr->next = (struct employee *) malloc (sizeof(struct employee));
		  /* move the current node pointer to the new node */
		   current_ptr = current_ptr->next;
		   }
 
	} /* while */
 
	/* print out listing of all employee id's and wages that were entered */
	print_list(head_ptr);

	printf("\n\nEnd of program\n");
	return 0;
}
