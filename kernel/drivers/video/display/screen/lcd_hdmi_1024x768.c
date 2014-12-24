#include <linux/delay.h>
#include <mach/gpio.h>
#include <mach/iomux.h>
#include <mach/board.h>
#include <linux/rk_fb.h>
#if defined(CONFIG_RK_HDMI)
#include "../../rockchip/hdmi/rk_hdmi.h"
#endif
#ifdef CONFIG_RK610_LVDS
#include "../transmitter/rk610_lcd.h"
#endif

  dfgs
/* Base */
#define OUT_TYPE		SCREEN_LVDS

#define LVDS_FORMAT    LVDS_8BIT_1 //  	LVDS_8BIT_2
#define OUT_FACE		OUT_P888   //OUT_D888_P666  
#define OUT_CLK			65000000
#define LCDC_ACLK        500000000//312000000           //29 lcdc axi DMA Ƶ��

/* Timing */

#define H_PW			10
#define H_BP			100
#define H_VD			1024
#define H_FP			210

#define V_PW			10
#define V_BP			10
#define V_VD			768
#define V_FP			18

#define LCD_WIDTH      162  // 202
#define LCD_HEIGHT     122  // 152

/*
#define H_PW			10
#define H_BP			100
#define H_VD			1024
#define H_FP			18

#define V_PW			2
#define V_BP			8
#define V_VD			768
#define V_FP			6

#define LCD_WIDTH          	216
#define LCD_HEIGHT         	135
*/
/* scaler Timing    */
//1920*1080*60
#define S_OUT_CLK		SCALE_RATE(148500000,66000000) //m=16 n=9 no=4
#define S_H_PW			100
#define S_H_BP			100
#define S_H_VD			1024
#define S_H_FP			151

#define S_V_PW			5
#define S_V_BP			15
#define S_V_VD			768
#define S_V_FP			12

#define S_H_ST			1757
#define S_V_ST			14

//1920*1080*50
#define S1_OUT_CLK		SCALE_RATE(148500000,54000000)  //m=16 n=11 no=4 
#define S1_H_PW			100
#define S1_H_BP			100
#define S1_H_VD			1024
#define S1_H_FP			126

#define S1_V_PW			5
#define S1_V_BP			15
#define S1_V_VD			768
#define S1_V_FP			12

#define S1_H_ST			1757
#define S1_V_ST			14

//1280*720*60
#define S2_OUT_CLK		SCALE_RATE(74250000,66000000)  //m=32 n=9 no=4
#define S2_H_PW			100
#define S2_H_BP			100
#define S2_H_VD			1024
#define S2_H_FP			151

#define S2_V_PW			5
#define S2_V_BP			15
#define S2_V_VD			768
#define S2_V_FP			12

#define S2_H_ST			0
#define S2_V_ST			12
//1280*720*50

#define S3_OUT_CLK		SCALE_RATE(74250000,54000000)   // m=32 n=11 no=4 
#define S3_H_PW			100
#define S3_H_BP			100
#define S3_H_VD			1024
#define S3_H_FP			151

#define S3_V_PW			5
#define S3_V_BP			15
#define S3_V_VD			768
#define S3_V_FP			12

#define S3_H_ST			0
#define S3_V_ST			12

//720*576*50
#define S4_OUT_CLK		SCALE_RATE(27000000,54375000)  //m=145 n=9 no=8 
#define S4_H_PW			100
#define S4_H_BP			100
#define S4_H_VD			1024
#define S4_H_FP			81

#define S4_V_PW			5
#define S4_V_BP			15
#define S4_V_VD			768
#define S4_V_FP			45


#define S4_H_ST			435
#define S4_V_ST			45
//720*480*60
#define S5_OUT_CLK		SCALE_RATE(27000000,72000000)  //m=32 n=3 no=4 
#define S5_H_PW			100
#define S5_H_BP			100
#define S5_H_VD			1024
#define S5_H_FP			81

#define S5_V_PW			5
#define S5_V_BP			15
#define S5_V_VD			768
#define S5_V_FP			51

#define S5_H_ST			858
#define S5_V_ST			45

#define S_DCLK_POL       0

/* Other */
#define DCLK_POL	 1  //	0

#define DEN_POL		0
#define VSYNC_POL	0
#define HSYNC_POL	0

#define SWAP_RB		0
#define SWAP_RG		0
#define SWAP_GB		0
 

