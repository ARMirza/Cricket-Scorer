#include<iostream>
#include <stdlib.h>


class CricketMatch
{
    private:
        int totalRuns, overs, outs, fours, sixes, wides, noBalls;
        float runRate;
        std::string teamName;
    public:
        CricketMatch();
        friend void setValues(CricketMatch*, CricketMatch*);
        void startInnings();
        void totalTeamScore(char, int*);
        void runRates( float*, int, int*);
        friend void displayWinner(CricketMatch, CricketMatch);
        friend void displaySummary(CricketMatch, CricketMatch);
        friend void batFirst(CricketMatch);
};
