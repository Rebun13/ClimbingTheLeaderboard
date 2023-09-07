#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY ranked
 *  2. INTEGER_ARRAY player
 */

vector<int> climbingLeaderboard(vector<int> ranked, vector<int> player) {
    vector<int> positions;
    set<int> rankedSet(ranked.begin(), ranked.end());
    vector<int> rankedList(rankedSet.begin(), rankedSet.end());
    int backwardsPosition = 0;
    for(int score : player) { // score: left to right
        // cout << "New score: [" << score << "]" << endl;
        // cout << "backwardsPosition: " << backwardsPosition << endl;

        bool found = false;
        for(int i = backwardsPosition; i < rankedList.size(); ++i) { // ranked: right to left
            // cout << "i value: " << rankedList[i] << endl;
            if(rankedList[i] > score) {
                // cout << score << " -> " << rankedList.size() - backwardsPosition + 1 << " position" << endl;
                found = true;
                positions.push_back(rankedList.size() - backwardsPosition + 1);
                break;
            } else if(rankedList[i] == score) {
                // cout << score << " -> " << rankedList.size() - backwardsPosition << " position" << endl;
                found = true;
                positions.push_back(rankedList.size() - backwardsPosition);
                break;
            }
            backwardsPosition++;
        }
        if(!found) {
            // cout << score << " -> Winner!" << endl;
            positions.push_back(1);
        } 
    }
    return positions;
}

int main()
{
    string ranked_count_temp;
    getline(cin, ranked_count_temp);

    int ranked_count = stoi(ltrim(rtrim(ranked_count_temp)));

    string ranked_temp_temp;
    getline(cin, ranked_temp_temp);

    vector<string> ranked_temp = split(rtrim(ranked_temp_temp));

    vector<int> ranked(ranked_count);

    for (int i = 0; i < ranked_count; i++) {
        int ranked_item = stoi(ranked_temp[i]);

        ranked[i] = ranked_item;
    }

    string player_count_temp;
    getline(cin, player_count_temp);

    int player_count = stoi(ltrim(rtrim(player_count_temp)));

    string player_temp_temp;
    getline(cin, player_temp_temp);

    vector<string> player_temp = split(rtrim(player_temp_temp));

    vector<int> player(player_count);

    for (int i = 0; i < player_count; i++) {
        int player_item = stoi(player_temp[i]);

        player[i] = player_item;
    }

    vector<int> result = climbingLeaderboard(ranked, player);

    for (size_t i = 0; i < result.size(); i++) {
        cout << result[i];

        if (i != result.size() - 1) {
            cout << "\n";
        }
    }

    cout << "\n";

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), [](unsigned char c) { return !ispunct(c); })
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), [](unsigned char c) { return !ispunct(c); }).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
