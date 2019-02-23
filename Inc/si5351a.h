
#ifndef SI5351A_H_
#define SI5351A_H_

#define SI5351A_REVB_REG_CONFIG_NUM_REGS				41
#define Si5351A_ADDRESS									0x60

typedef enum
{
	Si5351A_OK       = 0x00U,
	Si5351A_FAIL    = 0x01U,
} Si5351A_StatusTypeDef;

void Read_Si5351A(uint8_t reg, uint8_t *pData, uint16_t size);
void Write_Si5351A(uint16_t reg, uint8_t *pData, uint16_t size);
Si5351A_StatusTypeDef Si5351A_Init(void);



/*
 * Design Report
 *
 * Overview
 * ========
 * Part:               Si5351A
 * Project File:       C:\Users\Keung\Desktop\Si5351A-RevB-Project.slabtimeproj
 * Created By:         ClockBuilder Pro v2.27 [2018-08-12]
 * Timestamp:          2018-09-08 01:02:26 GMT+08:00
 *
 * Design Rule Check
 * =================
 * Errors:
 * - No errors
 *
 * Warnings:
 * - No warnings
 *
 * Design
 * ======
 * Inputs:
 *     IN0: 25 MHz
 *
 * Outputs:
 *    OUT0: 6.78 MHz [ 6 + 39/50 MHz ]
 *          Enabled LVCMOS 8 mA
 *          Offset 0.000 s
 *    OUT1: Unused
 *    OUT2: Unused
 *
 * Frequency Plan
 * ==============
 * PLL_A:
 *    Enabled Features = None
 *    Fvco             = 898.35 MHz [ 898 + 7/20 MHz ]
 *    M                = 35.934 [ 35 + 467/500 ]
 *    Input0:
 *       Source           = Crystal
 *       Source Frequency = 25 MHz
 *       Fpfd             = 25 MHz
 *       Load Capacitance = Load_08pF
 *    Output0:
 *       Features       = None
 *       Disabled State = StopLow
 *       R              = 1  (2^0)
 *       Fout           = 6.78 MHz [ 6 + 39/50 MHz ]
 *       N              = 132.5 [ 132 + 1/2 ]
 *
 * Settings
 * ========
 *
 * Location      Setting Name   Decimal Value      Hex Value
 * ------------  -------------  -----------------  -----------------
 * 0x0002[3]     XO_LOS_MASK    0                  0x0
 * 0x0002[4]     CLK_LOS_MASK   1                  0x1
 * 0x0002[5]     LOL_A_MASK     0                  0x0
 * 0x0002[6]     LOL_B_MASK     1                  0x1
 * 0x0002[7]     SYS_INIT_MASK  0                  0x0
 * 0x0003[7:0]   CLK_OEB        0                  0x00
 * 0x0007[7:4]   I2C_ADDR_CTRL  0                  0x0
 * 0x000F[2]     PLLA_SRC       0                  0x0
 * 0x000F[3]     PLLB_SRC       0                  0x0
 * 0x000F[4]     PLLA_INSELB    0                  0x0
 * 0x000F[5]     PLLB_INSELB    0                  0x0
 * 0x000F[7:6]   CLKIN_DIV      0                  0x0
 * 0x0010[1:0]   CLK0_IDRV      3                  0x3
 * 0x0010[3:2]   CLK0_SRC       3                  0x3
 * 0x0010[4]     CLK0_INV       0                  0x0
 * 0x0010[5]     MS0_SRC        0                  0x0
 * 0x0010[6]     MS0_INT        0                  0x0
 * 0x0010[7]     CLK0_PDN       0                  0x0
 * 0x0011[1:0]   CLK1_IDRV      0                  0x0
 * 0x0011[3:2]   CLK1_SRC       3                  0x3
 * 0x0011[4]     CLK1_INV       0                  0x0
 * 0x0011[5]     MS1_SRC        0                  0x0
 * 0x0011[6]     MS1_INT        0                  0x0
 * 0x0011[7]     CLK1_PDN       1                  0x1
 * 0x0012[1:0]   CLK2_IDRV      0                  0x0
 * 0x0012[3:2]   CLK2_SRC       3                  0x3
 * 0x0012[4]     CLK2_INV       0                  0x0
 * 0x0012[5]     MS2_SRC        0                  0x0
 * 0x0012[6]     MS2_INT        0                  0x0
 * 0x0012[7]     CLK2_PDN       1                  0x1
 * 0x0013[1:0]   CLK3_IDRV      0                  0x0
 * 0x0013[3:2]   CLK3_SRC       3                  0x3
 * 0x0013[4]     CLK3_INV       0                  0x0
 * 0x0013[5]     MS3_SRC        0                  0x0
 * 0x0013[6]     MS3_INT        0                  0x0
 * 0x0013[7]     CLK3_PDN       1                  0x1
 * 0x0014[1:0]   CLK4_IDRV      0                  0x0
 * 0x0014[3:2]   CLK4_SRC       3                  0x3
 * 0x0014[4]     CLK4_INV       0                  0x0
 * 0x0014[5]     MS4_SRC        0                  0x0
 * 0x0014[6]     MS4_INT        0                  0x0
 * 0x0014[7]     CLK4_PDN       1                  0x1
 * 0x0015[1:0]   CLK5_IDRV      0                  0x0
 * 0x0015[3:2]   CLK5_SRC       3                  0x3
 * 0x0015[4]     CLK5_INV       0                  0x0
 * 0x0015[5]     MS5_SRC        0                  0x0
 * 0x0015[6]     MS5_INT        0                  0x0
 * 0x0015[7]     CLK5_PDN       1                  0x1
 * 0x0016[1:0]   CLK6_IDRV      0                  0x0
 * 0x0016[3:2]   CLK6_SRC       3                  0x3
 * 0x0016[4]     CLK6_INV       0                  0x0
 * 0x0016[5]     MS6_SRC        0                  0x0
 * 0x0016[6]     FBA_INT        0                  0x0
 * 0x0016[7]     CLK6_PDN       1                  0x1
 * 0x0017[1:0]   CLK7_IDRV      0                  0x0
 * 0x0017[3:2]   CLK7_SRC       3                  0x3
 * 0x0017[4]     CLK7_INV       0                  0x0
 * 0x0017[5]     MS7_SRC        0                  0x0
 * 0x0017[6]     FBB_INT        0                  0x0
 * 0x0017[7]     CLK7_PDN       1                  0x1
 * 0x001C[17:0]  MSNA_P1        4087               0x00FF7
 * 0x001F[19:0]  MSNA_P2        276                0x00114
 * 0x001F[23:4]  MSNA_P3        500                0x001F4
 * 0x002C[17:0]  MS0_P1         16448              0x04040
 * 0x002F[19:0]  MS0_P2         0                  0x00000
 * 0x002F[23:4]  MS0_P4         2                  0x00002
 * 0x005A[7:0]   MS6_P2         0                  0x00
 * 0x005B[7:0]   MS7_P2         0                  0x00
 * 0x0095[14:0]  SSDN_P2        0                  0x0000
 * 0x0095[7]     SSC_EN         0                  0x0
 * 0x0097[14:0]  SSDN_P3        0                  0x0000
 * 0x0097[7]     SSC_MODE       0                  0x0
 * 0x0099[11:0]  SSDN_P1        0                  0x000
 * 0x009A[15:4]  SSUDP          0                  0x000
 * 0x00A2[21:0]  VCXO_PARAM     0                  0x000000
 * 0x00B7[7:6]   XTAL_CL        2                  0x2
 *
 *
 */
#endif /* SI5351A_H_ */
