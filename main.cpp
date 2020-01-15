#include "Point2D.h"
#include "View.h"
#include "Model.h"
#include "GameCommand.h"
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <ctime>
#include <fstream>
#include "Input_Handling.h"

using namespace std;

//Function prototypes
bool IsNumber(string s);
bool IsWhiteSpace(string s);

const string POKEMON_BANNER = "                                  ,'\\\n"
                              "    _.----.        ____         ,'  _\\   ___    ___     ____\n"
                              "_,-'       `.     |    |  /`.   \\,-'    |   \\  /   |   |    \\  |`.\n"
                              "\\      __    \\    '-.  | /   `.  ___    |    \\/    |   '-.   \\ |  |\n"
                              " \\.    \\ \\   |  __  |  |/    ,','_  `.  |          | __  |    \\|  |\n"
                              "   \\    \\/   /,' _`.|      ,' / / / /   |          ,' _`.|     |  |\n"
                              "    \\     ,-'/  /   \\    ,'   | \\/ / ,`.|         /  /   \\  |     |\n"
                              "     \\    \\ |   \\_/  |   `-.  \\    `'  /|  |    ||   \\_/  | |\\    |\n"
                              "      \\    \\ \\      /       `-.`.___,-' |  |\\  /| \\      /  | |   |\n"
                              "       \\    \\ `.__,'|  |`-._    `|      |__| \\/ |  `.__,'|  | |   |\n"
                              "        \\_.-'       |__|    `-._ |              '-.|     '-.| |   |\n"
                              "                                `'                            '-._|";
// TODO: Add help menu
int main(int argc, char** argv) {
    // Welcome Message
    cout << "EC327: Introduction to Software Engineering" << endl;
    cout << "Fall 2019" << endl;
    cout << "Programming Assignment 4" << endl;
    cout << POKEMON_BANNER << endl;
    //constructing the game model
    Model game_model;
    View game_view;
      bool error;

    bool game_is_running = true;

    bool read_from_file = false;
    game_model.ShowStatus();
    game_model.Display(game_view);
    ifstream input_file;
    if (argc == 2) {
        input_file.open(argv[1], ios_base::in);
        if (!input_file.is_open()) {
            cout << "Failed to open input file " << argv[1] << endl;
            exit(EXIT_FAILURE);
        }
        read_from_file = true;
        srand(0);
    } else
        srand(time(NULL));

    while (game_is_running) {
        cout << "Enter command: ";
        char command = 'a';
        int id = 0;
        int id1 = 0;
        int id2 = 0;
        bool error = false;
        string input = "'";
        double x = 0;
        double y = 0;
        unsigned int stamina_amount = 0;
        unsigned int training_unit_amount = 0;
        if (read_from_file) {
            getline(input_file, input);
        } else{
            getline(cin, input);
          }
        if (input.length() > 0 and !IsWhiteSpace(input))
            istringstream iss(input);
            vector<string> tokens;
            //copy(istream_iterator<string>(iss,
                // istream_iterator<string>(),
                 //back_inserter<vector<string> >(tokens));

            if (tokens[0].length() == 1)
                command = tokens[0][0];

            else{
                error = true;
              }
while(command != 'q')
{
	try
	{
		switch (command)
		{
		case 'm':
		{
			if (!(cin >> id))
			{
				throw Invalid_Input("Need an integer for ID");
			}
			if (!(cin >> x))
			{
				throw Invalid_Input("Need a double for coordinate x");
			}
			if (!(cin >> y))
			{
				throw Invalid_Input("Need a double for coordinate y");
			}
			DoMoveCommand(game_model, id, Point2D(x, y));
			game_model.Display(game_view);
			break;
		}


		case 'c':
		{
			if (!(cin >> id))
			{
				throw Invalid_Input("Need an integer for ID");
			}
			if (!(cin >> id2))
			{
				throw Invalid_Input("Need an integer for ID");
			}
			DoMoveToCenterCommand(game_model, id, id2);
			game_model.Display(game_view);
			break;
		}

		case 'g':
		{
			if (!(cin >> id))
			{
				throw Invalid_Input("Need an integer for ID");
			}
			if (!(cin >> id2))
			{
				throw Invalid_Input("Need an integer for ID");
			}
			DoMoveToGymCommand(game_model, id, id2);
			game_model.Display(game_view);
			break;
		}


		case 'r':
		{
			if (!(cin >> id))
			{
				throw Invalid_Input("Need an integer for ID");
			}
			if (!(cin >> id2))
			{
				throw Invalid_Input("Need an integer for ID");
			}
			DoRecoverInCenterCommand(game_model, id, stamina_amount);
			game_model.Display(game_view);
			break;
		}


		case 't':
		{
			if (!(cin >> id))
			{
				throw Invalid_Input("Need an integer for ID");
			}
			if (!(cin >> training_unit_amount))
			{
				throw Invalid_Input("Need an integer for the amount of Training Units");
			}
			DoTrainInGymCommand(game_model, id, training_unit_amount);
			game_model.Display(game_view);
			break;
		}


		case 's':
		{
			if (!(cin >> id))
			{
				throw Invalid_Input("Need an integer for ID");
			}
			DoStopCommand(game_model, id);
			game_model.Display(game_view);
			break;
		}

		case 'v':
		{
      DoGoCommand()
			if (!(cin >> DoGoCommand)
			{
				throw Invalid_Input("Need valid inputs for DoGoCommand");
			}
			break;
		}

		case 'x':
		{
      DoRunComannd()
			if (!(cin >> DoRunCommand)
			{
				throw Invalid_Input("Need valid inputs for DoRunCommand");
			}
			break;
		}

		case 'q':
		{
			break;
		}
    default:
        error = true;
        break;
		}
	}
}
        if (error)
        {
            cout << "ERROR: Please enter a valid command!" << endl;
    }
    else
    {
        error = true;
    }
    return 0;
}

bool IsNumber(string s){
    for(int i = 0; i < s.length(); i++) {
        if(!(s[i] >= '0' && s[i] <= '9')) {
            return false;
        }
    }
    return true;
}

bool IsWhiteSpace(string s){
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != ' ' && s[i] != '\t') {
            return false;
        }
    }

    return true;
}
