#include <objects.h>
#include <algorithm>
#include "ASCII/riddler_ascii.h"
#include "common/printing.hpp"
#include "common/random_generator.h"

using namespace std;

class Riddler : public spawnableObject {
private:
    string m_greet = "Hello There, i am the Riddler. If you solve my Riddle, you will get a reward";
    
    string r1 = "I am always in the water but never getting wet. What am I?";
    vector<string> a1{"reflection", "spiegelbild", "reflektion"} ;

    string r2 = "The poor have me but the rich need me. What am I?";
    vector<string> a2{"nothing", "nichts", "none", "nada"};

    map<string, vector<string>> riddleCollection{{r1, a1}, {r2, a2}};

    [[nodiscard]] pair<string, vector<string>> getRandomRiddle() const {
        int collectionSize = (int)riddleCollection.size();
        int index = getRandomNumber(0, collectionSize);
        auto it = next(riddleCollection.begin(), index);
        return make_pair(it->first, it->second);
    }

    static bool checkAnswer(const vector<string>& correctAnswers, string& answer) {
        transform(answer.begin(), answer.end(), answer.begin(),
                  [](unsigned char c){ return std::tolower(c); });
        //for(const auto& correctAnswer : correctAnswers) {
        //    if(answer == correctAnswer)
        //        return true;
        // return false;
        if (any_of(correctAnswers.begin(), correctAnswers.end(), [&answer](const string& a){return (a==answer);}))
        {
            return true;
        }
        else {
           return false;
        }
    }

public:
    Riddler() : spawnableObject("Randy der Rätsler",
                                riddlerASCII,
                                spawnBoundaries{0,0,2,2})
                                {};

    void inspectByPlayer() override {
        print(m_greet);
        cout << riddlerASCII << endl;
    }

    bool askRiddle() {
        auto randomRiddle = getRandomRiddle();
        print(randomRiddle.first);

        string answer = playerInput();
        return checkAnswer(randomRiddle.second, answer);
    }
};