/*----------------------------------------------------------------------------*/
//版权所有：    班特科技
//文件名：      ecatuser.c
//版本：    1.0
//作者:        paul        
//修订记录:    
//2026-08-08----单个电机版本
/*----------------------------------------------------------------------------*/
#include "ecatuser.h"

#include "stdio.h"
#include "string.h"

#include "stm32h7xx_hal.h"
#include "gpio.h"

PDO_Output *outputs1;
PDO_Input *inputs1;
PDO_Output *outputs2;
PDO_Input *inputs2;


char IOmap[200];
uint32_t dorun=0;
uint32_t OpenReady=0;
uint8 flag_time = 0;
int oloop, iloop;
uint32_t pdoTimeFlag = 0;
//motor control 
uint16 cur_status1;
uint16 cur_status2;
uint8_t startup_step=0;
int32 cur_pos1 = 0;
int32 cur_pos2 = 0;
uint16 csp_pos_delay;
int cmdpos_raw1;
int cmdpos_raw2;

#define DEBUG 1


int Servosetup(uint16 slave)
{	
	  int retval;
    uint16 u16val;
    uint8  u8val;
    uint32 u32val;
    retval = 0;

    u8val = 0;
    retval += ec_SDOwrite(slave, 0x1c12, 0x00, FALSE, sizeof(u8val), &u8val, EC_TIMEOUTRXM);
    u16val = 0x1600;	
    retval += ec_SDOwrite(slave, 0x1c12, 0x01, FALSE, sizeof(u16val), &u16val, EC_TIMEOUTRXM);
    u8val = 1;
    retval += ec_SDOwrite(slave, 0x1c12, 0x00, FALSE, sizeof(u8val), &u8val, EC_TIMEOUTRXM);

	
	  u8val = 0;
    retval += ec_SDOwrite(slave, 0x1600, 0x00, FALSE, sizeof(u8val), &u8val, EC_TIMEOUTRXM);
	  u32val = 0x60400010;	
    retval += ec_SDOwrite(slave, 0x1600, 0x01, FALSE, sizeof(u32val), &u32val, EC_TIMEOUTRXM);
		u32val = 0x607A0020;	
    retval += ec_SDOwrite(slave, 0x1600, 0x02, FALSE, sizeof(u32val), &u32val, EC_TIMEOUTRXM);
		u32val = 0x60600008;	
    retval += ec_SDOwrite(slave, 0x1600, 0x03, FALSE, sizeof(u32val), &u32val, EC_TIMEOUTRXM);
		u8val = 3;
    retval += ec_SDOwrite(slave, 0x1600, 0x00, FALSE, sizeof(u8val), &u8val, EC_TIMEOUTRXM);
		
		
    u8val = 0;
    retval += ec_SDOwrite(slave, 0x1c13, 0x00, FALSE, sizeof(u8val), &u8val, EC_TIMEOUTRXM);
    u16val = 0x1a00;
    retval += ec_SDOwrite(slave, 0x1c13, 0x01, FALSE, sizeof(u16val), &u16val, EC_TIMEOUTRXM);
    u8val = 1;
    retval += ec_SDOwrite(slave, 0x1c13, 0x00, FALSE, sizeof(u8val), &u8val, EC_TIMEOUTRXM);
	  
		u8val = 0;
    retval += ec_SDOwrite(slave, 0x1A00, 0x00, FALSE, sizeof(u8val), &u8val, EC_TIMEOUTRXM);
	  u32val = 0x60410010;	
    retval += ec_SDOwrite(slave, 0x1A00, 0x01, FALSE, sizeof(u32val), &u32val, EC_TIMEOUTRXM);
		u32val = 0x60640020;	
    retval += ec_SDOwrite(slave, 0x1A00, 0x02, FALSE, sizeof(u32val), &u32val, EC_TIMEOUTRXM);
		u32val = 0x606C0020;	
    retval += ec_SDOwrite(slave, 0x1A00, 0x03, FALSE, sizeof(u32val), &u32val, EC_TIMEOUTRXM);
		u32val = 0x603F0010;	
    retval += ec_SDOwrite(slave, 0x1A00, 0x04, FALSE, sizeof(u32val), &u32val, EC_TIMEOUTRXM);
		u32val = 0x60610008;	
    retval += ec_SDOwrite(slave, 0x1A00, 0x05, FALSE, sizeof(u32val), &u32val, EC_TIMEOUTRXM);		
		u8val = 5;
    retval += ec_SDOwrite(slave, 0x1A00, 0x00, FALSE, sizeof(u8val), &u8val, EC_TIMEOUTRXM);

    //op mode 8-csp
		u8val = 8;
    retval += ec_SDOwrite(slave, 0x6060, 0x00, FALSE, sizeof(u8val), &u8val, EC_TIMEOUTRXM);


    return 1;
}



