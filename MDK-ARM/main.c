/*
 * @Author       : wang chao
 * @Date         : 2022-12-05 07:38:51
 * @LastEditors  : wang chao
 * @LastEditTime : 2022-12-05 07:41:25
 * @FilePath     : main.c
 * @Description  : 
 * Copyright 2022 BingShan, All Rights Reserved. 
 */
#include "common.h"
#include "iap.h"

int main(void)
{
	IAP_Init();
	
	while(1)
	{
        /*
            1. 先判断是否需要升级，是否需要擦除硬盘
            2. 如果都没有，那么直接运行APP
        */
		switch(IAP_ReadFlag())
		{
			case UPDATE_FLAG_DATA:// download app state				
				if( !IAP_Update()) 
					IAP_WriteFlag(APPRUN_FLAG_DATA);
				break;
			case ERASE_FLAG_DATA:// erase app state
				IAP_Erase();
				break;
			default:
                IAP_RunApp();
				break;
		}
	}
}


