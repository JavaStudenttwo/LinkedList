#pragma once

const int DefaultSize = 10;

template <typename Type>
class  ArrayList
{
public:
	 ArrayList(int defaultSize);
	~ ArrayList();
	//��ʼ��������
	void InitList();
	void DestoryList();
	//����˳�����Ϣ
	int Length() const;
	bool isElement(Type x) const;
	bool IsEmpty();
	bool IsFull();
	//˳����Ԫ�ز���
	void Insert(Type x,int i);
	void Remove(Type x);
	Type GetElement(int i);
	//����
	int SequentialSearch(Type x);
	int BinarySearch(Type x);
	int InterpolateSearch(Type x);
	//����
	int BbSort(Type x);
	//��������
	void Print();

private:
	Type *elements;
	const int maxsize;
	int currentsize;

};

//���캯��
template <typename Type> 
ArrayList<Type>:: ArrayList(int defaultSize = DefaultSize)
	:maxsize(defaultSize), currentsize(-1){
	if (defaultSize > 0 )
	{
		elements = new Type[maxsize];
	}

}

//��������
template <typename Type>
ArrayList<Type>:: ~ ArrayList()
{
	delete[] elements;
}

//��ʼ��˳���
template <typename Type>
void ArrayList<Type>:: InitList();

//����˳���
template <typename Type>
void ArrayList<Type>:: DestoryList();

//��ȡ˳�����
template <typename Type>
int ArrayList<Type>::Length() const { return currentsize; }

//���Ԫ��ʵ���Ƿ���˳�����
template <typename Type>
bool ArrayList<Type>::isElement(Type x) const;

//���˳����Ƿ�Ϊ��
template <typename Type>
bool ArrayList<Type>::IsEmpty() { return currentsize == - 1; }

//���˳����Ƿ����
template <typename Type>
bool ArrayList<Type>::IsFull() { return currentsize == maxsize - 1; }

//����Ԫ��
template <typename Type>
void ArrayList<Type>::Insert(Type x, int i) {
	if (i<0 || i>currentsize + 1 || currentsize == maxsize - 1)
	{
		cout << "�������ݴ���" << endl;
	}
	currentsize++;
	for (int j = currentsize; j > i; j--)
	{
		elements[j] = elements[j - 1];
	}
	elements[i] = x;

}

//����Ԫ��ʵ�壬ɾ��˳����еĸ�Ԫ��
template <typename Type>
void ArrayList<Type>::Remove(Type x) {

}

//���ݽǱ��ȡԪ��
template <typename Type>
Type ArrayList<Type>::GetElement(int i) {

}

//���ֲ���
template <typename Type>
int ArrayList<Type>::BinarySearch(Type x) {
	int min = 0;
	int max = currentsize;
	int mid = max / 2;
	while (min<max)
	{
		if (elements[mid] == x) {
			return mid;
		} 
		else if (elements[mid] < x) {
			min = mid + 1 ;
			mid = min + (max - min) / 2;
		}
		else if (elements[mid] > x) {
			max = mid - 1 ;
			mid = min + (max - min) / 2;
		}
	}
	cout << "Ŀ��Ԫ�ز���˳�����" << endl;
	return -1;

}

//��ֵ����
template <typename Type>
int ArrayList<Type>::InterpolateSearch(Type x) {
	int min = 0;
	int max = currentsize;
	int mid = min + (max-min)/2;
	while (min<max)
	{
		if (elements[mid] == x) {
			return mid;
		}
		else if (elements[mid] < x) {
			min = mid + (max - min)*1.0*(mid - max) / (min - max);
			mid = min + (max - min) / 2;
		}
		else if (elements[mid] > x) {
			max = mid + (max - min)*1.0*(mid - max) / (min - max);
			mid = min + (max - min) / 2;
		}
	}
	cout << "Ŀ��Ԫ�ز���˳�����" << endl;
	return -1;
}

//��ӡ˳��������Ԫ��
template <typename Type>
void ArrayList<Type>::Print() {
	cout << "\n";
	for (int i = 0; i <= currentsize; i++)
	{
		cout << "��" << i + 1 << "���ֵΪ"<< ":\t" << elements[i] << endl;
	}
	cout << endl << endl;
}
 