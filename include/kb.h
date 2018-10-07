#ifndef __KB_H__
#define __KB_H__

enum KYBRD_ENCODER_IO {
 
	KYBRD_ENC_INPUT_BUF	=	0x60,
	KYBRD_ENC_CMD_REG	=	0x60
};
 
enum KYBRD_CTRL_IO {
 
	KYBRD_CTRL_STATS_REG	=	0x64,
	KYBRD_CTRL_CMD_REG	=	0x64
};


enum KYBRD_CTRL_STATS_MASK {
 
	KYBRD_CTRL_STATS_MASK_OUT_BUF	=	1,
	KYBRD_CTRL_STATS_MASK_IN_BUF	=	2,
	KYBRD_CTRL_STATS_MASK_SYSTEM	=	4,
	KYBRD_CTRL_STATS_MASK_CMD_DATA	=	8,
	KYBRD_CTRL_STATS_MASK_LOCKED	=	0x10,
	KYBRD_CTRL_STATS_MASK_AUX_BUF	=	0x20,
	KYBRD_CTRL_STATS_MASK_TIMEOUT	=	0x40,
	KYBRD_CTRL_STATS_MASK_PARITY	=	0x80
};

int get_char(void);

uint8_t kybrd_ctrl_read_status (void);
void kybrd_ctrl_send_cmd (uint8_t cmd);
uint8_t kybrd_enc_read_buf (void);
void kybrd_enc_send_cmd (uint8_t cmd);

#endif
