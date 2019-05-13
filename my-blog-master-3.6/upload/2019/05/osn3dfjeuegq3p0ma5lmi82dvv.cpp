/** 
 * ����Ŀ�ģ� 
 *   �������н���һ������������ת��Ϊ���Ľ��Ĵ�д��ʽ��C++�棩 
 * ���� 123.45 --> Ҽ�۷�ʰ��Ԫ������� 
 * @author LovinChan 
 * 
 *   ǰһ��ʱ�����˸� Java ��ġ�ͻȻ������Ѫ�������� C++ �汾�ģ�ʵ�ֵĹ��� 
 * �� Java �汾��ûʲô���𣬲��������Ҷ� C++ ���˽⻹���Ǻܶ࣬����ѧϰ�׶Σ� 
 * д�����Ķ������кܶ�����Ͳ��Ϲ淶�ĵط���ϣ����λ����ָ������ 
 *  
 *   �����ע���Ҿ���д����ϸһ�㣬����������������������������������иĽ��� 
 * �ط���ӭ��ʱ���ҽ����� 
 *  
 *   �Ҹ����˱����Ժ�� .exe �ļ��� .bat �ļ���������ĿԴ�룬����Ҳ����� 
 * 
 * ���ߣ�Microsoft Visual Studio 2005 
 * ���뻷����Microsoft Visual Studio 2005 
 * 
 * �ҵ�msn:egg.chenlw@gmail.com 
 *    QQ:372133556(ע��Ϊʲô���ҾͿ�����) 
 * �ҵ�blog:http://hi.baidu.com/egg_chen 
 * ��ӭ���� 
 */  
#include <iostream>  
#include <string>  

using namespace std;  

// ��ʾ�������ֵı�־  
const int INT_ONLY = 1;  
// ��ʾС�����ֵı�־  
const int SMALL_ONLY = 2;  
  
/** 
 * �������н���һ�����������е��� checkNum() ����������� 
 * ��֤����������Ӧ��ֵ 
 * @return �������Ϸ����������������� 
 */  
string getNum() {  
    string s;  
    cout << "������һ�����֣���ȷ��С�������λ����" << endl;  
    // ���������������������  
    cin >> s;  
    // ���������״̬��־  
    cin.clear();  
    return s;  
}  
  
/** 
* �ж��û�����������Ƿ�Ϸ����û�ֻ���������������֣��������������ַ� 
* @param s string 
* @return ����û��������ݺϷ������� true�����򷵻� false 
*/  
bool checkNum(string s) {  
    // atof(s.c_str()) �����Ĺ����ǽ��ַ��� s ת����һ��˫������ֵ�����ؽ��  
    double d = atof(s.c_str());  
    // ֻ�е��û�����һ������0����ʱ���Ż᷵��true  
    if(d > 0) {  
        return true;  
    }
    return false; 
}  

/**
 * �Դ���������������������
 * @param s string����������������Ǹ���
 * @return ������������ֵ
 */
string roundString(string s) {
    // �������ת���� double ���ͣ���������������������  
    // ��ת�����������������  
    // atof(s.c_str()) �����Ĺ����ǽ��ַ��� s ת����һ��˫������ֵ�����ؽ��  
    // c_str()��������һ��ָ������C�ַ�����ָ��, �����뱾�ַ�����ͬ  
    double d = atof(s.c_str());  
    // ������������������룬������С�������λ  
    // �ٽ������ת�����ַ������ȴ�ת�� 
    int dec, sign;
    // ע�⣺�������ת�����ַ����Ժ󲻻���ʾС���㣬���һ��������������ʽֻ����С�������λ  
    s = fcvt(d, 2, &dec, &sign);  
    // �涨��ֵ����󳤶�ֻ����15λ��������λ��  
    if(s.length() > 15) {  
        cout << "�������ݹ��󣡣������������13λ����" << endl;
        return "";
    }
    return s;  
}
  
/** 
 * �Ѵ������ת��Ϊ���Ľ���д��ʽ 
 * @param flag int ��־λ��1 ��ʾת���������֣�0 ��ʾת��С������ 
 * @param s string Ҫת�����ַ��� 
 * @return ת���õĴ���λ�����Ľ���д��ʽ 
 */  
string formatChinese(int flag, string s) {  
    int sLength = s.length();  
    // ���Ҵ�д��ʽ  
    string bigLetter[] = {"��", "Ҽ", "��", "��", "��", "��", "½", "��", "��", "��"};  
    // ���ҵ�λ  
    string unit[] = {"Ԫ", "ʰ", "��", "Ǫ", "��",   
                // ʰ��λ��Ǫ��λ  
                "ʰ", "��", "Ǫ",  
                // ��λ������λ  
                "��", "ʰ", "��", "Ǫ", "��"};  
    string small[] = {"��", "��"};  
    // �������ת��������ַ���  
    string newS = "";  
    // ��λ�滻Ϊ���Ĵ�д��ʽ 
    for(int i = 0; i < sLength; i ++) {
        if(flag == INT_ONLY) {
            // ת����������Ϊ���Ĵ�д��ʽ������λ��  
            newS = newS + bigLetter[s.at(i) - 48] + unit[sLength - i - 1]; 
        } else if(flag == SMALL_ONLY) {
            // ת��С�����֣�����λ��
            newS = newS + bigLetter[s.at(i) - 48] + small[sLength - i - 1];  
        }
    }
    return newS;
}

