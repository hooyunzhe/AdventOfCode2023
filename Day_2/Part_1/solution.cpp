#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main()
{
    ifstream    input_file("input.txt");
    string      line;
    int         id_sum = 0;

    while (getline(input_file, line))
    {
        stringstream    line_stream(line);
        string          token;
        int             current_game = 0;
        int             current_amount = 0;

        while (getline(line_stream, token, ' '))
        {
            if (token.find_first_not_of("0123456789:") == string::npos)
            {
                if (!current_game)
                {
                    current_game = stoi(token);
                    id_sum += current_game;
                }
                else
                    current_amount = stoi(token);
            }
            else if ((token.rfind("red", 0) != string::npos && current_amount > 12) ||
                     (token.rfind("green", 0) != string::npos && current_amount > 13) ||
                     (token.rfind("blue", 0) != string::npos && current_amount > 14))
            {
                id_sum -= current_game;
                break;
            }
        }
    }
    cout << "Sum of IDs of valid games: " << id_sum << endl;
}
