/*
https://www.interviewbit.com/problems/atoi/
Atoi
Asked in:  Adobe, Nvidia, Agilent systems, Bloomberg, Amazon, Apple, Microsoft, Groupon

Please Note:
There are certain questions where the interviewer would intentionally frame the question vague.
The expectation is that you will ask the correct set of clarifications or state your assumptions before you jump into coding.
Implement atoi to convert a string to an integer.

Example :
Input : "9 2704"
Output : 9
Note: There might be multiple corner cases here. Clarify all your doubts using “See Expected Output”.
 Questions: Q1. Does string contain whitespace characters before the number?
A. Yes Q2. Can the string have garbage characters after the number?
A. Yes. Ignore it. Q3. If no numeric character is found before encountering garbage characters, what should I do?
A. Return 0. Q4. What if the integer overflows?
A. Return INT_MAX if the number is positive, INT_MIN otherwise. 
Warning : DO NOT USE LIBRARY FUNCTION FOR ATOI.
*/

int Solution::atoi(const string A) {
    long res = 0;
    int sign = 1;
    int i=0;
    while(A[i]==' ')i++;
    if(A[i]=='-'){sign = -1;i++;}
    else if(A[i]=='+'){sign = 1;i++;}
    for(;i<A.size();i++){
        if(res>INT_MAX) {
            if(sign==-1){
                return INT_MIN;
            }else{
                return INT_MAX;
            }
        }
        if(!isdigit(A[i]))return sign*res;
        res*=10;
        res+=int(A[i]-'0');
    }
    return sign*res;
}
