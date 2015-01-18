#ifndef __LINUX_AXP_CFG_H_
#define __LINUX_AXP_CFG_H_
#include "axp-mfd.h"

#include <mach/gpio.h>
#include <mach/yfmach.h>

/*�豸��ַ*/
/*
	һ�㲻�ı䣺
	AXP22:0x34
*/
#define	AXP_DEVICES_ADDR	(0x68 >> 1)
/*i2c���������豸��:���忴��ʹ��ƽ̨Ӳ��������*/
#define	AXP_I2CBUS			1// like 8846 use i2c_1 change by wangjian
/*��ԴоƬ��Ӧ���жϺţ����忴��ʹ�õ�ƽ̨Ӳ�������ӣ�
�ж���nmi����cpu����·irq����gpio*/
#ifndef AXP_IRQNO
#define AXP_IRQNO			RK30_PIN0_PB3//64 like 8846 use RK30_PIN0_PB30 irq change by wangjian
#endif
/*��ʼ����·�������λmV��0��Ϊ�ر�*/
/*
	ldo1��
		��Ӳ�����������ѹ�������Ĳ��ˣ�ֻ����������ʾ��ѹ��
*/
#define AXP_LDO1_VALUE			3000//vcca_33
/*
	ldo2��
		AXP22:700~3300,100/step
*/
#define AXP_LDO2_VALUE		3300//700 vcc_card
/*
	ldo3��
		AXP22:700~3300,100/step
*/
#define AXP_LDO3_VALUE		1800//1800  vcc_18
/*
	ldo4��
		AXP22:700~3300,100/step
*/
#define AXP_LDO4_VALUE		2500//3000 VCCIO_WL not set
/*
	ldo5��
		AXP22:700~3300,100/step
*/
#define AXP_LDO5_VALUE		2800//700//vcc28_cif
/*
	ldo6��
		AXP22:700~3300,100/step
*/
#define AXP_LDO6_VALUE		2800////700 CSI-AVDD
/*
	ldo7��
		AXP22:700~3300,100/step
*/
#define AXP_LDO7_VALUE		3300////700 VCC_JETTAA
/*
	ldo8��
		AXP22:700~3300,100/step
*/
#define AXP_LDO8_VALUE		1200////700 VDD_1V2
/*
	ldo9��
		AXP22:700~3300,100/step
*/
#define AXP_LDO9_VALUE		2500//700 VCC_JETTA
/*
	ldo10��
		AXP22:700~3300,100/step
*/
#define AXP_LDO10_VALUE		1800//700 vcc18_cif 
/*
	ldo11��
		AXP22:700~3300,100/step
*/
#define AXP_LDO11_VALUE		3300//700 vcc_tp
/*
	ldo12��
		AXP22:700~1400,100/step
*/
#define AXP_LDO12_VALUE		1100 

/*
	DCDC1:
		AXP22:1600~3400,100/setp
*/
#define AXP_DCDC1_VALUE		3000 //vcc_io
/*
	DCDC2��
		AXP22:600~1540��20/step
*/
#define AXP_DCDC2_VALUE		1100//1200//avdd_com
/*
	DCDC3��
		AXP22:600~1860��20/step
*/
#define AXP_DCDC3_VALUE		1100//1260//vdd_log
/*
	DCDC4��
		AXP22:600~1540��20/step
*/
#define AXP_DCDC4_VALUE		1200
/*
	DCDC5��
		AXP22:1000~2550��50/step
*/
#define AXP_DCDC5_VALUE		1500//vcc_ddr

/*���������mAh������ʵ�ʵ�����������壬�Կ��ؼƷ�����˵
�����������Ҫ����������*/
static inline int yf_get_battery_capacity(void) {
	int cap = env_get_u32("battery_capacity", 4700);
	return (cap / 100) * 100;
}
#define BATCAP				(yf_get_battery_capacity())

