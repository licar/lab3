#pragma once

class CCar
{
public:
	CCar();
	~CCar();

	enum /*struct */ Direction
	{
		forward,
		back,
		stay
	};

	int GetTransmition() const;
	int GetSpeed() const;
	bool GetIsEngineTurn() const; //TODO: IsEngineOn IsEngineTurnedOn
	Direction GetDitection() const;// GetDirection
	
	bool TurnOnEngine();
	bool TurnOffEngine();
	bool SetGear(int gear);
	bool SetSpeed(int speed);

private:
	bool m_isEngineTurn;
	int m_speed;
	int m_gear;
	Direction m_direction;
};

