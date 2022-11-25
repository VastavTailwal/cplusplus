#include<iostream>
#include<windows.h>
#include<unistd.h>
using std::cout;
using std::endl;


void findPath(char dungeon[6][7], int i, int j, const int row = 6, const int col = 7)
{

    // base cases

    if(dungeon[i][j] == 'x')
    {
        for(int i = 0; i < 6; ++i)
        {
            for(int j = 0; j < 7; ++j)
            {
                cout<<dungeon[i][j]<<" ";
            }
            cout<<endl;
        }
        exit(0);
    }
    
    if(i < 0 || i >= row || j < 0 || j >= col || dungeon[i][j] != ' ')
    {
        return;
    }
    
    // mark visited using `.`

    dungeon[i][j] = '.';
    
    for(int i = 0; i < 6; ++i)
    {
        for(int j = 0; j < 7; ++j)
        {
            cout<<dungeon[i][j]<<" ";
        }
        cout<<endl;
    }
    sleep(1);
    system("cls");

    // recursion
    
    findPath(dungeon, i + 1, j);
    findPath(dungeon, i, j + 1);
    findPath(dungeon, i - 1, j);
    findPath(dungeon, i, j - 1);
    
    // backtracking
    
    dungeon[i][j] = ' ';

    for(int i = 0; i < 6; ++i)
    {
        for(int j = 0; j < 7; ++j)
        {
            cout<<dungeon[i][j]<<" ";
        }
        cout<<endl;
    }
    sleep(1);
    system("cls");
}


int main()
{
    char dungeon[6][7] =
    {
        {' ', ' ', '#', '#', ' ', ' ', 'x'},
        {' ', ' ', ' ', '#', ' ', '#', ' '},
        {' ', '#', ' ', '#', ' ', '#', ' '},
        {' ', '#', ' ', ' ', ' ', '#', ' '},
        {' ', '#', '#', '#', ' ', '#', ' '},
        {' ', '#', ' ', ' ', ' ', ' ', ' '}
    };
    
    findPath(dungeon, 0, 0);
    
    // print result
    
    for(int i = 0; i < 6; ++i)
    {
        for(int j = 0; j < 7; ++j)
        {
            cout<<dungeon[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}