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

int leaveGame = 0;

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

  void introduceItself()
      const
  {
    cout << id << " - " << tittle << " ( " << "Coins: " << thisValue.coins << ", Diamonds: " << thisValue.diamonds << ", Rubies: " << thisValue.rubies << " ) " << endl;
  }
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
void createTxtFile();
void readTxtFile();
void introduceTheGame();
void runGame();
void reWriteTxtFile();

array<Earning, EARNING_ARR_SIZE> earningGroup = {
    Earning("Mental revision", 5, 0, 0, 1),
    Earning("Written revision", 30, 0, 0, 2),
    Earning("Digital revision", 20, 0, 0, 3),
    Earning("Watch video lesson ( 0 - 5 min )", 5, 0, 0, 4),
    Earning("Watch video lesson ( 6 - 15 min )", 10, 1, 0, 5),
    Earning("Watch video lesson ( 16 - 30 min )", 15, 2, 1, 6),
    Earning("Watch video lesson ( 31 - 59 min )", 30, 4, 2, 7),
    Earning("Watch video lesson ( 1 hour - ++ )", 60, 10, 4, 8),
    Earning("Teach someone", 10, 0, 0, 9),
    Earning("Read an article", 10, 0, 0, 10),
    Earning("Read a ChatGPT explanation", 5, 0, 0, 11),
    Earning("Read a documentation", 15, 0, 1, 12),
    Earning("Written exercise ( Easy )", 6, 0, 0, 13),
    Earning("Digital exercise ( Easy )", 5, 0, 0, 14),
    Earning("Written exercise ( Medium )", 11, 0, 0, 15),
    Earning("Digital exercise ( Medium )", 10, 0, 0, 16),
    Earning("Written exercise ( Hard )", 16, 0, 1, 17),
    Earning("Digital exercise ( Hard )", 15, 0, 1, 18),
};

array<Spending, SPENDING_ARR_SIZE> spendingGroup = {
    Spending("Free day", 0, 100, 0, 19),
    Spending("Free weekend", 50, 0, 120, 20),
    Spending("Short break ( 10 min )", 15, 0, 0, 21),
    Spending("Short break+ ( 15 min )", 20, 0, 0, 22),
    Spending("Medium break ( 20 min )", 25, 0, 0, 23),
    Spending("Medium break+ ( 30 min )", 35, 0, 0, 24),
    Spending("The break ( 1 hour )", 60, 0, 0, 25),
};

int main()
{
  bool isThereFile = checkTxtFile(txtFileName);

  if (!isThereFile)
  {
    createTxtFile();
  }

  readTxtFile();

  introduceTheGame();

  runGame();

  reWriteTxtFile();

  return 0;
}

bool checkTxtFile(const string &txtFilename)
{
  ifstream txtFile(txtFilename);
  return txtFile.good();
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

void introduceTheGame()
{
  cout << endl
       << "Welcome to the Study Game, " << userName << "!!!" << endl;
  cout << "We're thrilled to have you join our learning adventure. This game is designed to make studying more engaging and rewarding. Here's how it works:" << endl;
  cout << "Type a number. If the number corresponds to an activity, earn resources. If the number corresponds to a shop item, spend resources to acquire the item." << endl;
  cout << "----- To exit the game: type '99' -----" << endl
       << endl;
}

void runGame()
{
  cout << "*************** STUDY GAME ***************" << endl
       << endl;
  cout << "*************** Your activities: " << endl
       << endl;

  for (const Earning &i : earningGroup)
  {
    i.introduceItself();
  }

  cout << endl
       << "*************** Store: " << endl
       << endl;

  for (const Spending &i : spendingGroup)
  {
    i.introduceItself();
  }

  int operation = 0;

  do
  {
    cin >> operation;
    if (operation == 99)
    {
      cout << "I see you soon!" << endl;
    }
    else if (operation >= 1 && operation <= 18)
    {
      earningGroup[operation].increaseValues();
    }
    else if (operation >= 19 && operation <= 25)
    {
      spendingGroup[operation].decreaseValues();
    }
    else
    {
      cout << "Invalid command" << endl;
    }
  } while (operation != 99);
}

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