/*��ʼ��������裬m����һ����100~200֮�䣬������ø���ʵ��
���Գ�����ȷ���������Ǵ򿪴�ӡ��Ϣ�����ӵ���պù̼���
�ϵ�أ����ӳ����������������1���Ӻ󣬽��ϳ��������
1~2���ӣ�����ӡ��Ϣ�е�rdcֵ����������*/
#define BATRDC				(env_get_u32("power_bat_rdc", 100))
/*��·��ѹ�����еĵ�ص�ѹ�Ļ���*/
#define AXP_VOL_MAX			1
/*
	��繦��ʹ�ܣ�
        AXP22:0-�رգ�1-��
*/
#define CHGEN       1

/*
	���������ã�uA��0Ϊ�رգ�
		AXP22:300~2550,100/step
*/
/*������������uA*/
#define STACHGCUR			(env_get_u32("STACHGCUR", 900)*1000)
/*������������uA*/
#define EARCHGCUR			(env_get_u32("EARCHGCUR", 900)*1000)
/*���߳�������uA*/
#define SUSCHGCUR			(env_get_u32("SUSCHGCUR", 900)*1000)
/*�ػ���������uA*/
#define CLSCHGCUR			(env_get_u32("CLSCHGCUR", 900)*1000)

/*Ŀ�����ѹ��mV*/
/*
	AXP22:4100/4220/4200/4240
*/
#define CHGVOL				4200
/*������С�����õ�����ENDCHGRATE%ʱ��ֹͣ��磬%*/
/*
	AXP22:10\15
*/ 
#define ENDCHGRATE			10
/*�ػ���ѹ��mV*/
/*
	ϵͳ��ƵĹػ�����ĵ�ض˵�ѹ����Ҫ��ػ��ٷֱȡ�
	��·��ѹ��Ӧ�ٷֱȱ����͵羯���ѹ�໥��ϲŻ�������
*/
#define SHUTDOWNVOL			3300

/*adc���������ã�Hz*/
/*
	AXP22:100\200\400\800
*/
#define ADCFREQ				100
/*Ԥ��糬ʱʱ�䣬min*/
/*
	AXP22:40\50\60\70
*/
#define CHGPRETIME			50
/*������糬ʱʱ�䣬min*/
/*
	AXP22:360\480\600\720
*/
#define CHGCSTTIME			480


/*pek����ʱ�䣬ms*/
/*
	��power��Ӳ������ʱ�䣺
		AXP22:128/1000/2000/3000
*/
#define PEKOPEN				1000
/*pek����ʱ�䣬ms*/
/*
	��power���������жϵ�ʱ�䣬���ڴ�ʱ���Ƕ̰������̰���irq��
	���ڴ�ʱ���ǳ�������������irq��
		AXP22:1000/1500/2000/2500
*/
#define PEKLONG				1500
/*pek�����ػ�ʹ��*/
/*
	��power�������ػ�ʱ��Ӳ���ػ�����ʹ�ܣ�
		AXP22:0-���أ�1-�ػ�
*/
#define PEKOFFEN			1
/*pek�����ػ�ʹ�ܺ󿪻�ѡ��*/
/*
	��power�������ػ�ʱ��Ӳ���ػ���������ѡ��:
		AXP22:0-ֻ�ػ���������1-�ػ�������
*/
#define PEKOFFRESTART			0
/*pekpwr�ӳ�ʱ�䣬ms*/
/*
	������powerok�źŵ��ӳ�ʱ�䣺
		AXP20:8/16/32/64
*/
#define PEKDELAY			32
/*pek�����ػ�ʱ�䣬ms*/
/*
	��power���Ĺػ�ʱ����
		AXP22:4000/6000/8000/10000
*/
#define PEKOFF				6000
/*���¹ػ�ʹ��*/
/*
	AXP�ڲ��¶ȹ���Ӳ���ػ�����ʹ�ܣ�
		AXP22:0-���أ�1-�ػ�
*/
#define OTPOFFEN			0
/* ����ѹ����ʹ��*/
/*
	AXP22:0-�رգ�1-��
*/
#define USBVOLLIMEN		1
/*  �����ѹ��mV��0Ϊ������*/
/*
	AXP22:4000~4700��100/step
*/
#define USBVOLLIM			0
/*  USB�����ѹ��mV��0Ϊ������*/
/*
	AXP22:4000~4700��100/step
*/
#define USBVOLLIMPC			4700

