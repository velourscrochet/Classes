/*-------------------------------------------------------------*/
/*                                                             */
/* HOMEWORK:    Midterm				               */
/*                                                             */
/* Name:        Amber V Crosson                	               */
/*                                                             */
/* Class:       C Programming, Cybercourse                     */
/*                                                             */
/* Date:        10/23/12	                               */
/*                                                             */
/*-------------------------------------------------------------*/

// Problem 1)
	// Part a)

float trapezoid_area (float base1, float base2, float height)
{
/**************************************************************************/
/*                        Function trapezoid_area		          */
/*                                                                        */
/*  Purpose:     Calculates the area of a trapezoid                       */
/*                                                                        */
/*  Parameters: base1	- length of one of the bases                  	  */
/*		base2	- length of the other base			  */
/*		height	- height of the trapezoid			  */
/*                                                                        */
/*  Returns:    area	- area of the trapezoid				  */
/**************************************************************************/

float area;		//area of the trapezoid
float avg_base;		//average base length

avg_base = (base1 + base2) / 2;

area = avg_base * height;

return (area);
}

	// Part b)

float trapezoid_perimeter (float base1, float base2, float side1, float side2)
{
/**************************************************************************/
/*                        Function trapezoid_perimeter		          */
/*                                                                        */
/*  Purpose:     Calculates the perimeter of a trapezoid                  */
/*                                                                        */
/*  Parameters: base1	- length of one of the bases                  	  */
/*		base2	- length of the other base			  */
/*		side1	- length of one side				  */
/*		side2	- length of th eother side			  */
/*                                                                        */
/*  Returns:    perimeter - perimeter of the trapezoid			  */
/**************************************************************************/

float perimeter;	//perimeter of the trapezoid

perimeter = base1 + base2 + side1 + side2;

return (perimeter);

}

// Problem 2)

int frequency (int theArray [ ], int n, int x)
{
/**************************************************************************/
/*                        Function frequency			          */
/*                                                                        */
/*  Purpose:     Counts the times x appears in the first n elements       */
/*                                                                        */
/*  Parameters:  theArray 	- The array from which to count 	  */
/*		 n		- the number of elements to inspect	  */
/*		 x		- the value to search for		  */
/*                                                                        */
/*  Returns:     tally		- how many times was it found?		  */
/**************************************************************************/

int tally = 0;		//Initialize count to zero
int curr_element = 0;	//Initialize current element to zero

while (curr_element < n)
{
	if (theArray[curr_element] == x)
	{
		tally++;
	}
	curr_element++;
}

return(tally);
}

// Problem 3)
	// Part a)

if (w > x) && (w > y) && (w > z)
{
	max = w;
}
else if (x > w) && (x > y) && (x > z)
{
	max = x;
}
else if (y > w) && (y > x) && (y > z)
{
	max = y;
}
else
{
	max = z;
}

	// Part b)

sign = ((x>0) ? 1 : (x==0) ? 0 : -1);

// Problem 4)

char score2grade(float score)
{
/**************************************************************************/
/*                        Function score2grade			          */
/*                                                                        */
/*  Purpose:     Calculates the letter grade, based on number score       */
/*                                                                        */
/*  Parameters:  score	- Numeric score, on an assignment	          */
/*                                                                        */
/*  Returns:     grade	- Letter grade, on the assignment		  */
/**************************************************************************/

char grade;		// letter grade

if ((score > 100) || (score < 0))
{
	grade = 'I';
}
else if (score >= 90)
{
	grade = 'A';
}
else if (score >= 80)
{
	grade = 'B';
}
else if (score >= 70)
{
	grade = 'C';
}
else if (score >= 60)
{
	grade = 'D';
}
else 
{
	grade = 'F';
}

return (grade);
}

// Problem 5)

struct Count
{
	int A;
	int B;
	int C;
	int D;
	int F;
	int I;
};

