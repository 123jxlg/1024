#include "Heap.h"
#include<assert.h>
#include<stdlib.h>
#include<malloc.h>
#include<stdio.h>
//С��
int Less(DataType left, DataType right){
	return left < right;
}
//���
int Greater(DataType left, DataType right){
	return left > right;
}

//����
void swap(DataType*a,DataType *b){
	DataType c = 0;
	assert(a);
	assert(b);
	c = *a;
	*a = *b;
	*b = c;
}
//����������
void HeapAdjustDown(Heap* hp, int parent){
	//��child��������Һ�������С��Ԫ��
	int child = parent * 2 + 1;
	int size = hp->_size;
	while (child<size)
	{
		if ((child + 1)<size&&(hp->_compare(hp->_array[child+1],hp->_array[child])))
			child += 1;
		if (hp->_compare(hp->_array[child],hp->_array[parent]))
		{
			swap(&hp->_array[parent], &hp->_array[child]);
			//�������Ӱ��������Ľṹ,��Ҫ������
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			return;
		}
	}
	
}
//����������
void HeapAdjustUp(Heap* hp, int child){
	int parent = ((child-1)>>1);
	while (child)
	{
		if (hp->_compare(hp->_array[child],hp->_array[parent]))
		{
			swap(&hp->_array[parent], &hp->_array[child]);
			child = parent;
			parent = ((child - 1) >> 1);
		}
		else
		   return;
	}
	

}
//�ѵĳ�ʼ��
void HeapInit(Heap *hp,Compare com){
	hp->_array = (DataType*)malloc(sizeof(DataType)*3);
	if (hp->_array == NULL)
	{
		assert(0);
		return;
	}
	hp->_capacity = 3;
	hp->_size = 0;
	hp->_compare = com;
}
//�Ѵ���
void HeapCreate(Heap *hp, DataType*array, int size,Compare com){
	int i = 0;
	int root = ((size - 2) >> 1);
	if (hp == NULL)
		return;
	hp->_array = (DataType*)malloc(sizeof(DataType)*size);
	if (hp->_array==NULL)
	{
		assert(0);
		return;
	}
    //�������Ԫ�طŵ�����ȥ
	for (i = 0; i < size; i++)
	{
		hp->_array[i] = array[i];
	}
	hp->_size = size;
	hp->_capacity = size;
	hp->_compare = com;
   //�ѵ���1.���µ���
	for (; root >=0; --root)
	{
		HeapAdjustDown(hp,root);
	}
	
}
//��������  //�����¿ռ�,����Ԫ��,�ͷžɿռ�
void _CheckCapacity(Heap *hp){
	int i = 0;
	assert(hp);
	if (hp->_size==hp->_capacity)
	{
		int NewCapacity = 2 *(hp->_capacity);
		DataType *temp = (DataType*)malloc(NewCapacity*sizeof(DataType));
		if (temp==NULL)
		{
			assert(0);
			return;
		}
		for (i = 0; i < hp->_size; i++)
		{
			temp[i] = hp->_array[i];
		}
		free(hp->_array);
		hp->_array = temp;
	}

}
//����в���Ԫ��
void InsertHeap(Heap *hp,DataType data){
	assert(hp);
	_CheckCapacity(hp);
	hp->_array[hp->_size++] = data;
	int child = (hp->_size) - 1;
	HeapAdjustUp(hp, child);
}
void PrintfHeap(Heap hp){
	int i = 0;
	int size = hp._size;
	for (i = 0; i < size; i++)
	{
		printf("%d ", hp._array[i]);
	}
	printf("\n");
}
int EmptyHeap(Heap *hp){
	assert(hp);
	return 0 == hp->_size;
}
//�����ɾ��Ԫ��--һ��ɾ���Ѷ�Ԫ��
void DeleteHeapTop(Heap *hp, DataType data){
	assert(hp);
	if (EmptyHeap(hp))
		return;
	hp->_array[0] = hp->_array[hp->_size-1];
	hp->_size--;
	HeapAdjustDown(hp, 0);
}
//������Ч��Ԫ��
int SizeHeap(Heap *hp){
	return hp->_size;
}
DataType GetHeapTop(Heap *hp){
	assert(!EmptyHeap(hp));
	return hp->_array[0];
}