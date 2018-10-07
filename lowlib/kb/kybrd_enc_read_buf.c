#include <asm.h>
#include <kb.h>

uint8_t kybrd_enc_read_buf (void) 
{
 
	return inportb (KYBRD_ENC_INPUT_BUF);
}
