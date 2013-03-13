/*-------------------------------------------------------------*/
/*                                                             */
/* HOMEWORK:    Final				               */
/*                                                             */
/* Name:        Amber V Crosson                	               */
/*                                                             */
/* Class:       C Programming, Cybercourse                     */
/*                                                             */
/* Date:        11/11/12	                               */
/*                                                             */
/*-------------------------------------------------------------*/

//Problem 1)

#define MIN5(A, B, C, D, E) 	{										\
					((A) >= (B)) && ((A) >= (C)) && ((A) >= (D)) && ((A) >= (E)) ? (A) :	\
					((B) >= (A)) && ((B) >= (C)) && ((B) >= (D)) && ((B) >= (E)) ? (B) :	\
					((C) >= (A)) && ((C) >= (B)) && ((C) >= (D)) && ((C) >= (E)) ? (C) :	\
					((D) >= (A)) && ((D) >= (B)) && ((D) >= (C)) && ((D) >= (E)) ? (D) :	\
					(E)									\
				}

//Problem 2)


/**************************************************************************/
/*                        Function word_count			          */
/*                                                                        */
/*  Purpose:     Determines how many words are in the string              */
/*                                                                        */
/*  Parameters: s - Input string, to count words in			  */
/*                                                                        */
/*  Returns:    num_words - Number of words counted			  */
/**************************************************************************/
int word_count (char * s)
{
	#define SPACE 32
	#define NONSPACE(x) (((x) > 0) && ((x) < 129) && ((x) != 32))
	#define EOS '\0'

	int num_words 	= 0;		//Number of words counted: always at least one?
	int ctr 	= 1;		//You CANNOT have a word break at the very beginning of a string. NO.
	char prevChar 	= SPACE;	//Helps to sanity check the character before the current character

	while (s[ctr] != EOS)
	{
		if (NONSPACE(s[ctr]) && ((prevChar == SPACE) || (prevChar == EOS)))
		{
			num_words++;
		}
		prevChar = s[ctr];
		ctr++;
	}

return (num_words);
}



//Problem 3)


/**************************************************************************/
/*                        Function dateCheck			          */
/*                                                                        */
/*  Purpose:  	Returns 1 if the date is valid, and 0 if the date is not */
/*                                                                        */
/*  Parameters: month, day, year					  */
/*                                                                        */
/*  Returns:    validDate						  */
/**************************************************************************/
int dateCheck (int month, int day, int year)
{
	#define TRUE 1
	#define FALSE 0
	int validMonth 	= FALSE;		//Preset all flags to FALSE
	int validDay	= FALSE;
	int validYear	= FALSE;
	int monthLength;

	int validDate;
//Check Year
	if (year >= 0)
	{
		validYear = TRUE;

//Check Month & Assign monthLength
		switch (month)					//organized by month, not by length
		{						//though length would have taken far fewer lines...
			case 1:
				monthLength = 31;
				break;
			case 2:
				if ((year % 4) == 0)
					monthLength = 29;
				else
					monthLength = 28;
				break;
			case 3:
				monthLength = 31;
				break;
			case 4:
				monthLength = 30;
				break;
			case 5:
				monthLength = 31;
				break;
			case 6:
				monthLength = 30;
				break;
			case 7:
			case 8:
				monthLength = 31;
				break;
			case 9:
				monthLength = 30;
				break;
			case 10:
				monthLength = 31;
				break;
			case 11:
				monthLength = 30;
				break;
			case 12:
				monthLength = 31;
				break;
			default:
				monthLength = 0;

		}//if month check
//Check Day
		if ((day <= monthLength) && (monthLength != 0))
		{
			validDay = TRUE;
			validMonth = TRUE;
		}//if day check
	}//if year check

//Are they ALL valid?
	if (validMonth && validDay && validYear)
	{
		validDate = TRUE;
	}
	else
	{
		validDate = FALSE;
	}
//Return TRUE or FALSE 
	return(validDate);
}

//Problem 4)

