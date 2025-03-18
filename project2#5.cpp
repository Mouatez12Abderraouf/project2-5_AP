#include<iostream>
#include<cstdlib>
#include<cmath>
using namespace std;

enum level {Easy = 1,Med = 2,Hard = 3,MixLv = 4};

enum TypeOfOpearation {Add = 1,Sub = 2,Mul = 3,Div = 4,MixOp = 5};

struct QuestionRoumd
{
    short nbOfRoundsQuestion;
    float answer;
    level levelOfGame;
    TypeOfOpearation typeOfGame;
    char symbolOfOperation;
    float rightAnswer;
    short num1,num2;
};

struct ResultOfGame
{
    short nbQuestion;
    string nameOfLevel;
    string nameOfOpearation;
    short nbOfRightAnswer;
    short nbOfWorngAnswer;
    string FinalResult;
    string emujiiOfFinalResult;
};

int readInRange(string message,int from,int to)
{
    int num;

    do
    {
        cout << message ;
        cin >> num ;
    } while (num < from || num > to);
    
    return num;
}

void printNumberQuestion(short counter,short limite)
{
    cout << "-------------------" <<endl;
    cout << "|  Question [" << counter << "/" << limite << "] |" << endl;
    cout << "-------------------" <<endl;
}

int randomNumber(int from,int to)
{
    return from + (rand() % (to + 1 - from));
}

QuestionRoumd fillQuestion(QuestionRoumd info)
{
    
    if (info.levelOfGame == level::Easy)
    {
        info.num1 = randomNumber(1,10);
        info.num2 = randomNumber(1,10);
    }
    else
        if (info.levelOfGame == level::Hard)
        {
            info.num1 = randomNumber(50,100);
            info.num2 = randomNumber(50,100);
        }
        else
            if (info.levelOfGame == level::Med)
            {
                info.num1 = randomNumber(20,40);
                info.num2 = randomNumber(20,40);
            }
            else
            {
                info.num1 = randomNumber(1,100);
                info.num2 = randomNumber(1,100);
            }
    
 
    return info;
}

string tab(int numTab)
{
    string res;
    for(int i = 1;i <= numTab;i++)
    {
        res += '\t';
    }

    return res;

}

float readAnswer()
{
    float num;
    cin >> num;
    return num;
}

void printResult(QuestionRoumd info)
{
    if(info.answer == info.rightAnswer)
    {
        cout << "Right answer :-)\n";
    }
    else
    {
        cout << "worng answer :-(\n";
        cout << "the right answer is: " << info.rightAnswer << endl;
    }
    
}

void printOperation(QuestionRoumd info)
{
    cout << info.num1 << endl;
    cout << info.num2 << tab(1) << info.symbolOfOperation << endl;
    cout << "______________" << endl;

}

QuestionRoumd preparationQuestion(QuestionRoumd info)
{
    begin:

    switch (info.typeOfGame)
    {
    case TypeOfOpearation::Add :
        info.symbolOfOperation = '+';
        info.rightAnswer = info.num1 + info.num2;
        break;
    
    case TypeOfOpearation::Div :
        info.symbolOfOperation = '/';
        info.rightAnswer = info.num1 / info.num2;
        break;
    
    case TypeOfOpearation::Mul :
    info.symbolOfOperation = '*';
        info.rightAnswer = info.num1 * info.num2;
        break;
    case TypeOfOpearation::Sub :
        info.symbolOfOperation = '-';
        info.rightAnswer = info.num1 - info.num2;
        break;
    case TypeOfOpearation::MixOp :
        info.typeOfGame = (TypeOfOpearation)randomNumber(1,4);
        goto begin;
    }
    printOperation(info);
    info.answer = readAnswer();
    return info; 

}

void playGame(ResultOfGame gameOver)
{
    
    QuestionRoumd infOfRounds;
    infOfRounds.levelOfGame = (level)readInRange("Enter Question level [1] Easy, [2] Med, [3] Hard, [4] Mix ?",1,4);
    infOfRounds.typeOfGame = (TypeOfOpearation) readInRange("Enter operation type [1] Add, [2] Sub, [3] Mul, [4] Div, [5] Mix ?",1,5);
    for(infOfRounds.nbOfRoundsQuestion = 1; infOfRounds.nbOfRoundsQuestion <= gameOver.nbQuestion;infOfRounds.nbOfRoundsQuestion++)
    {
        printNumberQuestion(infOfRounds.nbOfRoundsQuestion, gameOver.nbQuestion);
        infOfRounds = fillQuestion(infOfRounds);
        printResult(infOfRounds);
        
    }
}
void RestartScreen()
{
    system("clr");
    system("color 0F");
}

void startGame()
{
    char offOn;
    ResultOfGame finalGame;


    do
    {
        RestartScreen();
        finalGame.nbQuestion = readInRange("how many question do you want to answer ?",1,10);
        playGame(finalGame);
        
        cout << "do you want to play again? [y/n]?" ;
        cin >> offOn; 
    } while (offOn == 'y' || offOn == 'Y');
    
}

int main()
{
    srand((unsigned) time(NULL));
    
    // startGame();
    float n = 3.443434;
    float s = n;
}