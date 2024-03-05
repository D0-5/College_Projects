#include "CFootballTeam.h"

CFootballTeam::CFootballTeam(void)
{
}

CFootballTeam::CFootballTeam(string team)
    : m_Team(team)
    , m_gamesPlayed(0)
    , m_Points(0)
    , m_goalsAgainst(0)
    , m_goalsFor(0)
{
}

CFootballTeam::CFootballTeam(string team, int points, int gamesPlayed, int getGoalsfor, int getGoalsAgainst)

    : m_Team(team)
    , m_gamesPlayed(gamesPlayed)
    , m_Points(points)
    , m_goalsAgainst(getGoalsAgainst)
    , m_goalsFor(getGoalsfor)
{
}

string CFootballTeam::GetName(void)
{
    return m_Team;
}

int CFootballTeam::GetGamesPlayed(void)
{
    return m_gamesPlayed;
}

int CFootballTeam::GetGoalsFor(void)
{
    return m_goalsFor;
}

int CFootballTeam::GetGoalsAgainst(void)
{
    return m_goalsAgainst;
}

int CFootballTeam::GetPoints(void)
{
    return m_Points;
}

int CFootballTeam::GetNumOfTeams(void)
{
    return m_numofTeams;
}

int CFootballTeam::GetMatchResult(void)
{
    return m_finalResult;
}

void CFootballTeam::SetMatchResult(int result)
{
    m_matchResult = result;
}
void CFootballTeam::UpdateOnResult(int homeScore, int awayScore)
{
	m_gamesPlayed++;
	m_goalsFor += homeScore;
	m_goalsAgainst += awayScore;

	// Determine the match result and update points accordingly
	if (homeScore > awayScore)
	{
		// Team 1 wins
		m_Points += 3;
	}
	else if (homeScore < awayScore)
	{
		// Team 2 wins
		m_Points += 1;
	}
	else
	{
		// Draw
		m_Points += 2;
	}
}

void CFootballTeam::IncrementGoalsFor(int score)
{
    m_goalsFor += score;
}

void CFootballTeam::IncrementGoalsAgainst(int score)
{
    m_goalsAgainst += score;
}

void CFootballTeam::IncrementPointsFor(int points)
{
    m_pointsFor += points;
}

void CFootballTeam::IncrementPointsAgainst(int points)
{
    m_pointsAgainst += points;
}

char CFootballTeam::DoInitializeTeam(void)
{
    return m_initTeam;
}

string CFootballTeam::DoDisplayLeague(void)
{
    return m_displayLeague;
}

int CFootballTeam::DoEnterMatchResult(void)
{
    return m_matchResult;
}

int CFootballTeam::DoDeductPoints(void)
{
    return m_dedPoints;
}

char CFootballTeam::DoBestDefence(void)
{
    return m_bestDef;
}

char CFootballTeam::DoRelegationZone(void)
{
    return m_relZone;
}

void CFootballTeam::DoAddTeamToList(void)
{
}

string CFootballTeam::DoRemoveTeam(void)
{
    return m_removeTeam;
}
