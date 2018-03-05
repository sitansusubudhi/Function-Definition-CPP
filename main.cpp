#include <iostream>
#include <algorithm>
using namespace std;


int FindFunctionDefn(string strFunctionName, string strSourceCode )
{
    int lineCount = 0;
    int x = 0;
    do
    {
        int pos = strSourceCode.find("\\n");
        lineCount++;
        string temp = strSourceCode.substr(0, pos);
        cout<<temp<<endl;
        int check = temp.find(strFunctionName);
        if (check == -1) {
            strSourceCode = strSourceCode.substr(pos+3);
            cout<<strSourceCode<<endl;
            continue;
        }
        else
        {
            int openBracketpos = temp.find(")");
            int bracketPosition = temp.find("{");
            if(bracketPosition == -1)
                continue;
            else
            {
                int flag = 0;
                for(int i = openBracketpos; i < bracketPosition; i++)
                {
                    if(temp.at(i) == ' ')
                        continue;
                    if(temp.at(i) == ';')
                    {
                        flag = 1;
                        break;
                    }
                }
                if (!flag)
                    return lineCount;
            }
            strSourceCode = strSourceCode.substr(pos+3);
            cout<<strSourceCode<<endl;
        }

    } while(strSourceCode.find(strFunctionName) != -1);
    return 0;
}

int main()
{
    string strFunctionName = "func2";
    string strSourceCode = "int func1(){ return 0; }\\n int func2(){ return 1; }\\n"
                           "int main(int argc, char*argv[]){ return func2(); }\\n";
    cout<<strSourceCode;
    cout<<endl;

    //Returns the line number of function definition.
    cout<<FindFunctionDefn(strFunctionName, strSourceCode);
    return 0;
}
