#include <iostream>

using namespace std;
void pointers()
{
    cout<<"CHAPTER 11: POINTERS"<<endl;
    char c = 'a';
    char* p = &c;
    cout << "The value of the dereferenced pointer is: " << *p<<endl;
    int x = 123;
    int* p1 = &x;
    cout << "The value of the dereferenced pointer is: " << *p<<endl;
    int* p2 = &x;
    *p = 456; // change the value of pointed-to object
    cout << "The value of x is: " << x;
}
void references()
{
    cout<<"CHAPTER 12: REFERENCES"<<endl;
    int x = 123;
    int &y = x; //y is an alias for x
    cout<<"x: "<<x<<' '<<endl;
    x = 456;
    cout<<"y: "<<y<<' '<<endl;
    y = 789;
    cout<<"x: "<<x<<' '<<endl;

    int a = 123;
    const int& b = a; // const reference
    a = 456;
    cout<<"b: "<<b<<endl;
}
void strings()
{
    cout<<"CHAPTER 13: STRINGS"<<endl;
    string s = "Hello world";
    cout<<s<<endl;
    char c='!';
    s+=c;
    cout<<s<<endl;
    cout<<s[0]<<' '<<s.at(0)<<endl;
    cout<<s.c_str()<<endl;

    string s1="Hello",s2="World";
    if (s1==s2)
        cout<<"The strings are equal"<<endl;
    else
        cout<<"The strings are not equal"<<endl;

    string s3;
    cout<<"Input text: ";
    cin>>s3;
    cout<<"Your text: "<<s3<<endl;

    string s4="Hello world";
    string s5=s4.substr(3,4);
    cout<<s4<<"||"<<s5<<endl;

    string s6="Hello world";
    string::size_type found=s.find("world");
    if (found!=string::npos)
        cout<<"Substring found at position: " << found;
    else
        cout << "The substring is not found.";
}
void exercise_chapter15()
{
    cout<<"CHAPTER 15: EXERCISES"<<endl;
//Ex 1:
    double a[5]= {1.1,2.2,3.3,4.4,5.5};
    a[0]+=1;
    a[4]+=1;
    cout<<"1st element: "<<a[0]<<endl;
    cout<<"Last element: "<<a[4]<<endl;
    cout<<endl;
//Ex 2:
    double d=1.1;
    double *p=&d;
    cout<<"The value of the pointed-to object is: " << *p<<endl;
//Ex 3:
    double d2=1.1;
    double &ref_d=d2;
    d2+=1;
    cout << "The values are: " << d2 << " and " << ref_d<<endl;
    ref_d+=1;
    cout << "The values are: " << d2 << " and " << ref_d<<endl;
//Ex 4:
    string s1="Res",s2="ult";
    string s3=s1+s2;
    cout<< "The resulting string is: "<<s3<<endl;
//Ex 5:
    string fullname;
    cout<<"Please enter the first and the last name: ";
    getline(cin,fullname);
    cout<<"Your name is: "<<fullname<<endl;
//Ex 6:
    fullname="John Doe";
    string firstname=fullname.substr(0,4),lastname=fullname.substr(5,3);
    cout<<"Fullname is: "<<fullname<<endl;
    cout<<"Firstname is: "<<firstname<<endl;
    cout<<"Lastname is: "<<lastname<<endl;
//Ex 7:
    string s="Hello C++ World";
    auto found=s.find('C');
    if (found!=string::npos)
        cout<<"Character found at position: "<<found<<endl;
    else
        cout<< "Character was not found."<<endl;
//Ex 8:
    found=s.find("C++");
    if (found!=string::npos)
        cout<<"Character found at position: "<<found<<endl;
    else
        cout<< "Character was not found."<<endl;
//Ex 9:
    auto c = 'a';
    auto x = 123;
    auto d1 = 3.14;
    std::cout << "The type of c is deduced as char, the value is: "
              << c <<endl;
    std::cout << "The type of x is deduced as int, the value is: "
              << x <<endl;
    std::cout << "The type of d is deduced as double, the value is: "
              << d1 <<endl;
}
void myfunction_ref(int& byreference)
{
    cout << "Argument passed by reference: " << byreference;
    byreference++; // we can modify the value of the argument
}
void myfunction(const string& byconstreference)
{
    cout << "Arguments passed by const reference: " <<
         byconstreference;
}
void myfunction(int byvalue)
{
    cout << "Argument passed by value: " << byvalue;
}
void testscope()
{
    int x=10;
    {
        int x=11;
        x++;
        cout<<x<<endl;
    }
    cout<<x;
}
void pointer_int()
{
    int* p = new int;
    *p = 123;
    cout << "The pointed-to value is: " << *p;
    delete p;
}
void pointer_array()
{
    int* p = new int[3];
    p[0] = 1;
    p[1] = 2;
    p[2] = 3;
    cout << "The values are: " << p[0] << ' ' << p[1]
         << ' ' << p[2];
    delete[] p;
}
class MyClass
{
private:
    int x;
    double d;
    string s;
public:
    MyClass();
    ~MyClass();
    MyClass(int xx, double dd);
    MyClass(const MyClass& rhs);
    MyClass(double dd,string ss);
    void setx(int value)
    {
        x=value;
    }
    int getx()
    {
        return x;
    }
    void printmessage()
    {
        cout<<"Hello world";
    }
    void printdata();
    MyClass(MyClass&& otherobject)
        :d{move(otherobject.d)},s{move(otherobject.s)} {}
    MyClass& operator-=(const MyClass& rhs)
    {
        this->x-=rhs.x;
        this->d-=rhs.d;
        return *this;
    }
    friend MyClass operator-(MyClass lhs, const MyClass& rhs)
    {
        lhs -= rhs;
        cout<<lhs.x<<endl;
        return lhs;
    }
};
MyClass::MyClass()
{
    cout<<"Constructor invoked"<<endl;
}
MyClass::~MyClass()
{
    cout<<"Destructor invoked"<<endl;
}
MyClass::MyClass(int xx,double dd)
    :x{xx},d{dd}
{}
void MyClass::printdata()
{
    cout<<"x: "<<x<<' '<<"d: "<<d<<endl;
}
MyClass::MyClass(const MyClass& rhs)
    :x{rhs.x},d{rhs.d}
{}
MyClass::MyClass(double dd,string ss)
    :d{dd},s{ss} {}
void exercise_chapter24()
{
    MyClass o(3,3.1);
    MyClass o2(1,1.2);
    MyClass res;
    res=o-o2;
    //cout<<res.getx();
}
int main()
{
    exercise_chapter24();
    return 0;
}
