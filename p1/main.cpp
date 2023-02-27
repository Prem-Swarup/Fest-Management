#include "classes.h"
using namespace std;
#define ifs
int Attendee::totalAttendee = 0;
int Event::EventCount = 0;
int QuestionAnswer::questionNo = 0;


//run file as  " ./project < winners.txt " to automatically provide input for winners of events
int main()
{

	int n, tmp, ii, jj;
	class fest Chakravyuh(4, 5);
	ifstream c_ifs("commands.txt");

	c_ifs >> n;
	for (int i = 0; i < n; i++)
	{
		Chakravyuh.addAttendee();
	}

	c_ifs >> n;
	for (int i = 0; i < n; ++i)
	{
		c_ifs >> tmp;
		Chakravyuh.addEvent(tmp);
	}

	Chakravyuh.prepareTimeline();

	Chakravyuh.showTimeline();

	c_ifs >> n;
	c_ifs >> ii;
	for (int i = 0; i < n; ++i)
	{
		Chakravyuh.addEventParticipants(ii, i);
	}

	Chakravyuh.runEvent(0, 2);

	cout<<"Q. When will the fest start\n" ;
	Chakravyuh.askPARA("When will the fest start");

	cout<<"Q. will they provide free food to participants\n" ;
	Chakravyuh.askPARA("will they provide free food to participants");

	return 0;
}