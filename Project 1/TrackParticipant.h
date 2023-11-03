#pragma once
#include "EventParticipant.h"

const int SORT_NAME = 1;
const int SORT_TIME = 2;

class TrackParticipant : public EventParticipant
{
private:
	string time;
public:
	TrackParticipant(string time, string name, string team, string gender, int age);
	TrackParticipant();
	void setTime(string time);
	string getTime();
	TrackParticipant* newTrack();
	TrackParticipant* Driver(string time, string name, string team, string gender, int age);
	void printParticipant();
	float compare(TrackParticipant other, int sortField);
	void assignScores(int place);
	string fixTime(string &time);
};

