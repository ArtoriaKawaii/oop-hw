//Author:張浩綸B073040022
//Purpose:Define a class named zipCode, that decrypts and encrypts zip code.
//#include<bits/stdc++.h>
#include<string>
#include<iostream>
#include<sstream>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::stringstream;
class ZipCode{
    private:
        string str;
        int digits;
    public:
        ZipCode();
        ZipCode(string str);//input the zip code as a string consisting 0's and 1's
        ZipCode(int digits);//input the zip code as an interger
        string toEncrypt();
        int toDecrypt();
};
ZipCode::ZipCode(){}
ZipCode::ZipCode(string str):str(str){}
ZipCode::ZipCode(int digits):digits(digits){}
string ZipCode::toEncrypt(){
    string digit_str = str;
    string encrypted;
    for(int i = 0; i < 5; i++){
        int b[5] = {0, 0, 0, 0, 0};//the binarys correspond to 7, 4, 2, 1, 0 are b[0], b[1], b[2], b[3], b[4]
        if(digit_str.at(i) == '0'){
            b[0] = 1;
            b[1] = 1;
        }
        else{
            b[0] = (digit_str.at(i) - '0') / 7;
            b[1] = (digit_str.at(i) - '0' - b[0] * 7) / 4;
            b[2] = (digit_str.at(i) - '0' - b[0] * 7 - b[1] * 4) / 2;
            b[3] = digit_str.at(i) - '0' - b[0] * 7 - b[1] * 4 - b[2] * 2;
            //e.g. encrypt 7 = 10001
            int ones = 0;
            for(int j = 0; j < 4; j++)
                if(b[j] == 1)
                    ones++;
            if(ones == 1)
                b[4] = 1;
            //
        }
        for(int j = 0; j < 5; j++)
            encrypted += char('0' + b[j]);
        if(i != 4)
            encrypted += ' ';
    }
    return encrypted;
}
int ZipCode::toDecrypt(){
    //split the Encrypted string to five groups represents each digits
    stringstream ss(str);
    string strs[5];
    for(int i = 0; i < 5; i++)
        ss >> strs[i];
    //
    int decrypted = 0;
    for(int i = 0; i < 5; i++){//each group
        //each group have five binary number to compose a digit
        int digit = (strs[i].at(0) - '0') * 7 + (strs[i].at(1) - '0') * 4 + (strs[i].at(2) - '0') * 2 + (strs[i].at(3) - '0');
        if(digit == 11)
            digit = 0;
        decrypted *= 10;
        decrypted += digit;
    }
    return decrypted;
}
int main(){
    int loop;
    cin >> loop;
    cin.ignore(10, '\n');//discard '\n' in input stream
    for(int i = 0; i < loop; i++){
        char mode;
        cin >> mode;
        cin.ignore(10, '\n');
        if(mode == 'e'){
            string toEncrypt_s;
            getline(cin, toEncrypt_s);//read int as string
            ZipCode code(toEncrypt_s);
            cout << code.toEncrypt() << endl;
        }
        else if(mode == 'd'){
            string toDecrypt;
            getline(cin, toDecrypt);
            ZipCode code(toDecrypt);
            cout << code.toDecrypt() << endl;
        }
    }
    return 0;
}
