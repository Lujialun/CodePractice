#include<iostream>
#include<cstring>

using namespace std;

class String{
public:
    String(const char* str = nullptr);//Ĭ�Ϲ��캯��
    String(const String& str);//�������캯��
    ~String();//��������
    String& operator=(const String& str);
    friend ostream& operator<<(ostream &os,const String& str);//����������Ǳ������������Ϊ��Ԫ
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

String String::operator+(const String &str)   //�����ַ������ӣ�+�������
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
