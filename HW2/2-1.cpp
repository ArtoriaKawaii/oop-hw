//學號:B073040022
//姓名:張浩綸

#include<iostream>
#include<string>
#include<cmath>
using std::string;
using std::cin;
using std::cout;
using std::endl;
void getHighScore(string* names, int* scores, bool* high, int size){
    int max = scores[0];//assume that scores[0] is the highest score
    for(int i = 1; i < size; i++)
        if(scores[i] > max)
            max= scores[i];
    for(int i = 0; i < size; i++){//maybe have multiple highest
        if(scores[i] == max)
            high[i] = true;
        else
            high[i] = false;
    }
    /*for(int i = 0; i < size; i++)//check
        cout << names[i] << " " << scores[i] << endl;*/
}

int main(){
    int size = 0;//size: how many people
    string size_s;
    cin >> size_s;

    for(int i = 0; i < size_s.length(); i++){//check if size is legal(all digits)
        if(!isdigit(size_s.at(i))){
            cout << "-1\n";
            return 0;
        }
    }

    for(int i = 0; i < size_s.length(); i++)//convert size from string to int
        size += pow(10, size_s.length() - i - 1) * ((int)size_s.at(i) - (int)'0');
        
    if(size < 1){//check if flag <= 0
        cout << "-1\n";
        return 0;
    }
    string* names = new string[size];//record names
    int* scores = new int[size];//record scores according to the names by their index
    bool* high = new bool[size];//record scores which is the highest
    //input
    for(int t = 0; t < size; t++){
        string name, score_s;//score_s: read score as string first to check if it's legal
        cin >> name;
        //cout << name << " " << score_s << endl;//check
        /*for(int i = 0; i < name.length(); i++){//name doesn't have the limit of all-alphabated
            if(!isalpha(name.at(i))){
                cout << "-1\n";
                return 0;
            }
        }*/
        names[t] = name;

        cin >> score_s;
        int isNeg = 0;//check if the score is negative
        for(int i = 0; i < score_s.length(); i++){//check if score is legal
            if(score_s.at(0) == '-'){//check if the score is negative
                isNeg = 1;
                continue;
            }
            else if(!isdigit(score_s.at(i))){//if the score is illegal
                cout << "-1\n";
                return 0;
            }
        }

        int score = 0;
        if(!isNeg)
            for(int i = 0; i < score_s.length(); i++)//convert score from string to int
                score += pow(10, score_s.length() - i - 1) * ((int)score_s.at(i) - (int)'0');
        else{
            for(int i = 1; i < score_s.length(); i++)//convert score from string to int
                score += pow(10, score_s.length() - i - 1) * ((int)score_s.at(i) - (int)'0');
            score = 0 - score;
        }
        
        scores[t] = score;
    }

    
    /*for(int i = 0; i < size; i++){//check if there are same names//cancel due to time limit
        for(int j = 0; j < size; j++){
            if(names[i] == names[j] && i != j){
                cout << "-1\n";
                return 0;
            }
        }
    }*/

    /*for(int i = 0; i < size; i++)//check;
        cout << names[i] << " " << scores[i] << endl;*/
    
    getHighScore(names, scores, high, size);
    for(int i = 0; i < size; i++)//output the result if there's no error
        if(high[i] == true)
            cout << names[i] << endl << scores[i] << endl;

    return 0;
}