void ecat_init(void)
{
    int slc;
//    int i,chk;
    int cnt = 1;
		int expectedWKC;
    
    /* initialise SOEM, bind socket to ifname */
	if (ec_init("eth0"))
	{
		printf("ec_init succeeded.\r\n");
         HAL_Delay(100);
		if ( ec_config_init(TRUE) > 0 )
		{
			printf("%d slaves found and configured.\r\n",ec_slavecount);
            
			if ( ec_slavecount >= 1 ) 
			{
                for(slc = 1; slc <= ec_slavecount; slc++)
                 {
                     
                    for(slc = 1; slc <= ec_slavecount; slc++)
										{
											printf("Found %s at position %d\n", ec_slave[slc].name, slc);
											ec_slave[slc].PO2SOconfig = &Servosetup;
										}
                 }
            }
            
            ec_configdc();//DCʱ������
			ec_dcsync0(1, TRUE, SYNC0TIME, 250000); // SYNC0 on slave 1
			ec_dcsync0(2, TRUE, SYNC0TIME, 250000); // SYNC0 on slave 2
            ec_config_map(&IOmap);
            
//						ec_dcsync0(2, TRUE, SYNC0TIME, 0); // SYNC0 on slave 2
						
						printf("Slaves mapped, state to SAFE_OP.\n \r");	
						/* wait for all slaves to reach SAFE_OP state */
			      ec_statecheck(0, EC_STATE_SAFE_OP,  EC_TIMEOUTSTATE);
						/* read indevidual slave state and store in ec_slave[] */
						ec_readstate();
						
						printf("Slave 0 State=0x%04x\r\n",ec_slave[0].state);
						printf("Slave 1 State=0x%04x\r\n",ec_slave[1].state);			
						
						for(cnt = 1; cnt <= ec_slavecount ; cnt++){
						printf("Slave:%d Name:%s Output size:%3dbits Input size:%3dbits State:%2d delay:%d.%d\n \r",
							cnt, ec_slave[cnt].name, ec_slave[cnt].Obits, ec_slave[cnt].Ibits,
							ec_slave[cnt].state, (int)ec_slave[cnt].pdelay, ec_slave[cnt].hasdc);
						}
            
						oloop = ec_slave[0].Obytes;//��վ������վ���ֽ���������SSC-IO��2
						if ((oloop == 0) && (ec_slave[0].Obits > 0)) oloop = 1;
						if (oloop > 30) oloop = 30;
			
						iloop = ec_slave[0].Ibytes;//��վ������վ���ֽ���������SSC-IO��6		
						if ((iloop == 0) && (ec_slave[0].Ibits > 0)) iloop = 1;
						if (iloop > 30) iloop = 30;
			
						printf("oloop:%d iloop:%d\n\r",oloop,iloop);
						
						printf("segments : %d : %d %d %d %d\n \r",ec_group[0].nsegments ,ec_group[0].IOsegment[0],ec_group[0].IOsegment[1],ec_group[0].IOsegment[2],ec_group[0].IOsegment[3]);
						printf("Request operational state for all slaves\n \r");
						expectedWKC = (ec_group[0].outputsWKC * 2) + ec_group[0].inputsWKC;
						printf("Calculated workcounter %d\n \r", expectedWKC);
						
						/* send one valid process data to make outputs in slaves happy*/
            ec_send_processdata();
            ec_receive_processdata(EC_TIMEOUTRET);
            
            ec_writestate(0);

			ec_statecheck(0, EC_STATE_OPERATIONAL,  EC_TIMEOUTSTATE);	
            
						//printf("DC capable : %d\r\n",ec_configdc());
            
            //HAL_Delay(100);
            
					/* wait for all slaves to reach OP state */
						do{
							ec_receive_processdata(EC_TIMEOUTRET);
							ec_slave[0].state = EC_STATE_OPERATIONAL;
							ec_slave[1].state = EC_STATE_OPERATIONAL;
              				ec_writestate(0);
							ec_writestate(1);
							//printf("-%d %d-",ec_slave[0].state,ec_slave[1].state);
							}
						while ( (ec_slave[0].state != EC_STATE_OPERATIONAL)||(ec_slave[1].state != EC_STATE_OPERATIONAL));
//						while  (ec_slave[0].state != EC_STATE_OPERATIONAL);
						printf("\r\n%d %d\r\n",ec_slave[0].state,ec_slave[1].state);
            if (ec_slave[0].state == EC_STATE_OPERATIONAL )
            {
				flag_time = 1;	
				dorun = 1;
                
                outputs1 = (PDO_Output *)ec_slave[1].outputs;
                inputs1  = (PDO_Input *)ec_slave[1].inputs;
                outputs2 = (PDO_Output *)ec_slave[2].outputs;
                inputs2  = (PDO_Input *)ec_slave[2].inputs;                

                printf("all slaves reached operational state.\r\n");
            }
			
			else
			{
				printf("Not all slaves reached operational state.\n \r");
			}
		}
		else
		{
			printf("No slaves found!\r\n");
		}
	}
	else
	{
		printf("No socket connection Excecute as root\r\n");
	}
    
}





