#include "classes.h"
using namespace std;

QuestionAnswer::QuestionAnswer()
{
	questionNo++;
	this->questionId = "Q_No_" + to_string(questionNo);
	cout << "Enter Question:\n";
	cin >> question;
	cout << "Give the answer:\n";
	cin >> answer;
	writeToFile();
	stringMapper();
}

QuestionAnswer::QuestionAnswer(const string &ques)
{
	questionNo++;
	this->questionId = "Q_No_" + to_string(questionNo);
	this->question = ques;
	cout << "Give the answer:\n";
	cin >> answer;
	writeToFile();
	stringMapper();
}

QuestionAnswer::QuestionAnswer(const string &ques, const string &ans)
{
	questionNo++;
	this->questionId = "Q_No_" + to_string(questionNo);
	this->question = ques;
	this->answer = ans;
	writeToFile();
	stringMapper();
}

QuestionAnswer::QuestionAnswer(string fileName, int type)
{
	questionNo++;
	this->questionId = fileName;
	readFromFile(fileName);
	stringMapper();
}

void QuestionAnswer::stringMapper()
{
	string temp;
	
	for (int i = 0; i < question.length(); ++i)
	{
		if (question[i] != ' ' && question[i] != '?' && question[i] != ',')
		{
			temp.push_back(question[i]);
		}
		else
		{
			presentStrings[temp] = 1;

			temp.clear();
		}
	}
}

bool QuestionAnswer::match(const string &ques)
{
	string temp;
	float words = 0, count = 0;

	for (int i = 0; i < ques.length(); ++i)
	{
		if (ques[i] != ' ' && ques[i] != '?' && ques[i] != ',')
		{
			temp.push_back(ques[i]);
		}
		else
		{
			if (presentStrings[temp])
			{
				count++;
			}
			words++;
			temp.clear();
		}
	}

	if (count / words > 0.65)
	{
		return 1;
	}

	return 0;
}

string QuestionAnswer::getAnswer()
{
	return answer;
}

void QuestionAnswer::writeToFile()
{
	string fileName = questionId;
	ofstream os(fileName);
	os << question << endl
	   << answer << endl;
}

void QuestionAnswer::readFromFile(string fileName)
{
	ifstream ifs(fileName);
	getline(ifs, question);
	getline(ifs, answer);
}