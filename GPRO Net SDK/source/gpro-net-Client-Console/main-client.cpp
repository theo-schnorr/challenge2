/*
   Copyright 2021 Daniel S. Buckstein

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

	   http://www.apache.org/licenses/LICENSE-2.0

	Unless required by applicable law or agreed to in writing, software
	distributed under the License is distributed on an "AS IS" BASIS,
	WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
	See the License for the specific language governing permissions and
	limitations under the License.
*/

/*
	GPRO Net SDK: Networking framework.
	By Daniel S. Buckstein

	main-client.cpp
	Main source for console client application.
*/

#include "gpro-net/gpro-net-client/gpro-net-RakNet-Client.hpp"

#include "gpro-net/gpro-net.h"

#include "../gpro-net-Client-Plugin/gpro-net-Client-Plugin.h"

#include <string>
#include <iostream>

#if (defined _WINDOWS || defined _WIN32)

//#include <Windows.h>
#pragma comment(lib, "gpro-net-Client-Plugin.lib")

// complete plugin test
int testPlugin()
{
	//HMODULE plugin = LoadLibrary(TEXT("./plugin/gpro-net-Client-Plugin"));
	//if (plugin)
	{
		printf("%d \n", foo(9000));

		// done
		//return FreeLibrary(plugin);
		return 1;
	}
	return -1;
}

#else	// !(defined _WINDOWS || defined _WIN32)

// dummy plugin test
int testPlugin()
{
	return -1;
}

#endif	// (defined _WINDOWS || defined _WIN32)


// utility test (game states, console)
int testUtility()
{
	gpro_battleship battleship;
	gpro_checkers checkers;
	gpro_mancala mancala;

	gpro_battleship_reset(battleship);
	gpro_checkers_reset(checkers);
	gpro_mancala_reset(mancala);

	return gpro_consoleDrawTestPatch();
}

/* SPECIAL MESSAGE ID */
// Leave game message
// Enter game message

bool inGame = false;

int main(int const argc, char const* const argv[])
{
	testUtility();

	testPlugin();

	gproNet::cRakNetClient client;

	while (1)
	{
		client.MessageLoop();

		/* ENTER CLIENT COMMANDS FUNCTION HERE?  */
		ClientCommands();
	}

	printf("\n\n");
	system("pause");
}

void ClientCommands()
{
	// Want to poll so that you don't to wait for input and can just keep refreshing/getting messages when not typing

	std::string command;
	std::cin >> command;

	if (command == "/exit")
	{
		if (inGame)
		{
			inGame = false;
			// send a message packet with id of LEAVE_GAME_ID to the server
		}
		else
		{
			// send a packet that you're leaving the server and then close out
		}
	}
	else if (!inGame && command == "join")
	{
		std::cout << "Choose a room number" << endl;
		cin >> command;

		// read in the command send it in a message with id of ENTER_GAME_ID since this will tell what room to enter
	}
}