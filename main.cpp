#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>

using namespace std;

struct rightSide{
    string guess    = "                  ";
    string letters1 = "    ABCDEFGHIJ    ";
    string letters2 = "    KLMNOPQRST    ";
    string letters3 = "      UVWXYZ      ";
    string message ="";
};

string getWord(int nr){
    ifstream in("/home/cshark/Documents/Git/ConsoleHangman/words.txt");
    string word;
    for (int i = 0; i < nr; ++i) {
        in >> word;
    }
    return word;
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
        rightSide.message = "Lertter '" + guess + "' appears " + to_string(appearance) + " times!";
    } else{
        mistakes++;
        rightSide.message = "There are no '" + guess + "'s in the word!";
    }
}

void show(const rightSide& rightSide, int mistakes, bool& alive){
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
                 << rightSide.message << endl << endl
                 << "Please input a letter: ";
            cout.flush();
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
                 << rightSide.message << endl << endl
                 << "Please input a letter: ";
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
                 << rightSide.message << endl << endl
                 << "Please input a letter: ";
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
                 << rightSide.message << endl << endl
                 << "Please input a letter: ";
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
                 << rightSide.message << endl << endl
                 << "Please input a letter: ";
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
                 << rightSide.message << endl << endl
                 << "Please input a letter: ";
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
                 << "Game over!";
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

int main() {
    rightSide rightSide;
    int ranword;
    short int mistakes = 0;
    bool alive = 1;


    srand(time(nullptr));
    ranword = rand() % 854;

    string word = getWord(ranword);
    int start = 9 - word.size() / 2 - 1, finish = start + word.size();

    //add "_" in rightSide.guess
    for (int i = start, n = 0; i < finish; ++i) {
        rightSide.guess[i] = '_';
        n++;
    }
    show(rightSide,mistakes,alive);
    while (alive) {
        string guess;
        cin >> guess;
        transform(guess.begin(), guess.end(), guess.begin(), ::toupper);
        switch (isValid(guess, rightSide)) {
            case 1:
                isGood(guess, word, rightSide, mistakes);
                markAsGuessed(rightSide, guess);
                show(rightSide, mistakes, alive);
                break;
            case 2:
                rightSide.message = "Input can't be empty!";
                break;
            case 3:
                rightSide.message = "Please enter 1 letter at a time!";
                break;
            case 4:
                rightSide.message = "Please input a letter!";
                break;
            case 5:
                rightSide.message = "Letter already guessed!";
                break;
        }
    }
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


