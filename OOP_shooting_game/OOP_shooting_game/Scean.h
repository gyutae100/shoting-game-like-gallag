//------------------------------------------------------------------------------
//	Ŭ���� ������
//
//			    CSean
//		    /    /      |   
//		 CMenu   CStage1  CStatics 

//------------------------------------------------------------------------------

#pragma once

//------------------------------------------------------------------------------
//	ǥ�� ��� ���̺귯�� ��Ŭ���
//------------------------------------------------------------------------------
#include <iostream>
using namespace std;

//------------------------------------------------------------------------------
//	���� ���� ���̺귯�� ��Ŭ���
//------------------------------------------------------------------------------
//���� ���̺귯��
#include "_g_public.h"


extern void Cs_GetMsg();
extern void Bf_Out();
extern void Bf_Init();

//extern CSceneManager g_scean_manager;


//------------------------------------------------------------------------------
//	�� Ŭ����
//
//	:�ֻ��� ������Ʈ
//	:���� ��� ����
//------------------------------------------------------------------------------
class CScean {



public:
	virtual void Run() = 0;

	void Distroy()
	{
		delete(this);
	}

protected:
	virtual ~CScean()
	{

	}


};



//------------------------------------------------------------------------------
//	��������1 Ŭ����
//
//	:�ֻ��� ������Ʈ
//	:���� ��� ����
//------------------------------------------------------------------------------
class CStage1 : public CScean {

protected:
	virtual ~CStage1()
	{

	}

public:

	CStage1()
	{

	}

	virtual void Run()
	{

		//------------------------------------------------------------------------------
		//	extern ���� ��� ����
		//
		//	:�ʱ�ȭ ��� ��� '\0' 
		//------------------------------------------------------------------------------
		extern char g_buffer[SIZE_PLAY_SCREEN::PLAY_SCREEN_HEIGHT][SIZE_PLAY_SCREEN::PLAY_SCREEN_WIDTH];

		extern CList<CObject*>::iterator* g_buf_iter[SIZE_PLAY_SCREEN::PLAY_SCREEN_HEIGHT][SIZE_PLAY_SCREEN::PLAY_SCREEN_WIDTH];

		//------------------------------------------------------------------------------
		//	extern ���� ��ũ�� ����Ʈ
		//	
		//	:��� ������Ʈ ��� ����
		//------------------------------------------------------------------------------
		extern CList<CObject*> g_list_object;

		extern CList<CObject*>::iterator current_iter;

		//------------------------------------------------------------------------------
		//	�÷��̾� 
		//
		//	:���� 2�ο�
		//------------------------------------------------------------------------------
		const int cnt_player = 2;
		CPlayer *g_ptr_player[cnt_player];


		//------------------------------------------------------------------------------
		//	�ܼ� ���� ���� �غ� �۾� �� �ܼ� �ʱ� ���� 
		//------------------------------------------------------------------------------			cs_Initial();
		cs_Initial();

		//�� ���� �� ����
		CEnermy *new_enermy1 = new CEnermy("en", 5, 5, true, 1, UNIT_TYPE::ENERMY);
		g_list_object.push_back(new_enermy1);


		for (int i = 0; i < 6; i++)
		{
				//�ҷ� ��ü ����
				//CBullet *new_bullet1 = new CBullet(0, i, true, BULLET_TYPE::STRAIGHT, DIRECTION_MOVE::MOVE_RIGHT);

				//�ҷ� ��ü ����
				//CBullet *new_bullet2 = new CBullet(10, i, true, BULLET_TYPE::STRAIGHT, DIRECTION_MOVE::MOVE_LEFT);

				//�ҷ� ����
				//g_list_object.push_back(new_bullet1);
				//g_list_object.push_back(new_bullet2);

				//CEnermy *new_enermy1 = new CEnermy("en", 5*i, 3, true, 1, UNIT_TYPE::ENERMY);
				//g_list_object.push_back(new_enermy1);
		}

		CPlayer *new_player1 = new CPlayer(NUM_PLAYER::FIRST_PLAYER, "pl", 7, 5, true, 1, UNIT_TYPE::PLAYER);
		g_list_object.push_back(new_player1);



		//�� ���� �� ����
		//CEnermy *new_enermy1 = new CEnermy("en", 15, 5, true, 1, UNIT_TYPE::ENERMY);
		//g_list_object.push_back(new_enermy1);


		CEnermy *new_enermy2 = new CEnermy("en", 10, 2, true, 1, UNIT_TYPE::ENERMY);
		g_list_object.push_back(new_enermy2);

		CList<CObject*>::iterator end_iter;

		//�� �̻��� ���� �浹 ����

		

		//������ ���ͷ�����
		while (false == g_list_object.is_empty())
		{

			//Ű �Է� ����
			Cs_GetMsg();
			//Ŀ�� ��ġ ����
			cs_MoveCursor(0, 0);

			//���� 2���� �ʱ�ȭ
			memset(g_buffer, '\0', SIZE_PLAY_SCREEN::PLAY_SCREEN_HEIGHT * SIZE_PLAY_SCREEN::PLAY_SCREEN_WIDTH);
			memset(g_buf_iter, '\0', SIZE_PLAY_SCREEN::PLAY_SCREEN_HEIGHT * SIZE_PLAY_SCREEN::PLAY_SCREEN_WIDTH);

			//���� ��Ʈ
			current_iter = g_list_object.begin();
			end_iter = g_list_object.end();
			int len_list = g_list_object.size();
			for (int idx = 0; idx <len_list; idx++) {

				if (false == (*current_iter)->Action())
					current_iter++;

				len_list = g_list_object.size();
			}


			//���
			Bf_Out();

			//���
			Sleep(FRAME::PLAY_FRAME);


		}

	}
};




class CLogo : public CScean {


protected:
	virtual ~CLogo()
	{

	}

public:

	CLogo()
	{

	}

	virtual void Run()
	{

		cout << "�ΰ� ���";
	
		Sleep(1000);


	}

};


class CEnd : public CScean {

public:

	CEnd()
	{

	}

	virtual void Run()
	{

		cout << "���� ���";

		Sleep(5000);


	}

};