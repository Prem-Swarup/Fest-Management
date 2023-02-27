#include "classes.h"
using namespace std;


Participant::Participant(const Attendee &a)
{
    this->unique_id = a.unique_id;
    this->Name = a.Name;
    this->ContactNO = a.ContactNO;
    this->emailid = a.emailid;
    this->Rating = 0;
}

void Participant::increaseRating(int points)
{
    Rating += points;
}
