#include <iostream>
#include "stacktype.h"
#include "stacktype.cpp"

using namespace std;



int main()
{
    StackType <int> stck;

    if(stck.IsEmpty())
        cout << "stack is empty"<< endl;
    else
        cout<< "stack is not empty"<< endl;

    stck.Push(5);
    stck.Push(7);

    stck.Push(4);
    stck.Push(2);

    if(stck.IsEmpty())
        cout << "stack is empty"<< endl;
    else
        cout<< "stack is not empty"<< endl;


    if(stck.IsFull())
        cout << "stack is full"<< endl;
    else
        cout<< "stack is not full"<< endl;

    StackType<int> backupStck;
    int item;
    for(int i =  MAX_ITEMS-1; i>=0; i--)
    {
        if(stck.IsEmpty())
        {
            continue;
        }
        else
        {
            item = stck.Top();
            stck.Pop();
            backupStck.Push(item);
        }

    }
    //creating the stack again in order to the given inputs
    for(int i = 0; i< MAX_ITEMS; i++)
    {
        while(backupStck.IsEmpty()!= true)
        {
            item = backupStck.Top();
            cout << item << " ";
            backupStck.Pop();
            stck.Push(item);
        }
    }
    cout << endl;

    stck.Push(3);

    for(int i =  MAX_ITEMS-1; i>=0; i--)
    {
        if(stck.IsEmpty())
        {
            continue;
        }
        else
        {
            item = stck.Top();
            stck.Pop();
            backupStck.Push(item);
        }

    }
    //creating the stack again in order to the given inputs

    for(int i = 0; i< MAX_ITEMS; i++)
    {
        while(backupStck.IsEmpty()!= true)
        {
            item = backupStck.Top();
            cout << item << " ";
            backupStck.Pop();
            stck.Push(item);
        }
    }
    cout << endl;

    if(stck.IsFull())
        cout << "stack is full"<< endl;
    else
        cout<< "stack is not full"<< endl;
    stck.Pop();
    stck.Pop();
    cout << stck.Top()<< endl;

    string parentheses;
    cin >> parentheses;
    StackType <char> stckparent;

    for(int i = 0; i< parentheses.length(); i++)
    {
        if(parentheses[i]== '(')
            stckparent.Push(parentheses[i]);
        else
        {
            if(stckparent.IsEmpty()!= true)
                stckparent.Pop();
            else
                stckparent.Push(1);
        }

    }

     if(stckparent.IsEmpty())
        cout<< "balanced"<< endl;
     else
        cout<< "not balanced"<< endl;


    return 0;
}
