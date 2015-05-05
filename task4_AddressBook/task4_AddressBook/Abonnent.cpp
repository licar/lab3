#include "stdafx.h"
#include "Abonnent.h"


CAbonnent::CAbonnent()
	:m_apartament(0)
{
}

CAbonnent::CAbonnent(string const &name,
	string const &surname,
	string const &patronymic,
	string const &city,
	string const &house,
	unsigned apartament,
	vector<string> const &phoneNumbers,
	vector<string> const &mailAdresses)

	:m_name(name),
	m_surname(surname),
	m_city(city),
	m_house(house),
	m_apartament(apartament),
	m_phoneNumbers(phoneNumbers),
	m_mailAddresses(mailAdresses)
{
}


CAbonnent::~CAbonnent()
{
}

string CAbonnent::GetName()
{
	return m_name;
}

void CAbonnent::SetName(string const &name)
{
	m_name = name;
}

string CAbonnent::GetSurname()
{
	return m_surname;
}

void CAbonnent::SetSurname(string const &surname)
{
	m_surname = surname;
}

string CAbonnent::GetPatronymic()
{
	return m_patronymic;
}

void CAbonnent::SetPatronymic(string const &patronymic)
{
	m_patronymic = patronymic;
}

string CAbonnent::GetCity()
{
	return m_city;
}

void CAbonnent::SetCity(string const &city)
{
	m_city = city;
}

string CAbonnent::GetStreet()
{
	return m_street;
}

void CAbonnent::SetStreet(string const &street)
{
	m_street = street;
}

string CAbonnent::GetHouse()
{
	return m_house;
}

void CAbonnent::SetHouse(string const &house)
{
	m_house = house;
}

int CAbonnent::GetApartament()
{
	return m_apartament;
}

void CAbonnent::SetApartament(const int apartament)
{
	if (apartament > 0)
	{
		m_apartament = apartament;
	}
}

vector<string> CAbonnent::GetPhoneNumbers()
{
	return m_phoneNumbers;
}

bool CAbonnent::AddPhoneNumber(string const &newPhoneNumber)
{
	if (stoll(newPhoneNumber) < 0)
	{
		return false;
	}

	for (auto addedPhoneNumber : m_phoneNumbers)
	{
		if (addedPhoneNumber == newPhoneNumber)
		{
			return false;
		}
	}

	m_phoneNumbers.push_back(newPhoneNumber);
	return true;
}

vector<string> CAbonnent::GetMailAddresses()
{
	return m_mailAddresses;
}

bool CAbonnent::AddMailAddress(string const &newMailAddress)
{
	for (auto addedMailAddress : m_mailAddresses)
	{
		if (addedMailAddress == newMailAddress)
		{
			return false;
		}
	}

	m_phoneNumbers.push_back(newPhoneNumber);
	return true;
}




