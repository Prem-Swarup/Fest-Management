project: main.o Attendee.o Participant.o Team.o Event.o NonCompetitiveEvent.o CompetitiveEvent.o timeline.o knockouts.o league.o Standings.o ParticipantInfo.o chatbot.o QuestionAnswer.o fest.o 
	g++ -o project main.o Attendee.o Participant.o Team.o Event.o NonCompetitiveEvent.o CompetitiveEvent.o timeline.o knockouts.o league.o Standings.o ParticipantInfo.o chatbot.o QuestionAnswer.o fest.o

Attendee.o: classes.h Attendee.cpp
	g++ -c Attendee.cpp

Participant.o: classes.h Participant.cpp
	g++ -c Participant.cpp

Team.o: classes.h Team.cpp
	g++ -c Team.cpp

Event.o: classes.h Event.cpp
	g++ -c Event.cpp

NonCompetitiveEvent.o: classes.h NonCompetitiveEvent.cpp
	g++ -c NonCompetitiveEvent.cpp

CompetitiveEvent.o: classes.h CompetitiveEvent.cpp
	g++ -c CompetitiveEvent.cpp

timeline.o: classes.h timeline.cpp
	g++ -c timeline.cpp

knockouts.o: classes.h knockouts.cpp
	g++ -c knockouts.cpp

league.o: classes.h league.cpp
	g++ -c league.cpp

Standings.o: classes.h Standings.cpp
	g++ -c Standings.cpp

ParticipantInfo.o: classes.h ParticipantInfo.cpp
	g++ -c ParticipantInfo.cpp 

chatbot.o: classes.h chatbot.cpp
	g++ -c chatbot.cpp

QuestionAnswer.o: classes.h QuestionAnswer.cpp
	g++ -c QuestionAnswer.cpp

fest.o: classes.h fest.cpp 
	g++ -c fest.cpp

main.o: classes.h main.cpp
	g++ -c main.cpp

clean:
	rm *.o project
