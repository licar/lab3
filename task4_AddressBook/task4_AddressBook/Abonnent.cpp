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
	list<string> const &phoneNumbers,
	list<string> const &mailAdresses)

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