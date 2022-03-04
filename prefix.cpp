#include <bits/stdc++.h>
using namespace std;

int check(char op) //Helps in checking the precedence of the operators.
{
    if (op == '^')
        return (3);
    else if (op == '/' || op == '*')
        return (2);
    else if (op == '+' || op == '-')
        return (1);
    else
        return (-1);
}

string convertPostfix(string s)
{
    stack<char> stk; //Declaring a stack that stores char values.
    stk.push('#');   //Helps in checking the border cases.
    string postf;

    for (int i = 0; i < s.length(); ++i)
    {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) //Handling the operands.
            postf += s[i];

        //Handling parantheses.
        else if (s[i] == '(')
            stk.push('(');

        else if (s[i] == ')')
        {
            while (stk.top() != '#' && stk.top() != '(')
            {
                char ch = stk.top();
                stk.pop();
                postf += ch;
            }
            if (stk.top() == '(')
            {
                char c = stk.top();
                stk.pop();
            }
        }

        //Handling operators.
        else
        {
            while (stk.top() != '#' && check(s[i]) <= check(stk.top()))
            {
                char c = stk.top();
                stk.pop();
                postf += c;
            }
            stk.push(s[i]);
        }
    }

    //Pop the remaining elements.
    while (stk.top() != '#')
    {
        char c = stk.top();
        stk.pop();
        postf += c;
    }
    return postf;
}

string convertPrefix(string s)
{
    reverse(s.begin(), s.end()); //First we reverse the entered string, as we read the elements from right to left.

    for (int i = 0; i < s.length(); ++i) //Then we interchange the brackets from ( to ) and vice-versa.
    {
        if (s[i] == '(')
            s[i] = ')';
        else if (s[i] == ')')
            s[i] = '(';
    }

    convertPostfix(s);           //Then we convert this expression into postfix
    reverse(s.begin(), s.end()); //Then we reverse the postfix expression to get the prefix expression.
    return s;
}

int main()
{
    string inf, pref;
    cout << "Enter the infix expression:\n";
    cin >> inf;

    pref = convertPrefix(inf);
    cout << "The prefix expression is:\n"
         << pref;
    return 0;
}
