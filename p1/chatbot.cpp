#include "classes.h"
using namespace std;

chatbot::chatbot()
{

	int q_no = 1;
	string fileName = "Q_No_" + to_string(q_no);
	while (std::filesystem::exists(fileName))
	{
		Questions.push_back(QuestionAnswer(fileName, 1));
		totalQuestions++;
		q_no++;
		fileName = "Q_No_" + to_string(q_no);
	}
}

void chatbot::addQuestion()
{
	QuestionAnswer ques;
	Questions[totalQuestions] = ques;
	totalQuestions++;
}

void chatbot::addQuestion(const string &question)
{
	QuestionAnswer ques(question);
	Questions[totalQuestions] = ques;
	totalQuestions++;
}

void chatbot::addQuestion(const string &question, const string &answer)
{
	QuestionAnswer ques(question, answer);
	Questions[totalQuestions] = ques;
	totalQuestions++;
}

void chatbot::answerQuery(const string &ques)
{
	bool flag = 1;
	for (int i = 0; i < totalQuestions; ++i)
	{
		if (Questions[i].match(ques))
		{
			if (flag)
			{
				cout << "Here are answer(s), we got:\n";
			}
			cout << endl
				 << Questions[i].getAnswer() << endl;
			flag = 0;
		}
	}

	if (flag)
	{
		cout << "Sorry! We couldn't find any answer.\n";
		addQuesLog(ques);
	}

	cout << endl;
}

void chatbot::addQuesLog(const string &ques)
{
	quesLog.push_back(ques);
}

list<string> &chatbot::getQuesLog()
{
	return quesLog;
}