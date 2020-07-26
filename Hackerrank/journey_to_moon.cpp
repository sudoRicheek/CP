#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the journeyToMoon function below.
vector<int> astro[100000];
int visited[100000];
long len = 0;


void dfs(int k)
{
    visited[k] = 1;
    len++;
    for (int i = 0; i < astro[k].size(); i++)
    {
        if (!visited[astro[k][i]])
        {
            dfs(astro[k][i]);
        }
    }
}

long long journeyToMoon(int n, vector<vector<int>> &astronaut) {
    long long ans = 0 ;
    for(int i = 0 ; i < astronaut.size(); i++){
        astro[astronaut[i][0]].push_back(astronaut[i][1]);
        astro[astronaut[i][1]].push_back(astronaut[i][0]);
    }

    int i = 0;
    bool incomplete;
    while(true){
        len = 0;
        incomplete = false;
        dfs(i);
        ans += (len*(len-1))/2;
        for(int k = i+1; k < n ; k++){
            if(!visited[k]){
                i = k;
                incomplete = true;
                break;
            }
        }
        if(!incomplete){
            break;
        }
    }
    return (((long long)n*(n-1))/2 - ans);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string np_temp;
    getline(cin, np_temp);

    vector<string> np = split_string(np_temp);

    int n = stoi(np[0]);

    int p = stoi(np[1]);

    vector<vector<int>> astronaut(p);
    for (int i = 0; i < p; i++) {
        astronaut[i].resize(2);

        for (int j = 0; j < 2; j++) {
            cin >> astronaut[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    long long result = journeyToMoon(n, astronaut);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
