#include<iostream>
#include <string>

using namespace std;

int getInput (int crossSize, int cross[]);
void draw (int crossSize, int cross[]);
bool isChosen (int input, int cross[]);
bool didWin (int crossSize, int cross[]);

int main()
{
    int input = 0;
    bool isXTurn = 0;
    int crossSize = 9;
    int cross[crossSize];

    //initialize the cross
    for (int val = 0; val <= crossSize; val++)
    {
        cross[val] = val;
    }

    //start Game
    while(true)
    {
        draw(crossSize, cross);

        //if it's X's turn
        if (isXTurn == 1)
        {
            cout << "It's X Turn!" << endl;
            input = getInput(crossSize, cross);

            cross[input] = 10;
            isXTurn = 0;

        }

        else
        {
            cout << "It's O Turn!" << endl;
            input = getInput(crossSize, cross);

            cross[input] = 11;
            isXTurn = 1;
        }

       if(didWin(crossSize, cross))
       {
        break;
       }
        
    }
}

void draw(int crossSize, int cross[])
{
    for (int lineCounter = 1, counter = 0; lineCounter <= 3; lineCounter++)
    {
        for (int lineCounter = 0; lineCounter < 3; lineCounter++, counter++)
        {
            if(cross[counter] == 10)
            {
                cout << " X ";
            }

            else if (cross[counter] == 11)
            {
                cout << " O ";
            }

            else 
            {
                cout << " - ";
            }
        }

        cout << endl;
    }

};

bool didWin(int crossSize, int cross[])
{
    //check by line
    for (int lineCounter = 1, counter = 0; lineCounter <= 3; lineCounter++, counter += 3)
    {
        if (cross[counter] == 10 && cross[counter + 1] == 10 && cross[counter + 2] == 10 )
        {
            cout<<"X has Won!"<<endl;
            return 1;
            break;
        }

        if (cross[counter] == 11 && cross[counter + 1] == 11 && cross[counter + 2] == 11 )
        {
            cout<<"O has Won!"<<endl;
            return 1;
            break;
        }

    }

    for(int lineCounter = 1, counter = 0; lineCounter <= 3; lineCounter++, counter++)
    {
        if (cross[counter] == 10 && cross[counter + 3] == 10 && cross[counter + 6] == 10 )
        {
            cout<<"X has Won!"<<endl;
            return 1;
            break;
        }

         if (cross[counter] == 11 && cross[counter + 3] == 11 && cross[counter + 6] == 11 )
        {
            cout<<"O has Won!"<<endl;
            return 1;
            break;
        }
    }

    if(cross[0] == 11 && cross[4] == 11 && cross[8] == 11)
    {
        cout<<"O has Won!"<<endl;
            return 1;

    }

    if (cross[0] == 10 && cross[4] == 10 && cross[8] == 10)
    {
         cout<<"X has Won!"<<endl;
         return 1;
    }

    for(int i = 0, isDraw = 0; i < crossSize; i++)
    {
        if (cross[i] == 10 || cross[i] == 11)
        {
            if (i == 8)
            {
                cout << "Draw!" << endl;
                return 1;
                break;
            }
        }
        
        else
        {
           return 0;
           break;
        }

    }
    

    return 0;

};

bool isChosen(int input, int cross[])
{
    if (cross[input] == 10 || cross[input] == 11)
    {
        cout << "Chose another place please!" << endl;
        return 1;
    }
    else
    {
        return 0;
    }


};

int getInput(int crossSize, int cross[])
{
    int input = 0;
    do {
        cout << "wich house? ";
        cin >> input;
        }
        while(input < 0 || input > crossSize-1 || isChosen(input, cross) == 1 );

    return input;
};
