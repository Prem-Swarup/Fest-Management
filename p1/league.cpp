#include "classes.h"
using namespace std;

league::league(vector<Attendee *> &_Participants, int _Players, string eventName)
{
    this->Players = _Players;
    for (int i = 0; i < _Players; ++i)
    {
        Participants.push_back(_Participants[i]);
    }

    totalMatches = _Players * (_Players - 1) / 2;
    cout << "Total Matches Played in the league stage =" << totalMatches << endl;
    int N = 0;
    string winner;

    for (int i = 0; i <= _Players; i++)
    {
        ID.push_back(((this->Participants))[i]->getUniqueID());
    }

    for (int i = 0; i < _Players; i++)
    {
        for (int j = i + 1; j < _Players; j++)
        {
            N++;
            cout << "Match " << N << ": " << ((this->Participants))[i]->getUniqueID() << " v/s " << ((this->Participants))[j]->getUniqueID() << endl;
            cout << "Enter winner ID: ";
            cin >> winner;
            cout << endl;

            if (winner == ((this->Participants))[i]->getUniqueID())
            {
                ((this->Participants))[i]->increaseRating(100);
            }
            else
            {
                ((this->Participants))[j]->increaseRating(100);
            }
        }
    }
}
