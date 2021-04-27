#include<iostream>
#include<cstring>
using namespace std;

class String{
    char * val;
    int len;
public:
    String();
    ~String();
    friend ostream& operator<<(ostream& os, const String & s);
    String(const String& s);
    String(const char * s);
    String& operator=(const String& s);
    String operator-() const;
    String(int size):val(new char[size+1]), len(size) {}
    friend istream& operator>>(istream &is, String &s);
    String operator+(const String &s);
};

String::String(){
    val=nullptr;
}

String::~String(){
    delete []val;
}

ostream& operator<<(ostream &os, const String & s){
    os<<s.val;
    return os;
}

String::String(const String& s){
    len=s.len;
    val = new char[len+1];
    for (int i=0; i<=len; i++)
        val[i]=s.val[i];
}

String::String(const char*s){
    len=strlen(s);
    val=new char[len+1];
    for (int i=0; i<len; i++) {
        val[i]=s[i];
    }
    val[len]='\0';
}

String& String::operator=(const String& s){
    if (this != &s) {
        delete[] val;
        len=s.len;
        val = new char[len+1];
        for (int i=0; i<=len; i++) {
            val[i]=s.val[i];
        }
    }
    return *this;
}

String String::operator-() const{
    String vrem(len);
    for (int i=0; i<len; i++) {
        vrem.val[i] = val[len-i-1];
    }
    vrem.val[len] = 0;
    return vrem;
}

String String::operator+(const String &s){
    String news;int thisL=strlen(this->val);
    int otherL=strlen(s.val);
    news.val=new char[thisL+otherL+1];
    int i=0;
    for(; i<thisL; i++) {
        news.val[i]= this->val[i];
    }
    for (int j =0; j<otherL; j++,i++) {
        news.val[i]= s.val[j];
    }
    news.val[thisL+otherL]='\0';
    return news;
}

istream& operator>>(istream &is, String&s){
    delete []s.val;
    s.val=new char [1000];
    is>>s.val;
    return is;
}

int main(){
    String nul();
    String primer="primer";
    cout<<"primep = "<<primer<<endl;
    String copy="copy";
    cout<<"copy = "<<copy<<endl;
    String lol=copy;
    cout<<"lol = "<<lol<<endl;
    String inv= "Operator inversion";
    cout<<"inv = "<<inv<<endl;
    String a=-inv;
    cout<<"a = "<<a<<endl;
    String plus=inv+copy;
    cout<<"plus = "<<plus<<endl;
    String Pog;
    cin>>Pog;
    cout<<"Pog = "<<Pog<<endl;
    cin>>Pog;
    cout<<"Pog = "<<Pog<<endl;
    return 0;
}
