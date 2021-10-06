//Author:張浩綸B073040022
//Purpose:Create a class that can represent rational number and overload some operator
#include<bits/stdc++.h>
using std::ostream;
using std::istream;
using std::cin;
using std::cout;
using std::endl;
using std::string;
class Rational{
    private:
        long long int numerator, denominator;//numerator(分子)/denominator(分母)
    public:
        Rational();//default constructor that initializes an object to 0(that is, to 0/1).
        Rational(long long int numerator);//wholeNumber/1
        Rational(long long int numerator, long long int denominator);
        void normalize();
        //Overload all the following operators so that they correctly apply to the type Rational: ==, <, <=, >, >=, +, -, *, and /
        friend bool operator==(const Rational& A, const Rational& B);
        friend bool operator<(const Rational& A, const Rational& B);
        friend bool operator<=(const Rational& A, const Rational& B);
        friend bool operator>(const Rational& A, const Rational& B);
        friend bool operator>=(const Rational& A, const Rational& B);
        friend Rational operator+(const Rational& A, const Rational& B);
        friend Rational operator-(const Rational& A, const Rational& B);
        friend Rational operator*(const Rational& A, const Rational& B);
        friend Rational operator/(const Rational& A, const Rational& B);
        //Overload the input and output operators >> and <<
        friend ostream& operator<<(ostream& os, const Rational& num);
        friend istream& operator>>(istream& is, Rational& num);
        
};
long long int findGCD(long long int a, long long int b){//find Greatest Common Divisor of number a and b by Euclidean algorithm
    if( b == 0 )
        return a;
    return findGCD( b, a % b );
}
long long int findLCM(long long int a, long long int b){//find Least Common Multiple of number a and b by a * b / GCD(a, b)
    return a * b / findGCD(a, b);
}
template<class T>
void swap(T& a, T& b){
    T temp = a;
    a = b;
    b = temp;
}
template<class T>
void sort(T* arr, long long int size){//sort int asscending order by seletion sort algorithm
    for(int i = 0; i < size; i++){
        int minIndex = i;
        for(int j = i + 1; j < size; j++)
            if(arr[j] < arr[minIndex])
                minIndex = j;
        swap(arr[i], arr[minIndex]);
    }
}
Rational::Rational():numerator(0), denominator(1){}
Rational::Rational(long long int numerator):numerator(numerator), denominator(1){}
Rational::Rational(long long int numerator, long long int denominator):numerator(numerator), denominator(denominator){}
void Rational::normalize(){
    if(denominator == 0){//convenient to clac
        denominator = 1;
        numerator = 0;
    }
    else{
        if(numerator < 0 && denominator < 0){//-1/-1 = 1/1
            numerator *= -1;
            denominator *= -1;
        }
        else if(numerator >= 0 && denominator < 0){//1/-1 = -1/1
            numerator *= -1;
            denominator *= -1;
        }
        long long int gcd = findGCD(abs(numerator), denominator);
        if(gcd > 1){
            numerator /= gcd;
            denominator /= gcd;
        }
    }
}
bool operator==(const Rational& A, const Rational& B){
    return (A.numerator == B.numerator) && (A.denominator == B.denominator);
}
bool operator<(const Rational& A, const Rational& B){
    return (A.numerator * B.denominator) < (A.denominator) * (B.numerator);
}
bool operator<=(const Rational& A, const Rational& B){
    if(A == B)//A == B
        return true;
    return (A.numerator * B.denominator) < (A.denominator) * (B.numerator);
}
bool operator>(const Rational& A, const Rational& B){
    return !((A.numerator * B.denominator) < (A.denominator) * (B.numerator));
}
bool operator>=(const Rational& A, const Rational& B){
    if(A == B)//A == B
        return true;
    return !((A.numerator * B.denominator) < (A.denominator) * (B.numerator));
}
Rational operator+(const Rational& A, const Rational& B){
    long long int lcm = findLCM(A.denominator, B.denominator);
    Rational temp(A.numerator * (lcm / A.denominator) + B.numerator * (lcm / B.denominator), lcm);
    temp.normalize();
    return temp;
}
Rational operator-(const Rational& A, const Rational& B){
    long long int lcm = findLCM(A.denominator, B.denominator);
    Rational temp(A.numerator * (lcm / A.denominator) - B.numerator * (lcm / B.denominator), lcm);
    temp.normalize();
    return temp;
}
Rational operator*(const Rational& A, const Rational& B){
    Rational temp(A.numerator * B.numerator, A.denominator * B.denominator);
    temp.normalize();
    return temp;
}
Rational operator/(const Rational& A, const Rational& B){
    Rational temp(A.numerator * B.denominator, A.denominator * B.numerator);
    temp.normalize();
    return temp;
}
ostream& operator<<(ostream& os, const Rational& num){
    if(num.numerator == 0 && num.denominator == 1){//If the denominator of the rational number is 1, please display only the molecules when outputting
        os << "0/0";
    }
    else if(num.numerator == 0){
        os << "0";
    }
    else if(num.denominator == 1){
        os << num.numerator;
    }
    else
        os << num.numerator << "/" << num.denominator;
    return os;
}
istream& operator>>(istream& is, Rational& num){
    long long int numerator;
    if(!(is >> numerator)){
        cout << "-1\n";
        exit(1);
    }
    num.numerator = numerator;
    if(is.peek() == '\n'){
        num.denominator = 1;
    }
    else{
        is.get();//remove '/'
        long long int denominator;
        if(!(is >> denominator)){
            cout << "-1\n";
            exit(1);
        }
        num.denominator = denominator;
    }
    num.normalize();//after input, normalize immediately, to simplify the process
    return is;
}
int main(){
    long long int k;
    Rational p, q;
    if(!(cin >> k) || k < 0){//if input is illegal, output -1 and end program
        cout << "-1\n";
        exit(1);
    }
    if(k == 0)//if k == 0, end program
        return 0;
    cin >> p >> q;//p * Si + q for i = 0 to k - 1
    Rational s[k];
    for(long long int i = 0; i < k; i++){//input Si for i = 0 to k - 1
        cin >> s[i];
        s[i] = s[i] * p + q;
    }
    sort(s, k);
    for(long long int i = 0; i < k; i++)
        cout << s[i] << endl;
    return 0;
}