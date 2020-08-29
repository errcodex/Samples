#include <malloc.h>
#include <cstring>
#include <queue>
#include "MySort.h"
void  MySort::swap(int arr[], const uint a, const uint b)
{
	if (a == b)return;
	int t = arr[a];
	arr[a] = arr[b];
	arr[b] = t;
}
// ð������
// ������������ÿ��ѭ��ȷ��һ�������С����λ��
bool MySort::bubbleSort(int arr[], const uint len)
{
	for (uint i = 0; i < len; ++i)
	{
		for (uint j = 0; j < len - i - 1; ++j)
		{
			if (arr[j] > arr[j + 1])swap(arr, j, j + 1);
		}
	}
	return true;
}
// ѡ������
// ÿ�δ�δ�������ѡ��һ�������С����������������п�ͷ��ĩβ��
bool MySort::selectionSort(int arr[], const uint len)
{
	for (uint i = 0; i < len; ++i)
	{
		uint min = i;
		for (uint j = i + 1; j < len; ++j)
		{
			if (arr[min] > arr[j])min = j;
		}
		swap(arr, i, min);
	}
	return true;
}
// ��������
// ��δ���������ѡ��һ���������ŵ������������Ӧ��λ��
bool MySort::insertionSort(int arr[], const uint len)
{
	for (uint i = 1; i < len; ++i)
	{
		// j Ϊ�����i����ǰƫ����
		for (uint j = 0; j < i; ++j)
		{
			if (arr[i - j] < arr[i - j - 1])
			{
				swap(arr, i - j, i - j - 1);
				continue;
			}
			break;
		}
	}
	return true;
}
// ϣ������
// ѡ����������t(n)������t(n-1) > t(n)
// ÿ���������t(n)��ֵd���з��飬ÿ���¼�����ڵ������±����d
// ��ÿ��������ֱ�Ӳ�������
// ��������n++��������d���·��鲢����
// ֱ��d=1ʱ������Ϊһ�飬�൱����������ֱ�Ӳ�������
bool MySort::shellSort(int arr[], const uint len)
{
	uint h = 1;
	while (3 * h < len)
		h = 3 * h + 1;
	while (h >= 1)
	{
		for (uint i = h; i < len; ++i)
		{
			// j Ϊ�����i����ǰƫ����
			for (uint j = 0; j < i; j += h)
			{
				if (arr[i - j] < arr[i - j - 1])
				{
					swap(arr, i - j, i - j - 1);
					continue;
				}
				break;
			}
		}
		h /= 3;
	}
	return true;
}
// �鲢����
//����ռ䣬ʹ���СΪ�����Ѿ���������֮�ͣ��ÿռ�������źϲ�������У�
//�趨����ָ�룬���λ�÷ֱ�Ϊ�����Ѿ��������е���ʼλ�ã�
//�Ƚ�����ָ����ָ���Ԫ�أ�ѡ�����С��Ԫ�ط��뵽�ϲ��ռ䣬���ƶ�ָ�뵽��һλ�ã�
//�ظ����� 3 ֱ��ĳһָ��ﵽ����β��
//����һ����ʣ�µ�����Ԫ��ֱ�Ӹ��Ƶ��ϲ�����β��
bool MySort::mergeSort(int arr[], const uint len)
{
	if (len < 2)return true;
	int* t = (int*)malloc(sizeof(arr)*len);
	uint la = len >> 1;
	uint lb = len - la;
	int* pa = arr;
	int* pb = arr + la;
	mergeSort(pa, la);
	mergeSort(pb, lb);

	for (uint i = 0; i < len && la>0 && lb > 0; i++)
	{
		if (*pa <= *pb){
			t[i] = *pa;
			--la;
			++pa;
			continue;
		}
		t[i] = *pb;
		--lb;
		++pb;
	}

	memcpy(t + len - la, pa, la*sizeof(int));
	memcpy(t + len - lb, pb, lb*sizeof(int));

	memcpy(arr, t, len*sizeof(int));
	free(t);
	return true;
}

// ��������
// ѡ���׼������С�ڻ�׼�������ŵ�ǰ�棬�������ķŵ�����
// ÿ������ȷ����׼����λ��
bool MySort::quickSort(int arr[], const uint len)
{
	if (len < 2)return true;
	// С�ڻ�׼��������±�
	uint s_end = 0;
	for (uint i = 1; i < len; i++)
	{
		if (arr[i] < arr[0]){
			swap(arr, ++s_end, i);
		}
	}
	// ��׼����λ
	swap(arr, 0, s_end);
	// С�ڻ�׼��������
	quickSort(arr, s_end);
	// ���ڻ�׼��������
	quickSort(arr + s_end + 1, len - s_end - 1);
	return true;
}
// �������򣨻���2��ʵ�֣�
// 
bool MySort::radixSort(int arr[], const uint len)
{
	typedef std::queue<int> t;
	t base[2] = { t(), t() };
	// Ȩ
	for (uint i = 0;; ++i)
	{
		bool flag = false;
		for (uint j = 0; j < len; ++j)
		{
			// �����ŵ�base[k]�У�kΪ������iλ�������ƣ���ֵ
			base[(arr[j] & (0x1 << i)) >> i].push(arr[j]);
			if (arr[j] >> i)flag = true;
		}
		uint in = 0;
		// ��base[0]��base[1]�е�ֵ�Żص�arr��
		while (!base[0].empty())
		{
			arr[in++] = base[0].front();
			base[0].pop();
		}
		while (!base[1].empty())
		{
			arr[in++] = base[1].front();
			base[1].pop();
		}
		if (!flag)break;
	}
	return true;
}