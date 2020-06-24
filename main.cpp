#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <thread>
#include <chrono>

using namespace std;

struct rightSide{
    string guess    = "                  ";
    string letters1 = "    ABCDEFGHIJ    ";
    string letters2 = "    KLMNOPQRST    ";
    string letters3 = "      UVWXYZ      ";
    string message  = "";
    string message2 = "";
};

string getWord(int nr){
    ifstream in("/home/cshark/Documents/Git/ConsoleHangman/words.txt");
    string word;
    for (int i = 0; i < nr; ++i) {
        in >> word;
    }
    return word;
}

bool checkForWin(const rightSide& rightSide){
    if((rightSide.guess.find('_') < 0) || (rightSide.guess.find('_') > 19)){
        return true;
    } else
        return false;
}

int isValid(string guess,const rightSide& rightSide){
    transform(guess.begin(),guess.end(),guess.begin(), ::toupper);
    int l1=rightSide.letters1.find(guess),l2=rightSide.letters2.find(guess),l3=rightSide.letters3.find(guess);
    if(guess.empty())
        return 2; //empty input
    if(guess.size() > 1)
        return 3; //only 1 character allowed
    if(!(guess == "A" || guess == "B" || guess == "C" || guess == "D" || guess == "E" || guess == "F" || guess == "G" || guess == "H" || guess == "I" || guess == "J" || guess == "K" || guess == "L" || guess == "M" || guess == "N" || guess == "O" || guess == "P" || guess == "Q" || guess == "R" || guess == "S" || guess == "T" || guess == "U" || guess == "V" || guess == "W" || guess == "X" || guess == "Y" || guess == "Z"))
        return 4; //character not valid
    if(!((rightSide.letters1.find(guess) <= 19 && rightSide.letters1.find(guess) > 0) || (rightSide.letters2.find(guess) <= 19 && rightSide.letters2.find(guess) > 0) || (rightSide.letters3.find(guess) <= 19 && rightSide.letters3.find(guess) > 0)))
        return 5; //letter already guessed
    return 1;
}

void isGood(string guess, string word, rightSide& rightSide, short int& mistakes){
    int appearance = 0;
    if(word.find(guess) <= word.size() && word.find(guess) >= 0){
        while (word.find(guess) <= word.size()) {
            int startpos = 9 - word.size() / 2 - 1;
            int inwordpos = word.find(guess);
            int pos = startpos + inwordpos;
            rightSide.guess[pos] = word[inwordpos];
            word[inwordpos] = '-';
            appearance++;
        }
        if(appearance <= 1)
            rightSide.message = "Lertter '" + guess + "' appears " + to_string(appearance) + " time!";
        else
            rightSide.message = "Lertter '" + guess + "' appears " + to_string(appearance) + " times!";
    } else{
        mistakes++;
        rightSide.message = "There are no '" + guess + "'s in the word!";
    }
}

