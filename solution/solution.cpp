#include <iostream>
using namespace std;
int *temp;
int *arr;

void arraymerge(int start, int end, int *data) {

	int mid = (end + start) / 2;  // 중앙값

	int i = start;   // 왼쪽 index
	int j = mid + 1;  // 오른쪽 index

	int k = start;  // temp 배열 index
	while (i <= mid && j <= end) { // 하나라도 도달하면 빠져나옴

		if (data[i] <= data[j])   // data[i]가 작으면 
		{
			temp[k] = data[i];	  // temp 배열에 삽입하고
			i++;				  // i증가
		}
		else {
			temp[k] = data[j];	  // 반대작업
			j++;
		}
		k++;	// temp index 증가
	}

	int t;  // 한쪽 배열이 남았을 경우
	if (i > mid) t = j;  // i는 다 썼을 경우 t = j
	else t = i;  // i가 덜 사용됬을 경우 t = i

	for (k; k <= end; k++, t++) temp[k] = data[t];	//남은 배열 처리
	for (k = start; k <= end; k++) data[k] = temp[k];   //실제 데이터에 반영

}

void mergesort(int start, int end, int *data) {

	int mid;

	if (start < end) {
		mid = (end + start) / 2;  // 중앙값
		mergesort(start, mid, data);  // 왼쪽 정렬
		mergesort(mid + 1, end, data);  // 오른쪽 정렬
		arraymerge(start, end, data);  // 병합
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