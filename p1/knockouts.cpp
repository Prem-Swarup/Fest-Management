#include "classes.h"
using namespace std;

knockouts::knockouts(vector<class Attendee *> &_Participants, int _Players, string eventName)
{
    cout<<"Running event: "<<eventName<<endl ;
    cout<<"Total Participants: "<<_Players<<endl ;
    this->Players = _Players;

    for (int i = 0; i < _Players; i++)
    {
        this->Participants.push_back(_Participants[i]);
    }

    totalRounds = ceil(log2(this->Players));
    rounds.resize(totalRounds + 1);

    int Matches_in_Round = this->Players - pow(2, totalRounds - 1);

    for (int i = 0; i < 2 * Matches_in_Round; i++)
    {
        rounds[0].push_back(((this->Participants))[i]->getUniqueID());
    }

    run(0);
}

void knockouts::increaseRating(string winner, int points)
{
    for (int i = 0; i < ((this->Participants)).size(); i++)
    {
        if (((this->Participants))[i]->getUniqueID() == winner)
        {
            ((this->Participants))[i]->increaseRating(points);
            break;
        }
    }
}

void knockouts::run(int roundNo)
{
    string winner;
    cout << "Total Number of Matches in Round " << roundNo + 1 << ": " << rounds[roundNo].size() / 2 << endl<<endl;

    for (int i = 0; i < rounds[roundNo].size() / 2; i++)
    {
        cout << "Match " << i + 1 << ": " << rounds[roundNo][2 * i] << " v/s " << rounds[roundNo][(2 * i) + 1] << endl;
        cout << "Enter Winner: ";
        cin >> winner;
        cout << winner << endl;
        cout << endl;

        rounds[roundNo + 1].push_back(winner);

        increaseRating(winner, 100);
    }

    if (roundNo == 0)
    {
        for (int i = rounds[0].size(); i < (this->Participants).size(); i++)
        {
            rounds[1].push_back(((this->Participants))[i]->getUniqueID());
        }
    }

    if (roundNo == totalRounds - 1)
        cout << "Winner: " << winner << endl
             << endl;
    else
        run(roundNo + 1);
}