void show(rightSide& rightSide,const int& mistakes, bool& alive, bool win, string word){
    if (win)
        rightSide.message2 = "You win!";
    else
        rightSide.message2 = "Please input a letter: ";
    switch (mistakes) {
        //stage 0
        case 0: {
            cout << endl << endl
                 << "        ┏━━━━━━━━┓           " << endl
                 << "        ┃        ┃           " << rightSide.guess << endl
                 << "        ┃                    " << endl
                 << "        ┃                    " << endl
                 << "        ┃                    " << rightSide.letters1 << endl
                 << "        ┃                    " << rightSide.letters2 << endl
                 << "        ┃                    " << rightSide.letters3 << endl
                 << "        ┃                    " << endl
                 << " ━━━━━━━┻━━━━━━━             " << endl << endl
                 << rightSide.message << endl << endl;
            if (win) {
                rightSide.message2 = "You win!";
                cout << rightSide.message2;
                cout.flush();
                std::this_thread::sleep_for(std::chrono::seconds(3));
                cout << endl << endl << endl << endl << endl << endl;
            }else {
                rightSide.message2 = "Please input a letter: ";
                cout << rightSide.message2;
                cout.flush();
            }
            break;
        }
        case 1: {
            //stage 1
            cout << endl << endl
                 << "        ┏━━━━━━━━┓           " << endl
                 << "        ┃        ┃           " << rightSide.guess << endl
                 << "        ┃       ◜ ◝          " << endl
                 << "        ┃       ◟ ◞          " << endl
                 << "        ┃                    " << rightSide.letters1 << endl
                 << "        ┃                    " << rightSide.letters2 << endl
                 << "        ┃                    " << rightSide.letters3 << endl
                 << "        ┃                    " << endl
                 << " ━━━━━━━┻━━━━━━━             " << endl << endl
                 << rightSide.message << endl << endl;
            if (win) {
                rightSide.message2 = "You win!";
                cout << rightSide.message2;
                cout.flush();
                std::this_thread::sleep_for(std::chrono::seconds(3));
                cout << endl << endl << endl << endl << endl << endl;
            }else {
                rightSide.message2 = "Please input a letter: ";
                cout << rightSide.message2;
                cout.flush();
            }
            break;
        }
        case 2: {
            //stage 2
            cout << endl << endl
                 << "        ┏━━━━━━━━┓           " << endl
                 << "        ┃        ┃           " << rightSide.guess << endl
                 << "        ┃       ◜ ◝          " << endl
                 << "        ┃       ◟ ◞          " << endl
                 << "        ┃        ┃           " << rightSide.letters1 << endl
                 << "        ┃        ┃           " << rightSide.letters2 << endl
                 << "        ┃        ┃           " << rightSide.letters3 << endl
                 << "        ┃                    " << endl
                 << " ━━━━━━━┻━━━━━━━             " << endl << endl
                 << rightSide.message << endl << endl;
            if (win) {
                rightSide.message2 = "You win!";
                cout << rightSide.message2;
                cout.flush();
                std::this_thread::sleep_for(std::chrono::seconds(3));
                cout << endl << endl << endl << endl << endl << endl;
            }else {
                rightSide.message2 = "Please input a letter: ";
                cout << rightSide.message2;
                cout.flush();
            }
            break;
        }
        case 3: {
            //stage 3
            cout << endl << endl
                 << "        ┏━━━━━━━━┓           " << endl
                 << "        ┃        ┃           " << rightSide.guess << endl
                 << "        ┃       ◜ ◝          " << endl
                 << "        ┃       ◟ ◞          " << endl
                 << "        ┃        ┃           " << rightSide.letters1 << endl
                 << "        ┃        ┃           " << rightSide.letters2 << endl
                 << "        ┃        ┃           " << rightSide.letters3 << endl
                 << "        ┃       ╱            " << endl
                 << " ━━━━━━━┻━━━━━━━             " << endl << endl
                 << rightSide.message << endl << endl;
            if (win) {
                rightSide.message2 = "You win!";
                cout << rightSide.message2;
                cout.flush();
                std::this_thread::sleep_for(std::chrono::seconds(3));
                cout << endl << endl << endl << endl << endl << endl;
            }else {
                rightSide.message2 = "Please input a letter: ";
                cout << rightSide.message2;
                cout.flush();
            }
            break;
        }
        case 4: {
            //stage 4
            cout << endl << endl
                 << "        ┏━━━━━━━━┓           " << endl
                 << "        ┃        ┃           " << rightSide.guess << endl
                 << "        ┃       ◜ ◝          " << endl
                 << "        ┃       ◟ ◞          " << endl
                 << "        ┃        ┃           " << rightSide.letters1 << endl
                 << "        ┃        ┃           " << rightSide.letters2 << endl
                 << "        ┃        ┃           " << rightSide.letters3 << endl
                 << "        ┃       ╱ ╲          " << endl
                 << " ━━━━━━━┻━━━━━━━             " << endl << endl
                 << rightSide.message << endl << endl;
            if (win) {
                rightSide.message2 = "You win!";
                cout << rightSide.message2;
                cout.flush();
                std::this_thread::sleep_for(std::chrono::seconds(3));
                cout << endl << endl << endl << endl << endl << endl;
            }else {
                rightSide.message2 = "Please input a letter: ";
                cout << rightSide.message2;
                cout.flush();
            }
            break;
        }
        case 5: {
            //stage 5
            cout << endl << endl
                 << "        ┏━━━━━━━━┓           " << endl
                 << "        ┃        ┃           " << rightSide.guess << endl
                 << "        ┃       ◜ ◝          " << endl
                 << "        ┃       ◟ ◞          " << endl
                 << "        ┃       ╱┃           " << rightSide.letters1 << endl
                 << "        ┃        ┃           " << rightSide.letters2 << endl
                 << "        ┃        ┃           " << rightSide.letters3 << endl
                 << "        ┃       ╱ ╲          " << endl
                 << " ━━━━━━━┻━━━━━━━             " << endl << endl
                 << rightSide.message << endl << endl;
            if (win) {
                rightSide.message2 = "You win!";
                cout << rightSide.message2;
                cout.flush();
                std::this_thread::sleep_for(std::chrono::seconds(3));
                cout << endl << endl << endl << endl << endl << endl;
            }else {
                rightSide.message2 = "Please input a letter: ";
                cout << rightSide.message2;
                cout.flush();
            }
            break;
        }
        case 6: {
            //stage 6
            cout << endl << endl
                 << "        ┏━━━━━━━━┓           " << endl
                 << "        ┃        ┃           " << rightSide.guess << endl
                 << "        ┃       ◜ ◝          " << endl
                 << "        ┃       ◟ ◞          " << endl
                 << "        ┃       ╱┃╲          " << rightSide.letters1 << endl
                 << "        ┃        ┃           " << rightSide.letters2 << endl
                 << "        ┃        ┃           " << rightSide.letters3 << endl
                 << "        ┃       ╱ ╲          " << endl
                 << " ━━━━━━━┻━━━━━━━             " << endl << endl
                 << rightSide.message << endl << endl
                 << "Game over! The word was: " + word + ".";
            cout.flush();
                std::this_thread::sleep_for(std::chrono::seconds(3));
            cout << endl << endl << endl << endl << endl << endl;
            alive = false;
            break;
        }
    }
}

