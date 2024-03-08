#include <iostream>
#include <random>
#include <vector>

using namespace std;

int main() {
    
    string words[] = {"Alex", "Jordan", "Taylor", "Morgan", "Casey", "Skyler", "Jamie", "Robin", "Smith", "Johnson", "Williams", "Jones", "Brown", "Davis", "Miller", "Wilson"};
    vector<string> letters;
        
    random_device rd;
    mt19937 gen(rd()); 

    uniform_int_distribution<> distr(1, size(words)); 

    int index = distr(gen);
    string word = words[index];

    int sizeWord = size(word);
    cout << "Word is " << word << endl;

    cout << sizeWord << " letter word" << endl;
    for (int i;i < sizeWord;i++) {
        letters.push_back(string(1, word[i]));
        cout << "_ ";
    }

    cout << endl;

    while (true){
        cout << "Guess the letters: ";
        string guess;
        cin >> guess;

        if (guess == word) {
            cout << "Correct Word Guessed!" << endl;
            break;
        }
        else if (size(guess) == 1) {
            for (size_t i = 0;i < sizeWord;i++) {
                if (letters[i] == guess) {  
                    
                    cout << guess << " is in the word" << endl;
                    
                    for (int i;i < sizeWord;i++) {
                        if (string(1, word[i]) == guess) {
                            cout << word[i] << endl;
                        }
                        else if (string(1, word[i]) != guess) {
                            cout << "_ ";
                        }
                    }
                }
            }
        }
    }

    
    return 0;
}