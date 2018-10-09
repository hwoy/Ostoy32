#include <asm.h>
#include <kb.h>

void kybrd_enc_send_cmd (uint8_t cmd) 
{
 
	while (1)
		if ( (kybrd_ctrl_read_status () & KYBRD_CTRL_STATS_MASK_IN_BUF) == 0)
			break;
 
	outportb (KYBRD_ENC_CMD_REG, cmd);
}
