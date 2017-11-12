#pragma once

const int DefaultSize = 10;

template <typename Type>
class  ArrayList
{
public:
	 ArrayList(int defaultSize);
	~ ArrayList();
	//初始化和销毁
	void InitList(Type * p ,int size);
	void DestoryList();
	//返回顺序表信息
	int Length() const;
	bool isElement(Type x) const;
	bool IsEmpty();
	bool IsFull();
	//顺序表的元素操作
	void Insert(Type x,int i);
	void Remove(Type x);
	Type GetElement(int i);
	//查找
	int SequentialSearch(Type x);
	int BinarySearch(Type x);
	int InterpolateSearch(Type x);
	//排序
	void BubbleSort();
	void SelectSort();
	//基础功能
	void Print();
	void Swap(Type *x, Type *y);

private:
	Type *elements;
	const int maxsize;
	int currentsize;

};

//构造函数
template <typename Type> 
ArrayList<Type>:: ArrayList(int defaultSize = DefaultSize)
	:maxsize(defaultSize), currentsize(-1){
	if (defaultSize > 0 )
	{
		elements = new Type[maxsize];
	}
}

//析构函数
template <typename Type>
ArrayList<Type>:: ~ ArrayList()
{
	delete[] elements;
}

//初始化顺序表
template <typename Type>
void ArrayList<Type>::InitList(Type * p ,int size)
{
	if (size > maxsize) {
		count << "数据过多" << endl;
		break;
	}
	for (int i = 0; i < size; i++) {
		elements[i] = p[i];
	}
}

//销毁顺序表
template <typename Type>
void ArrayList<Type>::DestoryList()
{
	delete[] elements;
}

//获取顺序表长度
template <typename Type>
int ArrayList<Type>::Length() const { return currentsize; }

//检测元素实体是否在顺序表中
template <typename Type>
bool ArrayList<Type>::isElement(Type x) const;

//检测顺序表是否为空
template <typename Type>
bool ArrayList<Type>::IsEmpty() { return currentsize == - 1; }

//检测顺序表是否过载
template <typename Type>
bool ArrayList<Type>::IsFull() { return currentsize == maxsize - 1; }

//根据顺序表元素角标插入元素
template <typename Type>
void ArrayList<Type>::Insert(Type x, int i) {
	//当出现，插入位置最小值越界，插入位置最大值越界，顺序表元素过载
	if (i<0 || i>currentsize + 1 || currentsize == maxsize - 1) {
		cout << "插入数据错误" << endl;
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

//根据元素实体，删除顺序表中的该元素
template <typename Type>
void ArrayList<Type>::Remove(Type x) {
	int size = currentsize;
	for (int i = 0; i < currentsize;) {
		if (elements[i] == x) {
			for (int j = i; j < currentsize; j++) {
				elements[j] = elements[j + 1];
			}
			currentsize - 1;
			//如果删除了一个元素，则i不用自增
			continue;
		}
		i++;
	}
}

//根据角标获取元素
template <typename Type>
Type ArrayList<Type>::GetElement(int i) {

}

//二分查找
template <typename Type>
int ArrayList<Type>::BinarySearch(Type x) {
	int min = 0;
	int max = currentsize;
	int mid = min + (max - min) / 2;
	cout << mid << endl;
	//注意这里是小于等于，没有等于号会出现重大错误
	while (min <= max)
	{
		if (elements[mid] == x) {
			cout << "目标元素是顺序表中的第" << mid+1 << "个元素" << endl;
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
	cout << "目标元素不在顺序表中" << endl;
	return -1;

}

//插值查找
template <typename Type>
int ArrayList<Type>::InterpolateSearch(Type x) {
	int min = 0;
	int max = currentsize;
	int mid = min + (max-min)/2;
	cout << mid << endl;
	while (min <= max)
	{
		if (elements[mid] == x) {
			cout << "目标元素是顺序表中的第" << mid + 1 << "个元素" << endl;
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
	cout << "目标元素不在顺序表中" << endl;
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

//打印顺序表的所有元素
template <typename Type>
void ArrayList<Type>::Print() {
	cout << "\n";
	for (int i = 0; i <= currentsize; i++)
	{
		cout << "第" << i + 1 << "项的值为"<< ":\t" << elements[i] << endl;
	}
	cout << endl << endl;

	cout << endl << currentsize << endl;
}
 
//交换两元素的位置
template <typename Type>
void ArrayList<Type>::Swap(Type *x, Type *y) {
	Type z;
	z = *x;
	*x = *y;
	*y = z;
}

