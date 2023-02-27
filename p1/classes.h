#include <bits/stdc++.h>
using namespace std;

class Attendee
{
private:
    string unique_id;
    string Name;
    string ContactNO;
    string emailid;
    static int totalAttendee;
    friend class Participant;

public:
    Attendee();
    Attendee(const Attendee &a);
    Attendee(string _name, string _contact, string _email);
    void inputDetails(ifstream &ifs_event, int type);
    string getUniqueID();
    int getAtCount();
    string getName();
    void getDetails();
    virtual void increaseRating(int);
};

class Participant : public Attendee
{
private:
    int Rating;

public:
    Participant();
    Participant(const Attendee &a);
    int getRating();
    void increaseRating(int inc); 
};

template <class T>
class Team
{
private:
    string teamName;
    int noPlayers = 0;
    int TRating;
    static int teamCount;

    int teamHead = 0;

    vector<T> Tmembers;

public:
    Team(string evID);

    void addMember(T member);
    void printMembers();
    void increaseTRating(int point);
    int getTRating();
    void setHead(string id);
};

class Timeline
{
    vector<class Event *> events;
    int totalEvents;
    int days;
    int venues;
    int startTime = 12;
    int endTime = 24;
    map<int, map<int, vector<int>>> schedule;
    unordered_map<int, pair<int, int>> id_schedule;
    unordered_map<int, unordered_map<int, int>> occupiedTime;

public:
    Timeline(int _days, int _venues);
    Timeline(int _totalEvents, vector<class Event *> &_events, int _days, int _venues);
    void prepareSchedule();
    void addEvent(Event *_event);
    pair<int, int> findTime(int duration, pair<int, int> _preference);
    void addToSchedule(int i);
    void addToSchedule(string id);
    int findIndex(string id);
    void changeSchedule(string, int day, int hour);
    void printSchedule();
    Event *operator()(int a, int b);
    pair<int, int> operator[](string id);
};

class chatbot
{
    vector<class QuestionAnswer> Questions;
    int totalQuestions = 0;
    list<string> quesLog;

public:
    chatbot();
    void addQuestion();
    void addQuestion(const string &ques);
    void addQuestion(const string &ques, const string &ans);
    void answerQuery(const string &ques);
    void addQuesLog(const string &ques);
    list<string> &getQuesLog();
};

class QuestionAnswer
{
    static int questionNo;
    string questionId;
    string question;
    string answer;
    unordered_map<string, bool> presentStrings;

public:
    QuestionAnswer();
    QuestionAnswer(const string &ques);
    QuestionAnswer(const string &ques, const string &ans);
    QuestionAnswer(string fileName, int type2);
    bool match(const string &ques);
    string getAnswer();
    void writeToFile();
    void readFromFile(string fileName);
    void stringMapper();
};

class Event
{
private:
    static int EventCount;

    string ID;
    string Name;
    string Head;
    string Information;
    vector<Attendee *> Participants;
    int Registrations = 0;
    int Duration;
    pair<int, int> PreferredDayAndTime;
    int Priority;
    friend class NonCompetitiveEvent;
    friend class CompetitiveEvent;
    friend class Timeline;
    friend class fest;

public:
    Event();
    Event(string _name, string _head, string _info, int _duration, pair<int, int> preference);
    void setName();
    string getName();
    void setHead();
    string getHead();
    virtual void setID();
    string getID();
    void setInfo();
    virtual string getInfo();
    void printDetails();
    virtual void addParticipant(Attendee *a);
    int getRegistrations();
    void setDuration();
    virtual int getDuration();
    Attendee *getParticipantbyID(string);
    pair<int, int> getPreference();
    void setPreference();
    void setPriority();
    int getPriority();
    bool ComparatorPriority(Event a, Event b);
    virtual void run(int);
};

class knockouts;

class CompetitiveEvent : public Event
{
private:
    static int CompetitiveEventCount;

    vector<pair<Participant, int>> Leaderboard;
    class fixtures *Fixture;
    friend class Timeline;

public:
    CompetitiveEvent();
    CompetitiveEvent(string _name, string _head, string _info, int _duration, pair<int, int> preference);
    void setID();
    void showLeaderboard();
    Participant getWinner();
    void run(int);
    void addParticipant(Attendee *a);
};

class NonCompetitiveEvent : public Event
{
private:
    static int NonCompetitiveEventCount;
    string GuestName;

public:
    NonCompetitiveEvent();
    NonCompetitiveEvent(string _name, string _head, string _info, int _duration, pair<int, int> preference);
    NonCompetitiveEvent(string);
    void setID();
    void setGuest(string);
    void printGuestName();
};

class fest
{
    vector<Attendee *> attendees;
    int totalAttendees;
    vector<Event *> events;
    int totalEvents;
    int days, venues;
    class Timeline *timeline;
    bool timelinePrepared = 0;
    ifstream ifs_event;
    ifstream ifs_attendee;
    class chatbot PARA;

public:
    fest(int _days, int _venues);
    void addAttendee();
    void addEvent(int type);
    void addEventParticipants(int i, int j);
    void prepareTimeline();
    void showTimeline();
    void askPARA(string ques);
    void addQnA();
    void addQnA(string ques, string ans);
    void runEvent(int i, int type);
};

class fixtures
{
    vector<Attendee *> Participants;
    int Players;
    friend class knockouts;
    friend class league;
};

template <class U>
bool compare(U a, U b)
{
    return a.getRating() >= b.getRating();
}

template <class T, class U>
class Standings
{
    vector<T> *Participants;
    int Players;
    vector<U> LeaderBoard;

public:
    Standings(vector<T> *_Participants, int _Players);
    void PrintStandings();
};

template <class T>
class ParticipantInfo
{
    string Participant_Name;
    int Participant_ID;
    int Rating;

public:
    ParticipantInfo(T _Participant);

    string getName();
    int getID();
    int getRating();
};

class knockouts : public fixtures
{
    int totalRounds;
    vector<vector<string>> rounds;

public:
    knockouts(vector<Attendee *> &_Participants, int _Players, string eventName);
    void run(int roundNo);
    void increaseRating(string winner, int points);
};

class league : public fixtures
{
    int totalMatches;
    int N;
    vector<string> ID;

public:
    league(vector<Attendee *> &_Participants, int _Players, string eventName);
};
