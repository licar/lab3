// car_tests.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include "../Car/ccar.h"

BOOST_AUTO_TEST_CASE(EngineTurnOffAfterInitialization)
{
	CCar car;
	BOOST_CHECK_EQUAL(car.GetIsEngineTurn(), false);
}

BOOST_AUTO_TEST_CASE(Speed0AfterInitialization)
{
	CCar car;
	BOOST_CHECK_EQUAL(car.GetSpeed(), 0);
}

BOOST_AUTO_TEST_CASE(Transmition0AfterInitialization)
{
	CCar car;
	BOOST_CHECK_EQUAL(car.GetTransmition(), 0);
}

BOOST_AUTO_TEST_CASE(DirectionStayAfterInitialization)
{
	CCar car;
	BOOST_CHECK_EQUAL(car.GetDitection(), car.stay);
}


BOOST_AUTO_TEST_CASE(EngineCanBeTurn)
{
	CCar car;
	BOOST_CHECK_EQUAL(car.TurnOnEngine(), true);
}

BOOST_AUTO_TEST_CASE(EngineCanNotTurnOnTwoTimes)
{
	CCar car;
	car.TurnOnEngine();
	BOOST_CHECK_EQUAL(car.TurnOnEngine(), false);
}

BOOST_AUTO_TEST_CASE(EngineCanTurnOff)
{
	CCar car;
	car.TurnOnEngine();
	BOOST_CHECK_EQUAL(car.TurnOffEngine(), true);
}

BOOST_AUTO_TEST_CASE(EngineCanNotTurnOffTwoTimes)
{
	CCar car;
	car.TurnOnEngine();
	car.TurnOffEngine();
	BOOST_CHECK_EQUAL(car.TurnOffEngine(), false);
}

BOOST_AUTO_TEST_CASE(CarCanChangeSpeed)
{
	CCar car;
	car.TurnOnEngine();
	BOOST_CHECK_EQUAL(car.SetSpeed(0), true);
}

BOOST_AUTO_TEST_CASE(CarCanNotSetNegativeSpeed)
{
	CCar car;
	car.TurnOnEngine();
	BOOST_CHECK_EQUAL(car.SetSpeed(-1), false);
}

BOOST_AUTO_TEST_CASE(CarCanNotUppSpeedOnNeutral)
{
	CCar car;
	car.TurnOnEngine();
	BOOST_CHECK_EQUAL(car.SetSpeed(2), false);
}

BOOST_AUTO_TEST_CASE(ChangeTransmitionsWhenSpeed0)
{
	CCar car;
	car.TurnOnEngine();
	BOOST_CHECK_EQUAL(car.SetGear(1), true);
	BOOST_CHECK_EQUAL(car.SetGear(-1), true);
	BOOST_CHECK_EQUAL(car.SetGear(0), true);
	BOOST_CHECK_EQUAL(car.SetGear(1), true);
	BOOST_CHECK_EQUAL(car.SetGear(2), false);
	BOOST_CHECK_EQUAL(car.SetGear(3), false);
	BOOST_CHECK_EQUAL(car.SetGear(4), false);
	BOOST_CHECK_EQUAL(car.SetGear(5), false);
	BOOST_CHECK_EQUAL(car.SetGear(6), false);
}

BOOST_AUTO_TEST_CASE(ChangeTransmitionsWhenSpeed20)
{
	CCar car;
	car.TurnOnEngine();
	BOOST_CHECK_EQUAL(car.SetGear(1), true);
	BOOST_CHECK_EQUAL(car.SetSpeed(20), true);
	BOOST_CHECK_EQUAL(car.SetGear(-1), false);
	BOOST_CHECK_EQUAL(car.SetGear(0), true);
	BOOST_CHECK_EQUAL(car.SetGear(2), true);
	BOOST_CHECK_EQUAL(car.SetGear(3), false);
	BOOST_CHECK_EQUAL(car.SetGear(4), false);
	BOOST_CHECK_EQUAL(car.SetGear(5), false);
	BOOST_CHECK_EQUAL(car.SetGear(6), false);
}



