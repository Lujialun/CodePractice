#include<iostream>
#include<cstring>

using namespace std;

class String{
public:
    String(const char* str = nullptr);//默认构造函数
    String(const String& str);//拷贝构造函数
    ~String();//析构函数
    String& operator=(const String& str);
    friend ostream& operator<<(ostream &os,const String& str);//左侧运算量非本对象必须声明为友元
private:
    char* m_data;
    int   m_size;
};

String::String(const char* str)
{
    if(str == nullptr){
        m_data = new char[1];
        m_data[0]='\0';
        m_size=0;
    }else{
        m_size=strlen(str);
        m_data=new char[m_size+1];
        strcpy(m_data,str);
    }
}

String::String(const String& str)
{
    m_size=str.m_size;
    m_data=new char[m_size+1];
    strcpy(m_data,str.m_data);
}

String::~String()
{
    if(m_data != nullptr)
        delete[] m_data;
}

String& String::operator=(const String& str)
{
    if(this == &str) return *this;

    delete[] m_data;
    m_size=str.m_size;
    m_data=new char[m_size+1];
    strcpy(m_data,str.m_data);
    return *this;
}

ostream& operator<<(ostream& os, const String &str)
{
    os << str.m_data;
    return os;
}

/*

String String::operator+(const String &str)   //重载字符串连接（+）运算符
{
	String NewString ;
	int size = strlen(m_data)+strlen(str.m_data);
	NewString.m_data = new char[size+1];

	strcpy(NewString.m_data,m_data);
	strcat(NewString.m_data,str.m_data);
	return NewString;
}
*/
int main()
{
    String a="aaa";
    String b="ccc";
    a=b;
    cout<<a<<endl;
}
