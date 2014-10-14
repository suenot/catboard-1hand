#define LED_CONFIG	(DDRD	|= (1<<4))
#define LED_OFF		(PORTD	&= ~(1<<4))
#define LED_ON		(PORTD	|= (1<<4))

#define LED_RED_CONFIG	LED_CONFIG
#define LED_RED_OFF		LED_ON
#define LED_RED_ON		LED_OFF

#define LED_BLUE_CONFIG	LED_CONFIG
#define LED_BLUE_OFF	LED_OFF
#define LED_BLUE_ON		LED_ON

#define FN_KEY_ID			7*5

uint8_t *const col_pin_sw2 = _PIND;
const uint8_t col_bit_sw2 = (1<<7);

// Init ports
void init_ports(void) {
	DDRB	= 0x00; DDRC	= 0b11110100;	DDRD	= 0x80;
	PORTB	= 0xFF; PORTC	= 0b11110100; 	PORTD	= 0xFF;
}

// Pins keyboard matrix (have to properly initialize ports)
uint8_t *const	row_port[ROWS]	= { _PORTC,	_PORTC,	_PORTC,	_PORTC,	_PORTC};
const uint8_t	row_bit[ROWS]	= { (1<<7),	(1<<6),	(1<<5),	(1<<4),	(1<<2)};
uint8_t *const	col_pin[COLS]	= {_PIND, _PIND, _PIND, _PIND, _PIND, _PIND, _PINB,	_PINB,	_PINB, _PINB, _PINB, _PINB};
const uint8_t	col_bit[COLS]	= { (1<<6),	(1<<5),	(1<<3),	(1<<2),	(1<<1),	(1<<0),	(1<<7),	(1<<6),	(1<<5),	(1<<4),	(1<<1),	(1<<0)};

const uint8_t layer1[KEYS] = {
	//ROW0				ROW1				ROW2			ROW3			ROW4
	KEY_ESC,			KEY_LAYER1,			KEY_RIGHT_CTRL|KEY_MOD,KEY_TAB,	KEY_TILDE,		// COL0
	KEY_ALT_TAB,		KEY_Z,				KEY_A,			KEY_Q,			KEY_1,			// COL1
	KEY_GUI|KEY_MOD,	KEY_X,				KEY_S,			KEY_W,			KEY_2,			// COL2
	KEY_ALT|KEY_MOD,	KEY_C,				KEY_D,			KEY_E,			KEY_3,			// COL3
	KEY_CTRL|KEY_MOD,	KEY_V,				KEY_F,			KEY_R,			KEY_4,			// COL4
	KEY_MY_SHIFT,		KEY_B,				KEY_G,			KEY_T,			KEY_5,			// COL5
	KEY_SPACE,			KEY_N,				KEY_H,			KEY_Y,			KEY_6,			// COL6 
	KEY_FN,				KEY_M,				KEY_J,			KEY_U,			KEY_7,			// COL7
	KEY_RIGHT_ALT|KEY_MOD,KEY_COMMA,		KEY_K,			KEY_I,			KEY_8,			// COL8
	KEY_BACKSLASH,		KEY_PERIOD,			KEY_L,			KEY_O,			KEY_9,			// COL9
	KEY_RIGHT_BRACE,	KEY_SLASH,			KEY_SEMICOLON,	KEY_P,			KEY_0,			// COL10
	KEY_EQUAL,			KEY_LAYER2,			KEY_QUOTE,		KEY_LEFT_BRACE,	KEY_MINUS		// COL11
};

const uint8_t layer_fn[KEYS] = {
	//ROW0				ROW1				ROW2			ROW3			ROW4
	KEY_TURBO_REPEAT,	KEY_LAYER1,			KEY_RIGHT_CTRL|KEY_MOD,KEY_TAB,	KEY_PRINTSCREEN,// COL0
	KEY_TAB,			NULL,				NULL,			NULL,			KEY_F1,			// COL1
	KEY_GUI|KEY_MOD,	NULL,				NULL,			NULL,			KEY_F2,			// COL2
	KEY_ALT|KEY_MOD,	NULL,				NULL,			NULL,			KEY_F3,			// COL3
	KEY_CTRL|KEY_MOD,	NULL,				NULL,			NULL,			KEY_F4,			// COL4
	KEY_MY_SHIFT,		NULL,				NULL,			KEY_TILDE,		KEY_F5,			// COL5
	KEY_MAC_MODE,		KEY_BACKSPACE,		KEY_ENTER,		KEY_LED,		KEY_F6,			// COL6 
	KEY_FN,				KEY_DELETE,			KEY_LEFT,		KEY_HOME,		KEY_F7,			// COL7
	KEY_FN_LOCK,		KEY_INSERT,			KEY_DOWN,		KEY_UP,			KEY_F8,			// COL8
	KEY_ENTER,			NULL,				KEY_RIGHT,		KEY_END,		KEY_F9,			// COL9
	KEY_SCROLL_LOCK,	NULL,				KEY_PAGE_DOWN,	KEY_PAGE_UP,	KEY_F10,		// COL10
	KEY_F12,			KEY_LOCK,			KEY_PAUSE,		KEY_ESC,		KEY_F11			// COL11
};

const uint8_t layer_fnlock[KEYS] = {
	//ROW0				ROW1				ROW2			ROW3			ROW4
	KEY_ESC,			KEY_LAYER1,			KEY_RIGHT_CTRL|KEY_MOD,KEY_TAB,	KEY_TILDE,		// COL0
	KEY_ALT_TAB,		NULL,				KEY_PAGE_DOWN,	KEY_PAGE_UP,	KEY_1,			// COL1
	KEY_GUI|KEY_MOD,	NULL,				KEY_LEFT,		KEY_HOME,		KEY_2,			// COL2
	KEY_ALT|KEY_MOD,	NULL,				KEY_DOWN,		KEY_UP,			KEY_3,			// COL3
	KEY_CTRL|KEY_MOD,	NULL,				KEY_RIGHT,		KEY_END,		KEY_4,			// COL4
	KEY_MY_SHIFT,		NULL,				KEY_ENTER,		KEY_TILDE,		KEY_5,			// COL5
	KEY_SPACE,			KEYPAD_0,			KEYPAD_ASTERIX,	KEYPAD_SLASH,	KEY_6,			// COL6 
	KEY_FN,				KEYPAD_1,			KEYPAD_4,		KEYPAD_7,		KEY_7,			// COL7
	KEY_RIGHT_ALT|KEY_MOD,KEYPAD_2,			KEYPAD_5,		KEYPAD_8,		KEY_8,			// COL8
	KEY_ENTER,			KEYPAD_3,			KEYPAD_6,		KEYPAD_9,		KEY_9,			// COL9
	KEY_NUM_LOCK,		KEYPAD_PERIOD,		KEYPAD_PLUS,	KEYPAD_MINUS,	KEY_0,			// COL10
	KEY_EQUAL,			KEY_LAYER2,			KEY_ENTER,		KEY_ESC,		KEY_MINUS		// COL11
};
