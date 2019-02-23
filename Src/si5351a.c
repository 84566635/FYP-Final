#include "stm32f0xx_hal.h"
#include "si5351a.h"
#include "i2c.h"

uint16_t const si5351a_revb_registers[SI5351A_REVB_REG_CONFIG_NUM_REGS][2] =
{
		{ 0x0002, 0x53 },
		{ 0x0003, 0x00 },
		{ 0x0007, 0x00 },
		{ 0x000F, 0x00 },
		{ 0x0010, 0x0F },
		{ 0x0011, 0x8C },
		{ 0x0012, 0x8C },
		{ 0x0013, 0x8C },
		{ 0x0014, 0x8C },
		{ 0x0015, 0x8C },
		{ 0x0016, 0x8C },
		{ 0x0017, 0x8C },
		{ 0x001A, 0x01 },
		{ 0x001B, 0xF4 },
		{ 0x001C, 0x00 },
		{ 0x001D, 0x0F },
		{ 0x001E, 0xF7 },
		{ 0x001F, 0x00 },
		{ 0x0020, 0x01 },
		{ 0x0021, 0x14 },
		{ 0x002A, 0x00 },
		{ 0x002B, 0x02 },
		{ 0x002C, 0x00 },
		{ 0x002D, 0x40 },
		{ 0x002E, 0x40 },
		{ 0x002F, 0x00 },
		{ 0x0030, 0x00 },
		{ 0x0031, 0x00 },
		{ 0x005A, 0x00 },
		{ 0x005B, 0x00 },
		{ 0x0095, 0x00 },
		{ 0x0096, 0x00 },
		{ 0x0097, 0x00 },
		{ 0x0098, 0x00 },
		{ 0x0099, 0x00 },
		{ 0x009A, 0x00 },
		{ 0x009B, 0x00 },
		{ 0x00A2, 0x00 },
		{ 0x00A3, 0x00 },
		{ 0x00A4, 0x00 },
		{ 0x00B7, 0x92 },
};

void Read_Si5351A(uint8_t reg, uint8_t *pData, uint16_t size)
{
	HAL_StatusTypeDef status;
	uint16_t address = Si5351A_ADDRESS<<1;

	status = I2C_WriteBytes_NoReg(address , &reg, 1);

	if (status == HAL_OK)
	{
		address = Si5351A_ADDRESS<<1 | 0x01;
		status = I2C_ReadBytes_NoReg(address, pData, size);
	}

	if (status != HAL_OK)
	{
		_Error_Handler(__FILE__, __LINE__);
	}
}

void Write_Si5351A(uint16_t reg, uint8_t *pData, uint16_t size)
{
	uint16_t addr= Si5351A_ADDRESS<<1;
	HAL_StatusTypeDef status;

	status = I2C_WriteBytes(addr, reg, pData, size);

	if (status != HAL_OK)
	{
		_Error_Handler(__FILE__, __LINE__);
	}
}

Si5351A_StatusTypeDef Si5351A_Init(void)
{
	uint8_t temp_data;
	uint16_t temp_reg;

	uint8_t i;

	//step 1
	//Set CLKx_DIS high
	temp_data = 0;
	temp_reg = 24;
	Write_Si5351A(temp_reg, &temp_data, 1);
	//Reg. 3 = 0xFF
	temp_data = 0xFF;
	temp_reg = 3;
	Write_Si5351A(temp_reg, &temp_data, 1);

	//step2, Powerdown all output drivers, reg 16~23 = 0x80
	temp_reg = 15;
	temp_data = 0x80;
	for (i = 0; i < 8; i++)
	{
		temp_reg++;
		Write_Si5351A(temp_reg, &temp_data, 1);
	}

	//step3, Si5351A does not have interrupt

	//step 4, config to 6.78Mhz output
	for (i = 0; i < SI5351A_REVB_REG_CONFIG_NUM_REGS; i++)
	{
		temp_reg = si5351a_revb_registers[i][0];
		temp_data = si5351a_revb_registers[i][1];
		Write_Si5351A(temp_reg, &temp_data, 1);
	}

	//step 5, Apply PLLA and PLLB soft reset
	temp_reg = 177;
	temp_data= 0xAC;
	Write_Si5351A(temp_reg, &temp_data, 1);

	//step 6, enable CLK0
	temp_reg = 3;
	temp_data= 0xFE;
	Write_Si5351A(temp_reg, &temp_data, 1);

	return Si5351A_OK;
}
