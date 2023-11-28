#include "BigReal.h"
#include <bits/stdc++.h>
using namespace std;


bool BigReal:: isValidReal (string realNumber){

    int Periods = 0;
    bool OnlyNumbers = true;
    for (int i = 0; i < realNumber.size(); ++i) {
        if (i==0 && (realNumber[i] == '+' || realNumber[i] == '-') ){
            continue;
        }
        if (realNumber[i] == '.'){

            Periods++;
        }
        if ( (realNumber[i] >= '0' && realNumber[i] <= '9') || (realNumber[i] == '.' ) ){
            continue;
        }
        else {
            OnlyNumbers = false;
            break;
        }
    }
    if ( (Periods == 1 || Periods == 0) && OnlyNumbers ){
        return true;

    } else {

        cerr << "Invalid number" << '\n';
        exit(1);
        return false;
    }
}
BigReal::BigReal (double x)
{
    INPUT = to_string(x);
    if (INPUT[0] == '-'){
        isNegative = true;
    } else{
        isNegative = false;
    }
}
BigReal:: BigReal (string realNumber){

    if (isValidReal(realNumber)){
        INPUT = realNumber;
        if (INPUT[0] == '-'){
            isNegative = true;
            if (INPUT[1] == '.'){
                INPUT.insert(1, 1, '0');
            }
        } else if (INPUT[0] == '+'){
            isNegative = false;
            INPUT.erase(0, 1);
            if (INPUT[0] == '.'){
                INPUT.insert(0, 1, '0');
            }
        }
        else if (INPUT[0] == '.'){
            isNegative = false;
            INPUT.insert(0, 1, '0');
        } else {
            isNegative = false;
        }
        int Periods = 0;
        for (int i = 0; i < INPUT.size(); ++i) {
            if (INPUT[i] == '.'){
                Periods++;
                break;
            }
        }
        if (Periods == 0 ){
            INPUT += ".0";
        }
        while (true){
            if (INPUT[0] == '0' && INPUT[1]!='.'){
                INPUT.erase(0, 1);
            } else {
                break;
            }

        }
    }

}
BigReal::BigReal (const BigReal& other){
    INPUT = other.INPUT;
    isNegative = other.isNegative;

}
BigReal& BigReal:: operator=(const BigReal& other) {
    if (this != &other) {
        INPUT = other.INPUT;
        isNegative = other.isNegative;
    }
    return *this;
}
ostream&  operator << (ostream& OUT, BigReal num) {
    cout << num.INPUT;
    return OUT;

}
pair<string,string > padding (string a, string b)
{
    // Keeping the sign for later
    bool flag1= false,flag2= false;
    if (a[0] == '-'){
        flag1 = true;
        a.erase(0, 1);

    }
    if (b[0] == '-'){
        flag2 = true;
        b.erase(0, 1);
    }
    // Find the positions of the decimal points in the strings
    size_t dot1 = a.find('.');
    size_t dot2 = b.find('.');

    // Determine the lengths of the integer and fractional parts
    size_t intPartLen1 = (dot1 == string::npos) ? a.length() : dot1;
    size_t intPartLen2 = (dot2 == string::npos) ? b.length() : dot2;
    size_t fracPartLen1 = (dot1 == string::npos) ? 0 : (a.length() - dot1 - 1);
    size_t fracPartLen2 = (dot2 == string::npos) ? 0 : (b.length() - dot2 - 1);

    // Calculate the maximum integer and fractional part lengths
    size_t maxIntPartLen = max(intPartLen1, intPartLen2);
    size_t maxFracPartLen = max(fracPartLen1, fracPartLen2);

    // Pad the strings with leading zeros
    std::string paddedNum1 = string(maxIntPartLen - intPartLen1, '0') + a + string(maxFracPartLen - fracPartLen1, '0');
    std::string paddedNum2 = string(maxIntPartLen - intPartLen2, '0') + b + string(maxFracPartLen - fracPartLen2, '0');

    if (flag1){paddedNum1.insert(0,1,'-');}
    if (flag2) {paddedNum2.insert(0,1,'-');}

    return {paddedNum1,paddedNum2};
}


