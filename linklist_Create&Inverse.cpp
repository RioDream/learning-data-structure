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
	//�����鸳ֵ
	int len = 5;
	node nd = { 5, NULL };
	node* last_nd = &nd;
	node* head;

	//�Ӻ�ǰ����������
	for (int i = len - 1; i >= 0; i--){
		node* n = new node;
		*n = { i, last_nd };
		last_nd = n;

	}
	head = last_nd;

	//��ǰ����������� 
	node* iter = head;
	cout << "��ǰ��������������" << endl;
	while (iter != NULL)
	{
		cout << iter->i << endl;
		iter = iter->next;
	}

	//��ǰ������������
	iter = last_nd;
	node* p_current = iter->next;
	node* p_next = p_current->next;
	iter->next = NULL; //��ͷ��Ϊβ
	node* p_prior = iter;
	while (p_current != NULL) //ע��������p_current ����p_next
	{
		//����·
		p_next = p_current->next;
		//��ǰ��ָ��ǰһ��
		p_current->next = p_prior;
		
		p_prior = p_current;
		p_current = p_next;
	}

	//���
	cout << endl;
	cout << "��ǰ�����������֮�������" << endl;
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
//		last_nd = *n; //�����������last_nd�ĵ�ַ��û�иı䣬ֻ��ֵ���� ��
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

