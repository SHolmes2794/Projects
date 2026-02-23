// Soccer Tournament Management System.cpp 
// Created by: Samuel Holmes        Last Edited: 2/23/26

#include <iostream>
#include <string>
using namespace std;

//--------------------------
// Declare Enums and Structs
//--------------------------

enum match_result { win, loss, draw };

struct player
{
    int player_id;
    string player_name;
    int goals_scored;
};

struct team
{
    string team_name;
    player players[4];
    match_result results[3];
};

//----------------------
// Function Declarations
//----------------------

void input_players(player league_players[][4], int team_count, int players_per_team);
void build_teams(team teams[], const player league_players[][4], int team_count, int players_per_team);
void input_results(team teams[], int team_count, int match_count);
void display_report(const team teams[], int team_count, int players_per_team, int match_count);

//===============================//
//         Main Function         //
//===============================//

int main()
{
    // Declare Constants
    const int team_count = 3;
    const int players_per_team = 4;
    const int match_count = 3;

    // Declare Arrays
    player league_players[team_count][players_per_team];
    team teams[team_count];

    // Input Team Names
    for (int index = 0; index < team_count; index++)
    {
        cout << "Enter Team " << index + 1 << " name: ";
        cin >> teams[index].team_name;
    }
    cout << endl;

    // Input Players
    input_players(league_players, team_count, players_per_team);

    // Build Teams
    build_teams(teams, league_players, team_count, players_per_team);

    // Input Results
    input_results(teams, team_count, match_count);

    // Display Report
    display_report(teams, team_count, players_per_team, match_count);

    return 0;
}

//---------------------
// Function Definitions
//---------------------

void input_players(player league_players[][4], int team_count, int players_per_team)
{
    // Input Player Data
    
    // Outer Loop - Per Team
    for (int team = 0; team < team_count; team++)
    {
        cout << "--- Enter Players for Team " << team + 1 << " ---" << endl;
        // Inner Loop - Per Player
        for (int player = 0; player < players_per_team; player++)
        {
            cout << "Player ID: ";
            cin >> league_players[team][player].player_id;
            cout << "Player Name: ";
            cin >> league_players[team][player].player_name;
            cout << "Goals Scored: ";
            cin >> league_players[team][player].goals_scored;
        }
        cout << endl;
    }
}

void build_teams(team teams[], const player league_players[][4], int team_count, int players_per_team)
{
    // Copy Players into Team Structure

    // Outer Loop - Per Team
    for (int team = 0; team < team_count; team++)
    {
        // Inner Loop - Per Player
        for (int player = 0; player < players_per_team; player++)
        {
            teams[team].players[player] = league_players[team][player];
        }
    }
}

void input_results(team teams[], int team_count, int match_count)
{
    // Input Match Results for Teams
    
    // Outer Loop - Per Team
    for (int team = 0; team < team_count; team++)
    {
        cout << "--- Enter Results for " << teams[team].team_name << " ---" << endl;
        // Inner Loop - Per Match
        for (int match = 0; match < match_count; match++)
        {
            int result_number;
            do {
                cout << "Match " << match + 1 << " (0-Win,1-Loss,2-Draw): ";
                cin >> result_number;
            } while (result_number < 0 || result_number > 2);

            switch (result_number)
            {
                case 0:
                    teams[team].results[match] = win;
                    break;
                case 1:
                    teams[team].results[match] = loss;
                    break;
                case 2:
                    teams[team].results[match] = draw;
                    break;
                default:
                    cout << "Error: Unknown. Match reported as draw" << endl;
                    teams[team].results[match] = draw;
                    break;
            }
        }
        cout << endl;
    }
}

void display_report(const team teams[], int team_count, int players_per_team, int match_count)
{
    // Display Total Data in Report
    cout << "\n============ SOCCER TOURNAMENT REPORT ============" << endl;

    // Declare Variables for Winning Team
    string winning_team_name;
    int winning_team_total_points = 0;
    int winning_team_total_goals = 0;

    // Outer Loop - Per Team
    for (int team = 0; team < team_count; team++)
    {
        cout << "Team: " << teams[team].team_name << endl;
        cout << "Players: " << endl;

        // Inner Loop - Per Player - Print Player Data
        for (int player = 0; player < players_per_team; player++)
        {
            cout << teams[team].players[player].player_id << " ";
            cout << teams[team].players[player].player_name << " - ";
            cout << "Goals: " << teams[team].players[player].goals_scored << endl;
        }

        // Calculate and Print Total Goals - Inner Loop - Per Player
        int total_goals = 0;
        for (int player = 0; player < players_per_team; player++)
        {
            total_goals += teams[team].players[player].goals_scored;
        }
        cout << "Total Goals: " << total_goals << endl;

        // Calculate and Print Total Points - Inner Loop - Per Match Result
        int total_points = 0;
        for (int result = 0; result < match_count; result++)
        {
            if (teams[team].results[result] == win)
            {
                total_points += 3;
            }
            else if (teams[team].results[result] == draw)
            {
                total_points += 1;
            }
        }
        cout << "Total Points: " << total_points << endl;
        cout << "------------------------" << endl << endl;

        // Update Winning Team (if Applicable)
        if (total_points > winning_team_total_points)       // If Team Observed has higher than Current Winning Team
        {
            winning_team_name = teams[team].team_name;
            winning_team_total_points = total_points;
            winning_team_total_goals = total_goals;
        }
        else if (total_points == winning_team_total_points) // If Team Observed has same amount as Current Winning Team
        {
            if (total_goals > winning_team_total_goals)     // Tiebreaker: Total Goals
            {
                winning_team_name = teams[team].team_name;
                winning_team_total_points = total_points;
                winning_team_total_goals = total_goals;
            }
        }
    }

    cout << "Tournament Winner: " << winning_team_name << endl;
    cout << "Points: " << winning_team_total_points << " | Goals: " << winning_team_total_goals << endl;
}