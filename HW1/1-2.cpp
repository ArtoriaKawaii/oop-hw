//學號:B073040022
//姓名:張浩綸
//Compute the square root of a positive number N using Babylonian algorithm
#include<iostream>
using std::cin;
using std::cout;
using std::endl;
int main(){
        int number;//the number we have to compute
        while(cin >> number){
        //Babylonian algorithm * 5 times
        int guess = number / 2;
        int r;
        for(int i = 0; i < 5; i++){
            r = number / guess;
            guess = (guess + r) / 2;
        }
        cout << guess << endl;
        }
    
    return 0;
}