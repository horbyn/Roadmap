/* 选择排序->堆排序
 * 插入排序
 * 冒泡排序(交换排序)->快速排序
 * 归并排序
 */
/* 相关题: A1098、A1089、A1101 */
#include <iostream>
using namespace std;

int n = 10;
int a[] = { 44, 13, 76, 25, 49, 58, 92, 33, 67, 82 };///除堆排其他从 0 开始
int tmp[10] = {};
int heap[] = { 0, 44, 13, 76, 25, 49, 58, 92, 33, 67, 82 };///堆排从 1 开始

void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

//选择
void selection_sort() {
	for (int i = 0; i < n - 1; ++i) {
		int min = i;
		for (int j = i; j < n; ++j)
			if (a[min] > a[j])    min = j;
		swap(a[i], a[min]);
	}
}


//插入
void insertion_sort() {
	for (int i = 1; i < n; ++i) {
		int tmp = a[i], j = i;
		for (; j > 0 && a[j - 1] > tmp; --j)    a[j] = a[j - 1];
		swap(a[j], tmp);
	}
}

//冒泡(即交换)
void bubble_sort() {
	for (int i = 0; i < n - 1; ++i)
		for (int j = n - 1; j > i; --j)
			if (a[j - 1] > a[j])    swap(a[j - 1], a[j]);
}

//堆排(即选择)附件一
void adjust_down(int l, int h) {
	int i = l, j = 2 * i;
	while (j <= h) {
		if (j + 1 < h && heap[j + 1] > heap[j])    j++;

		if (heap[i] < heap[j]) {
			swap(heap[i], heap[j]);
			i = j;
		} else    i = 2 * i;

		j = 2 * i;
	}
}

//堆排(即选择)附件二
void create_heap() {
	for (int i = n / 2; i >= 1; --i)    adjust_down(i, n);
}

//堆排(即选择)
void heap_sort() {
	create_heap();

	for (int i = n; i > 1; --i) {
		swap(heap[1], heap[i]);
		adjust_down(1, i - 1);
	}
}

//快排
void quick_sort(int l, int r) {
	if (l > r)    return;//递归必须要有循环条件

	int pivot = l, i = l, j = r;
	while (i != j) {
		while (a[pivot] <= a[j] && i != j)    --j;
		while (a[pivot] >= a[i] && i != j)    ++i;
		if (i != j)    swap(a[i], a[j]);
	}
	swap(a[pivot], a[i]);

	quick_sort(l, i - 1);
	quick_sort(i + 1, r);
}

//归并附件一
void merge(int l, int r, int rE) {
	int lE = r - 1, num = rE - l + 1;
	int p = l;

	while (l <= lE && r <= rE) {
		if (a[l] < a[r])    tmp[p++] = a[l++];
		else    tmp[p++] = a[r++];
	}
	while (l <= lE)    tmp[p++] = a[l++];
	while (r <= rE)    tmp[p++] = a[r++];

	--p;
	for (int i = 0; i < num; ++i, --p)    a[p] = tmp[p];
}

//归并附件二
void submerge(int s) {
	int i = 0;
	for (; i <= n - 2 * s; i += 2 * s)    merge(i, i + s, i + 2 * s - 1);
	if (i + s < n)    merge(i, i + s, n - 1);//最后两个子列
}

//归并排序
void merge_sort() {
	int step = 1;//步长
	while (step < n) {
		submerge(step);
		step *= 2;
	}
}

int main() {
	//EXECUATE
	//selection_sort();
	//insertion_sort();
	//bubble_sort();
	//heap_sort();
	//merge_sort();
	quick_sort(0, n - 1);

	//OUTPUT
	for (int i = 0; i < n; ++i)    cout << a[i] << " ";///除堆排外其他函数的输出
	//for (int i = 1; i <= n; ++i)    cout << heap[i] << " ";///堆排专用输出

	return 0;
}