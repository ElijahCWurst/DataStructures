#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <iomanip>
#include <time.h>

using namespace std;

class EventParticipant
{
protected:
	string name;
	string team;
	string gender;
	int age;
	int points = 0;
	
public:
	EventParticipant(string name, string team, string gender, int age);
	EventParticipant();
	void setName(string name);
	void setTeam(string team);
	void setGender(string gender);
	void setAge(int age);
	void setPoints(int points);
	string getName();
	void printParticipant();
	void assignScores(int place);
};

