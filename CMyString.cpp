#include <iostream>

using namespace std;

class CMyString {
	public:
		CMyString(char *pData = NULL);
		CMyString(const CMyString& str);
		~CMyString(void);

		CMyString& operator=(cosnt CMyString& str);

	private:
		char *m_pData;
};

CMyString& CMyString::operator=(const CMyString& str)
{
	if (this != &str) {
		CMyString strTemp(str);

		char *pTemp = strTemp.m_pData;
		strTemp.m_pData = m_pData;
		m_pData = pTemp;
	}

	return *this;
}

int main(int argc, const char *argv[])
{
	
	return 0;
}
