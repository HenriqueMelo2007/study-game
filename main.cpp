#include <iostream>
#include <array>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

#define EARNING_ARR_SIZE 18
#define SPENDING_ARR_SIZE 7

const string txtFileName = "userdata.txt";

string userName;
string userCoins;
string userDiamonds;
string userRubies;

vector<string> userItems;

struct Value
{
  int coins;
  int diamonds;
  int rubies;
};

class Unit
{
public:
  int id;
  string tittle;
  Value thisValue;

  Unit(const string &tittle, int coins, int diamonds, int rubies, int id)
      : id(id), tittle(tittle), thisValue{coins, diamonds, rubies} {}
};

class Earning : public Unit
{
public:
  Earning(const string &tittle, int coins, int diamonds, int rubies, int id) : Unit(tittle, coins, diamonds, rubies, id) {}
  void increaseValues() {}
};

class Spending : public Unit
{
public:
  Spending(const string &tittle, int coins, int diamonds, int rubies, int id) : Unit(tittle, coins, diamonds, rubies, id) {}
  void decreaseValues() {}
};

bool checkTxtFile(const string &txtFilename);
void introduceTheGame();
void createTxtFile();
void readTxtFile();
void runGame();
void reWriteTxtFile();

int main()
{

  bool isThereFile = checkTxtFile(txtFileName);

  if (!isThereFile)
  {
    introduceTheGame();
    createTxtFile();
  }

  readTxtFile();

  array<Earning, EARNING_ARR_SIZE> earningGroup = {
      Earning("1 - Mental revision", 5, 0, 0, 1),
      Earning("2 - Written revision", 30, 0, 0, 2),
      Earning("3 - Digital revision", 20, 0, 0, 3),
      Earning("4 - Watch video lesson ( 0 - 5 min )", 5, 0, 0, 4),
      Earning("5 - Watch video lesson ( 6 - 15 min )", 10, 1, 0, 5),
      Earning("6 - Watch video lesson ( 16 - 30 min )", 15, 2, 1, 6),
      Earning("7 - Watch video lesson ( 31 - 59 min )", 30, 4, 2, 7),
      Earning("8 - Watch video lesson ( 1 hour - ++ )", 60, 10, 4, 8),
      Earning("9 - Teach someone", 10, 0, 0, 9),
      Earning("10 - Read an article", 10, 0, 0, 10),
      Earning("11 - Read a ChatGPT explanation", 5, 0, 0, 11),
      Earning("12 - Read a documentation", 15, 0, 1, 12),
      Earning("13 - Written exercise ( Easy )", 6, 0, 0, 13),
      Earning("14 - Digital exercise ( Easy )", 5, 0, 0, 14),
      Earning("15 -Written exercise ( Medium )", 11, 0, 0, 15),
      Earning("16 Digital exercise ( Medium )", 10, 0, 0, 16),
      Earning("17 - Written exercise ( Hard )", 16, 0, 1, 17),
      Earning("18 - Digital exercise ( Hard )", 15, 0, 1, 18),
  };

  array<Spending, SPENDING_ARR_SIZE> spendingGroup = {
      Spending("19 - Free day", 0, 100, 0, 19),
      Spending("20 - Free weekend", 50, 0, 120, 20),
      Spending("21 - Short break ( 10 min )", 15, 0, 0, 21),
      Spending("22 - Short break+ ( 15 min )", 20, 0, 0, 22),
      Spending("23 - Medium break ( 20 min )", 25, 0, 0, 23),
      Spending("24 - Medium break+ ( 30 min )", 35, 0, 0, 24),
      Spending("25 - The break ( 1 hour )", 60, 0, 0, 25),
  };

  runGame();

  reWriteTxtFile();

  return 0;
}

bool checkTxtFile(const string &txtFilename)
{
  ifstream txtFile(txtFilename);
  return txtFile.good();
}

void introduceTheGame()
{
  cout << "Welcome to the Study Game!" << endl;
  cout << "We're thrilled to have you join our learning adventure. This game is designed to make studying more engaging and rewarding. Here's how it works:" << endl;
  cout << "In the Study Game, you can earn rewards for various study-related activities. These rewards include coins, diamonds, and rubies. The more you study and engage with learning materials, the more you earn. Here’s a quick look at how you can earn rewards:" << endl;
}

void createTxtFile()
{
  cout << "Type your username: ";
  cin >> userName;

  ofstream txtFile(txtFileName);

  if (txtFile.is_open())
  {
    txtFile << userName << endl;
    txtFile << 0 << endl;
    txtFile << 0 << endl;
    txtFile << 0 << endl;
  }

  txtFile.close();
}

void readTxtFile()
{
  ifstream txtFile(txtFileName);

  if (!txtFile.is_open())
  {
    cerr << "Não foi possível abrir o arquivo: " << txtFileName << endl;
    return;
  }

  getline(txtFile, userName);
  getline(txtFile, userCoins);
  getline(txtFile, userDiamonds);
  getline(txtFile, userRubies);

  if (txtFile.fail())
  {
    cerr << "Erro ao ler o arquivo: " << txtFileName << endl;
  }

  txtFile.close();
}

void runGame() {}

void reWriteTxtFile()
{
  ofstream txtFile(txtFileName);

  if (txtFile.is_open())
  {
    txtFile << userName << endl;
    txtFile << userCoins << endl;
    txtFile << userDiamonds << endl;
    txtFile << userRubies << endl;
  }

  txtFile.close();
}