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

	main-client-dll.c/.cpp
	Main source for client DLL.
*/

#if (defined _WINDOWS || defined _WIN32)


#include <Windows.h>


//-----------------------------------------------------------------------------
// optional DLL entry point

int APIENTRY DllMain(
	HMODULE hModule,
	DWORD  ul_reason_for_call,
	LPVOID lpReserved
)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		// called when a process loads the library
		break;
	case DLL_THREAD_ATTACH:
		// called when a thread loads the library
		break;
	case DLL_THREAD_DETACH:
		// called when a thread unloads the library
		break;
	case DLL_PROCESS_DETACH:
		// called when a process unloads the library
		break;
	}
	return TRUE;
}


#endif	// (defined _WINDOWS || defined _WIN32)