/**************************************************************************/
/*                        Function check_prime			          */
/*                                                                        */
/*  Purpose:  	Returns 1 if the input number is prime, and 0 if the 	  */
/*		number is not						  */
/*                                                                        */
/*  Parameters: num - Number to check for prime-ness			  */
/*                                                                        */
/*  Returns:    isPrime							  */
/**************************************************************************/
int check_prime (int num)
{
	#define TRUE 1		//make it easy to read
	#define FALSE 0

/*optimized for speed...I know this is not the cleanest way, but I wanted it to work quickly for large numbers*/

	int div2check;		//current divisor to check 
	int quotient;		//integer quotient: num / num2check
	int num2add;		//what to add to num2check in the next iteration
	int isPrime = TRUE;	//TRUE until proven FALSE



/* The Algorithm */
	if ((num > 0) && (num < 4))			//is it 1, 2, or 3? If so: PRIME.
		isPrime = TRUE;
	else
	{
		quotient = num / 2;			//check for the two most likely divisors: 2 & 3
		if (num == quotient * 2)
		{
			isPrime = FALSE;
		}//mult of 2
		else						//if not a mult of 2
		{
			quotient = num/3;
			if (num == quotient * 3)
			{
				isPrime = FALSE;
			}//mult of 3
			else					//if not a mult of 3
			{
				div2check = 5;			//initialized at 5, the first prime after 2 & 3 are outruled
				num2add = 2;			//will be switching between 2 and 4, to check 2 out of each 6 numbers as factors
								//that is 5,.,7,.,.,.,11,.,13,.,.,.,17,.19, etc.
				while ((div2check*div2check <= num) && (isPrime == FALSE))
				{
					quotient = num / div2check;
					if (quotient * div2check == num)
						isPrime = FALSE;
					else
					{
						if (num2add == 2)
						{
							num2add = 4;
						}
						else if (num2add == 4)
						{
							num2add = 2;
						}
					}//div2check was not a factor
				}//while loop
			}//else 3
		}//else 2
	}

return (isPrime);
}

//Problem 5)

/**************************************************************************/
/*                        Function perfect			          */
/*                                                                        */
/*  Purpose:  	Returns 1 if the input number is perfect, and 0 if the 	  */
/*		number is not						  */
/*                                                                        */
/*  Parameters: num - Number to check for prime-ness			  */
/*                                                                        */
/*  Returns:    isPerfect						  */
/**************************************************************************/
int perfect (int num)		
{
#define TRUE 1								//increase readability
#define FALSE 0
#define ODD(x) ((x)&1)							//test using bitwise AND 
#define perfect_clever(x) ((x == 6) || (x == 28) || (x == 496) || (x == 8128) || (x == 33550336) || (x == 8589869056)) 	
									//int only allows numbers < 7th perfect number (which is 137438691328)
int isPerfect;
int count = 1;
int quotient;
int total = 0;

/*attempted optimization for speed*/

	if perfect_clever(num)
	{
		isPerfect = TRUE;
	}//if
	else if (num<137438691328)	//This is the 7th Perfect Number: if it is less than this, it has been caught by perfect_clever
	{
		isPerfect = FALSE;
	}//else if
	else if (ODD(num)) 		//Because there exist no odd perfect numbers < 10^1500, and this is a very simple screening mechanism
	{
		isPerfect = FALSE;
	}//esle if
	else				//Fine, I'll do the actual test, because you probably want me to.
	{
		while (count < num)
			{
				quotient = num / count;			//Faster than %
				if (quotient == num * count)
					total += count;

				count ++;
			}//while
		if (total == num)
			isPerfect = TRUE;
		else
			isPerfect = FALSE;
	}//else


return (isPerfect);
}

//Problem 6)

/**************************************************************************/
/*                        Function palindrome			          */
/*                                                                        */
/*  Purpose:     Determines whether a string is a palindrome              */
/*                                                                        */
/*  Parameters: s - Input string, check					  */
/*                                                                        */
/*  Returns:    isPalindrome - 1 = True, 0 = False			  */
/**************************************************************************/
//I wasn't sure if I could use strlen, strcmp, etc, so I did it from scratch

