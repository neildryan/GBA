/* Definitions of MMIO register locations, given as indexes into
 * `NUM_IO_REGS size array of 32 bit vectors
 *
 * NOTE: Offsets 0x15A-0x199 are unused, in case the system is running
 *       short on LUTs.
 */
`ifndef GBA_MMIO_DEFINES_VH
`define GBA_MMIO_DEFINES_VH

`define DISPCNT_IDX     (32'h000 / 4)
`define DISPSTAT_IDX    (32'h004 / 4)
`define VCOUNT_IDX      (32'h006 / 4)
`define BG0CNT_IDX      (32'h008 / 4)
`define BG1CNT_IDX      (32'h00A / 4)
`define BG2CNT_IDX      (32'h00C / 4)
`define BG3CNT_IDX      (32'h00E / 4)

`define BG0HOFS_IDX     (32'h010 / 4)
`define BG0VOFS_IDX     (32'h012 / 4)
`define BG1HOFS_IDX     (32'h014 / 4)
`define BG1VOFS_IDX     (32'h016 / 4)
`define BG2HOFS_IDX     (32'h018 / 4)
`define BG2VOFS_IDX     (32'h01A / 4)
`define BG3HOFS_IDX     (32'h01C / 4)
`define BG3VOFS_IDX     (32'h01E / 4)

`define BG2PA_IDX       (32'h020 / 4)
`define BG2PB_IDX       (32'h022 / 4)
`define BG2PC_IDX       (32'h024 / 4)
`define BG2PD_IDX       (32'h026 / 4)
`define BG2X_L_IDX      (32'h028 / 4)
`define BG2X_H_IDX      (32'h02A / 4)
`define BG2Y_L_IDX      (32'h02C / 4)
`define BG2Y_H_IDX      (32'h02E / 4)

`define BG3PA_IDX       (32'h030 / 4)
`define BG3PB_IDX       (32'h032 / 4)
`define BG3PC_IDX       (32'h034 / 4)
`define BG3PD_IDX       (32'h036 / 4)
`define BG3X_L_IDX      (32'h038 / 4)
`define BG3X_H_IDX      (32'h03A / 4)
`define BG3Y_L_IDX      (32'h03C / 4)
`define BG3Y_H_IDX      (32'h03E / 4)

`define WIN0H_IDX       (32'h040 / 4)
`define WIN1H_IDX       (32'h042 / 4)
`define WIN0V_IDX       (32'h044 / 4)
`define WIN1V_IDX       (32'h046 / 4)
`define WININ_IDX       (32'h048 / 4)
`define WINOUT_IDX      (32'h04A / 4)
`define MOSAIC_IDX      (32'h04C / 4)

`define BLDCNT_IDX      (32'h050 / 4)
`define BLDALPHA_IDX    (32'h052 / 4)
`define BLDY_IDX        (32'h054 / 4)

`define SOUND1CNT_L_IDX (32'h060 / 4)
`define SOUND1CNT_H_IDX (32'h062 / 4)
`define SOUND1CNT_X_IDX (32'h064 / 4)
`define SOUND2CNT_L_IDX (32'h068 / 4)
`define SOUND2CNT_H_IDX (32'h06C / 4)
`define SOUND3CNT_L_IDX (32'h070 / 4)
`define SOUND3CNT_H_IDX (32'h072 / 4)
`define SOUND3CNT_X_IDX (32'h074 / 4)
`define SOUND4CNT_L_IDX (32'h078 / 4)
`define SOUND4CNT_H_IDX (32'h07C / 4)
`define SOUNDCNT_L_IDX  (32'h080 / 4)
`define SOUNDCNT_H_IDX  (32'h082 / 4)
`define SOUNDCNT_X_IDX  (32'h084 / 4)
`define SOUNDBIAS_IDX   (32'h088 / 4)
`define WAVE_RAM0_L_IDX (32'h090 / 4)
`define WAVE_RAM0_H_IDX (32'h092 / 4)
`define WAVE_RAM1_L_IDX (32'h094 / 4)
`define WAVE_RAM1_H_IDX (32'h096 / 4)
`define WAVE_RAM2_L_IDX (32'h098 / 4)
`define WAVE_RAM2_H_IDX (32'h09A / 4)
`define WAVE_RAM3_L_IDX (32'h09C / 4)
`define WAVE_RAM3_H_IDX (32'h09E / 4)
`define FIFO_A_L        (32'h0A0 / 4)
`define FIFO_A_H        (32'h0A2 / 4)
`define FIFO_B_L        (32'h0A4 / 4)
`define FIFO_B_H        (32'h0A6 / 4)

`define DMA0SAD_L_IDX   (32'h0B0 / 4)
`define DMA0SAD_H_IDX   (32'h0B2 / 4)
`define DMA0DAD_L_IDX   (32'h0B4 / 4)
`define DMA0DAD_H_IDX   (32'h0B6 / 4)
`define DMA0CNT_L_IDX   (32'h0B8 / 4)
`define DMA0CNT_H_IDX   (32'h0BA / 4)
`define DMA1SAD_L_IDX   (32'h0BC / 4)
`define DMA1SAD_H_IDX   (32'h0BE / 4)
`define DMA1DAD_L_IDX   (32'h0C0 / 4)
`define DMA1DAD_H_IDX   (32'h0C2 / 4)
`define DMA1CNT_L_IDX   (32'h0C4 / 4)
`define DMA1CNT_H_IDX   (32'h0C6 / 4)
`define DMA2SAD_L_IDX   (32'h0C8 / 4)
`define DMA2SAD_H_IDX   (32'h0CA / 4)
`define DMA2DAD_L_IDX   (32'h0CC / 4)
`define DMA2DAD_H_IDX   (32'h0CE / 4)
`define DMA2CNT_L_IDX   (32'h0D0 / 4)
`define DMA2CNT_H_IDX   (32'h0D2 / 4)
`define DMA3SAD_L_IDX   (32'h0D4 / 4)
`define DMA3SAD_H_IDX   (32'h0D6 / 4)
`define DMA3DAD_L_IDX   (32'h0D8 / 4)
`define DMA3DAD_H_IDX   (32'h0DA / 4)
`define DMA3CNT_L_IDX   (32'h0DC / 4)
`define DMA3CNT_H_IDX   (32'h0DE / 4)

`define TM0CNT_L_IDX    (32'h100 / 4)
`define TM0CNT_H_IDX    (32'h102 / 4)
`define TM1CNT_L_IDX    (32'h104 / 4)
`define TM1CNT_H_IDX    (32'h106 / 4)
`define TM2CNT_L_IDX    (32'h108 / 4)
`define TM2CNT_H_IDX    (32'h10A / 4)
`define TM3CNT_L_IDX    (32'h10C / 4)
`define TM3CNT_H_IDX    (32'h10E / 4)

`define SIODATA32_L_IDX (32'h120 / 4)
`define SIODATA32_H_IDX (32'h122 / 4)
`define SIOCNT_IDX      (32'h128 / 4)
`define SIODATA8_IDX    (32'h12A / 4)

`define SIOMULTI0_IDX   (32'h120 / 4)
`define SIOMULTI1_IDX   (32'h122 / 4)
`define SIOMULTI2_IDX   (32'h124 / 4)
`define SIOMULTI3_IDX   (32'h126 / 4)
`define SIOMLT_SEND_IDX (32'h12A / 4)

`define KEYINPUT_IDX    (32'h130 / 4)
`define KEYCNT_IDX      (32'h132 / 4)

`define RCNT_IDX        (32'h134 / 4)
`define JOYCNT_IDX      (32'h140 / 4)
`define JOY_RECV_L_IDX  (32'h150 / 4)
`define JOY_RECV_H_IDX  (32'h152 / 4)
`define JOY_TRANS_L_IDX (32'h154 / 4)
`define JOY_TRANS_H_IDX (32'h156 / 4)
`define JOYSTAT_IDX     (32'h158 / 4)

`define IE_IDX          (32'h200 / 4)
`define IF_IDX          (32'h202 / 4)
`define WAITCNT_IDX     (32'h204 / 4)
`define IME_IDX         (32'h208 / 4)

// Unofficial registers for debug
`define LED_REG0_IDX     (32'h160 / 4)
`define LED_REG1_IDX     (32'h164 / 4)
`define LED_REG2_IDX     (32'h168 / 4)
`define LED_REG3_IDX     (32'h16C / 4)

`endif
