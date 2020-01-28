/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Copyright (c) 2019 MediaTek Inc.
 */

#ifndef __MFD_MT6358_CORE_H__
#define __MFD_MT6358_CORE_H__

#define MT6358_REG_WIDTH 16

struct irq_top_t {
	int hwirq_base;
	unsigned int num_int_regs;
	unsigned int num_int_bits;
	unsigned int en_reg;
	unsigned int en_reg_shift;
	unsigned int sta_reg;
	unsigned int sta_reg_shift;
	unsigned int top_offset;
};

struct pmic_irq_data {
	unsigned int num_top;
	unsigned int num_pmic_irqs;
	unsigned short top_int_status_reg;
	bool *enable_hwirq;
	bool *cache_hwirq;
};

enum mt6358_irq_top_status_shift {
	MT6358_BUCK_TOP = 0,
	MT6358_LDO_TOP,
	MT6358_PSC_TOP,
	MT6358_SCK_TOP,
	MT6358_BM_TOP,
	MT6358_HK_TOP,
	MT6358_AUD_TOP,
	MT6358_MISC_TOP,
};

enum mt6358_irq_numbers {
	MT6358_IRQ_VPROC11_OC = 0,
	MT6358_IRQ_VPROC12_OC,
	MT6358_IRQ_VCORE_OC,
	MT6358_IRQ_VGPU_OC,
	MT6358_IRQ_VMODEM_OC,
	MT6358_IRQ_VDRAM1_OC,
	MT6358_IRQ_VS1_OC,
	MT6358_IRQ_VS2_OC,
	MT6358_IRQ_VPA_OC,
	MT6358_IRQ_VCORE_PREOC,
	MT6358_IRQ_VFE28_OC = 16,
	MT6358_IRQ_VXO22_OC,
	MT6358_IRQ_VRF18_OC,
	MT6358_IRQ_VRF12_OC,
	MT6358_IRQ_VEFUSE_OC,
	MT6358_IRQ_VCN33_OC,
	MT6358_IRQ_VCN28_OC,
	MT6358_IRQ_VCN18_OC,
	MT6358_IRQ_VCAMA1_OC,
	MT6358_IRQ_VCAMA2_OC,
	MT6358_IRQ_VCAMD_OC,
	MT6358_IRQ_VCAMIO_OC,
	MT6358_IRQ_VLDO28_OC,
	MT6358_IRQ_VA12_OC,
	MT6358_IRQ_VAUX18_OC,
	MT6358_IRQ_VAUD28_OC,
	MT6358_IRQ_VIO28_OC,
	MT6358_IRQ_VIO18_OC,
	MT6358_IRQ_VSRAM_PROC11_OC,
	MT6358_IRQ_VSRAM_PROC12_OC,
	MT6358_IRQ_VSRAM_OTHERS_OC,
	MT6358_IRQ_VSRAM_GPU_OC,
	MT6358_IRQ_VDRAM2_OC,
	MT6358_IRQ_VMC_OC,
	MT6358_IRQ_VMCH_OC,
	MT6358_IRQ_VEMC_OC,
	MT6358_IRQ_VSIM1_OC,
	MT6358_IRQ_VSIM2_OC,
	MT6358_IRQ_VIBR_OC,
	MT6358_IRQ_VUSB_OC,
	MT6358_IRQ_VBIF28_OC,
	MT6358_IRQ_PWRKEY = 48,
	MT6358_IRQ_HOMEKEY,
	MT6358_IRQ_PWRKEY_R,
	MT6358_IRQ_HOMEKEY_R,
	MT6358_IRQ_NI_LBAT_INT,
	MT6358_IRQ_CHRDET,
	MT6358_IRQ_CHRDET_EDGE,
	MT6358_IRQ_VCDT_HV_DET,
	MT6358_IRQ_RTC = 64,
	MT6358_IRQ_FG_BAT0_H = 80,
	MT6358_IRQ_FG_BAT0_L,
	MT6358_IRQ_FG_CUR_H,
	MT6358_IRQ_FG_CUR_L,
	MT6358_IRQ_FG_ZCV,
	MT6358_IRQ_FG_BAT1_H,
	MT6358_IRQ_FG_BAT1_L,
	MT6358_IRQ_FG_N_CHARGE_L,
	MT6358_IRQ_FG_IAVG_H,
	MT6358_IRQ_FG_IAVG_L,
	MT6358_IRQ_FG_TIME_H,
	MT6358_IRQ_FG_DISCHARGE,
	MT6358_IRQ_FG_CHARGE,
	MT6358_IRQ_BATON_LV = 96,
	MT6358_IRQ_BATON_HT,
	MT6358_IRQ_BATON_BAT_IN,
	MT6358_IRQ_BATON_BAT_OUT,
	MT6358_IRQ_BIF,
	MT6358_IRQ_BAT_H = 112,
	MT6358_IRQ_BAT_L,
	MT6358_IRQ_BAT2_H,
	MT6358_IRQ_BAT2_L,
	MT6358_IRQ_BAT_TEMP_H,
	MT6358_IRQ_BAT_TEMP_L,
	MT6358_IRQ_AUXADC_IMP,
	MT6358_IRQ_NAG_C_DLTV,
	MT6358_IRQ_AUDIO = 128,
	MT6358_IRQ_ACCDET = 133,
	MT6358_IRQ_ACCDET_EINT0,
	MT6358_IRQ_ACCDET_EINT1,
	MT6358_IRQ_SPI_CMD_ALERT = 144,
	MT6358_IRQ_NR,
};

