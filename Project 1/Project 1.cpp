#include "EventParticipant.h"
#include "TrackParticipant.h"
#include "FieldParticipant.h"

using namespace std;

//-----------Function-Headers-----------//
void driver();
void sortTrack(vector<TrackParticipant*>& vect, int sortField);
void sortField(vector<FieldParticipant*>& vect, int sortField);
void displayTrackData(vector<TrackParticipant*> &vect);
void displayFieldData(vector<FieldParticipant*>& vect);
void setTrackScores(vector<TrackParticipant*>& vect);
void setFieldScores(vector<FieldParticipant*>& vect);

int main()
{
    bool again = true;
    bool run = true;
    string userResponse = " ";
    while (run) {
        cout << "Please choose an event. Enter whether it is a 'track' or 'field' event. Enter 'driver' for the DRIVER function (Driver function uses track)." << endl;
        getline(cin, userResponse);
        if (userResponse == "track") {
            TrackParticipant add;
            vector<TrackParticipant*> trackList;
            while (again) {
                if (again) {
                    trackList.push_back(add.newTrack());
                    cout << "Enter another? (y/n)" << endl;
                    getline(cin, userResponse);
                    if (userResponse == "n") {
                        again = false;
                    }
                }
            }
            setTrackScores(trackList);
            cout << "Sort:" << endl << "1. Alphabetically" << endl << "2. By time" << endl;
            getline(cin, userResponse);
            if (userResponse == "1") { sortTrack(trackList, 1); }
            if (userResponse == "2") { sortTrack(trackList, 2); }
            displayTrackData(trackList);
            cout << "Restart? (y/n)\n";
            getline(cin, userResponse);
            if (userResponse == "n") {
                return 0;
            }
        }
        if (userResponse == "field") {
            FieldParticipant add;
            vector<FieldParticipant*> fieldList;
            while (again) {
                if (again) {
                    fieldList.push_back(add.newField());
                    cout << "Enter another? (y/n)" << endl;
                    getline(cin, userResponse);
                    if (userResponse == "n") {
                        again = false;
                    }
                }
            }
            setFieldScores(fieldList);
            cout << "Sort:" << endl << "1. Alphabetically" << endl << "2. By distance" << endl;
            getline(cin, userResponse);
            if (userResponse == "1") { sortField(fieldList, 1); }
            if (userResponse == "2") { sortField(fieldList, 2); }
            displayFieldData(fieldList);
            cout << "Restart? (y/n)\n";
            getline(cin, userResponse);
            if (userResponse == "n") {
                return 0;
            }
        }
        if (userResponse == "driver") {
            driver();
            cout << "Restart? (y/n)\n";
            getline(cin, userResponse);
            if (userResponse == "n") {
                return 0;
            }
        }
        again = true;
    }
}

//----------Function-Definitions----------//
void displayTrackData(vector<TrackParticipant*> &vect) {
    const int WIDTH = 10;
    cout << setw(WIDTH) << left << "Points"
        << setw(WIDTH * 2) << left << "Name"
        << setw(WIDTH) << left << "Team"
        << setw(WIDTH) << left << "Gender"
        << setw(WIDTH / 2) << left << "Age"
        << setw(WIDTH) << right << fixed << setprecision(2) << "Time" << endl;
    for (int i = 0; i < vect.size(); ++i) {
        vect[i]->printParticipant();                // 
    }
}
void displayFieldData(vector<FieldParticipant*>& vect) {
    const int WIDTH = 10;
    cout << setw(WIDTH) << left << "Points"
        << setw(WIDTH * 2) << left << "Name"
        << setw(WIDTH) << left << "Team"
        << setw(WIDTH) << left << "Gender"
        << setw(WIDTH / 2) << left << "Age"
        << setw(WIDTH) << right << fixed << setprecision(2) << "Distance" << endl;
    for (int i = 0; i < vect.size(); ++i) {
        vect[i]->printParticipant();                // 
    }
}
void sortTrack(vector<TrackParticipant*>& vect, int sortField) {
    bool swapMade = true;
    TrackParticipant* temp;
    while (swapMade) {
        swapMade = false;
        for (int i = 1; i < vect.size(); ++i) {
            if (vect[i-1]->compare(*vect[i], sortField)<0) {
                temp = vect[i - 1];
                vect[i - 1] = vect[i];
                vect[i] = temp;
                swapMade = true;
            }
        }
        if (!swapMade) {
            return;
        }
    }
}
void sortField(vector<FieldParticipant*>& vect, int sortField) {
    //TrackParticipant.setSortField(sortField);
    bool swapMade = true;
    FieldParticipant* temp;
    while (swapMade) {
        swapMade = false;
        for (int i = 1; i < vect.size(); ++i) {
            if (vect[i - 1]->compare(*vect[i], sortField) < 0) {
                temp = vect[i - 1];
                vect[i - 1] = vect[i];
                vect[i] = temp;
                swapMade = true;
            }
        }
        if (!swapMade) {
            return;
        }
    }
}
void setTrackScores(vector<TrackParticipant*>& vect) {
    sortTrack(vect, 2);
    for (int i = 0; i < vect.size(); ++i) {
        vect[i]->assignScores(i + 1);
    }
}
void setFieldScores(vector<FieldParticipant*>& vect) {
    sortField(vect, 2);
    for (int i = 0; i < vect.size(); ++i) {
        vect[i]->assignScores(i + 1);
    }
}
void driver() {
    TrackParticipant add;
    vector<TrackParticipant*> trackList;
    trackList.push_back(add.Driver("00:58.50", "Wurst, Elijah", "NNU", "Male", 19));
    trackList.push_back(add.Driver("00:59.50", "Mounts, Eli", "NNU", "Male", 19));
    trackList.push_back(add.Driver("01:20.50", "Wurst, Ian", "NNU", "Male", 21));
    trackList.push_back(add.Driver("01:12.50", "Creech, Ashlyn", "NNU", "Female", 19));
    trackList.push_back(add.Driver("02:00.29", "Wurst, Jeff", "NNU", "Male", 45));
    trackList.push_back(add.Driver("02:24.12", "Wurst, Spring", "NNU", "Female", 46));
    trackList.push_back(add.Driver("00:54.90", "Zink, Tim", "NNU", "Male", 21));
    trackList.push_back(add.Driver("02:42.28", "Smith, John", "SNU", "Male", 22));
    trackList.push_back(add.Driver("16:40.99", "Turtle, Frank", "BSU", "Male", 88));
    trackList.push_back(add.Driver("00:50.44", "Stewart, Joshua", "NNU", "Male", 19));
    trackList.push_back(add.Driver("01:40.00", "Johnson, Jenna", "CWI", "Female", 23));

    setTrackScores(trackList);
    displayTrackData(trackList);

    //create time formatting...

    return;
}
