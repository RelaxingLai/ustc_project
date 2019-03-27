#define NUM_MAC 3
#include <climits>
#include<iostream>
#define NUM_TASK 10

 using namespace std;
 
 int x[NUM_TASK+1] = {}; // �����ʱ��
 int best_x[NUM_TASK+1] = {}; // ������Ž� 
 int t[NUM_TASK+1] = {0,2,3,5,1,6,4,9,7,3,7}; // Ԥ�������������ʱ��
 int bestTime= INT_MAX;
 int cur_time = 0;
 int macTime[NUM_MAC+1] = {0}; 
 
 int getMax(int macTime[]){
 	int max = macTime[1];
 	for(int i=2; i<=NUM_MAC; i++)
 	{
 		if(macTime[i] > max)
 			max = macTime[i];
	 }
	 return max;
 }
 
 void backtrack(int k){
 	if(k>NUM_TASK){
 		cur_time = getMax(macTime);
 		if(cur_time < bestTime){
 			bestTime = cur_time;
 			for(int i=1; i<=NUM_TASK; i++){
 				best_x[i] = x[i];
			 }
		 }
	 }
 	else {
 		for(int i=1; i<=NUM_MAC; i++){
 			x[k] = i;     
 			macTime[i] += t[k];
 			if(macTime[i] < bestTime)
 				backtrack(k+1);
 			macTime[i] -= t[k];
		 }
	 }
 }
 
 
 int main(){
 	cout << "��������" << 3 << endl;
	cout << "ִ��ÿ�����������ʱ�䣺"  ;
	for(int i=1; i<=NUM_TASK; i++)
	{
		cout << t[i] << " " ;
	 } 
	 cout << endl;
	 
	 backtrack(1);
	 
	 cout <<"��ѷ�������ʱ�䣺 "<< bestTime<< endl << endl;;
	 for(int i=1; i<=NUM_TASK; i++){
	 	cout << "�� " << i << " ������������� " << best_x[i] << " ������"  << endl; 
	 }
 } 
