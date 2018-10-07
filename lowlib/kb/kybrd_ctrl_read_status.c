#include <asm.h>
#include <kb.h>


uint8_t kybrd_ctrl_read_status (void) 
{
 
	return inportb (KYBRD_CTRL_STATS_REG);
}