string addition(string a , string b){
    string fraq_f , fraq_s="" , real_f="" , real_s="" , res="" , f ,s;
    int carry=0;
    bool sign = false;
    if (a[0]=='+' || a[0]=='-'){
        a[0]= '0';
        sign = true;
    }
    if (b[0]=='+' || b[0]=='-'){
        b[0]= '0';
        sign = true;
    }
    real_f = a.substr(0 , a.find("."));
    real_s = b.substr(0 , b.find("."));
    fraq_f = a.substr(real_f.size()+1 , a.size()-1);
    fraq_s = b.substr(real_s.size()+1 , b.size()-1);

    if (real_f.size()>real_s.size()){
        int w = (real_f.size()-real_s.size());
        for(int i=0 ; i<w; i++){
            real_s = "0" + real_s;
        }
    }
    else if (real_s.size()>real_f.size()){
        int w =(real_s.size()-real_f.size());
        for(int i=0 ; i<w ; i++){
            real_f = "0" + real_f;
        }

    }

    if (fraq_f.size()>fraq_s.size()){
        int w = (fraq_f.size()-fraq_s.size());
        for(int i=0 ; i<w ; i++){
            fraq_s = fraq_s + "0";

        }
    }
    else if (fraq_s.size()>fraq_f.size()){
        int w = (fraq_s.size()-fraq_f.size());
        for(int i=0 ; i<w ; i++){
            fraq_f = fraq_f + "0";
        }
    }

    f = real_f + "." + fraq_f;
    s = real_s + "." + fraq_s;




    for(long long i=f.size()-1 ; i>=0 ; i--){
        if (f[i]=='.'){
            res+='.';
            continue;
        }
        else {
            int x = f[i]-'0' , z = s[i]-'0';


            if (x+z+carry >= 10){
                res += ((x+z+carry)%10)+'0';
                carry = 1;
            }
            else {
                res += ((x+z+carry)%10)+'0';
                carry = 0;
            }
            if (i==0 && carry==1){
                res+='1';
            }

        }

    }
    reverse(res.begin(), res.end());
    return res;
}

string subtraction(string a , string b){
    string fraq_f , fraq_s="" , real_f="" , real_s="" , res="" , f ,s;
    int subcarry=0 ;

    if (a[0]=='+' || a[0]=='-'){
        a[0]= '0';

    }
    if (b[0]=='+' || b[0]=='-'){
        b[0]= '0';

    }
    real_f = a.substr(0 , a.find("."));
    real_s = b.substr(0 , b.find("."));
    fraq_f = a.substr(real_f.size()+1 , a.size()-1);
    fraq_s = b.substr(real_s.size()+1 , b.size()-1);


    if (real_f.size()>real_s.size()){
        int w = (real_f.size()-real_s.size());
        for(int i=0 ; i<w; i++){
            real_s = "0" + real_s;
        }
    }
    else if (real_s.size()>real_f.size()){
        int w =(real_s.size()-real_f.size());
        for(int i=0 ; i<w ; i++){
            real_f = "0" + real_f;
        }

    }

    if (fraq_f.size()>fraq_s.size()){
        int w = (fraq_f.size()-fraq_s.size());
        for(int i=0 ; i<w ; i++){
            fraq_s = fraq_s + "0";

        }
    }
    else if (fraq_s.size()>fraq_f.size()){
        int w = (fraq_s.size()-fraq_f.size());
        for(int i=0 ; i<w ; i++){
            fraq_f = fraq_f + "0";
        }
    }

    f = real_f + "." + fraq_f;
    s = real_s + "." + fraq_s;




    for(long long i=f.size()-1 ; i>=0 ; i--){
        if (f[i]=='.'){
            res+='.';
            continue;
        }
        else {
            int x = f[i]-'0' , z = s[i]-'0';

            if (((x-subcarry)-z)<0){
                res += ((x+10-subcarry)-z)+'0';
                subcarry = 1;

            }
            else {
                res += (((x-subcarry)-z)%10)+'0';
                subcarry = 0;

            }

        }

    }

    reverse(res.begin(), res.end());
    return res;

}

BigReal BigReal::operator+(BigReal &other)
{
    if ((INPUT[0]=='-' && other.INPUT[0]=='-') ||(INPUT[0]=='+' && other.INPUT[0]=='+') || ((INPUT[0]>='0' && INPUT[0]<='9') && (other.INPUT[0]>='0' && other.INPUT[0]<='9')) ){

        string res = addition(INPUT,other.INPUT);

        while (true){
            if (res[0]=='0'){
                res.erase(0, 1);
            }
            else {
                break;
            }
        }
        if (isNegative==true){
            res = "-" + res;
        }
        BigReal b;
        b.INPUT = res;
        if (b.INPUT[0]=='-'){b.isNegative = true;}
        else {b.isNegative = false;}
        return b;
    }

    else {

        string res;
        bool sbigger= false;
        string sign1="+" , sign2="+";
        string compf=INPUT , comps=other.INPUT;

        if (compf[0]=='+' || compf[0]=='-'){
            if (compf[0]=='-'){

                sign1="-";
            }
            compf.erase(0, 1);
        }
        if (comps[0]=='+' || comps[0]=='-'){
            if (comps[0]=='-'){
                sign2="-";
            }
            comps.erase(0, 1);
        }
        // padding to compare
        pair<string , string>c = padding(compf , comps);
        compf = c.first;
        comps = c.second;

        for(int i = 0; i < compf.length(); ++i) {
            if ((compf[i] - '0') < (comps[i] - '0')) {
                sbigger = true;
                break;
            }
            else if ((compf[i] - '0') > (comps[i] - '0')) {
                break;
            }
        }

        if (sbigger == false)
            res = subtraction(INPUT, other.INPUT);
        else
            res = subtraction(other.INPUT, INPUT);

        while (true){
            if (res[0]=='0' && res[1]!='.'){
                res.erase(0, 1);
            }
            else {
                break;
            }
        }


        if ((sbigger==false && sign1=="-") && (compf!=comps)){
            res = sign1 + res;
        }
        else if ((sbigger== true && sign2=="-") && (compf!=comps)){
            res = sign2 + res;
        }

        BigReal b;
        b.INPUT = res;
        if (b.INPUT[0]=='-'){b.isNegative = true;}
        else {b.isNegative = false;}
        return b;

    }


}

