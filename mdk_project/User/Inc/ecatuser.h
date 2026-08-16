/*----------------------------------------------------------------------------*/
//版权所有：    班特科技
//文件名：      ecatuser.h
//版本：    1.0
//作者:        paul        
//修订记录:    
//2026-08-08----单个电机版本
/*----------------------------------------------------------------------------*/


#ifndef _ECATUSER_H_
#define _ECATUSER_H_


#include "ethercat.h"

#include "osal.h"
#define SYNC0TIME 10000 
///1000us

typedef __packed struct
{
   uint16 ControlWord;
   int32 TargetPos;
   uint8 TargetMode;
}PDO_Output;

typedef __packed struct 
{
   uint16 StatusWord;
   int32 CurrentPosition;
   int32 CurrentVelocity;
   uint16 ErrorCode;
   uint8 CurrentMode;
}PDO_Input;



void ecat_init(void);
void ecat_loop(void);
void ctrl_state(void);



#endif

