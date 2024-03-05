#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <windows.h>

using namespace std;

class CFootballTeam
{
private:
    string m_Team;
    int m_gamesPlayed;
    int m_goalsFor;
    int m_goalsAgainst;
    int m_Points;
    int m_pointsFor;
    int m_pointsAgainst;
    int m_dedPoints;
    int m_matchResult;
    int m_numofTeams;
    int m_finalResult;
    char m_initTeam;
    string m_displayLeague;
    char m_bestDef;
    char m_relZone;
    string m_removeTeam;

public:
    CFootballTeam(void);
    CFootballTeam(string team);
    CFootballTeam(string team, int points, int gamesPlayed, int getGoalsfor, int getGoalsAgainst);

    string GetName(void);
    int GetGamesPlayed(void);
    int GetGoalsFor(void);
    int GetGoalsAgainst(void);
    int GetPoints(void);
    int GetNumOfTeams(void);
    int GetMatchResult(void);

    void SetMatchResult(int result);
    void UpdateOnResult(int homeScore, int awayScore);
    void IncrementGoalsFor(int score);
    void IncrementGoalsAgainst(int score);
    void IncrementPointsFor(int points);
    void IncrementPointsAgainst(int points);

    char DoInitializeTeam(void);
    string DoDisplayLeague(void);
    int DoEnterMatchResult(void);
    int DoDeductPoints(void);
    char DoBestDefence(void);
    char DoRelegationZone(void);
    void DoAddTeamToList(void);
    string DoRemoveTeam(void);
};
