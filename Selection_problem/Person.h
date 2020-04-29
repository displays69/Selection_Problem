#pragma once
#ifndef __PERSON__
#define __PERSON__
#include<string.h>
class Person
{
private:
	char *name;
	int ID;

public:
	Person() = default;//Constructors
	Person(char *name, int ID);
	Person(const char* name, int ID);
	Person(const Person& p);

	~Person();//Destructor
	const Person& operator=(const Person& other);
	//set methods

	void SetName(const char *name);

	void SetId(int id);

	//get methods
	char* GetName() const { return this->name; };
	int GetId() const { return this->ID; };

};







#endif
