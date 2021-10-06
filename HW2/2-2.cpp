//學號:B073040022
//姓名:張浩綸

#include<iostream>
#include<cstring>
using std::cout;
using std::endl;
using std::cin;

int main(){
    char result[5][2] = {{'a', '0'},//store the result
                         {'e', '0'},
                         {'i', '0'},
                         {'o', '0'},
                         {'u', '0'}};
    char str_c[50+1];//store at most 50 characters(inlcude one '\0')
    cin.getline(str_c, 50+1);//read input string at most 50 characters(inlcude one '\0')
    for(int i = 0; i < strlen(str_c); i++){//calc to number of vowels of the string(ignore capital)
        switch(str_c[i]){
            case 'a':
            case 'A':
                result[0][1]++;
                break;
            case 'e':
            case 'E':
                result[1][1]++;
                break;
            case 'i':
            case 'I':
                result[2][1]++;
                break;
            case 'o':
            case 'O':
                result[3][1]++;
                break;
            case 'u':
            case 'U':
                result[4][1]++;
                break;
            /*default:
                //do nothing*/
        }
    }
    for(int i = 0; i < 5; i++){//print out the result
        for(int j = 0; j < 2; j++){
            cout << result[i][j];
            if(j == 0)
                cout << " ";
        }
        cout << endl;
    }
    return 0;
}