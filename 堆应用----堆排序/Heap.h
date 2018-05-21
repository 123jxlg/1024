#pragma once
//ָ����Ը�ֵ,���Ͳ����Ը�ֵ
typedef int(*Compare)(DataType , DataType );//compare��һ������
typedef int DataType;
typedef struct Heap
{
	DataType* _array;
	int _capacity;
	int _size;
	Compare _compare;
}Heap;
//�ѵĻ�������
void HeapInit(Heap *hp, Compare com);
void HeapCreate(Heap *hp, DataType*array, int size, Compare com);
void HeapAdjustDown(Heap* hp, int parent);
void HeapAdjustUp(Heap* hp, int child);
void _CheckCapacity(Heap *hp);
int EmptyHeap(Heap *hp);
void PrintfHeap(Heap hp);
void InsertHeap(Heap *hp, DataType data);
void DeleteHeapTop(Heap *hp);
DataType GetHeapTop(Heap *hp);
int SizeHeap(Heap *hp);
//���
int Greater(DataType left, DataType right);
//С��
int Less(DataType left, DataType right);
void swap(DataType*a, DataType *b);
