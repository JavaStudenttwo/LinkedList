#pragma once

const int DefaultSize = 10;

template <typename Type>
class  ArrayList
{
public:
	 ArrayList(int defaultSize);
	~ ArrayList();
	//��ʼ��������
	void InitList(Type * p ,int size);
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
	void BubbleSort();
	void SelectSort();
	//��������
	void Print();
	void Swap(Type *x, Type *y);

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
void ArrayList<Type>::InitList(Type * p ,int size)
{
	if (size > maxsize) {
		count << "���ݹ���" << endl;
		break;
	}
	for (int i = 0; i < size; i++) {
		elements[i] = p[i];
	}
}

//����˳���
template <typename Type>
void ArrayList<Type>::DestoryList()
{
	delete[] elements;
}

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

//����˳���Ԫ�ؽǱ����Ԫ��
template <typename Type>
void ArrayList<Type>::Insert(Type x, int i) {
	//�����֣�����λ����СֵԽ�磬����λ�����ֵԽ�磬˳���Ԫ�ع���
	if (i<0 || i>currentsize + 1 || currentsize == maxsize - 1) {
		cout << "�������ݴ���" << endl;
	}
	//currentsize 3 maxsize 4  
	//InSert(6,3)	i=3 
	//currentsize=4 
	//1	  2	  3   4
	//1   2   3   6   4
	currentsize++;
	for (int j = currentsize; j > i; j--) {
		elements[j] = elements[j - 1];
	}
	elements[i] = x;

}

//����Ԫ��ʵ�壬ɾ��˳����еĸ�Ԫ��
template <typename Type>
void ArrayList<Type>::Remove(Type x) {
	int size = currentsize;
	for (int i = 0; i < currentsize;) {
		if (elements[i] == x) {
			for (int j = i; j < currentsize; j++) {
				elements[j] = elements[j + 1];
			}
			currentsize - 1;
			//���ɾ����һ��Ԫ�أ���i��������
			continue;
		}
		i++;
	}
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
	int mid = min + (max - min) / 2;
	cout << mid << endl;
	//ע��������С�ڵ��ڣ�û�е��ںŻ�����ش����
	while (min <= max)
	{
		if (elements[mid] == x) {
			cout << "Ŀ��Ԫ����˳����еĵ�" << mid+1 << "��Ԫ��" << endl;
			return mid;
		} 
		else if (elements[mid] < x) {
			min = mid + 1 ;
			mid = min + (max - min) / 2;
			cout << mid << endl;
		}
		else if (elements[mid] > x) {
			max = mid - 1 ;
			mid = min + (max - min) / 2;
			cout << mid << endl;
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
	cout << mid << endl;
	while (min <= max)
	{
		if (elements[mid] == x) {
			cout << "Ŀ��Ԫ����˳����еĵ�" << mid + 1 << "��Ԫ��" << endl;
			return mid;
		}
		else if (elements[mid] < x) {
			min = mid + 1;
			mid = min + (max - min)*1.0*(x - elements[min]) / (elements[max] - elements[min]);
			cout << mid << endl;
		}
		else if (elements[mid] > x) {
			max = mid - 1;
			mid = min + (max - min)*1.0*(x - elements[min]) / (elements[max] - elements[min]);
			cout << mid << endl;
		}
	}
	cout << "Ŀ��Ԫ�ز���˳�����" << endl;
	return -1;
}

template <typename Type>
void ArrayList<Type>::BubbleSort() {
	
}

template <typename Type>
void ArrayList<Type>::SelectSort() {
	for (int i = 0; i < currentsize; i++) {
		for (int j = i + 1; j < currentsize; j++) {
			if (elements[i] > elements[j]) {
				Swap(&elements[i], &elements[j]);
			}
		}
	}
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

	cout << endl << currentsize << endl;
}
 
//������Ԫ�ص�λ��
template <typename Type>
void ArrayList<Type>::Swap(Type *x, Type *y) {
	Type z;
	z = *x;
	*x = *y;
	*y = z;
}