#if  ( defined(CONFIG_ONE_LCDC_DUAL_OUTPUT_INF)&& defined(CONFIG_RK610_LVDS) ) || defined(CONFIG_HDMI_DUAL_DISP)
static int set_scaler_info(struct rk29fb_screen *screen, u8 hdmi_resolution)
{
	screen->s_clk_inv = S_DCLK_POL;
	screen->s_den_inv = 0;
	screen->s_hv_sync_inv = 0;
	switch(hdmi_resolution){
	case HDMI_1920x1080p_60Hz:
	        /* Scaler Timing    */
		screen->hdmi_resolution = hdmi_resolution;
		screen->s_pixclock = S_OUT_CLK;
		screen->s_hsync_len = S_H_PW;
		screen->s_left_margin = S_H_BP;
		screen->s_right_margin = S_H_FP;
		screen->s_hsync_len = S_H_PW;
		screen->s_upper_margin = S_V_BP;
		screen->s_lower_margin = S_V_FP;
		screen->s_vsync_len = S_V_PW;
		screen->s_hsync_st = S_H_ST;
		screen->s_vsync_st = S_V_ST;
		break;
	case HDMI_1920x1080p_50Hz:
		/* Scaler Timing    */
		screen->hdmi_resolution = hdmi_resolution;
		screen->s_pixclock = S1_OUT_CLK;
		screen->s_hsync_len = S1_H_PW;
		screen->s_left_margin = S1_H_BP;
		screen->s_right_margin = S1_H_FP;
		screen->s_hsync_len = S1_H_PW;
		screen->s_upper_margin = S1_V_BP;
		screen->s_lower_margin = S1_V_FP;
		screen->s_vsync_len = S1_V_PW;
		screen->s_hsync_st = S1_H_ST;
		screen->s_vsync_st = S1_V_ST;
		break;
	case HDMI_1280x720p_60Hz:
		/* Scaler Timing    */
		screen->hdmi_resolution = hdmi_resolution;
		screen->s_pixclock = S2_OUT_CLK;
		screen->s_hsync_len = S2_H_PW;
		screen->s_left_margin = S2_H_BP;
		screen->s_right_margin = S2_H_FP;
		screen->s_hsync_len = S2_H_PW;
		screen->s_upper_margin = S2_V_BP;
		screen->s_lower_margin = S2_V_FP;
		screen->s_vsync_len = S2_V_PW;
		screen->s_hsync_st = S2_H_ST;
		screen->s_vsync_st = S2_V_ST;
		break;
	case HDMI_1280x720p_50Hz:
		/* Scaler Timing    */
		screen->hdmi_resolution = hdmi_resolution;
		screen->s_pixclock = S3_OUT_CLK;
		screen->s_hsync_len = S3_H_PW;
		screen->s_left_margin = S3_H_BP;
		screen->s_right_margin = S3_H_FP;
		screen->s_hsync_len = S3_H_PW;
		screen->s_upper_margin = S3_V_BP;
		screen->s_lower_margin = S3_V_FP;
		screen->s_vsync_len = S3_V_PW;
		screen->s_hsync_st = S3_H_ST;
		screen->s_vsync_st = S3_V_ST;
		break;
    case HDMI_720x576p_50Hz_4_3:
    case HDMI_720x576p_50Hz_16_9:
		/* Scaler Timing    */
		screen->hdmi_resolution = hdmi_resolution;
		screen->s_pixclock = S4_OUT_CLK;
		screen->s_hsync_len = S4_H_PW;
		screen->s_left_margin = S4_H_BP;
		screen->s_right_margin = S4_H_FP;
		screen->s_hsync_len = S4_H_PW;
		screen->s_upper_margin = S4_V_BP;
		screen->s_lower_margin = S4_V_FP;
		screen->s_vsync_len = S4_V_PW;
		screen->s_hsync_st = S4_H_ST;
		screen->s_vsync_st = S4_V_ST;
		break;
    case HDMI_720x480p_60Hz_16_9:
    case HDMI_720x480p_60Hz_4_3:
                /* Scaler Timing    */
		screen->hdmi_resolution = hdmi_resolution;
		screen->s_pixclock = S5_OUT_CLK;
		screen->s_hsync_len = S5_H_PW;
		screen->s_left_margin = S5_H_BP;
		screen->s_right_margin = S5_H_FP;
		screen->s_hsync_len = S5_H_PW;
		screen->s_upper_margin = S5_V_BP;
		screen->s_lower_margin = S5_V_FP;
		screen->s_vsync_len = S5_V_PW;
		screen->s_hsync_st = S5_H_ST;
		screen->s_vsync_st = S5_V_ST;
		break;
    default :
            printk("%s lcd not support dual display at this hdmi resolution %d \n",__func__,hdmi_resolution);
            return -1;
	        break;
	}
	
	return 0;
}
#else
static int set_scaler_info(struct rk29fb_screen *screen, u8 hdmi_resolution){return 0;}
#endif

void set_lcd_info(struct rk29fb_screen *screen,  struct rk29lcd_info *lcd_info )
{
	/* screen type & face */
	screen->type = OUT_TYPE;
	screen->face = OUT_FACE;
	screen->hw_format = LVDS_FORMAT;

	/* Screen size */
	screen->x_res = H_VD;
	screen->y_res = V_VD;

	screen->width = LCD_WIDTH;
	screen->height = LCD_HEIGHT;

	/* Timing */
	screen->lcdc_aclk = LCDC_ACLK;
	screen->pixclock = OUT_CLK;
	screen->left_margin = H_BP;
	screen->right_margin = H_FP;
	screen->hsync_len = H_PW;
	screen->upper_margin = V_BP;
	screen->lower_margin = V_FP;
	screen->vsync_len = V_PW;

	/* Pin polarity */
	screen->pin_hsync = HSYNC_POL;
	screen->pin_vsync = VSYNC_POL;
	screen->pin_den = DEN_POL;
	screen->pin_dclk = DCLK_POL;

	/* Swap rule */
	screen->swap_rb = SWAP_RB;
	screen->swap_rg = SWAP_RG;
	screen->swap_gb = SWAP_GB;
	screen->swap_delta = 0;
	screen->swap_dumy = 0;

	/* Operation function*/
	screen->init = NULL;
	screen->standby = NULL;
	screen->sscreen_get = set_scaler_info;
#ifdef CONFIG_RK610_LVDS
    screen->sscreen_set = rk610_lcd_scaler_set_param;
#endif
}

size_t get_fb_size(void)
{
	size_t size = 0;
	#if defined(CONFIG_THREE_FB_BUFFER)
		size = ((H_VD)*(V_VD)<<2)* 3; //three buffer
	#else
		size = ((H_VD)*(V_VD)<<2)<<1; //two buffer
	#endif
	return ALIGN(size,SZ_1M);
}