BigReal BigReal::operator-(BigReal& other) {
    string res;
    bool sbigger= false;
    string sign1="+" , sign2="+";
    string compf=INPUT , comps=other.INPUT;

    if (compf[0]=='+' || compf[0]=='-'){
        if (compf[0]=='-'){
            sign1="-";
        }
        compf.erase(0, 1);
    }
    if (comps[0]=='+' || comps[0]=='-'){
        if (comps[0]=='-'){
            sign2="-";
        }
        comps.erase(0, 1);

    }
    pair<string , string>c = padding(compf , comps);
    compf = c.first;
    comps = c.second;

    for(int i = 0; i < compf.length(); ++i) {
        if ((compf[i] - '0') < (comps[i] - '0')) {
            sbigger = true;
            break;
        }
        else if ((compf[i] - '0') > (comps[i] - '0')) {
            break;
        }
    }

    if ((INPUT[0]=='-' && other.INPUT[0]=='-') ||(INPUT[0]=='+' && other.INPUT[0]=='+') || ((INPUT[0]>='0' && INPUT[0]<='9') && (other.INPUT[0]>='0' && other.INPUT[0]<='9')) ){

        if (sbigger == false) {

            res = subtraction(INPUT, other.INPUT);

        } else {

            res = subtraction(other.INPUT, INPUT);
        }

        while (true){

            if (res[0]=='0' && res[1]!='.'){
                res.erase(0, 1);
            }
            else {
                break;
            }
        }

        if (((sbigger==false && sign1 == "-") || (sbigger==true && sign2 == "+"))  && (compf!=comps) ) {
            res = "-" + res;
        }
        BigReal b;

        b.INPUT = res;
        if (b.INPUT[0]=='-'){b.isNegative = true;}
        else {b.isNegative = false;}
        return b;



    }

    else{
        string res = addition(INPUT, other.INPUT);
        while (true){
            if (res[0]=='0'){
                res.erase(0, 1);
            }
            else {
                break;
            }
        }
        if (INPUT[0]=='-' && (other.INPUT[0]=='+' || (other.INPUT[0]>='0' && other.INPUT[0]<='9'))){
            res = "-" + res;

        }
        else {
            if (sbigger==false && sign1 == "-") {
                res = sign1 + res;
            } else if (sbigger==true && sign2 == "+") {
                res = "-" + res;
            }
        }

        BigReal b;

        b.INPUT = res;
        if (b.INPUT[0]=='-'){b.isNegative = true;}
        else {b.isNegative = false;}
        return b;

    }


}



bool BigReal :: operator == (BigReal anotherReal){
    pair<string,string> tmp = padding(this->INPUT,anotherReal.INPUT);
    return  ( tmp.first == tmp.second);
}

bool BigReal :: operator > (BigReal anotherReal)
{
    if (this->isNegative && !(anotherReal.isNegative)){return false;}
    if (!(this->isNegative) && (anotherReal.isNegative)){return true;}
    pair<string,string> tmp = padding(this->INPUT,anotherReal.INPUT);
    if ((!( (this->isNegative) && (anotherReal.isNegative) ))){

        return (tmp.first > tmp.second );

    }
    else {
        return (tmp.first < tmp.second );

    }

}
bool BigReal :: operator < (BigReal anotherReal)
{
    if (this->isNegative && !(anotherReal.isNegative)){return true;}
    if (!(this->isNegative) && (anotherReal.isNegative)){return false;}
    pair<string,string> tmp = padding(this->INPUT,anotherReal.INPUT);
    if ((!( (this->isNegative) && (anotherReal.isNegative) ))){

        return (tmp.first < tmp.second );

    }
    else {
        return (tmp.first > tmp.second );

    }


}






