#include<iostream>
#include<cmath>
#include<fstream>
using namespace std;
class Quadratic{
public:
    Quadratic(const float p,const float q,const float s){
        a=p;
        b=q;
        c=s;
    }
    Quadratic(){
        a=0;
        b=0;
        c=0;
    }
    float geta(){
        return a;
    }
    float getb(){
        return b;
    }
    float getc(){
        return c;
    }
    float eval(float x);
    friend ostream &operator << (ostream &output,Quadratic &Q);
    friend istream &operator >> (istream &input,Quadratic &Q);
private:
    float a;
    float b;
    float c;
};
float Quadratic::eval(float x){
    return a*x*x+b*x+c;
}
istream &operator >> (istream &input,Quadratic &Q){
    input >> Q.a >> Q.b >>Q.c;
    return input;
}
ostream &operator << (ostream &output,Quadratic &Q){
    if((Q.b<0)&&(Q.c>=0)){
        output << Q.a << "x^2" << Q.b << "x" << "+" << Q.c;
    }
    else if((Q.b<0)&&(Q.c<0)){
        output << Q.a << "x^2" << Q.b << "x" << Q.c;
    }
    else if((Q.b>=0)&&(Q.c<0)){
        output << Q.a << "x^2" << "+" << Q.b << "x" << Q.c;
    }
    else{
        output << Q.a << "x^2" << "+" << Q.b << "x" << "+" << Q.c;
    }
    return output;
}
const Quadratic operator + (Quadratic &first,Quadratic &second){
    return Quadratic(first.geta() + second.geta(),first.getb() + second.getb(),first.getc() + second.getc());
}
int main(){
    Quadratic one,two,three;
    int t;
    cin >> t;//x的值
    cin >> one;
    cin >> two;
    //cout << one << endl;
    //cout << one.eval(t) <<endl;
    three = one + two;
    cout << three<<endl;
    cout<<three.eval(t)<<endl;
}