void markAsGuessed(rightSide& rightSide, string guess){
    if (rightSide.letters1.find(guess) <= 18){
        rightSide.letters1[rightSide.letters1.find(guess)] = '-';
    } else if(rightSide.letters2.find(guess) <= 18){
        rightSide.letters2[rightSide.letters2.find(guess)] = '-';
    } else if(rightSide.letters3.find(guess) <= 18){
        rightSide.letters3[rightSide.letters3.find(guess)] = '-';
    }
}

void initRightSideGuess(rightSide& rightSide,const string& word){
    int start = 9 - word.size() / 2 - 1, finish = start + word.size();
    //add "_" in rightSide.guess
    for (int i = start, n = 0; i < finish; ++i) {
        rightSide.guess[i] = '_';
        n++;
    }
}

void setSeed(){
    srand(time(nullptr));
}

void getRandomWord(rightSide& rightSide, string& word){
    setSeed();
    int ranword = rand() % 854;
    word = getWord(ranword);
    initRightSideGuess(rightSide,word);
}

bool game(rightSide& rightSide, short int& mistakes, bool& alive, string& word, bool& win){
    show(rightSide,mistakes,alive,0,word);
    while (alive) {
        string guess;
        cin >> guess;
        transform(guess.begin(), guess.end(), guess.begin(), ::toupper);
        bool win = checkForWin(rightSide);
        switch (isValid(guess, rightSide)) {
            case 1:
                isGood(guess, word, rightSide, mistakes);
                markAsGuessed(rightSide, guess);
                win = checkForWin(rightSide);
                show(rightSide, mistakes, alive, win, word);
                break;
            case 2:
                rightSide.message = "Input can't be empty!";
                show(rightSide, mistakes, alive, win, word);
                break;
            case 3:
                rightSide.message = "Please enter 1 letter at a time!";
                show(rightSide, mistakes, alive, win, word);
                break;
            case 4:
                rightSide.message = "Please input a letter!";
                show(rightSide, mistakes, alive, win, word);
                break;
            case 5:
                rightSide.message = "Letter already guessed!";
                show(rightSide, mistakes, alive, win, word);
                break;
        }
        if (win)
            return true;
        if (alive == false)
            return false;
    }
}

bool startGame(rightSide& rightSide, short int& mistakes, bool& alive, string& word, bool& win){
    mistakes = 0;
    win = false;
    alive = 1;
    word = "";
    rightSide.guess    = "                  ";
    rightSide.letters1 = "    ABCDEFGHIJ    ";
    rightSide.letters2 = "    KLMNOPQRST    ";
    rightSide.letters3 = "      UVWXYZ      ";
    rightSide.message  = "";
    rightSide.message2 = "";
    getRandomWord(rightSide, word);
    bool hasWon = game(rightSide,mistakes,alive,word,win);
}

