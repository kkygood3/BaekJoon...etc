#include <iostream>
using namespace std;
int *temp;
int *arr;

void arraymerge(int start, int end, int *data) {

	int mid = (end + start) / 2;  // �߾Ӱ�

	int i = start;   // ���� index
	int j = mid + 1;  // ������ index

	int k = start;  // temp �迭 index
	while (i <= mid && j <= end) { // �ϳ��� �����ϸ� ��������

		if (data[i] <= data[j])   // data[i]�� ������ 
		{
			temp[k] = data[i];	  // temp �迭�� �����ϰ�
			i++;				  // i����
		}
		else {
			temp[k] = data[j];	  // �ݴ��۾�
			j++;
		}
		k++;	// temp index ����
	}

	int t;  // ���� �迭�� ������ ���
	if (i > mid) t = j;  // i�� �� ���� ��� t = j
	else t = i;  // i�� �� ������ ��� t = i

	for (k; k <= end; k++, t++) temp[k] = data[t];	//���� �迭 ó��
	for (k = start; k <= end; k++) data[k] = temp[k];   //���� �����Ϳ� �ݿ�

}

void mergesort(int start, int end, int *data) {

	int mid;

	if (start < end) {
		mid = (end + start) / 2;  // �߾Ӱ�
		mergesort(start, mid, data);  // ���� ����
		mergesort(mid + 1, end, data);  // ������ ����
		arraymerge(start, end, data);  // ����
	}

}

int main() {

	int t;
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> t;

	temp = new int[t];
	arr = new int[t];
	for (int i = 0; i < t; i++) {
		cin >> arr[i];
	}
	mergesort(0, t - 1, arr);
	for (int i = 0; i < t; i++) {
		cout << arr[i] << '\n';
	}
	return 0;
}