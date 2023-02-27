#include "classes.h"
using namespace std;

template <class T, class U>
Standings<T, U>::Standings(vector<T> *_Participants, int _Players)
{
    this->Participants = _Participants;
    this->Players = _Players;
    for (int i = 0; i < this->Players; i++)
    {
        U temp_Participant_info((*(this->Participants)[i]));
        LeaderBoard.push_back(temp_Participant_info);
    }
    sort(LeaderBoard.begin(), LeaderBoard.end(), compare);
}

template <class T, class U>
void Standings<T, U>::PrintStandings()
{
    cout<<"Rank "<< " Player Name "<< " Player ID "<< " Rating "<<endl;
    for(int i=0; i<Players; i++){
        cout<< i+1<<"  "<<Participants[i].getName()<<"  "<<Participants[i].getID()<<"  "<<Participants[i].getRating()<<endl;
    }
}