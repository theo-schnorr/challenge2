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

	main-server.cpp
	Main source for console server application.
*/

#include "gpro-net/gpro-net-server/gpro-net-RakNet-Server.hpp"



int main(int const argc, char const* const argv[])
{
	gproNet::cRakNetServer server;

	// Have vectors to represent the different rooms
	// vector for main server area
	// vector for game room 1
	// vector for game room 2
	// etc

	while (1)
	{
		server.MessageLoop();
		
	}

	printf("\n\n");
	system("pause");
}

bool ProcessSeverMessage(RakNet::BitStream& bitstream, RakNet::SystemAddress const sender, RakNet::Time const dtSendToReceive, RakNet::MessageID const msgID)
{
	// process messages that have been sent to the server
	switch (msgID)
	{
	case ENTER_GAME_ID:
		// add user address to game they joined
		// find correct gameroom vector based on message
		// read bitstream, get the message
		// Send message into a switch of some sort to find proper gameroom vector
			// vector.push_back(sender)

		// for loop to find user in main server room vector and remove them

		break;

	case LEAVE_GAME_ID:
		// main server room vector.push_back(sender)
		
		// message should include current game room
		// for loop to find user in their current game room and remove from vector

		break;
	}
	return false;
}

// Message broadcasting from server should then take in what room someone is in, and then use a for loop to send the message out to everyone in that vector