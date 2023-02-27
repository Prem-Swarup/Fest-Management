#include "classes.h"
using namespace std;

fest::fest(int _days, int _venues) : ifs_event("eventss.txt"), ifs_attendee("attendee.txt")
{
	days = _days;
	venues = _venues;
	totalAttendees = 0;
	totalEvents = 0;
}

void fest::addAttendee()
{

	attendees.push_back(new Attendee());
	attendees[totalAttendees]->inputDetails(ifs_attendee, 0);
	totalAttendees++;
	attendees[totalAttendees - 1]->getDetails();
	cout << endl;
}

void fest::addEvent(int type)
{
	string _name;
	string _head;
	string _info;
	int _duration;
	string null;
	pair<int, int> preference;

	getline(ifs_event, _name);
	while (_name == "")
		getline(ifs_event, _name);
	getline(ifs_event, _head);
	getline(ifs_event, _info);
	ifs_event >> preference.first >> preference.second >> _duration;

	switch (type)
	{
	case 1:
	{

		events.push_back(new Event(_name, _head, _info, _duration, preference));
		break;
	}
	case 2:
	{

		events.push_back(new CompetitiveEvent(_name, _head, _info, _duration, preference));

		break;
	}
	case 3:
	{
		events.push_back(new NonCompetitiveEvent(_name, _head, _info, _duration, preference));

		break;
	}
	default:
	{
		return;
	}
	}

	if (timelinePrepared)
	{
		timeline->addToSchedule(totalEvents);
	}

	events[totalEvents]->printDetails();
	cout << endl;
	totalEvents++;
}

void fest::addEventParticipants(int i, int j)
{

	events[i]->addParticipant(attendees[j]);
}

void fest::runEvent(int i, int type)
{
	events[i]->run(type);
}

void fest::prepareTimeline()
{
	timeline = new Timeline(totalEvents, events, venues, days);
	timeline->prepareSchedule();
	timelinePrepared = 1;
}

void fest::showTimeline()
{
	timeline->printSchedule();
}

void fest::askPARA(string ques)
{
	PARA.answerQuery(ques);
}

void fest::addQnA()
{
	PARA.addQuestion();
}

void fest::addQnA(string ques, string ans)
{
	PARA.addQuestion(ques, ans);
}
