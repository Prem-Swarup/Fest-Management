#include "classes.h"
using namespace std;

template <class T>
ParticipantInfo<T>::ParticipantInfo(T _Participant)
{
    this->Participant_Name = _Participant.getName();
    this->Participant_ID = _Participant.getID();
    this->Rating = _Participant.getRating();
}

template <class T>
int ParticipantInfo<T>::getRating()
{
    return Rating;
}

template <class T>
int ParticipantInfo<T>::getID()
{
    return Participant_ID;
}

template <class T>
string ParticipantInfo<T>::getName()
{
    return Participant_Name;
}