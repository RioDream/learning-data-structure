// ConsoleApplication5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
using namespace std;

struct node{
	int i;
	node* next;
};

int _tmain(int argc, _TCHAR* argv[])
{
	//给数组赋值
	int len = 5;
	node nd = { 5, NULL };
	node* last_nd = &nd;
	node* head;

	//从后到前，建立链表
	for (int i = len - 1; i >= 0; i--){
		node* n = new node;
		*n = { i, last_nd };
		last_nd = n;

	}
	head = last_nd;

	//从前到后遍历链表 
	node* iter = head;
	cout << "从前到后遍历输出链表" << endl;
	while (iter != NULL)
	{
		cout << iter->i << endl;
		iter = iter->next;
	}

	//从前到后将链表逆序
	iter = last_nd;
	node* p_current = iter->next;
	node* p_next = p_current->next;
	iter->next = NULL; //把头置为尾
	node* p_prior = iter;
	while (p_current != NULL) //注意这里是p_current 不是p_next
	{
		//留后路
		p_next = p_current->next;
		//当前的指向前一个
		p_current->next = p_prior;
		
		p_prior = p_current;
		p_current = p_next;
	}

	//输出
	cout << endl;
	cout << "从前到后遍历倒序之后的链表" << endl;
	iter = p_prior;
	while (iter != NULL)
	{
		cout << iter->i << endl;
		iter = iter->next;
	}

	
	getchar();

	return 0;
}

//int _tmain(int argc, _TCHAR* argv[])
//{
//	int len = 5;
//	node nd = { 5, NULL };
//	node last_nd = nd;
//
//	for (int i = len - 1; i > 0; i--){
//		node* n = new node;
//		*n = { i, &last_nd };
//		last_nd = *n; //这里产生错误，last_nd的地址并没有改变，只是值传递 ！
//
//	}
//
//	while (last_nd.next != NULL)
//	{
//		std::cout << last_nd.i << std::endl;
//		last_nd = *last_nd.next;
//	}
//
//	getchar();
//
//	return 0;
//}