struct Count grade_counter(char gradeArray [], int arraySize)
{
/**************************************************************************/
/*                        Function grade_counter		          */
/*                                                                        */
/*  Purpose:    Sorts the letter grade into tallied buckets               */
/*                                                                        */
/*  Parameters: gradeArray	- Array of letter grades                  */
/*		arraySize	- size of the array = # of grades	  */
/*                                                                        */
/*  Returns:    gradeTally	- Struct containing counts for each grade */
/*	My assumption is that I didn't HAVE to store the data but if I    */
/*		data, but if I ever needed it, I'd want it in a struct    */
/*	I would return 0, and have separate variables for each, if I knew */
/*		that I would NEVER need to refer to these values again	  */
/*	Count struct defined above, included <ctype.h>			  */
/**************************************************************************/

struct Count gradeTally = {0,0,0,0,0,0}; //initialize grade tally to all zeros
int currElem = 0;			 //initialize counter to zero

while (currElem < arraySize)
{
	gradeArray[currElem] = toupper(gradeArray[currElem]);
	switch (gradeArray[currElem])
	{
		case 'A':
		
		Count.A++;
		break;

		case 'B':
		
		Count.B++;
		break;

		case 'C':
		
		Count.C++;
		break;

		case 'D':
		
		Count.D++;
		break;

		case 'F':
		
		Count.F++;
		break;

		default:
		
		Count.I++;
		break;
	}
}

currElem = 0;				//reset counter to zero
printf("Grade	Total\n");
printf("-----	-----\n");
printf("A	%d",gradeTally.A);
printf("B	%d",gradeTally.B);
printf("C	%d",gradeTally.C);
printf("D	%d",gradeTally.D);
printf("F	%d",gradeTally.F);
printf("I	%d",gradeTally.I);

return(gradeTally);
}

// Problem 6)
#include <stdio.h>

float array_sum (float theArray[], int arraySize)
{
/**************************************************************************/
/*                        Function score2grade			          */
/*                                                                        */
/*  Purpose:     Calculates the letter grade, based on number score       */
/*                                                                        */
/*  Parameters:  score	- Numeric score, on an assignment	          */
/*                                                                        */
/*  Returns:     grade	- Letter grade, on the assignment		  */
/**************************************************************************/

float sum;
int count = 0;

while (count < arraySize)
{
	sum += theArray[count];
}

return(sum);
}

float array_avg (float theArray[], int arraySize)
{
/**************************************************************************/
/*                        Function score2grade			          */
/*                                                                        */
/*  Purpose:     Calculates the letter grade, based on number score       */
/*                                                                        */
/*  Parameters:  score	- Numeric score, on an assignment	          */
/*                                                                        */
/*  Returns:     grade	- Letter grade, on the assignment		  */
/**************************************************************************/

float avg;
int count = 0;

while (count < arraySize)
{
	avg += theArray[count];
}	
avg = avg / arraySize;
return(avg);
}

float array_min (float theArray[], int arraySize)
{
/**************************************************************************/
/*                        Function score2grade			          */
/*                                                                        */
/*  Purpose:     Calculates the letter grade, based on number score       */
/*                                                                        */
/*  Parameters:  score	- Numeric score, on an assignment	          */
/*                                                                        */
/*  Returns:     grade	- Letter grade, on the assignment		  */
/**************************************************************************/

float min = theArray[0];
int count = 0;

while (count < arraySize)
{
	if (theArray[count] < min)
	{
		min = theArray[count];
	}
}

return(min);
}

int main()
{
float sum;
float avg;
float min;
int arraySize = 10;

float SomeArray[arraySize];

sum = array_sum(SomeArray, arraySize);
avg = array_avg(SomeArray, arraySize);
min = array_min(SomeArray, arraySize);

printf("The sum of the array elements is: %f.\nThe average of the array elements is: %f.\nThe minimum value of the array elements is: %f.", sum, avg, min);
	
return(0);
}


// Problem 7)

int x_to_the_n(int x, int n)
{
/**************************************************************************/
/*                        Function x_to_the_n			          */
/*                                                                        */
/*  Purpose:     Calculates x^n			                          */
/*                                                                        */
/*  Parameters:  x	- base				                  */
/*		 n	- exponent					  */
/*                                                                        */
/*  Returns:     product	- x^n					  */
/**************************************************************************/

int product = x;	//x^1 = x
int counter = 1;	//initialize counter to 0

while (counter < n)
{
	product *= x;	//multiply the product by x
}

return(product);
}

// Problem 8)

struct earthDate
{
	int Month;
	int Day;
	int Year;
};

struct name
{
	char Title[8];
	char First[16];
	char Middle[16];
	char Last[16];
	char Suffix[8];
};

struct address
{
	char Street1[24];
	char Street2[24];
	char City[24];
	char State[24];
	int  Zip;
	int  ZipExt;
	char Planet[24];
};

struct officer
{
	struct name OffName;
	struct earthDate DOB;
	struct address Residence;
	char rank[40];
	char ship[40];
	char nickname[40];
	char favTweet[140];
	float startingStardate;
	char maritalStatus[16];
	struct earthDate starfleetGraduation;
};

//code needed to declare an array of size 100, for the officer struct:
struct officer Federation [100];
