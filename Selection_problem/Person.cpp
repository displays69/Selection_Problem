#pragma warning(disable : 4996)

#include <iostream>
using namespace std;
#include "Person.h"
#include <string.h>


Person::Person(char *name, int ID)
{
	SetName(name);
	SetId(ID);
}


Person::Person(const char *name, int ID)
{
	SetName(name);
	SetId(ID);
}

Person::Person(const Person& p)
{
	SetName(p.GetName());
	SetId(p.GetId());
}


Person::~Person()
{
	delete[]name;
}


const Person& Person::operator=(const Person& other)
{
	if (this != &other) {
		SetName(other.GetName());
		SetId(other.GetId());
	}

	return *this;

}


void Person::SetName(const char *name)
{
	this->name = strdup(name);
}


void Person::SetId(int id)
{
	this->ID = id;
}