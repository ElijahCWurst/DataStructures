#include "TrackParticipant.h"


// Constructors:
TrackParticipant::TrackParticipant(string time, string name, string team, string gender, int age): EventParticipant(name, team, gender, age) {
	this->time = time;
}
TrackParticipant::TrackParticipant() {
	time = -1;
}


// Getters and Setters:
void TrackParticipant::setTime(string time) {
	this->time = time;
}
string TrackParticipant::getTime() {
	return time;
}


// Other:
TrackParticipant* TrackParticipant::newTrack() {
	TrackParticipant* athlete = new TrackParticipant();
	string strTemp;
	
	cout << "Name (last, first): ";
	getline(cin, strTemp);
	athlete->setName(strTemp);

	cout << "Team: "; 
	getline(cin, strTemp);
	athlete->setTeam(strTemp);

	cout << "Gender: ";
	getline(cin, strTemp);
	athlete->setGender(strTemp);

	cout << "Age: ";
	getline(cin, strTemp);
	athlete->setAge(stoi(strTemp));

	cout << "Time (00:00.00): ";
	getline(cin, strTemp);
	//string temp = fixTime(strTemp);
	athlete->setTime(fixTime(strTemp));

	return athlete;
}
TrackParticipant* TrackParticipant::Driver(string time, string name, string team, string gender, int age) {
	TrackParticipant* athlete = new TrackParticipant(time, name, team, gender, age);
	return athlete;
}
void TrackParticipant::printParticipant() {
	const int WIDTH = 10;
	cout	<< setw(WIDTH)		<< left		<< points
			<< setw(WIDTH*2)	<< left		<< name
			<< setw(WIDTH)		<< left		<< team
			<< setw(WIDTH)		<< left		<< gender
			<< setw(WIDTH/2)	<< left		<< age
			<< setw(WIDTH)		<< right	<< fixed << setprecision(2) << time << endl;
}
float TrackParticipant::compare(TrackParticipant other, int sortField) {
	switch (sortField) {
	case SORT_NAME:
		if (getName() < other.getName()) {
			return 1;
		}
		else {
			return -1;
		}
		break;
	case SORT_TIME:
		if (getTime() < other.getTime()) {
			return 1;
		}
		else {
			return -1;
		}
		break;
	}
}
void TrackParticipant::assignScores(int place) {
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
string TrackParticipant::fixTime(string &time) {
	bool hasMinutes = false;
	for (int i = 0; i < time.size(); ++i) {
		if (time[i] == ':') {
			hasMinutes = true;
			continue;
		}
	}
	if (hasMinutes) {
		if (time[2] == ':' && time[5] == '.' && time[8] == '\0') {
			return time;
		}
		if (time[2] == ':') {
			if (time[5] == '.') {
				time += '0';
				return time;
			}
			else {
				time += ".00";
				return time;
			}
		}
		if (time[1] == ':' && time[4] == '.' && time[7] == '\0') {
			time = '0' + time;
			return time;
		}
		if (time[1] == ':') {
			//string newtime = "0";
			if (time[4] == '.') {
				time = '0' + time;
				time += '0';
				return time;
			}
			else {
				time = '0' + time;
				time += ".00";
				return time;
			}
		}

	}
	if (!hasMinutes) {
		int newtime = stof(time) * 100;  // divide answer by 100...
		int seconds = newtime % 6000;
		newtime -= seconds;
		newtime /= 6000;
		string strSeconds = to_string(seconds);
		if (strSeconds.size() == 3) {
			strSeconds = '0' + strSeconds;
		}

		string answer = to_string(newtime) + ':' + strSeconds[0] +  strSeconds[1] + '.' + strSeconds[2] + strSeconds[3];

		return fixTime(answer);
	}

	
}