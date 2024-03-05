#include "CFootballTeam.h"

CFootballTeam list[25];
int numTeams = 0;
const int RELEGATION_THRESHOLD = 15;  // Adjust the value based on your criteria
const string PASSWORD = "password";  // Add your own password

// Function declarations
int ShowMenu();
void DoInitializeTeam();
void DoDisplayLeague();
void DoEnterMatchResult();
int DoDeductPoints();
char DoBestDefence();
void DoRelegationZone();
void DoAddTeamToList();
void DoRemoveTeam();

int main()
{
    string enteredPassword;
    int attempts = 0;

    do
    {
        cout << "Enter password: ";
        cin >> enteredPassword;
        attempts++;

        if (enteredPassword != PASSWORD)
        {
            cout << "Incorrect password. Attempts remaining: " << 3 - attempts << endl;
        }

    } while (enteredPassword != PASSWORD && attempts < 3);

    if (enteredPassword != PASSWORD)
    {
        cout << "Too many incorrect attempts. Exiting program." << endl;
        return 1;
    }
    system("CLS");

    ifstream infile("teamInfo.dat");
    if (!infile)
    {
        cout << "Database file teamInfo.dat does not exist\n";
        cout << "You should use Add teams to add 25 teams to the list \n\n";
    }
    else
    {
        infile >> numTeams;

        for (int i = 0; i < numTeams; i++)
        {
            string team;
            int gamesPlayed, goalsFor, goalsAgainst, points;
            infile >> team >> gamesPlayed >> goalsFor >> goalsAgainst >> points;

            // Create CFootballTeam object with read data and assign to list
            list[i] = CFootballTeam(team, points, gamesPlayed, goalsFor, goalsAgainst);
        }
    }

    // DISPLAY USER INTERFACE
    int option;
    do
    {
        option = ShowMenu();
        switch (option)
        {
        case 1:
            DoInitializeTeam();
            break;
        case 2:
            DoDisplayLeague();
            break;
        case 3:
            DoEnterMatchResult();
            break;
        case 4:
            DoDeductPoints();
            break;
        case 5:
            DoBestDefence();
            break;
        case 6:
            DoRelegationZone();
            break;
        case 7:
            DoAddTeamToList();
            break;
        case 8:
            DoRemoveTeam();
            break;
        case 0:
            break;
        default:
            cout << "Invalid option\n";
        }

        system("PAUSE");
        system("CLS");

    } while (option != 0);

    if (numTeams > 0)
    {
        ofstream outfile("teamInfo.dat");
        if (!outfile)
        {
            cerr << "Error opening output file." << endl;
            return 1;  // Return an error code
        }

        outfile << numTeams << endl;

        for (int i = 0; i < numTeams; i++)
        {
            outfile << list[i].GetName() << " "
                << list[i].GetGamesPlayed() << " "
                << list[i].GetGoalsFor() << " "
                << list[i].GetGoalsAgainst() << " "
                << list[i].GetPoints() << endl;
        }

        outfile.close();
        cout << "Data saved to teamInfo.dat" << endl;
    }
    else
    {
        cout << "No data to save." << endl;
    }

    return 0;
}

int ShowMenu(void)
{
	int option;
	cout << "\n\t      ** FOOTBALL LEAGUE MANAGEMENT ** \n";
	cout << "\t-----------------------------------------\n";
	cout << "\t:| 1.  Initialize Team List            |:\n";
	cout << "\t:| 2.  Display League Table            |:\n";
	cout << "\t:| 3.  Enter a Match Result            |:\n";
	cout << "\t:| 4.  Deduct Points                   |:\n";
	cout << "\t:| 5.  Best Defence                    |:\n";
	cout << "\t:| 6.  Relegation Zone                 |:\n";
	cout << "\t:| 7.  Add Team to List                |:\n";
	cout << "\t:| 8.  Remove Team from list           |:\n";
	cout << "\t:| 0.  Quit                            |:\n";
	cout << "\t----------------------------------------\n";
	cout << "\nEnter your choice: ";

	cin >> option;
	return option;
}

void DoInitializeTeam(void)
{
    if (numTeams > 0)
    {
        char clearChoice;
        cout << "A team list is already initialized. Do you want to clear the existing list and start over? (Y/N): ";
        cin >> clearChoice;

        if (toupper(clearChoice) == 'Y')
        {
            // Clear the existing team list
            numTeams = 0;
            cout << "Existing team list cleared.\n";
        }
        else
        {
            cout << "Existing team list preserved.\n";
            return;  // If the user chooses not to clear the list, exit the function
        }
    }

    cout << "\nEnter the number of teams to initialize: ";
    int newTeams;
    cin >> newTeams;

    for (int i = numTeams; i < numTeams + newTeams; ++i)
    {
        if (i >= 25)
        {
            cout << "Maximum team limit reached." << endl;
            break;
        }

        string teamName;
        cout << "Enter name for team " << (i + 1) << ": ";
        cin >> teamName;

        // Initialize other team parameters as needed
        list[i] = CFootballTeam(teamName, 0, 0, 0, 0);
    }

    numTeams += newTeams;
    cout << "Team list updated. Total teams: " << numTeams << endl;
}


void DoDisplayLeague(void)
{
    if (numTeams == 0) {
        cout << "No teams in the league." << endl;
    }
    else
    {
        cout << left << setw(20) << "Team Name"
            << setw(15) << "Games Played"
            << setw(15) << "Goals For"
            << setw(15) << "Goals Against"
            << setw(10) << "Points" << endl;

        for (int i = 0; i < numTeams; i++)
        {
            cout << left << setw(20) << list[i].GetName()
                << setw(15) << list[i].GetGamesPlayed()
                << setw(15) << list[i].GetGoalsFor()
                << setw(15) << list[i].GetGoalsAgainst()
                << setw(10) << list[i].GetPoints() << endl;
        }
    }
}

