#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main()
{
    ifstream    input_file("input.txt");
    string      line;
    int         power_sum = 0;

    while (getline(input_file, line))
    {
        stringstream    line_stream(line);
        string          token;
        int             current_amount = 0;
        int             red_max = 0;
        int             green_max = 0;
        int             blue_max = 0;

        while (getline(line_stream, token, ' '))
        {
            if (token.find_first_not_of("0123456789") == string::npos)
                current_amount = stoi(token);
            else if (token.rfind("red", 0) != string::npos && current_amount > red_max)
                red_max = current_amount;
            else if (token.rfind("green", 0) != string::npos && current_amount > green_max)
                green_max = current_amount;
            else if (token.rfind("blue", 0) != string::npos && current_amount > blue_max)
                blue_max = current_amount;
        }
        power_sum += red_max * green_max * blue_max;
    }
    cout << "Sum of power of games: " << power_sum << endl;
}
