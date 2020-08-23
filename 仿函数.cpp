template<typename T> struct comp
{
    bool operator()(T in1, T in2) const
    {
        return (in1>in2);
    }
};

comp<int> m_comp_objext;
cout << m_comp_objext(6, 3) << endl;     //使用对象调用
cout << comp<int>()(1, 2) << endl;       //使用仿函数实现