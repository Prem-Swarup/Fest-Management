#include "classes.h"
using namespace std;

string Attendee::getUniqueID()
{
    return unique_id;
}

string Attendee::getName()
{
    return Name;
}

Attendee::Attendee()
{
    totalAttendee++;
    unique_id = "EMT000" + to_string(totalAttendee);
}

void Attendee::inputDetails(ifstream &ifs_attendee, int type)
{
    if (type)
    {
        cout << "\naName -; ";
        cin >> Name;
        cout << "\nContact NO -; ";
        cin >> ContactNO;
        cout << "\nEmail-ID -; ";
        cin >> emailid;
        return;
    }
    ifs_attendee >> Name;
    ifs_attendee >> ContactNO;
    ifs_attendee >> emailid;
}

void Attendee::increaseRating(int points)
{
    ;
}

Attendee::Attendee(const Attendee &a)
{
    ;
}

Attendee::Attendee(string _name, string _contact, string _email)
{
    totalAttendee++;
    unique_id = "EMT000" + to_string(totalAttendee);
    Name = _name;
    ContactNO = _contact;
    emailid = _email;
}

void Attendee::getDetails()
{
    cout << "ID: " << unique_id << endl;
    cout << "Name: " << Name << endl;
    cout << "Contact NO: " << ContactNO << endl;
    cout << "Email-ID: " << emailid << endl;
}
int Attendee::getAtCount()
{
    return totalAttendee;
}