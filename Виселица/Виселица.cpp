#include <iostream>
#include<vector>
#include<fstream>
#include <random>
#include<string>
#ifdef _WIN32
#include <windows.h>
#endif
using namespace std;
int getRandomNumber(int min, int max) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(min, max);
    return distribution(gen);
}

class word {
private:
    struct word_
    {
        char let;
        bool isVisible;
    };

    vector<word_> gueseWord;
public:
    word()
    {

    }
    void setWorld(string word)
    {
        for (int i = 0; i < word.size(); i++)
        {
            word_ w;
            w.let = word[i];
            w.isVisible = false;
            gueseWord.push_back(w);
        }
    }
    void display()
    {
        for (int i = 0; i < gueseWord.size(); i++)
        {
            if (gueseWord[i].isVisible == true)
            {
                cout << gueseWord[i].let;
            }
            else cout << '_';
        }
    }
    bool isGuessed(char let)
    {
        bool isGuessed_ = false;
        for (int i = 0; i < gueseWord.size(); i++)
        {
            if (gueseWord[i].let == let)
            {
                gueseWord[i].isVisible = true;
                isGuessed_ = true;
            }
        }
        return isGuessed_;
    }
    bool isVisible()
    {
        for (int i = 0; i < gueseWord.size(); i++)
        {
            if (gueseWord[i].isVisible == false)
            {
                return false;
            }

        }
        return true;
    }
};
string getRandomWordFromFile(string file, int levelOfHard)
{
    vector<string> words;
    string word;
    ifstream inFile(file);
    // Open the file before reading from it
    string line;
    while (getline(inFile, line))
    {
        words.push_back(line);
    }
    if (levelOfHard == 1)
    {
        word = words[getRandomNumber(0, 35731)];
    }
    else if (levelOfHard == 2)
    {
        word = words[getRandomNumber(35732, 48617)];
    }
    else if (levelOfHard == 3)
    {
        word = words[getRandomNumber(48617, 51246)];
    }
    inFile.close();
    return word;
}
class game {
public:
    int levelOfHard;
    game()
    {
        int attempts = 6;
        cout << "Ввеите уровень сложности(1-3): ";
        cin >> levelOfHard;
        cout << " _________" << endl;
        cout << " |       |" << endl;
        cout << " |       " << endl;
        cout << " |       " << endl;
        cout << " |       " << endl;
        cout << " |       " << endl;
        word gueseWord;
        char let;
        string wrongLet;
        gueseWord.setWorld(getRandomWordFromFile("russian.txt", levelOfHard));
        do
        {
            system("cls");
            if (attempts == 5) {
                cout << " _________" << endl;
                cout << " |       |" << endl;
                cout << " |       O" << endl;
                cout << " |       " << endl;
                cout << " |       " << endl;
                cout << " |       " << endl;
            }
            if (attempts == 4) {
                cout << " _________" << endl;
                cout << " |       |" << endl;
                cout << " |       O" << endl;
                cout << " |       |" << endl;
                cout << " |       " << endl;
                cout << " |       " << endl;
            }
            if (attempts == 3) {
                cout << " _________" << endl;
                cout << " |       |" << endl;
                cout << " |       O" << endl;
                cout << " |      /|" << endl;
                cout << " |       " << endl;
                cout << " |       " << endl;
            }
            if (attempts == 2) {
                cout << " _________" << endl;
                cout << " |       |" << endl;
                cout << " |       O" << endl;
                cout << " |      /|\\" << endl;
                cout << " |       " << endl;
                cout << " |       " << endl;
            }
            if (attempts == 1) {
                cout << " _________" << endl;
                cout << " |       |" << endl;
                cout << " |       O" << endl;
                cout << " |      /|\\" << endl;
                cout << " |      /" << endl;
                cout << " |       " << endl;
            }
            if (attempts == 0) {
                
            }
            gueseWord.display();
            cout << "Использованные буквы: ";
            for (int i = 0; i < wrongLet.size(); i++) {
                cout << wrongLet[i] << " ";
            };
            cout << endl << "Введите букву: ";
            cin >> let;
            wrongLet += let;
            if (gueseWord.isGuessed(let))
            {
                cout << endl << "Вы угадали букву!" << endl;
                if (gueseWord.isVisible())
                {
                    cout << endl << "Вы выиграли!" << endl;
                    break;
                }
            }
            else {
                cout << endl << "Вы не угадали букву!" << endl;
                attempts--;
            }

            cout << endl;
        } while (attempts != 0);
        cout << "Вас повесили" << endl;
        cout << " _________" << endl;
        cout << " |       |" << endl;
        cout << " |       O" << endl;
        cout << " |      /|\\" << endl;
        cout << " |      / \\" << endl;
        cout << " |       " << endl;
    }
};
int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    game();
}