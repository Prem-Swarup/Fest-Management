#include "classes.h"
using namespace std;

Timeline::Timeline(int _days, int _venues)
{
	totalEvents = 0;
	days = _days;
	venues = _venues;
}

bool priorityComp(Event *e1, Event *e2)
{
	return e1->getPriority() >= e2->getPriority();
}

Timeline::Timeline(int _totalEvents, vector<Event *> &_events, int _days, int _venues)
{
	totalEvents = _totalEvents;
	days = _days;
	venues = _venues;
	for (int i = 0; i < _events.size(); ++i)
	{
		events.push_back(_events[i]);
	}
}

void Timeline::prepareSchedule()
{

	for (int i = 0; i < events.size(); i++)
	{
		this->addToSchedule(i);
	}
}

void Timeline::addEvent(Event *_event)
{
	events.push_back(_event);
	addToSchedule(events.size() - 1);
}

void Timeline::addToSchedule(int i)
{

	pair<int, int> temp = findTime(events[i]->Duration, events[i]->getPreference());

	if (schedule.find(temp.first) == schedule.end())
	{
		schedule.insert({temp.first, map<int, vector<int>>()});
	}

	if (schedule[temp.first].find(temp.second) == schedule[temp.first].end())
		;
	{
		schedule[temp.first].insert({temp.second, vector<int>()});
	}

	schedule[temp.first][temp.second].push_back(i);

	for (int i = 0; i < events[i]->getDuration(); ++i)
	{
		occupiedTime[temp.first][temp.second + i]++;
	}

	return;
}

int Timeline::findIndex(string id)
{
	for (int i = 0; i < events.size(); i++)
	{
		if (events[i]->getID() == id)
		{
			return i;
		}
	}

	return -1;
}

void Timeline::addToSchedule(string id)
{
	int i = this->findIndex(id);
	addToSchedule(i);
}

pair<int, int> Timeline::findTime(int duration, pair<int, int> _pref)
{

	if (occupiedTime[_pref.first][_pref.second] <= venues)
	{
		return _pref;
	}
	for (int i = 0; i < days; i++)
	{
		for (int j = startTime; j < endTime; j++)
		{
			if (occupiedTime[i][j] <= venues)
			{

				for (int k = 0; k < duration; k++)
				{

					if (occupiedTime[i][j++] >= venues)
					{

						break;
					}
					if (k == duration - 1)
					{
						return {i, j};
					}
				}
			}
		}
	}

	return _pref;
}

void Timeline::changeSchedule(string id, int day, int hour)
{
	;
}

void Timeline::printSchedule()
{
	cout<<"Schedule of fest:\n\n" ;
	cout<<"Day\tHour\tEvent Name\n" ;
	for (auto _days : schedule)
	{

		for (auto hrs : _days.second)
		{
			for (auto _no : hrs.second)
			{
				cout << _days.first << "\t" << hrs.first << "\t" << events[_no]->getName() << endl;
			}
		}
	}
	cout<<endl ;
}

Event *Timeline::operator()(int a, int b)
{
	return events[schedule[a][b][0]];
}

pair<int, int> Timeline::operator[](string id)
{
	int indx = findIndex(id);
	return id_schedule[indx];
}