/* ����������ʹ��*/
/*
	AXP22:0-�رգ�1-��
*/
#define USBCURLIMEN		1
/* ���������mA��0Ϊ������*/
/*
	AXP22:500/900
*/
#define USBCURLIM			0
/* usb ���������mA��0Ϊ������*/
/*
	AXP22:500/900
*/
#define USBCURLIMPC			500
/* PMU �жϴ�������ʹ��*/
/*
	AXP22:0-�����ѣ�1-����
*/
#define IRQWAKEUP			0
/* N_VBUSEN PIN ���ܿ���*/
/*
	AXP22:0-���������OTG��ѹģ�飬1-���룬����VBUSͨ·
*/
#define VBUSEN			1
/* ACIN/VBUS In-short ��������*/
/*
	AXP22:0-AC VBUS�ֿ���1-ʹ��VBUS��AC,�޵���AC
*/
#define VBUSACINSHORT			0
/* CHGLED �ܽſ�������*/
/*
	AXP22:0-�������1-�ɳ�繦�ܿ���
*/
#define CHGLEDFUN			0
/* CHGLED LED ��������*/
/*
	AXP22:0-���ʱled������1-���ʱled��˸
*/
#define CHGLEDTYPE			0
/* ���������У��ʹ��*/
/*
	AXP22:0-�رգ�1-��
*/
#define BATCAPCORRENT			0
/* �����ɺ󣬳�����ʹ��*/
/*
	AXP22:0-�رգ�1-��
*/
#define BATREGUEN			0
/* ��ؼ�⹦��ʹ��*/
/*
	AXP22:0-�رգ�1-��
*/
#define BATDET		1
/* PMU����ʹ��*/
/*
	AXP22:0-�رգ�1-�򿪰���Դ��16������PMU����
*/
#define PMURESET		0
/*�͵羯���ѹ1��%*/
/*
	����ϵͳ���������
	AXP22:5%~20%
*/
#define BATLOWLV1    15
/*�͵羯���ѹ2��%*/
/*
	����ϵͳ���������
	AXP22:0%~15%
*/
#define BATLOWLV2    0

#define ABS(x)				((x) >0 ? (x) : -(x) )

#ifdef	CONFIG_KP_AXP22
/*AXP GPIO start NUM,����ƽ̨ʵ���������*/
#define AXP22_NR_BASE AXP22_GPIO_EXPANDER_BASE//100

/*AXP GPIO NUM,��������������LCD power�Լ�VBUS driver pin*/
#define AXP22_NR 5

/*��ʼ����·��ѹ��Ӧ�ٷֱȱ�*/
/*
	����ʹ��Ĭ��ֵ��������ø���ʵ�ʲ��Եĵ����ȷ��ÿ��
	��Ӧ��ʣ��ٷֱȣ��ر���Ҫע�⣬�ػ���ѹSHUTDOWNVOL�͵��
	������ʼУ׼ʣ�������ٷֱ�BATCAPCORRATE��������׼ȷ��
	AXP22����
*/
#define OCVREG0				0		 //3.13V
#define OCVREG1				0		 //3.27V
#define OCVREG2				0		 //3.34V
#define OCVREG3				0		 //3.41V
#define OCVREG4				0		 //3.48V
#define OCVREG5				0		 //3.52V
#define OCVREG6				0		 //3.55V
#define OCVREG7				0		 //3.57V
#define OCVREG8				5		 //3.59V
#define OCVREG9				8		 //3.61V
#define OCVREGA				9		 //3.63V
#define OCVREGB				10		 //3.64V
#define OCVREGC				13		 //3.66V
#define OCVREGD				16		 //3.7V
#define OCVREGE				20		 //3.73V 
#define OCVREGF				33		 //3.77V
#define OCVREG10		 	41                //3.78V
#define OCVREG11		 	46                //3.8V
#define OCVREG12		 	50                //3.82V 
#define OCVREG13		 	53                //3.84V
#define OCVREG14		 	57                //3.85V
#define OCVREG15		 	61                //3.87V
#define OCVREG16		 	67                //3.91V
#define OCVREG17		 	73                //3.94V
#define OCVREG18		 	78                //3.98V
#define OCVREG19		 	84                //4.01V
#define OCVREG1A		 	88                //4.05V
#define OCVREG1B		 	92                //4.08V
#define OCVREG1C		 	93                //4.1V 
#define OCVREG1D		 	94                //4.12V
#define OCVREG1E		 	95                //4.14V
#define OCVREG1F		 	100                //4.15V

