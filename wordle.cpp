#include<iostream>
#include<fstream>
#include<vector>
#include<ctime>

using namespace std;

const string GREEN = "\033[32m";
const string YELLOW = "\033[33m";
const string GRAY = "\033[90m";
const string RESET = "\033[0m";

vector<string> LOADDICTIONARY(const string &filename){
    vector<string> wordBank;
    ifstream file(filename);

    if(!file.is_open()){
        cout << "Error: Could not find '" << filename << "." << endl;
        return wordBank;
    }

    string fileWord;
    while(getline(file, fileWord)){
        for(int i = 0; i < fileWord.length(); i++){
            fileWord[i] = toupper(fileWord[i]);
        }
        wordBank.push_back(fileWord);
    }
    file.close();
    return wordBank;
}

string GETRANDOMWORD(const vector<string> &dict){
    if(dict.empty()){
        return "";
    }
    int index = rand() % dict.size();
    return dict[index];
}

bool VALIDATEINPUT(string &input){
    if(input.length() != 5){
        cout << "Word must be exactly 5 letters!" << endl;
        return false;
    }
    for(int i = 0; i < input.length(); i++){
        input[i] = toupper(input[i]);
    }
    return true;
}

bool CHECKGUESS(const string &guess, const string &target){
    if(guess == target){
        cout << GREEN << guess << RESET << "\nYou Won!" << endl;
        return true; 
    }
    for (int i = 0; i < 5; i++) {
        if(guess[i] == target[i]){
            cout << GREEN << guess[i] << RESET;
        } 
        else if(target.find(guess[i]) != string::npos){                    
            cout << YELLOW << guess[i] << RESET;
        } 
        else{
            cout << GRAY << guess[i] << RESET;
        }
    }
    cout << endl;
    return false; 
}

int main() {
    srand((time(nullptr)));

    cout << "=== TERMINAL WORDLE ===" << endl;
    
    vector<string> dictionary = LOADDICTIONARY("wordle-answers-alphabetical.txt");
    if(dictionary.empty()) return 1; 

    bool keepPlaying = true;

    while(keepPlaying){
        string target = GETRANDOMWORD(dictionary);
        int attempts = 5;
        bool won = false;

        cout << "Type a 5-letter word and press Enter." << endl;

        while(attempts > 0){
            string guess;
            cout << "\nGuess (" << attempts << " left): ";
            cin >> guess;

            if(!VALIDATEINPUT(guess)){                                   
                continue;                                                
            }
            won = CHECKGUESS(guess, target);
            if(won){
                break;                                                   
            }
            attempts--;
        }
        if(!won){
            cout << "\nGame Over! The word was " << target << endl;
        }
        char choice;
        cout << "\nPlay again with a new word? (y/n): \n";
        cin >> choice;
        
        if(choice != 'y'){
            keepPlaying = false;
        }
    }
    cout << "Thanks for playing!" << endl;
    return 0;
}