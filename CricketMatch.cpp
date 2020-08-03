#include<iostream>
#include"CricketMatch.h"
CricketMatch::CricketMatch()
{
    totalRuns=0;
    overs=0;
    outs=0;
    fours=0;
    sixes=0;
    wides=0;
    noBalls=0;
    runRate=0.0;
    teamName = " ";
}

void setValues(CricketMatch *tm1, CricketMatch *tm2)
{
    std::cout<<"Enter the name of team who is batting first: ";
    std::cin>>tm1->teamName;
    std::cout<<"Enter the name of team who is bowling: ";
    std::cin>>tm2->teamName;
    std::cout<<"Enter the number of overs you want to play for: ";
    std::cin>>tm1->overs;
    tm2->overs = tm1->overs;
}

void CricketMatch::startInnings()
{
    int j=0, outs=0, i=0, scorer=0;
    char runs;
    std::cout<<"\n\nslect the following as according to the if:\n1-run: '1'\n2-runs: '2'\n3-runs: '3'\n4-runs: '4'\n6-runs: '6'\nWide: 'w'\nWicket: 'o'\nNo-Ball: 'n'\n";
    while(j != overs && outs<10)
			{
				i=0;
				while(i<6 && outs<10)
				{
					std::cout<<"\nEnter the runs on ball "<<j<<"."<<i<<": ";
					std::cin>>runs;
					switch(runs)
					{
						case '1':
							totalTeamScore(runs, &scorer);

							break;

						case '2':
							totalTeamScore(runs, &scorer);

							break;

						case '3':
							totalTeamScore(runs, &scorer);

							break;

						case '4':
							totalTeamScore(runs, &scorer);
							fours++;

							break;

						case '6':
							totalTeamScore(runs, &scorer);
							sixes++;
							break;

						case 'o':
							outs++;
							break;

						case 'w':
							wides++;
							while(runs == 'w' || runs == 'n')
							{
								totalTeamScore(runs, &scorer);
								std::cout<<"\nEnter the runs on ball "<<j<<"."<<i<<": ";
                                std::cin>>runs;
								if(runs == 'w')
								{
									wides++;
								}
								else if(runs == 'n')
								{
									noBalls++;
								}
							}

							break;

						case 'n':
							noBalls++;
							while(runs == 'n' || runs == 'w')
							{
								totalTeamScore(runs, &scorer);
								std::cout<<"\nEnter the runs on ball "<<j<<"."<<i<<": ";
                                std::cin>>runs;
								if(runs == 'w')
								{
									wides++;
								}
								else if(runs == 'n')
								{
									noBalls++;
								}
							}
							break;
					}
					i++;
				}
				j++;
				runRates(&runRate,j,&scorer);
				std::cout<<"\n\nScore In "<<j<<" overs: "<<scorer<<"\n\n";
				std::cout<<"outs In "<<j<<" overs: "<<outs<<"\n\n";
				std::cout<<"run rate In "<<j<<" overs: "<<runRate<<"\n\n";
			}
			totalRuns = scorer;
}

void CricketMatch::totalTeamScore(char run, int *scorer)
{
	switch(run)
	{
		case '1':
		*scorer = *scorer + 1;
		break;

		case '2':
		*scorer = *scorer + 2;
		break;

		case '3':
		*scorer = *scorer + 3;
		break;

		case '4':
		*scorer = *scorer + 4;
		break;

		case '6':
		*scorer = *scorer + 6;
		break;

		case 'w':
		*scorer = *scorer + 1;
		break;

		case 'n':
		*scorer = *scorer + 1;
		break;
	}
}

void CricketMatch::runRates( float *runRate,int over,int *scorer)
{

		*runRate=(float)*scorer/(over);

}

void displayWinner(CricketMatch tm1, CricketMatch tm2)
{
    if(tm1.totalRuns>tm2.totalRuns)
	{
		std::cout<<"\n\t\t\t"<<tm1.teamName<<" won the Match!!!";
	}
	else if(tm2.totalRuns>tm1.totalRuns)
	{
		std::cout<<"\n\t\t\t"<<tm2.teamName<<" won the Match!!!";
	}
	else
	{
		std::cout<<"\n\t\t\t  The match is draw!!!";
	}
}

void batFirst(CricketMatch tm)
{
   std::cout<<"\t\t\t\t"<<tm.teamName<<" to Bat Now\n";
}

void displaySummary(CricketMatch tm1, CricketMatch tm2)
{
    std::cout<<"\n\n\t\t\t\t"<<tm1.teamName<<" stats";
    std::cout<<"\n score: "<<tm1.totalRuns<<"\n wickets: "<<tm1.outs<<"\n run rate: "<<tm1.runRate<<"\n";
	std::cout<<" fours: "<<tm1.fours<<"\n sixes: "<<tm1.sixes<<"\n wides: "<<tm1.wides<<"\n No-Balls: "<<tm1.noBalls;
	std::cout<<"\n\n\n";
	std::cout<<"\n\n\t\t\t\t"<<tm2.teamName<<" stats";
	std::cout<<"\n score: "<<tm2.totalRuns<<"\n wickets: "<<tm2.outs<<"\n run rate: "<<tm2.runRate<<"\n";
	std::cout<<" fours: "<<tm2.fours<<"\n sixes: "<<tm2.sixes<<"\n wides: "<<tm2.wides<<"\n No-Balls: "<<tm2.noBalls;
}