#include<iostream>
#include<vector>
using namespace std;
void sort(vector<int> &a , vector<int> &res, int k){
	vector<int> c(k+1);
	
	cout << endl;

	for(int i=0; i<a.size(); i++)
	{
		c[a[i]]++;
	}     //��a�е�ÿ�������� 
	for(int i=1 ; i<k+1; i++) // a���鲻Ҫ�ˣ�����ֻ��עc���飬c����Ȱ���a�����ֵ��Ҳ����ֵ֮���˳�򣬻�����a�����е�ֵ�м����� 
	{
		if(c[i])
			for(int j=0, t=0; j<c[i];j++)
				res.push_back(i);
	}
} 

int main(){
	vector<int> a = {2, 5, 2 , 4, 1, 5, 4, 6, 2,1};
	vector<int> res={};
	sort(a, res, 6);
	for(int i=0; i<res.size(); i++)
		cout << res[i] << '\t';
} 
