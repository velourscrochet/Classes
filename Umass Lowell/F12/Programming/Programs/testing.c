#include <stdio.h>

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



void main()
{
	struct playerStats a=calculateStats(3,4,5,1,20);
	printf("\t%i,%f,%f,%f\n",a.totalBases,a.battingAvg,a.homeRunRatio,a.sluggingAvg);
}