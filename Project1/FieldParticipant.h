#pragma once
#include "EventParticipant.h"

const int SORT_NAME2 = 1;
const int SORT_DIST = 2;

class FieldParticipant : public EventParticipant 
{
private:
	float distance;
public:
	FieldParticipant(float distance, string name, string team, string gender, int age);
	FieldParticipant();
	void setDistance(float distance);
	float getDistance();
	FieldParticipant* newField();
	FieldParticipant* Driver(float distance, string name, string team, string gender, int age);
	void printParticipant();
	float compare(FieldParticipant other, int sortField);
	void assignScores(int place);
};

