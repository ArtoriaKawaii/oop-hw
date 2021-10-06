//學號:B073040022
//姓名:張浩綸

#include<iostream>
#include<string>
#include<cmath>

using std::cin;
using std::cout;
using std::ios;
using std::endl;
using std::string;

int main(){
    string subjectline;//read the # of subject as string
    int subject = 0;
    double average = 0;//first use it to calc total score
    cin >> subjectline;
    for(int i = 0; i < subjectline.length(); i++){//turn subjectline to int subject
        if(!isdigit(subjectline.at(i))){
            cout << "-1\n";
            return 0;
        }
        else{
            subject += pow(10, subjectline.length() - i - 1) * ((int)subjectline.at(i) - 48);
        }
    }
    
    string grade;//read grade
    for(int i = 0; i < subject; i++){
        cin >> grade;
        if(grade.length() > 1){//two or more grades in a line
            cout << "-1\n";
            return 0;
        }
        switch(grade.at(0)){
            case 'S':
                average += 10;
                break;
            case 'A':
                average += 9;
                break;
            case 'B':
                average += 8;
                break;
            case 'C':
                average += 7;
                break;
            case 'D':
                average += 6;
                break;
            case 'E':
                average += 5;
                break;
            case 'F':
                break;
            default://don't have such grade
                cout << "-1\n";
                return 0;
        }
    }
    if(average > 0)
        average /= subject;//calc the average score
    
    cout.setf(ios::fixed);//used to show two decimal places
    cout.setf(ios::showpoint);
    cout.precision(2);
    cout << average << endl;
    return 0;
}