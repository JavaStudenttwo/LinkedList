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
	void InsertSort_attempt();
	void InsertSort(ArrayList &list);
	//��������
	void Print();

	Type * GetElements();

private:
	Type *elements;
	const int maxsize;
	int currentsize;

	//�ڲ����õķ���
	void Swap(Type &x, Type &y);
	void InsertSort(ArrayList &list, int i);

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

//ð������
template <typename Type>
void ArrayList<Type>::BubbleSort() {
	int flag = 0;
	for (int i = 0; i < currentsize; i++) {
		for (int j = currentsize; j > i; j--) {
			if (elements[j] < elements[j-1]) {
				Swap(elements[j], elements[j-1]);
				flag = 1;
			}
		}
		if (flag == 0){	break; }
		flag = 0;
	}
}

//ѡ������
template <typename Type>
void ArrayList<Type>::SelectSort() {
	for (int i = 0; i <= currentsize; i++) {
		for (int j = i + 1; j <= currentsize; j++) {
			if (elements[i] > elements[j]) {
				Swap(elements[i], elements[j]);
			}
		}
	}
}

//��������ʧ�ܵĳ���
template <typename Type>
void ArrayList<Type>::InsertSort_attempt() {
	//������һ��Type����temp
	Type * temp = new Type[currentsize];
	//��elements[0]��Ϊtemp�ĵ�һ��Ԫ�أ�����temp������Ϊ1
	int size = 1;
	temp[0] = elements[0];
	//ѭ������Ԫ��
	for (int i = 1; i < currentsize; i++){
		//����һ��Type�������ݣ���Ϊ������Ԫ��
		Type element = elements[i];
		cout << "�ڲ�" << elements[i] << endl;
		//����temp���ҵ������
		for (int j = 0; j < size; j++) {
			if (temp[j] < element) {
				//������Ԫ��ȫ������ƶ�һ����λ
				for (int z = size + 1; z > j; z--){
					temp[z + 1] = temp[z];
				}
				temp[j] = element;
				cout << "�ⲿ" << element << endl;
			}
		}
		//����һ��Ԫ�غ�,temp������һ
		size++;
	}
}

//��������
template <typename Type>
void ArrayList<Type>::InsertSort(ArrayList &list) {
	for (int i = 1; i < list.currentsize + 1; i++) {
		InsertSort(list, i);
	}
}

template <typename Type>
void ArrayList<Type>::InsertSort(ArrayList &list, int i) {
	Type temp = list.elements[i];
	int j;
	for (j = i; j > 0; j--) {
		if (temp > list.elements[j - 1]) {
			break;
		}
		else {
			list.elements[j] = list.elements[j - 1];
		}
	}
	list.elements[j] = temp;
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

template <typename Type>
Type * ArrayList<Type>::GetElements() {
	return elements;
}
 
//������Ԫ�ص�λ��
template <typename Type>
void ArrayList<Type>::Swap(Type &x, Type &y) {
	Type z;
	z = x;
	x = y;
	y = z;
}