void checkIfGameIsWon(const bool& hasWon, unsigned short int& wins, unsigned short int& loses){
    if (hasWon) {
        wins++;
        return;
    } else {
        loses++;
        return;
    }
}

void mainMenu(rightSide& rightSide, short int& mistakes, unsigned short int& wins, unsigned short int& loses, bool& alive, bool& win, string& word){
    bool quit = false, correctOption = false;
    int option;
    while (!quit) {
        correctOption = false;
        cout << "  _    _                                            _               _____     _                _    \n"
                " | |  | |                                          | |             / ____|   | |              | |   \n"
                " | |__| | __ _ _ __   __ _ _ __ ___   __ _ _ __    | |__  _   _   | |     ___| |__   __ _ _ __| | __\n"
                " |  __  |/ _` | '_ \\ / _` | '_ ` _ \\ / _` | '_ \\   | '_ \\| | | |  | |    / __| '_ \\ / _` | '__| |/ /\n"
                " | |  | | (_| | | | | (_| | | | | | | (_| | | | |  | |_) | |_| |  | |____\\__ \\ | | | (_| | |  |   < \n"
                " |_|  |_|\\__,_|_| |_|\\__, |_| |_| |_|\\__,_|_| |_|  |_.__/ \\__, |   \\_____|___/_| |_|\\__,_|_|  |_|\\_\\\n"
                "                      __/ |                                __/ |                                    \n"
                "                     |___/                                |___/                                     "
             << endl << endl << endl
             << "     Statistics:     " << endl << endl
             << "Wins: " << wins << " "
             << "Loses: " << loses << "."
             << endl << endl << endl
             << "Press 1 for a new game."
             << endl << endl
             << "Press 2 to exit."
             << endl << endl << endl;

        while (!correctOption) {
            cout << "Please enter your option: ";
            if(cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            cin >> option;
            if (option == 1) {
                //start a new game
                bool hasWon = startGame(rightSide, mistakes, alive, word, win);
                checkIfGameIsWon(hasWon, wins, loses);
                correctOption = true;
                break;
            } else if (option == 2) {
                quit = true;
                correctOption = true;
                break;
            } else{
                cout << endl << endl;
                cout << "Invalid option!" << endl << endl;
            }
        }
    }
}

int main() {
    rightSide rightSide;
    short int mistakes = 0;
    unsigned short int wins = 0,loses = 0;
    bool alive = 1;
    bool win = 0;
    string word;
    mainMenu(rightSide,mistakes,wins,loses,alive,win,word);
}
/* 2500
  1.
        ┏━━━━━━━━┓
        ┃        ┃
        ┃
        ┃
        ┃
        ┃
        ┃
        ┃
 ━━━━━━━┻━━━━━━━
  2.
        ┏━━━━━━━━┓
        ┃        ┃
        ┃       ◜ ◝
        ┃       ◟ ◞
        ┃
        ┃
        ┃
        ┃
 ━━━━━━━┻━━━━━━━
  3.
        ┏━━━━━━━━┓
        ┃        ┃
        ┃       ◜ ◝
        ┃       ◟ ◞
        ┃        ┃
        ┃        ┃
        ┃        ┃
        ┃
 ━━━━━━━┻━━━━━━━
  4.
        ┏━━━━━━━━┓
        ┃        ┃
        ┃       ◜ ◝
        ┃       ◟ ◞
        ┃        ┃
        ┃        ┃
        ┃        ┃
        ┃       ╱
 ━━━━━━━┻━━━━━━━
  5.
        ┏━━━━━━━━┓
        ┃        ┃
        ┃       ◜ ◝
        ┃       ◟ ◞
        ┃        ┃
        ┃        ┃
        ┃        ┃
        ┃       ╱ ╲
 ━━━━━━━┻━━━━━━━
  6.
        ┏━━━━━━━━┓
        ┃        ┃
        ┃       ◜ ◝
        ┃       ◟ ◞
        ┃       ╱┃
        ┃        ┃
        ┃        ┃
        ┃       ╱ ╲
 ━━━━━━━┻━━━━━━━
  7.
        ┏━━━━━━━━┓
        ┃        ┃
        ┃       ◜ ◝
        ┃       ◟ ◞
        ┃       ╱┃╲
        ┃        ┃
        ┃        ┃
        ┃       ╱ ╲
 ━━━━━━━┻━━━━━━━
 */


