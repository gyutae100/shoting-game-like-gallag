// OOP_shooting_game.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

//------------------------------------------------------------------------------
//	표준 언어 라이브러리 인클루드
//------------------------------------------------------------------------------
#include <iostream>
using namespace std;

//------------------------------------------------------------------------------
//	게임 구성 라이브러리 인클루드
//------------------------------------------------------------------------------
//#include "SceanManager.h"
#include "_g_public.h"

//신 매니저
extern CSceneManager g_scean_manager;


void main()
{


	//초기 신 로딩
	g_scean_manager.SetNextScean(SCEAN::SCEAN_LOGO);

	bool b_check_end = false;

	while (true)
	{
		//게임 종료 여부 파악
//		g_scean_manager.IsFinish();
		
		//다음 신 로딩
		b_check_end = g_scean_manager.LoadScean();


		g_scean_manager.Run();
		
		if (false == b_check_end)
			return;
	}


}




