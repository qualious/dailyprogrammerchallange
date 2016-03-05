#include <vector>
#include <string>
#include <cctype>
#include <iostream>

using namespace std;
/*
You are going to write a home-work helper tool for high-school students
who are learning C for the first time. These students are in the advanced
placement math course, but do not know anything about programming or formal
languages of any kind. However, they do know about functions and variables!
They have been given an 'input guide' that tells them to write simple pure
mathematical functions like they are used to from their homework with a
simple subset grammar, like this:
f(x)=x*x
big(x,y)=sqrt(x+y)*10
They are allowed to use sqrt,abs,sin,cos,tan,exp,log, and the mathematical
arithmetic operators /+-*, they can name their functions and variables any
lower-case alphanumeric name and functions can have between 0 and 15 arguments.
In the this challenge, your job is to write a program that can take in their
"simple format" mathematical function and output the correct C syntax for that function.
All arguments should be single precision, and all functions will only return one float.
As an example, the input
L0(x,y)=abs(x)+abs(y)
should output
float L0(float x,float y){
    return fabsf(x)+fabsf(y);
}

*/

vector<string>
split(string line, char ch){
    vector<string> ret;
    size_t i = 0;
    while(i<line.length()){
        size_t j = i;
        while(j<line.length() && line[j]!=ch){
            ++j;
        }
        if(j!=i){
            ret.push_back(line.substr(i, j-i));
            i=j + 1;
        }
    }
    return ret;
}

string
findAndReplace(string line, string substring, string replacement){
    size_t i = 0;
    while(i + substring.length() < line.length()){
        i = line.find(substring, i);
        if(i < line.length()){
            line.replace(i, substring.length(), replacement);
            i += replacement.length();
        }
        else
            break;
    }
    return line;
}

string
parseFunctionLine(const string& line){
    string ret = "float ";
    vector<string> splitString = split(line, '(');
    ret += splitString[0];
    ret += "(";
    vector<string> arguments = split(splitString[1], ',');
    typedef vector<string>::iterator vector_length;
    for(vector_length i = arguments.begin(); i < arguments.end(); ++i){
        ret = ret + "float " + *i;
        if(i+1 < arguments.end()){
            ret += ",";
        }
    }
    return ret;
}

string
parseBody(string line){
    string ret = "return ";
    line = findAndReplace(line, "abs", "fabsf");
    string::size_type position = line.find('^');
    if(position<line.length()){
        string::size_type start = position,end = position;
        while(start>0 && isalnum(line[start-1])){
            start--;
        }
        while(end<line.length()-1 && isalnum(line[end+1])){
            end++;
        }
        string replace = "pow(" + line.substr(start, position-start)
                                + "," + line.substr(position + 1, end - position) + ")";
        line.replace(start, end-start+1, replace);
    }
    ret = ret + line + ";";
    return ret;
}

vector<string>
parse(const vector<string>& input){
    typedef vector<string>::const_iterator vector_length;
    vector<string> result;
    for(vector_length i = input.begin(); i < input.end(); ++i){
        vector<string> splitString = split(*i, '=');
        string functionLine = parseFunctionLine(splitString[0]);
        string body = parseBody(splitString[1]);
        result.push_back(functionLine);
        result.push_back("{\n\t");
        result.push_back(body);
        result.push_back("\n}\n");
    }
    return result;
}

int main(int argc, char const *argv[]){
    typedef vector<string>::iterator vector_length;
    vector<string> input;
    vector<string> result;
    string line;
    getline(cin,line);
    input.push_back(line);
    result = parse(input);
    for(vector_length i=result.begin(); i < result.end(); ++i){
        cout << *i;
    }
    return 0;
}
