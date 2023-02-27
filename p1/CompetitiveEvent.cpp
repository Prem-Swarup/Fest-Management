#include "classes.h"
using namespace std;

CompetitiveEvent::CompetitiveEvent()
{

    this->ID = " CE000" + to_string(EventCount);
}

CompetitiveEvent::CompetitiveEvent(string _name, string _head, string _info, int _duration, pair<int, int> preference)
{

    setID();
    this->Name = _name;
    this->Head = _head;
    this->Information = _info;
    this->Duration = _duration;
    this->PreferredDayAndTime = preference;
}

void CompetitiveEvent::setID()
{
    this->ID = " CE000" + to_string(EventCount);
}

void CompetitiveEvent::showLeaderboard()
{
    cout << "The Leaderboard is as follows:" << endl;
}

void CompetitiveEvent::addParticipant(Attendee *a)
{
    Participants.push_back(new Participant(*a));
    Registrations++;
    return;
}

void CompetitiveEvent::run(int type)
{
    if (type == 1)
    {
        Fixture = new league(Participants, Participants.size(), Name);
    }
    else
    {
        Fixture = new knockouts(Participants, Participants.size(), Name);
    }
}

Participant CompetitiveEvent::getWinner()
{
    return Leaderboard[0].first;
}