int palindrome (char * s)
{
	#define TRUE 1			//making it readable
	#define FALSE 0
	#define EOS '\0'

	int is_palindrome;	
	int length;		
	int ctr;
	int ctrReverse;
	
	ctr = 0;

	while (s[ctr] != EOS)		//How long is the string?
	{
		ctr++;
	}

	length = ctr;	

	char reverseString [length];	//initialize a new variable, to put the string's reverse into

	ctr = 0;			//reset
	ctrReverse = length - 1;

	while (ctr < length )		//create a reverse of the input string, s
	{
		reverseString [ctrReverse] = s[ctr];
		ctr++;
		ctrReverse--;
	}
	
	ctr = 0;			//reset
	is_palindrome = TRUE;	

	while ((ctr < length) && (is_palindrome == TRUE))	//compare the two strings until proven wrong
	{
		if (toupper(s[ctr]) == toupper(reverseString[ctr]))
			ctr++;
		else
			is_palindrome = FALSE;
	}
	return (is_palindrome);
}



//Problem 7

struct stringData
{
	int strLength;
	int numUpper;
	int numLower;
	int numDigit;
	int nonAlphaNumeric;
};

/**************************************************************************/
/*                        Function stringCalc			          */
/*                                                                        */
/*  Purpose:     Determines 	1) string length (use strlen),		  */
/*     				2) number of upper case characters, 	  */
/*				3) number of lower case characters,	  */
/*     				4) number of digits, and 		  */
/*				5) number of non-alphanumeric characters. */
/*                                                                        */
/*  Parameters: s - Input string, to process				  */
/*                                                                        */
/*  Returns:    info							  */
/**************************************************************************/
struct stringData stringCalc (char * s)
{
	struct stringData info;
	int UpperCt = 0;
	int LowerCt = 0;
	int NumberCt = 0;
	int OtherCt = 0;
	int ctr = 0;		//initialized

	while (s[ctr] != '\0')
	{
		if ((s[ctr] >= 48) && (s[ctr] <= 57))
			NumberCt++;
		else if ((s[ctr] >= 65) && (s[ctr] <= 90))
			UpperCt++;
		else if ((s[ctr] >= 97) && (s[ctr] <= 122))
			LowerCt++;
		else 
			OtherCt++;

		ctr++;
	}

/* Assign values to struct */

	info.strLength = ctr;
	info.numUpper = UpperCt;
	info.numLower = LowerCt;
	info.numDigit = NumberCt;
	info.nonAlphaNumeric = OtherCt;

	return(info);
}

//Problem 8

struct playerStats
	{
		int totalBases;
		float battingAvg;
		float homeRunRatio;
		float sluggingAvg;
	};
/**************************************************************************/
/*                        Function calculateStats		          */
/*                                                                        */
/*  Purpose:     Determines 	Total Bases, Batting Average, 		  */
/*				Home Run Ration, Slugging Average	  */
/*                                                                        */
/*  Parameters: singles, doubles, triples, hrs, atBats			  */
/*                                                                        */
/*  Returns:    currentPlayer						  */
/**************************************************************************/
struct playerStats calculateStats (int singles, int doubles, int triples, int hrs, int atBats)
{
	struct playerStats currentPlayer;
	float hits;

	hits = singles + doubles + triples + hrs;

	currentPlayer.totalBases = singles + (2 * doubles) + (3 * triples) + (4 * hrs);
	currentPlayer.battingAvg = hits / atBats;
	currentPlayer.homeRunRatio = hrs / atBats;
	currentPlayer.sluggingAvg = currentPlayer.totalBases / atBats;

return (currentPlayer);
}
//Problem 9

struct person
{
	char firstName [20];
	char lastName  [20];
	
	struct person *next;
};

struct date
{
	int month;
	int day;
	int year;
};
 
struct movie
{
	char title [50];
	struct person director;
	struct person producer;
	struct person screenwriter;
	struct person stars;
	struct date releaseDate;
	float runTime;
	char language [20];
	char maturityRating [4];
	float ratingOutOfTen;
};