/** 
 * ���û����������С����Ϊ��ָ���������� numFormat() ���� 
 * ������Ӧ�����Ľ���д��ʽ��ת�� 
 * ע������������Ӧ���Ǿ��� roundString() ����������������������� 
 * @param s string 
 * @return ת���õ����Ľ���д��ʽ���ַ��� 
 */  
string splitNum(string s) {  
    // ���������ǿմ���������ؿմ�  
    if("" == s) {  
        return "";  
    }  
    // ��ȡ�������ֵ���������  
    string intOnly = s.substr(0, s.size() - 2);  
    string intPart = formatChinese(INT_ONLY, intOnly);  
  
    // ��ȡ�������С������  
    string smallOnly = s.substr(s.size() - 2, s.size());  
    string smallPart = formatChinese(SMALL_ONLY, smallOnly);  
  
    // ��ת�����˵��������ֺ�С����������ƴ��һ���µ��ַ���  
    string newS = intPart + smallPart;  
  
    return newS;  
}  
  
/** 
 * ʹ�ø����� replacement �滻���ַ�������ƥ������� regex �����ַ����� 
 * @param src - ��������Դ�ַ��� 
 * @param regex - ����ƥ����ַ�����������ʽ 
 * @param replacement - �����滻ÿ��ƥ������ַ���  
 * @return �滻����ַ���  
 */  
string replaceAll(string src, string regex, string replacement) {  
    int length = regex.length();  
    while(src.find(regex) < src.length()) {  
        // �滻 src �ַ����дӵ�һ��ƥ�� regex ���ַ���������ʼ�� length ���ַ�Ϊ replacement �ַ���          
        src.replace(src.find(regex), length, replacement);  
    } 
    return src;  
}  

/** 
 * ���Ѿ�ת���õ����Ľ���д��ʽ���ԸĽ������������ 
 * �������������㣬������ַ�����ø��ӿɹ� 
 * ע������������Ӧ���Ǿ��� splitNum() �������д�������� 
 * ����Ӧ���Ѿ��������Ľ���д��ʽ��ʾ�� 
 * @param s string �Ѿ�ת���õ��ַ��� 
 * @return �Ľ�����ַ��� 
 */  

string cleanZero(string s) {  
    // ���������ǿմ���������ؿմ�  
    if("" == s) {  
        return "";  
    }
    // �ַ����д��ڶ��'��'��һ���ʱ��ֻ����һ��'��'����ʡ�Զ���ĵ�λ  
    /* ���ڱ��˶��㷨���о�̫���ˣ�ֻ����4��������ʽȥת���ˣ���λ��Ϻ������... */  
    string regex1[] = {"��Ǫ", "���", "��ʰ"};  
    string regex2[] = {"����", "����", "��Ԫ"};  
    string regex3[] = {"��", "��", "Ԫ"};  
    string regex4[] = {"���", "���"}; 

    // ��һ��ת���� "��Ǫ", ���","��ʰ"���ַ����滻��һ��"��"  
    for(int i = 0; i < 3; i ++) {
        s = replaceAll(s, regex1[i], "��");  
    }   
    // �ڶ���ת������ "����","����","��Ԫ"�����  
    // "��","��","Ԫ"��Щ��λ��Щ����ǲ���ʡ�ģ���Ҫ��������  
    for(int i = 0; i < 3; i ++) {  
        // ����һ��ת�������п����кܶ�������һ��  
        // Ҫ�Ѻܶ���ظ�������һ����  
        s = replaceAll(s, "������", "��");  
        s = replaceAll(s, "����", "��");  
        s = replaceAll(s, regex2[i], regex3[i]);  
    }  
    // ������ת����"���","���"�ַ���ʡ��  
    for(int i = 0; i < 2; i ++) {  
        s = replaceAll(s, regex4[i], "");  
    }  
//     ��"��"��"��"֮��ȫ����"��"��ʱ�򣬺���"����"��λ��ֻ����һ��"��"  
    s = replaceAll(s, "����", "��");  
    return s;  
}  
  
int main() {  
    cout << "\n------------������ת�������Ľ��Ĵ�д��ʽ��C++��------------\n" << endl;  
    string s = getNum();  
    if(checkNum(s)) {  
        s = roundString(s);  
        s = splitNum(s); 
        s = cleanZero(s);  
        cout << "ת�������ĺ�Ϊ��" << s << endl;  
    } else {  
        cout << "�Ƿ����룬���򼴽��˳�" << endl;  
    } 
    cout << "\n--------------------------------------------------------------" << endl;  
}
