#include <bits/stdc++.h>

using namespace std;

// Complete the quickestWayUp function below.
int quickestWayUp(vector<vector<int>> ladders, vector<vector<int>> snakes) {
    vector<int> snl[101];
    int level[101];

    list<int> queue; 
    
    for(int i = 1; i <= 100; i++){
        for(int j = 1; j <= 6; j++){
            snl[i].push_back(i+j);
        }
    }

    for(int k = 0; k < ladders.size(); k++){
        if(ladders[k][0] > 6){
            for(int i = ladders[k][0] - 6; i < ladders[k][0]; i++){
                replace(snl[i].begin(), snl[i].end(), ladders[k][0], ladders[k][1]); 
            }
        }
        else
        {
            for(int i = 1; i < ladders[k][0]; i++){
                replace(snl[i].begin(), snl[i].end(), ladders[k][0], ladders[k][1]); 
            }
        }
    }

    for(int k = 0; k < snakes.size(); k++){
        for(int i = snakes[k][0] - 6; i < snakes[k][0]; i++){
            replace(snl[i].begin(), snl[i].end(), snakes[k][0], snakes[k][1]); 
        }
    }
    /*
    for(int z = 1; z < 100; z++){
        for(int y = 0; y < snl[z].size(); y++){
            cout << snl[z][y] << " ";
        }
        cout << endl;
    }*/

    for(int i = 0; i <= 100; i++){
        level[i] = -1;
    }

    level[1] = 0;
    queue.push_back(1);

    while(!queue.empty()) 
    { 
        // Dequeue a vertex from queue and print it 
        int s = queue.front();  
        queue.pop_front(); 

        for (int i = 0; i < snl[s].size(); i++) 
        { 
            if(level[snl[s][i]] == -1){
                level[snl[s][i]] = level[s] + 1;
                queue.push_back(snl[s][i]);
            }            
        }
    }
    return level[100];
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<vector<int>> ladders(n);
        for (int i = 0; i < n; i++) {
            ladders[i].resize(2);

            for (int j = 0; j < 2; j++) {
                cin >> ladders[i][j];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        int m;
        cin >> m;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<vector<int>> snakes(m);
        for (int i = 0; i < m; i++) {
            snakes[i].resize(2);

            for (int j = 0; j < 2; j++) {
                cin >> snakes[i][j];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        int result = quickestWayUp(ladders, snakes);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
