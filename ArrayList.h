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
	void InsertSort_attempt();
	void InsertSort(ArrayList &list);
	//基础功能
	void Print();

	Type * GetElements();

private:
	Type *elements;
	const int maxsize;
	int currentsize;

	//内部调用的方法
	void Swap(Type &x, Type &y);
	void InsertSort(ArrayList &list, int i);

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

//冒泡排序
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

//选择排序
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

//插入排序，失败的尝试
template <typename Type>
void ArrayList<Type>::InsertSort_attempt() {
	//定义另一个Type数组temp
	Type * temp = new Type[currentsize];
	//将elements[0]作为temp的第一个元素，并将temp长度设为1
	int size = 1;
	temp[0] = elements[0];
	//循环插入元素
	for (int i = 1; i < currentsize; i++){
		//声明一个Type类型数据，作为待插入元素
		Type element = elements[i];
		cout << "内部" << elements[i] << endl;
		//遍历temp，找到插入点
		for (int j = 0; j < size; j++) {
			if (temp[j] < element) {
				//将表中元素全部向后移动一个单位
				for (int z = size + 1; z > j; z--){
					temp[z + 1] = temp[z];
				}
				temp[j] = element;
				cout << "外部" << element << endl;
			}
		}
		//插入一个元素后,temp长度增一
		size++;
	}
}

//插入排序
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

template <typename Type>
Type * ArrayList<Type>::GetElements() {
	return elements;
}
 
//交换两元素的位置
template <typename Type>
void ArrayList<Type>::Swap(Type &x, Type &y) {
	Type z;
	z = x;
	x = y;
	y = z;
}