uint8 wkc;



void ecat_loop(void)
{	
	static int16_t i = 0;
	i++;
    if(flag_time == 1)
    {		
			ec_send_processdata();
			ec_receive_processdata(EC_TIMEOUTRET);
			cur_status1 = inputs1->StatusWord;//0x6041
			cur_pos1 = inputs1->CurrentPosition;
			cur_status2 = inputs2->StatusWord;//0x6041
			cur_pos2 = inputs2->CurrentPosition;			
			switch(startup_step)
			{
				case 1:
				  outputs1->ControlWord = 0x06;//0x6040
				  outputs2->ControlWord = 0x06;//0x6040
				  if(((cur_status1==0x1631)||(cur_status1==0x1231))&&((cur_status2==0x1631)||(cur_status2==0x1231)))
						 startup_step=2;
				  printf("0x06,cur=%x\r\n",cur_status1);
				break;

			  case 2:
					outputs1->ControlWord = 0x07;
					outputs2->ControlWord = 0x07;
					if(((cur_status1==0x1633)||(cur_status1==0x1233)) && ((cur_status2==0x1633)||(cur_status2==0x1233)))
						 startup_step=3;
					printf("0x07,cur=%x\r\n",cur_status1);
					break;

				case 3:
					outputs1->ControlWord = 0x0f;
					outputs2->ControlWord = 0x0f;
				 	if(((cur_status1==0x1637)||(cur_status1==0x1633)||(cur_status1==0x1237))&&((cur_status2==0x1637)||(cur_status2==0x1633)||(cur_status2==0x1237)))
						 startup_step=4;
                   printf("0x08,cur=%x\r\n",cur_status1);
					break;
					

				case 4:
           			outputs1->ControlWord = 0x1f;
					outputs2->ControlWord = 0x1f;
				   //outputs1->TargetPos = cur_pos;//0x607A	
							
						csp_pos_delay++;

                  

                  if(csp_pos_delay <= 1000)
                  {
                     cur_pos1 += 500;
					 cur_pos2 += 500;
                  }
                  else if(csp_pos_delay <= 2000)
                  {
                     cur_pos1 -= 500;
					 cur_pos2 -= 500;
                  }
				  else
				  {
					csp_pos_delay = 0;
				  }

				  cmdpos_raw1 = cur_pos1;
				  cmdpos_raw2 = cur_pos2;
                

               

               
				break;
				default :
					startup_step=1;
				  outputs1->ControlWord = 0x03;//0x6040
				  outputs2->ControlWord = 0x03;//0x6040
				break;
			}
		}
	 outputs1->TargetPos = cmdpos_raw1;
	 outputs1->TargetMode = 0x8;
	outputs2->TargetPos = cmdpos_raw2;
	 outputs2->TargetMode = 0x8;
		if(i>=500) i = 0;
}





