#include "stdafx.h"
#include <iostream>
#include "../Car/ccar.h"


using namespace std;

CCar::CCar()
:m_isEngineTurn(false),
m_speed(0),
m_gear(0),
m_direction(stay)
{
}


CCar::~CCar()
{
}

int CCar::GetTransmition() const
{
	return m_gear;
}

int CCar::GetSpeed() const
{
	return m_speed;
}

bool CCar::GetIsEngineTurn() const
{
	return m_isEngineTurn;
}

CCar::Direction CCar::GetDitection() const
{
	return m_direction;
}

bool CCar::TurnOnEngine()
{
	if (m_isEngineTurn)
	{
		return false;
	}
	m_isEngineTurn = true;
	m_gear = 0;
	return true;
}

bool CCar::TurnOffEngine()
{
	if (!m_isEngineTurn ||
		m_speed != 0 ||
		m_gear != 0)
	{
		cout << "Engine can't be turn off";
		return false;
	}

	m_isEngineTurn = false;
	return true;
}

bool CCar::SetSpeed(int speed)
{
	if (speed < 0 || speed > 150)
	{
		cout << "Uncorrect speed" << endl;
		return false;
	}
	if (!m_isEngineTurn)
	{
		cout << "Engine is turn off";
		return false;
	}

	switch (m_gear)
	{
	case -1:
		if (speed > 20)
		{
			cout << "Uncorrect speed" << endl;
			return false;
		}

		if (speed == 0)
		{
			m_direction = stay;
		}
		else
		{
			m_direction = back;
		}
		break;
	case 0:
		if (speed > m_speed)
		{
			cout << "Uncorrect speed" << endl;
			return false;
		}

		if (speed == 0)
		{
			m_direction = stay;
		}
		else if (m_gear = 1)
		{
			m_direction = forward;
		}
		else if (m_gear = -1)
		{
			m_direction = back;
		}
		break;
	case 1:
		if (speed > 30)
		{
			cout << "Uncorrect speed" << endl;
			return false;
		}
		if (speed == 0)
		{
			m_direction = stay;
		}
		else
		{
			m_direction = forward;
		}
		break;
	case 2:
		if (speed < 20 ||
			speed > 50)
		{
			cout << "Uncorrect speed" << endl;
			return false;
		}
		m_direction = forward;
		break;
	case 3:
		if (speed < 30 ||
			speed > 60)
		{
			cout << "Uncorrect speed" << endl;
			return false;
		}
		m_direction = forward;
		break;
	case 4:
		if (speed < 40 ||
			speed > 90)
		{
			cout << "Uncorrect speed" << endl;
			return false;
		}
		m_direction = forward;
		break;
	case 5:
		if (speed < 50 ||
			speed > 150)
		{
			cout << "Uncorrect speed" << endl;
			return false;
		}
		m_direction = forward;
		break;
	}
	m_speed = speed;
	return true;
}

bool CCar::SetGear(int gear)
{
	if (!m_isEngineTurn)
	{
		cout << "Engine is turn off" << endl;
		return false;
	}

	switch (gear)
	{
	case -1:
		if ((m_gear == 0 || m_gear == 1) && m_speed != 0)
		{
			cout << "speed is not equal to 0" << endl;
			return false;
		}
		else if (m_speed > 20)
		{
			cout << "Uncorrect speed" << endl;
			return false;
		}
		break;
	case 0:
		break;
	case 1:
		if ((m_gear == 0 || m_gear == -1) && m_speed != 0)
		{
			cout << "speed is not equal to 0" << endl;
			return false;
		}
		if (m_speed > 30) 
		{
			cout << "Uncorrect speed" << endl;
			return false;
		}
		break;
	case 2:
		if (m_speed < 20 || m_speed > 50)
		{
			cout << "uncorrect speed" << endl;
			return false;
		}
		break;
	case 3:
		if (m_speed < 30 || m_speed > 60)
		{
			cout << "uncorrect speed" << endl;
			return false;
		}
		break;
	case 4:
		if (m_speed < 40 || m_speed > 90)
		{
			cout << "uncorrect speed" << endl;
			return false;
		}
		break;
	case 5:
		if (m_speed < 50 || m_speed > 150)
		{
			cout << "uncorrect speed" << endl;
			return false;
		}
		break;
	default:
		return false;
		break;
	}
	m_gear = gear;
	return true;
}
