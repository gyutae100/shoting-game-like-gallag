#pragma once

#include "Scean.h"

class CSceneManager
{


private:

	CScean * _p_current_scean;

	//���� �������� ����
	SCEAN _next_scean;

public:

	//������
	CSceneManager() 
	{
		_p_current_scean= new CLogo();
		_next_scean = SCEAN_LOGO;
	}
	
	//���� �� �ε�
	bool LoadScean() 
	{
		switch (_next_scean)
		{
		case SCEAN::SCEAN_LOGO:
			_p_current_scean->Distroy();
			_p_current_scean = new CLogo();

			_next_scean = SCEAN::SCEAN_STAGE1;

			break;

		case SCEAN::SCEAN_STAGE1:
			_p_current_scean->Distroy();
			_p_current_scean = new CStage1();

			_next_scean = SCEAN::SCEAN_END;

			break;

		case SCEAN::SCEAN_END:
			_p_current_scean->Distroy();
			_p_current_scean = new CEnd();
			_next_scean = SCEAN::SCEAN_END;

			return false;
		}

		return true;
	}

	//���� �� ����
	void SetNextScean(SCEAN next_scean)
	{
		_next_scean = next_scean;
	}

	//����
	void Run()
	{
		//Ŀ�� ��ġ ����
		_p_current_scean->Run();
	}


	//���� ���� ���� �ľ�
	bool IsFinish()
	{
		if (_next_scean == SCEAN::SCEAN_END)
			return true;
		else
			return false;
	}




};