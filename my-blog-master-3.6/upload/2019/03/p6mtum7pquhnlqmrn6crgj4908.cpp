#include <stdio.h>
#include<iostream>
#define ARRAY_SIZE 10

int select(int a[], int l, int r, int k);
int partition(int a[], int p, int r, int pivot);
void insertsort(int a[], int low, int high);
void swap(int a[], int i, int j);

int main(void)
{
	int a[ARRAY_SIZE] = { 25,31,89,12,67,53,44,59,71,19 };

	printf("%d\n", select(a, 0, ARRAY_SIZE - 1, 6));

	system("pause");
}

int select(int a[], int l, int r, int k)
{
	int group;
	int i;
	int left, right, mid;
	int pivot;
	int q, left_num;

	if (r - l + 1 <= 5) {   // �����������ܹ���5������û��
		insertsort(a, l, r);   // ��ô����������ڵ���ֱ�Ӳ�������
		return a[l + k - 1];	// Ȼ�󷵻ص�k�����ͺ���
	}

	group = (r - l + 1 + 5) / 5;    // ����˵����ֹ5���������ҿ���Ҫ�ּ����飬group������
	for (i = 0; i < group; i++) {   // ѭ��group��
		left = l + 5 * i;
		right = (left + 4) > r ? r : left + 4; //�����ұ߽��ʹ���ұ߽縳ֵ
		mid = (left + right) / 2;
		insertsort(a, left, right);
		//��������λ����ǰi��Ԫ�ػ���λ�ã�����ݹ�selectѰ����λ������λ��
		swap(a, l + i, mid);
	}  // ѭ������֮��ǰgroup��������ݶ�����λ��
	pivot = select(a, l, l + group - 1, (group + 1) / 2); // �ݹ������λ������λ����Ҳ�������ǰgroup��������λ��
	//ע��pivot�����Ǹ���ֵ�����������±�
	// ����λ������λ����Ϊ��׼��λ��
	q = partition(a, l, r, pivot);    // �ҳ��µĻ���λ��

	//left_num = q - l;
	if (k == q)
		return a[q];
	else if (k <= q-1) //k�ڵ���
		return select(a, l, q - 1, k);
	else //k�ڸ���
		return select(a, q + 1, r, k - q);
}

int partition(int a[], int p, int r, int pivot)
{
	int x;
	int i = p - 1;
	int j, tmp;

	for (j = p; j < r; j++) {//���ȱ���һ�飬��pivot�����һ��Ԫ�ػ�����
		if (a[j] == pivot) {
			swap(a, j, r);
		}
	}    //��������ͺ�һ���partitionһ�����㷨��
	x = a[r];

	for (j = p; j < r; j++) {
		if (a[j] <= x) {
			i++;
			tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
		}
	}
	tmp = a[r];
	a[r] = a[i + 1];
	a[i + 1] = tmp;  
	return i + 1;
}

// ��������
void insertsort(int a[], int low, int high)
{
	int i, j;
	int key;

	for (i = low + 1; i <= high; i++) {
		key = a[i];
		for (j = i - 1; j >= low && key < a[j]; j--){
			a[j + 1] = a[j];
		}
		a[j + 1] = key;
	}
}

void swap(int a[], int i, int j)
{
	int tmp = a[i];

	a[i] = a[j];
	a[j] = tmp;
}