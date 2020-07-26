#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'kruskals' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts WEIGHTED_INTEGER_GRAPH g as parameter.
 */

/*
 * For the weighted graph, <name>:
 *
 * 1. The number of nodes is <name>_nodes.
 * 2. The number of edges is <name>_edges.
 * 3. An edge exists between <name>_from[i] and <name>_to[i]. The weight of the edge is <name>_weight[i].
 *
 */
int par[3005];
bool sortcol( const vector<int>& v1, 
               const vector<int>& v2 ) { 
 return v1[2] < v2[2]; 
} 

int find(int a)
{
    if(par[a] == -1){
        return a;
    }

    return par[a] = find(par[a]);
}

void merge(int a, int b)
{
    par[a] = b;
}

int kruskals(int g_nodes, vector<vector<int>> g_weight) {
    int a , b, sum = 0;
    for(int i = 1; i <= g_nodes; i++)
    {
        par[i] = -1;
    }

    sort(g_weight.begin(), g_weight.end(), sortcol);

    for (int i = 0; i < g_weight.size(); i++)
    {
        a = find(g_weight[i][0]);
        b = find(g_weight[i][1]);

        if(a != b)
        {
            sum += g_weight[i][2];
            merge(a, b);
        }
    }
    return sum;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string g_nodes_edges_temp;
    getline(cin, g_nodes_edges_temp);

    vector<string> g_nodes_edges = split(rtrim(g_nodes_edges_temp));

    int g_nodes = stoi(g_nodes_edges[0]);
    int g_edges = stoi(g_nodes_edges[1]);

    vector<vector<int>> g_weight(g_edges);

    for (int i = 0; i < g_edges; i++) {
        string g_from_to_weight_temp;
        getline(cin, g_from_to_weight_temp);

        vector<string> g_from_to_weight = split(rtrim(g_from_to_weight_temp));

        int g_from_temp = stoi(g_from_to_weight[0]);
        int g_to_temp = stoi(g_from_to_weight[1]);
        int g_weight_temp = stoi(g_from_to_weight[2]);

        g_weight[i].push_back(g_from_temp);
        g_weight[i].push_back(g_to_temp);
        g_weight[i].push_back(g_weight_temp);
    }

    int res = kruskals(g_nodes, g_weight);

    fout << res;

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
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
