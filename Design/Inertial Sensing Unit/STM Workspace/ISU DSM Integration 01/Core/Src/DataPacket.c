/*
 * DataPacket.c
 *
 *  Created on: Apr 8, 2023
 *      Author: student
 */
#include "stdio.h"
extern union Transmission trans1;

/*void PackTx(char* TxBuff)
{
	memset(*TxBuff,"\0",strlen(TxBuff));
	for(int i=0;i<17;i++)
	{
		gcvt(trans1.dataframe[i],&TxBuff[i],6);
		strcpy(*TxBuff,",");
	}
	strcpy(TxBuff,"\n");
	return 0;

}
*/