/*  AXP�ж�*/
#define AXP_IRQ_USBLO		AXP22_IRQ_USBLO	//usb �͵�
#define AXP_IRQ_USBRE		AXP22_IRQ_USBRE	//usb �γ�
#define AXP_IRQ_USBIN		AXP22_IRQ_USBIN	//usb ����
#define AXP_IRQ_USBOV		AXP22_IRQ_USBOV	//usb ��ѹ
#define AXP_IRQ_ACRE			AXP22_IRQ_ACRE	//ac  �γ�
#define AXP_IRQ_ACIN			AXP22_IRQ_ACIN	//ac  ����
#define AXP_IRQ_ACOV		AXP22_IRQ_ACOV //ac  ��ѹ
#define AXP_IRQ_TEMLO		AXP22_IRQ_TEMLO //��ص���
#define AXP_IRQ_TEMOV		AXP22_IRQ_TEMOV //��ع���
#define AXP_IRQ_CHAOV		AXP22_IRQ_CHAOV //��س�����
#define AXP_IRQ_CHAST		AXP22_IRQ_CHAST //��س�翪ʼ
#define AXP_IRQ_BATATOU	AXP22_IRQ_BATATOU //����˳�����ģʽ
#define AXP_IRQ_BATATIN		AXP22_IRQ_BATATIN //��ؽ��뼤��ģʽ
#define AXP_IRQ_BATRE		AXP22_IRQ_BATRE //��ذγ�
#define AXP_IRQ_BATIN		AXP22_IRQ_BATIN //��ز���
#define AXP_IRQ_PEKLO		AXP22_IRQ_POKLO //power������
#define AXP_IRQ_PEKSH		AXP22_IRQ_POKSH //power���̰�

#define AXP_IRQ_CHACURLO	AXP22_IRQ_CHACURLO //������С������ֵ
#define AXP_IRQ_ICTEMOV		AXP22_IRQ_ICTEMOV //AXPоƬ�ڲ�����
#define AXP_IRQ_EXTLOWARN2	AXP22_IRQ_EXTLOWARN2 //APS��ѹ�����ѹ2
#define AXP_IRQ_EXTLOWARN1	AXP22_IRQ_EXTLOWARN1 //APS��ѹ�����ѹ1

#define AXP_IRQ_GPIO0TG		AXP22_IRQ_GPIO0TG //GPIO0������ش���
#define AXP_IRQ_GPIO1TG		AXP22_IRQ_GPIO1TG //GPIO1������ش���

#define AXP_IRQ_PEKFE		AXP22_IRQ_PEKFE //power���½��ش���
#define AXP_IRQ_PEKRE		AXP22_IRQ_PEKRE //power�������ش���
#define AXP_IRQ_TIMER		AXP22_IRQ_TIMER //��ʱ����ʱ

#endif

/*ѡ����Ҫ�򿪵��ж�ʹ��*/
static const uint64_t AXP22_NOTIFIER_ON = (AXP_IRQ_USBIN |AXP_IRQ_USBRE |
				       		                            AXP_IRQ_ACIN |AXP_IRQ_ACRE |
				       		                            AXP_IRQ_BATIN |AXP_IRQ_BATRE |
				       		                            AXP_IRQ_CHAST |AXP_IRQ_CHAOV|
						                            0);//(uint64_t)AXP_IRQ_PEKFE |(uint64_t)AXP_IRQ_PEKRE);

/* ��Ҫ�������ţ��usb�ػ�������bootʱpower_start����Ϊ1������Ϊ0*/
#define POWER_START 0


#endif