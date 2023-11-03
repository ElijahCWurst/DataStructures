#include "EventParticipant.h"


using namespace std;


// Drivers:
EventParticipant::EventParticipant(string name, string team, string gender, int age) {
	this->name = name;
	this->team = team;
	this->gender = gender;
	this->age = age;
}
EventParticipant::EventParticipant() {
	team = " ";
	name = " ";
	age = -1;
	gender = " ";
	points = -1;
}


// Getters/Setters:
void EventParticipant::setAge(int age) {
	this->age = age;
}
void EventParticipant::setGender(string gender) {
	this->gender = gender;
}
void EventParticipant::setName(string tempname) {
	this->name = tempname;
}
void EventParticipant::setTeam(string team) {
	this->team = team;
}
void EventParticipant::setPoints(int points) {
	this->points = points;
}
string EventParticipant::getName() {
	return name;
}


// Other:
void EventParticipant::printParticipant() {
	const int WIDTH = 10;
	cout << setw(WIDTH) << points
		 << setw(WIDTH) << name
		 << setw(WIDTH) << team
		 << setw(WIDTH) << gender
		 << setw(WIDTH) << age
		 << setw(WIDTH) << fixed << setprecision(2) << time;
} 
void EventParticipant::assignScores(int place) {
	switch (place) {
	case 1:
		points = 10;
		break;
	case 2:
		points = 8;
		break;
	case 3:
		points = 6;
		break;
	case 4:
		points = 4;
		break;
	case 5:
		points = 2;
		break;
	case 6:
		points = 1;
		break;
	default:
		points = 0;
		break;
	}
}
