#pragma once

#include "environment_setting.h"

//------------------------------------------------------------------------------
//
//		*함수 선언부*
//
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//	콘솔 제어 위한 준비 작업
//------------------------------------------------------------------------------
void cs_Initial(void);

//------------------------------------------------------------------------------
//	콘솔 화면의 커서를 X, Y 좌표로 이동시킨다
//------------------------------------------------------------------------------
void cs_MoveCursor(int iPosX, int iPosY);

//------------------------------------------------------------------------------
//	콘솔 화면 초기화
//------------------------------------------------------------------------------
void cs_ClearScreen(void);