#define MT6358_IRQ_BUCK_BASE MT6358_IRQ_VPROC11_OC
#define MT6358_IRQ_LDO_BASE MT6358_IRQ_VFE28_OC
#define MT6358_IRQ_PSC_BASE MT6358_IRQ_PWRKEY
#define MT6358_IRQ_SCK_BASE MT6358_IRQ_RTC
#define MT6358_IRQ_BM_BASE MT6358_IRQ_FG_BAT0_H
#define MT6358_IRQ_HK_BASE MT6358_IRQ_BAT_H
#define MT6358_IRQ_AUD_BASE MT6358_IRQ_AUDIO
#define MT6358_IRQ_MISC_BASE MT6358_IRQ_SPI_CMD_ALERT

#define MT6358_IRQ_BUCK_BITS (MT6358_IRQ_VCORE_PREOC - MT6358_IRQ_BUCK_BASE + 1)
#define MT6358_IRQ_LDO_BITS (MT6358_IRQ_VBIF28_OC - MT6358_IRQ_LDO_BASE + 1)
#define MT6358_IRQ_PSC_BITS (MT6358_IRQ_VCDT_HV_DET - MT6358_IRQ_PSC_BASE + 1)
#define MT6358_IRQ_SCK_BITS (MT6358_IRQ_RTC - MT6358_IRQ_SCK_BASE + 1)
#define MT6358_IRQ_BM_BITS (MT6358_IRQ_BIF - MT6358_IRQ_BM_BASE + 1)
#define MT6358_IRQ_HK_BITS (MT6358_IRQ_NAG_C_DLTV - MT6358_IRQ_HK_BASE + 1)
#define MT6358_IRQ_AUD_BITS (MT6358_IRQ_ACCDET_EINT1 - MT6358_IRQ_AUD_BASE + 1)
#define MT6358_IRQ_MISC_BITS	\
	(MT6358_IRQ_SPI_CMD_ALERT - MT6358_IRQ_MISC_BASE + 1)

#define MT6358_TOP_GEN(sp)	\
{	\
	.hwirq_base = MT6358_IRQ_##sp##_BASE,	\
	.num_int_regs =	\
		((MT6358_IRQ_##sp##_BITS - 1) / MT6358_REG_WIDTH) + 1,	\
	.num_int_bits = MT6358_IRQ_##sp##_BITS, \
	.en_reg = MT6358_##sp##_TOP_INT_CON0,	\
	.en_reg_shift = 0x6,	\
	.sta_reg = MT6358_##sp##_TOP_INT_STATUS0,	\
	.sta_reg_shift = 0x2,	\
	.top_offset = MT6358_##sp##_TOP,	\
}

#endif /* __MFD_MT6358_CORE_H__ */