int DoDeductPoints()
{
    if (numTeams == 0)
    {
        cout << "No teams in the league." << endl;
        return 0;
    }

    cout << "\nEnter the index of the team to deduct points from (1 to " << numTeams << "): ";
    int teamIndex;
    cin >> teamIndex;

    if (teamIndex < 1 || teamIndex > numTeams)
    {
        cout << "Invalid team index." << endl;
        return 0;
    }

    cout << "Enter the number of points to deduct: ";
    int points;
    cin >> points;

    // Deduct points from the specified team
    list[teamIndex - 1].SetMatchResult(list[teamIndex - 1].GetMatchResult() - points);

    cout << "Points deducted from team '" << list[teamIndex - 1].GetName() << "'." << endl;

    return 0;
}

void DoEnterMatchResult()
{
    if (numTeams == 0)
    {
        cout << "No teams in the league." << endl;
        return;
    }

    string homeTeam, awayTeam;
    int homeScore, awayScore;

    cout << "Enter the Home Team Name: ";
    cin >> homeTeam;

    cout << "Enter " << homeTeam << "'s Score: ";
    cin >> homeScore;

    cout << "Enter the Away Team Name: ";
    cin >> awayTeam;

    cout << "Enter " << awayTeam << "'s Score: ";
    cin >> awayScore;

    // Find and update the home team
    for (int i = 0; i < numTeams; ++i)
    {
        if (list[i].GetName() == homeTeam)
        {
            list[i].UpdateOnResult(homeScore, awayScore);
        }
    }

    // Find and update the away team
    for (int i = 0; i < numTeams; ++i)
    {
        if (list[i].GetName() == awayTeam)
        {
            list[i].UpdateOnResult(awayScore, homeScore);
        }
    }

    cout << "-----Match result updated for teams----- \n\n";
    cout << "Home Side: " << homeTeam << ", Home Score: " << homeScore << endl;
    cout << "Away Side: " << awayTeam << ", Away Score: " << awayScore << endl;

    // Save the changes to the "teamInfo.dat" file
    ofstream outfile("teamInfo.dat");
    if (!outfile)
    {
        cerr << "Error opening output file." << endl;
        return; // Return an error code
    }

    outfile << numTeams << endl;

    for (int i = 0; i < numTeams; i++)
    {
        outfile << list[i].GetName() << " "
            << list[i].GetMatchResult() << " "
            << list[i].GetGamesPlayed() << " "
            << list[i].GetGoalsFor() << " "
            << list[i].GetGoalsAgainst() << " "
            << list[i].GetPoints() << endl;
    }
    outfile.close();
}
char DoBestDefence(void)
{
	int bestDefIndex = -1;
	int leastGoalsAgainst = INT_MAX;

	for (int i = 0; i < numTeams; i++)
	{
		if (list[i].GetGoalsAgainst() < leastGoalsAgainst)
		{
			leastGoalsAgainst = list[i].GetGoalsAgainst();
			bestDefIndex = i;
		}
	}

	if (bestDefIndex != -1)
	{
		cout << "Best defense: " << list[bestDefIndex].GetName() << "  " << leastGoalsAgainst << " Goals conceded" << endl;
	}
	else
	{
		cout << "No Data" << endl;
	}
    return '0'; 
}

void DoRelegationZone(void)
{
    //if <= 3 teams, code will not show relegation zone
	if (numTeams <= 3)
    {
		cout << "Not enough teams for relegation zone. Add more teams to the league.\n";
		return;
	}

	//sorting based on points
	for (int i = 0; i < numTeams - 1; ++i)
    {
		for (int j = 0; j < numTeams - i - 1; ++j)
        {
			if (list[j].GetPoints() < list[j + 1].GetPoints()) 
            {
				// Swap teams
				CFootballTeam temp = list[j];
				list[j] = list[j + 1];
				list[j + 1] = temp;
			}
		}
	}
	// Display the names and points of the last three teams
	cout << "Relegation Zone - Last Three Teams\n";
	for (int i = numTeams - 3; i < numTeams; ++i) 
    {
		cout << "Team: " << list[i].GetName() << ", Points: " << list[i].GetPoints() <<endl;
	}
}

void DoAddTeamToList(void)
{
    if (numTeams >= 25)
    {
        cout << "The team list is full. Cannot add more teams." << endl;
        return;
    }

    string teamName;
    cout << "Enter the name of the new team: ";
    cin >> teamName;

    // Assuming the rest of the data is initialized to some default value
    list[numTeams] = CFootballTeam(teamName, 0, 0, 0, 0);
    numTeams++;

    cout << "Team '" << teamName << "' added to the list." << endl;
}

void DoRemoveTeam(void)
{
    if (numTeams == 0)
    {
        cout << "The team list is empty. There are no teams to remove." << endl;
        return;
    }

    string teamName;
    cout << "Enter the name of the team to remove: ";
    cin >> teamName;

    bool found = false;
    for (int i = 0; i < numTeams; i++)
    {
        if (list[i].GetName() == teamName)
        {
            // Shift all elements to the left
            for (int j = i; j < numTeams - 1; j++)
            {
                list[j] = list[j + 1];
            }
            numTeams--;
            cout << "Team '" << teamName << "' has been removed from the list." << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Team '" << teamName << "' not found in the list." << endl;
    }
}
