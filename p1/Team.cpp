#include "classes.h"
using namespace std ;

template <class T>
void Team<T>::increaseTRating(int point)
{
    TRating+=point;
}

template <class T>
Team<T>::Team(string evID)
{
    teamCount++;
    string Tunique_id = evID + "00" + to_string(teamCount);
}

template <class T>
void Team<T>::addMember(T member)
{
    noPlayers++;
    Tmembers.push_back(member);
}

template <class T>
void Team<T>::printMembers()
{
    for (int i = 0; i < noPlayers; i++)
    {
        cout << Tmembers[i].getUniqueID() << " ";
        if (i == teamHead)
            cout << "(Team Head)";
        cout << endl;
    }
}

template <class T>
void Team<T>::setHead(string id)
{
    for (int i = 0; i < noPlayers; i++)
    {
        if (Tmembers[i].getUniqueID() == id)
        {
            teamHead = i;
            break;
        }
    }
}