#include<iostream>
#include<string>
using namespace std;


string ones[] = {"", "one ", "two ", "three ", "four ", "five ", "six ", "seven ", "eight ", "nine ", "ten", "eleven ", "twelve ", "thirteen ", "fourteen ", "fifteen ", "sixteen ", "seventeen ", "eighteen ", "nineteen "};
string tens[] = {"", "", "twenty ", "thirty ", "forty ", "fifty ", "sixty ", "seventy ", "eighty ", "ninety "};

string logic(int num, string adder)
{
    string result = "";
    if(num < 20)
    {
        result += ones[num];
    }
    else
    {
        result += tens[num / 10] + ones[num % 10];
    }
    if(num)
    {
        result += adder;
    }
    return result;
}


string numToWord(int num)
{
    string result = "";
    result += logic(num / 10000000, "crore ");
    num %= 10000000;
    result += logic(num / 100000, "lakh ");
    num %= 100000;
    result += logic(num / 1000, "thousand ");
    num %= 1000;
    result += logic(num / 100, "hundred ");
    if(num % 100 != 0 && num > 100)
    {
        result += "and ";
    }
    num %= 100;
    result += logic(num, "");
    return result;
}


int main()
{
    cout<<numToWord(34614702);
    return 0;
}