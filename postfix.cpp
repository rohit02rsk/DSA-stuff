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

void convertPostfix(string s)
{
    stack<char> stk; //Declaring a stack that stores char values.
    stk.push('#');   //Helps in checking the border cases.
    string postf;

    for (int i = 0; i < s.length(); ++i)
    {
	  //Handling the operands.
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) 
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

    //Print the postfix expression.
    cout << "The postfix expression is:\n"
         << postf << endl;
}

int main()
{
    string inf;
    cout << "Input the infix expression:\n";
    cin >> inf;
    convertPostfix(inf);
    return 0;
}
