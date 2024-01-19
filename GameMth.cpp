#include<iostream>
#include <cstdlib>
#include<string>
using namespace std;
enum enQuastionLevel{Easy=1,Medium=2,Hard=3,Mix=4};
enum enOpType{Add=1,Subtraction=2,Multiply=3,Divide=4,mix=5 };
struct stQuizz {
	enQuastionLevel QuastionLevel;
	enOpType OpType;
	int Number1;
	int Number2;
	int HowManyQuastion;
};
struct stFinalResult {
	string Quastion1;
	enOpType OpType;
	int UrAnswer=0;
	int Answer1=0;
	int QuastionNumber;
};
int ReadNumber(string Message) {
		int Num;
		cout << Message;
		cin >> Num;
		return Num;
}
int RandomNumber(int from, int to) {
	int num = rand() %to - from + 1 + from;
	return num;
}
enOpType ChoiceOpType(int Choice) {
	
	int arrOpTypeChoices[5] = { 1,2,3,4,5};
	return (enOpType)arrOpTypeChoices[Choice - 1];
}
enOpType getOpTypeRandomly() {
	int i = RandomNumber(1, 4);
	return (enOpType)i;
}
enQuastionLevel QuastionLevelFromRead(int Num) {
	int arrQustion[4] = { 1,2,3,4 };
	return (enQuastionLevel)arrQustion[Num-1];
}
int ReadNumQustionLevel(enQuastionLevel QuastionLevel) {
	int Number1;
	Number1 = 0;
	switch (QuastionLevel) {
	case enQuastionLevel::Easy:
		Number1 = RandomNumber(1, 10);
		return Number1;
		break;
	case enQuastionLevel::Medium:
		Number1 = RandomNumber(10, 100);
		return Number1;
		break;
	case enQuastionLevel::Hard:
		Number1 = RandomNumber(100, 1000);
		return Number1;
		break;
		default:
		int i = RandomNumber(1, 3);
		return ReadNumQustionLevel((enQuastionLevel)i);
	}
}
void OpStorefromMix(stFinalResult & OpType1) {
OpType1.OpType=	getOpTypeRandomly();
}
string ReadOpType(enOpType OpType) {
	switch (OpType) {
	case enOpType::Add:
		return "+";
	case  enOpType::Subtraction:
		return "-";
		break;
	case  enOpType::Multiply:
		return "*";
		break;
	case enOpType::Divide:
		return "/";
	default:
		return
		ReadOpType(getOpTypeRandomly());
		break;
	}
} 
string QuastionGraph(int Number1, int Number2, enOpType OpType) {
	stFinalResult Quastion1;
	switch (OpType) {
	case enOpType::Add:
		return  Quastion1.Quastion1 = (to_string(Number1)+"\n          +\n"+ to_string( Number2) +"\n---------------\n");
		break;
	case enOpType::Subtraction:
		return Quastion1.Quastion1 = (to_string(Number1) + "\n          -\n" +to_string(Number2) + "\n---------------\n");
		break;
	case enOpType::Divide:
		return Quastion1.Quastion1 = (to_string(Number1) +"\n          /\n"+ to_string(Number2) + "\n---------------\n");
		break;
	case enOpType::mix:
		 OpStorefromMix(Quastion1);
		return QuastionGraph(Number1, Number2, Quastion1.OpType);
		break;
	default:
		return Quastion1.Quastion1 = (to_string(Number1) +"\n          *\n"+ to_string(Number2) + "\n---------------\n");
		break;
	}
}

void PrintQuastion(string qustion1)
{
	cout << qustion1;
}

int Answer(int Number1, int Number2, enOpType OpType) {
	switch (OpType) {
	case enOpType::Add:
		return (Number1 + Number2);
		break;
	case enOpType::Subtraction:
		return (Number1 - Number2);
		break;
	case enOpType::Divide:
		return (Number1 / Number2);
		break;
	default:
		return (Number1 * Number2);
		break;
	}
}
bool IsAnswerTrue(stFinalResult checkAnswer) {
	return (checkAnswer.UrAnswer == checkAnswer.Answer1);
}
void ShowColorscreen(stFinalResult Final) {
	if (IsAnswerTrue(Final)) {cout << "The Answer Is True :-)";
			system("color 2F");cout << endl;
			cout << " ur anwser Is :" << Final.UrAnswer;
			cout << " \n Our anwser Is " << Final.Answer1 << endl;;
	}
	else {
		cout << "The Answer IsFalse :-)";
		system("color 4E"); cout << endl;
		cout << " ur anwser Is :" << Final.UrAnswer;
		cout << " \n Our anwser Is " << Final.Answer1 << endl;;

	}
			
		
}
stFinalResult Fillresult() {
	stQuizz Quizz;
	stFinalResult Final;
	Quizz.HowManyQuastion = ReadNumber("Enter how Many Quastion U want To Answer?");
	Quizz.OpType = ChoiceOpType(ReadNumber("Enter Operation type [1] Add,[2] Sub,[3] Multi,[4] Div,[5] Mix ?"));
	Quizz.QuastionLevel = (QuastionLevelFromRead(ReadNumber("Enter Quastion Level [1] Easy ,[2] Medium,[3] Hard ,[4] Mix ? ")));
	int i = 1;
		
	do{	Quizz.Number1 = ReadNumQustionLevel(Quizz.QuastionLevel);
		Quizz.Number2 = ReadNumQustionLevel(Quizz.QuastionLevel);
		Final.Quastion1 = QuastionGraph(Quizz.Number1, Quizz.Number2, Final.OpType);
		
		
		PrintQuastion(Final.Quastion1);
		Final.UrAnswer = ReadNumber("");
Final.Answer1 = Answer(Quizz.Number1, Quizz.Number2, Final.OpType);
		ShowColorscreen(Final);
		i++;
	} while (i <= Quizz.HowManyQuastion);
	return Final;
}
void ResetScreen() {
	system("cls");
	system("color 0F");
}

void StartGame()
{
	char PlayAgain = 'Y';
	do {
		ResetScreen();
		Fillresult();
		cout << endl  << "Do You Want To Play Again ? Y/N ";
		cin >> PlayAgain;
	} while (PlayAgain =='Y'||PlayAgain=='y');
}
int main() {
	srand((unsigned)time(NULL));
	StartGame();
	return 0;
}

