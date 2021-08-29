//==========================================================================
//
//       Configuration Bits
//
//==========================================================================

//Configuration Byte 2 Options
#define _OSCS_ON_2     0xDF	// Oscillator Switch enable
#define _OSCS_OFF_2    0xFF
#define _LP_OSC_2      0xF8	// Oscillator type
#define _XT_OSC_2      0xF9
#define _HS_OSC_2      0xFA
#define _RC_OSC_2      0xFB
#define _EC_OSC_2      0xFC	// External Clock w/OSC2 output divide by 4
#define _ECIO_OSC_2    0xFD	// w/OSC2 as an IO pin (RA6)
#define _HSPLL_OSC_2   0xFE	// HS PLL
#define _RCIO_OSC_2    0xFF	// RC w/OSC2 as an IO pin (RA6)

//Configuration Byte 3 Options
#define _BOR_ON_3      0xFF	// Brown-Out Reset enable
#define _BOR_OFF_3     0xFD
#define _PWRT_OFF_3    0xFF	// Power-Up Timer enable
#define _PWRT_ON_3     0xFE
#define _BORV_20_3     0xFF	// BOR Voltage - 2.0v
#define _BORV_27_3     0xFB	//               2.7v
#define _BORV_42_3     0xF7 	//               4.2v
#define _BORV_45_3     0xF3	//               4.5v

//Configuration Byte 4 Options
#define _WDT_ON_4      0xFF	// Watch Dog Timer enable
#define _WDT_OFF_4     0xFE
#define _WDTPS_128_4   0xFF	// Watch Dog Timer PostScaler count
#define _WDTPS_64_4    0xFD
#define _WDTPS_32_4    0xFB
#define _WDTPS_16_4    0xF9
#define _WDTPS_8_4     0xF7
#define _WDTPS_4_4     0xF5
#define _WDTPS_2_4     0xF3
#define _WDTPS_1_4     0xF1

//Configuration Byte 6 Options
#define _CCP2MX_ON_6   0xFF	// CCP2 pin Mux enable
#define _CCP2MX_OFF_6  0xFE

//Configuration Byte 7 Options
#define _STVR_ON_7     0xFF	// Stack over/underflow Reset enable
#define _STVR_OFF_7    0xFE
#define _LVP_ON_7      0xFF    // Low-voltage ICSP enable
#define _LVP_OFF_7     0xFB
#define _DEBUG_ON_7    0x7F    // Backgound Debugger enable
#define _DEBUG_OFF_7   0xFF

//Configuration Byte 9 Options
#define _CP0_ON_9      0xFE    // Code protect user block enable
#define _CP0_OFF_9     0xFF
#define _CP1_ON_9      0xFD
#define _CP1_OFF_9     0xFF
#define _CP2_ON_9      0xFB
#define _CP2_OFF_9     0xFF
#define _CP3_ON_9      0xF7
#define _CP3_OFF_9     0xFF

//Configuration Byte 10 Options
#define _CPB_ON_10      0xBF    // Code protect boot block enable
#define _CPB_OFF_10     0xFF
#define _CPD_ON_10      0x7F    // Code protect Data EE enable
#define _CPD_OFF_10     0xFF

//Configuration Byte 11 Options
#define _WRT0_ON_11     0xFE    // Write protect user block enable
#define _WRT0_OFF_11    0xFF
#define _WRT1_ON_11     0xFD
#define _WRT1_OFF_11    0xFF
#define _WRT2_ON_11     0xFB
#define _WRT2_OFF_11    0xFF
#define _WRT3_ON_11     0xF7
#define _WRT3_OFF_11    0xFF

//Configuration Byte 12 Options
#define _WRTC_ON_12     0xDF    // Write protect CONFIG regs enable
#define _WRTC_OFF_12    0xFF
#define _WRTB_ON_12     0xBF    // Write protect boot block enable
#define _WRTB_OFF_12    0xFF
#define _WRTD_ON_12     0x7F    // Write protect Data EE enable
#define _WRTD_OFF_12    0xFF

//Configuration Byte 13 Options
#define _EBTR0_ON_13    0xFE    // Table Read protect user block enable
#define _EBTR0_OFF_13   0xFF
#define _EBTR1_ON_13    0xFD
#define _EBTR1_OFF_13   0xFF
#define _EBTR2_ON_13    0xFB
#define _EBTR2_OFF_13   0xFF
#define _EBTR3_ON_13    0xF7
#define _EBTR3_OFF_13   0xFF

//Configuration Byte 14 Options
#define _EBTRB_ON_14    0xBF    // Table Read protect boot block enable
#define _EBTRB_OFF_14   0xFF

// To use the Configuration Bits, place the following lines in your source code
//  in the following format, and change the configuration value to the desired
//  setting (such as CP_OFF to CP_ON).  These are currently commented out here
//  and each __CONFIG line should have the preceding semicolon removed when
//  pasted into your source code.

