#include "FieldParticipant.h"


// Constructors:
FieldParticipant::FieldParticipant(float distance, string name, string team, string gender, int age): EventParticipant(name, team, gender, age) {
	this->distance = distance;
}
FieldParticipant::FieldParticipant() {
	distance = -1;
}


// Getters/Setters:
void FieldParticipant::setDistance(float distance) {
	this->distance = distance;
}
float FieldParticipant::getDistance() {
	return distance;
}


// Other:
FieldParticipant* FieldParticipant::newField() {
	FieldParticipant* athlete = new FieldParticipant;
	string temp;

	cout << "Name (last, first): ";
	getline(cin, temp);
	athlete->setName(temp);

	cout << "Team: ";
	getline(cin, temp);
	athlete->setTeam(temp);

	cout << "Gender: ";
	getline(cin, temp);
	athlete->setGender(temp);

	cout << "Age: ";
	getline(cin, temp);
	athlete->setAge(stoi(temp));

	cout << "Distance (m): ";
	getline(cin, temp);
	athlete->setDistance(stof(temp));

	return athlete;
}
FieldParticipant* FieldParticipant::Driver(float distance, string name, string team, string gender, int age) {
	FieldParticipant* athlete = new FieldParticipant(distance, name, team, gender, age);
	return athlete;
}
float FieldParticipant::compare(FieldParticipant other, int sortField) {
	switch (sortField) {
	case SORT_NAME2:
		if (getName() < other.getName()) {
			return 1;
		}
		else {
			return -1;
		}
		break;
	case SORT_DIST:
		return getDistance() - other.getDistance();
		break;
	}
}
void FieldParticipant::printParticipant() {
	const int WIDTH = 10;
	cout	<< setw(WIDTH)		<< left		<< points
			<< setw(WIDTH * 2)	<< left		<< name
			<< setw(WIDTH)		<< left		<< team
			<< setw(WIDTH)		<< left		<< gender
			<< setw(WIDTH / 2)	<< left		<< age
			<< setw(WIDTH)		<< right	<< fixed << setprecision(2) << distance << endl;
}
void FieldParticipant::assignScores(int place) {
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