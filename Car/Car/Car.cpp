// Car.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "ccar.h"
#include <iostream>
#include <string>

int _tmain(int argc, _TCHAR* argv[])
{
	CCar car;
	int speed, gear;
	std::string strAction;
	std::cout << "menu : info EngineOn EngineOff SetGear SetSpeed: " << std::endl <<  ": ";

	std::cin >> strAction;
	while (!strAction.empty())
	{
		if (strAction == "info")
		{
			std::cout << "Engine Turn: " << car.GetIsEngineTurn() << std::endl <<
				"Speed : " << car.GetSpeed() << std::endl <<
				"Gear : " << car.GetTransmition() << std::endl <<
				"Direction : " << car.GetDitection() << std::endl;
		}
		else if (strAction == "EngineOn")
		{
			car.TurnOnEngine();
		}
		else if (strAction == "EngineOff")
		{
			car.TurnOffEngine();
		}
		else if (strAction == "SetGear")
		{
			std::cin >> gear;
			car.SetGear(gear);
		}
		else if (strAction == "SetSpeed")
		{
			std::cin >> speed;
			car.SetSpeed(speed);
		}
		std::cout << "menu : info EngineOn EngineOff SetGear SetSpeed: " << std::endl << ": ";
		std::cin >> strAction;
	}
	return 0;
}

