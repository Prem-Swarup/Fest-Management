#include "classes.h"
using namespace std;

NonCompetitiveEvent::NonCompetitiveEvent()
{
    EventCount++;
    this->setID();
}

NonCompetitiveEvent::NonCompetitiveEvent(string _name, string _head, string _info, int _duration, pair<int, int> preference)
{
    EventCount++;
    setID();
    this->Name = _name;
    this->Head = _head;
    this->Information = _info;
    this->Duration = _duration;
    this->PreferredDayAndTime = preference;
}

void NonCompetitiveEvent::setID()
{
    this->ID = " NE000" + to_string(EventCount);
}

void NonCompetitiveEvent::setGuest(string a)
{
    GuestName = a;
}

void NonCompetitiveEvent::printGuestName()
{
    cout << "The Guest for the Event is " << GuestName << endl;
}
