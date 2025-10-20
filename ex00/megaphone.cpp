#include <iostream>
#include <string>

using namespace std;

int main (int argc, char *argv[])
{
    if (argc == 1)
        cout <<"* LOUD AND UNBEARABLE FEEDBACK NOISE *" << endl;
    else
    {
        for (int i = 1; i <argc; i++)
        {
            for (int j = 0; argv[i][j]; j++)
                std::cout <<(char)std::toupper(argv[i][j]);
        }
        cout << endl;
    }
}
