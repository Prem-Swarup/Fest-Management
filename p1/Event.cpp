#include "classes.h"
using namespace std;

Event::Event()
{
    EventCount++;
}

Event::Event(string _name, string _head, string _info, int _duration, pair<int, int> preference)
{
    EventCount++;
    setID();
    this->Name = _name;
    this->Head = _head;
    this->Information = _info;
    this->Duration = _duration;
    this->PreferredDayAndTime = preference;
}

int Event::getPriority()
{
    return Priority;
}

void Event::setName()
{

    cout << "Enter Event Name: ";
    string _Name;
    cin >> _Name;
    cout << _Name << endl;
    this->Name = _Name;
    return;
}

string Event::getName()
{
    return this->Name;
}

void Event::setHead()
{

    cout << "Enter Event Head Name: ";
    string _Head;

    getline(cin, _Head);
    cout << _Head << "head\n";
    this->Head = _Head;
    return;
}

string Event::getHead()
{
    return this->Head;
}

void Event::setID()
{
    this->ID = " E000" + to_string(EventCount);
}

string Event::getID()
{
    return ID;
}

void Event::setInfo()
{
    cout << "Enter Event Information: ";
    string info;
    getline(cin, info);
    this->Information = info;
    return;
}

string Event::getInfo()
{
    return this->Information;
}

void Event::printDetails()
{
    cout << "Event Name: " << Name << endl;
    cout << "Event ID: " << ID << endl;
    cout << "Event Head: " << Head << endl;
    cout << "Event Info: " << this->Information << endl;
    return;
}

void Event::addParticipant(Attendee *p)
{
    Participants.push_back(p);
    return;
}

void Event::setPreference()
{
    int Day, Time;
    cout << "Print Preferred Day(DDMMYYYY format) :";
    cin >> Day;
    this->PreferredDayAndTime.first = Day;
    cout << "Print Preferred Time(24 Hr format) :";
    cin >> Time;
    this->PreferredDayAndTime.second = Time;
}

pair<int, int> Event::getPreference()
{
    return PreferredDayAndTime;
}

void Event::setDuration()
{
    int _Duration;
    cout << "Enter Event Duration(in hrs) :";
    cin >> _Duration;
    cout << _Duration << "dd\n";
    this->Duration = _Duration;
}
int Event::getDuration()
{
    return Duration;
}

void Event::run(int type)
{
    ;
}
Attendee *Event::getParticipantbyID(string id)
{
    for (int i = 0; i < Participants.size(); i++)
    {
        if (Participants[i]->getUniqueID() == id)
        {
            return Participants[i];
        }
    }

    return NULL;
}

void Event::setPriority()
{
    int _Priority;
    cin >> _Priority;
    this->Priority = _Priority;
    return;
}

bool Event::ComparatorPriority(Event a, Event b)
{
    return (a.getPriority() > b.getPriority());
}