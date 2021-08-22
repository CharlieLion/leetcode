class CMystring
{
    public:
    CMystring(char* pData=nullptr);
    CMystring(const CMystring& pdata);
    ~CMystring();
    CMystring& CMystring::operator =(const CMystring &str)
    {
        if(this ==&str)
        return *this;
        delete []m_pData;
        m_pData =nullptr;
        m_pData = new char[strlen(str.m_pData)+1];
        
    }
    private:
        char* m_pData;

};


