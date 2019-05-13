#include<iostream>
#include<ctime>
#include<vector>
#define K 20 
using namespace std;

void countingSort(vector<int> &a){ // a�е�Ԫ��ֵ0~19 
//	vector<int> b(a.size());
	unsigned long c[20] = {};
	for(int i= 0; i<a.size(); i++){
//		b[i] = a[i];
		c[a[i]]++;
	}// c�д����ÿ�����ĸ������Ӷ����Ժ����׵ó�ÿ����������
	int n = a.size()-1;
	for(int i = K-1; i>=0; i--){	// �����˼·�ǽ����ִӴ�С������� ��ֱ�ӷţ��Ӻ���ǰ����ķš� �����������ϵĻ�Ҫͳ��С���Լ������� 
		for(int j=0; j<c[i]; j++){
			a[n--] = i;
		}
	}
}

int main(){
	srand(time(0));
	vector<int> a;
	int n;
	cin>>n;

	for(int i=0; i<n; i++){
		a.push_back(rand()%20);
	}
	cout << "����� ��"; 
	for(int i=0; i<a.size(); i++){
		cout << a[i] << '\t';
	}
	cout << endl;
	
	countingSort(a);		 //********��������**********************************

	cout << "����� ��";
	for(int i=0;i<a.size();i++)	
		cout << a[i]  << "\t" ;
	return 0;
}
