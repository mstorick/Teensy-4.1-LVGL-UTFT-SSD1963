// CTE TFT LCD/SD Shield for Arduino Due
// -------------------------------------
// Uncomment the following line if you are using this shield
//#define CTE_DUE_SHIELD 1
//
// For this shield: RS=25, WR=26, CS=27, RST=28
//********************************************************************

// *** Hardwarespecific defines ***
#define cbi(reg, bitmask) *reg &= ~bitmask
#define sbi(reg, bitmask) *reg |= bitmask
#define pulse_high(reg, bitmask) sbi(reg, bitmask); cbi(reg, bitmask);
#define pulse_low(reg, bitmask) cbi(reg, bitmask); sbi(reg, bitmask);

#define cport(port, data) port &= data
#define sport(port, data) port |= data

#define swap(type, i, j) {type t = i; i = j; j = t;}

#define fontbyte(x) cfont.font[x]  

#ifdef pgm_read_word
#undef pgm_read_word
#endif
#ifdef pgm_read_byte
#undef pgm_read_byte
#endif
#define pgm_read_word(data) *data
#define pgm_read_byte(data) *data
#if defined(TEENSYDUINO) && TEENSYDUINO >= 117 && !defined(__IMXRT1062__)
  #define regtype volatile uint8_t
  #define regsize uint8_t
#else
  #define regtype volatile uint32_t
  #define regsize uint32_t
#endif
#define bitmapdatatype unsigned short*
