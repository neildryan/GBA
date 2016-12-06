typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;
typedef uint16 rgb15;
typedef uint32 tile4bpp[8];

#define SCREEN_WIDTH  240
#define SCREEN_HEIGHT 160

#define MEM_IO   0x04000000
#define MEM_PAL  0x05000000
#define MEM_VRAM 0x06000000
#define MEM_OAM  0x07000000

#define REG_DISPLAY_VCOUNT (*((volatile uint32 *)(MEM_IO + 0x0006)))
#define REG_KEY_INPUT      ((volatile uint32 *)(MEM_IO + 0x0130))

#define KEY_UP     0x0040
#define KEY_DOWN   0x0080
#define KEY_START  0x0008
#define KEY_A      0x0001
#define KEY_R      0x0100
#define KEY_ANY    0x03FF

#define bg_palette_memory  ((volatile rgb15 *)MEM_PAL)
#define obj_palette_memory ((volatile rgb15 *)(MEM_PAL + 0x200))
//register definitions
#define dispcnt ((volatile uint16 *)MEM_IO)

#define bg0cnt ((volatile uint16 *)(MEM_IO + 0x08))
#define bg1cnt ((volatile uint16 *)(MEM_IO + 0x0A))
#define bg2cnt ((volatile uint16 *)(MEM_IO + 0x0C))

#define bg0hofs ((volatile uint16 *)(MEM_IO + 0x10))
#define bg0vofs ((volatile uint16 *)(MEM_IO + 0x12))
#define bg1hofs ((volatile uint16 *)(MEM_IO + 0x14))
#define bg1vofs ((volatile uint16 *)(MEM_IO + 0x16))
#define bg2hofs ((volatile uint16 *)(MEM_IO + 0x18))
#define bg2vofs ((volatile uint16 *)(MEM_IO + 0x1A))


#define sound2cnt_l ((volatile uint16 *)(MEM_IO + 0x68))
#define sound2cnt_h ((volatile uint16 *)(MEM_IO + 0x6C))
#define soundcnt_l ((volatile uint16 *)(MEM_IO + 0x80))
#define soundcnt_h ((volatile uint16 *)(MEM_IO + 0x82))
#define soundcnt_x ((volatile uint16 *)(MEM_IO + 0x84))
#define sound1cnt_l ((volatile uint16 *)(MEM_IO + 0x60))
#define sound1cnt_h ((volatile uint16 *)(MEM_IO + 0x62))
#define sound1cnt_x ((volatile uint16 *)(MEM_IO + 0x64))

#define MIN_H_SCREEN (-0x04)
#define MAX_H_SCREEN (-0xEF)
#define MIN_V_SCREEN 0x00
#define MAX_V_SCREEN (-0x97)
#define CENTER_V_SCREEN (-0x4B)
#define CENTER_H_SCREEN (-0x77)
#define PADDLE_1_X (-0X0B)
#define PADDLE_0_X (-0xDF)

#define PADDLE_WIDTH 0x08
#define PADDLE_HEIGHT 0xF
#define BALL_HEIGHT 0x08
#define BALL_WIDTH 0x08

// Form a 16-bit BGR GBA colour from three component values (hopefully, in range).
static inline rgb15 RGB15(int r, int g, int b) { return r | (g << 5) | (b << 10); }

// Clamp 'value' in the range 'min' to 'max' (inclusive).
static inline int clamp(int value, int min, int max) { return (value < min ? min : (value > max ? max : value)); }

// Listing 18.1: a sound-rate macro and friends

typedef enum 
{
    NOTE_C=0, NOTE_CIS, NOTE_D,   NOTE_DIS, 
    NOTE_E,   NOTE_F,   NOTE_FIS, NOTE_G, 
    NOTE_GIS, NOTE_A,   NOTE_BES, NOTE_B
} eSndNoteId;

// Rates for traditional notes in octave +5
const uint32 __snd_rates[12]=
{
    8013, 7566, 7144, 6742, // C , C#, D , D#
    6362, 6005, 5666, 5346, // E , F , F#, G
    5048, 4766, 4499, 4246  // G#, A , A#, B
};

#define SND_RATE(note, oct) ( 2048-(__snd_rates[note]>>(4+(oct))) )

#define SDMG_SQR1    0x01
#define SDMG_SQR2    0x02
#define SDMG_WAVE    0x04
#define SDMG_NOISE   0x08

#define SDMG_BUILD(_lmode, _rmode, _lvol, _rvol)    \
    ( ((_lvol)&7) | (((_rvol)&7)<<4) | ((_lmode)<<8) | ((_rmode)<<12) )

#define SDMG_BUILD_LR(_mode, _vol) SDMG_BUILD(_mode, _mode, _vol, _vol)



void letter_M(void) {
    //attribute 0 square, 16x16 palette, mosaic off, normal oBL, single-fold, no rotation scaling,
    //y coord = 0;
	*(volatile unsigned short *)(MEM_OAM + 0x0000) = 0x0000; 
    //attribute 1 obj size =16x16, no horizontal, vertical flip, no rotation scaling
    //x coord = 0
	*(volatile unsigned short *)(MEM_OAM + 0x0002) = 0x4000; 
    //obj attribute 2 pallette =16x16, priority 0, char 0
	*(volatile unsigned short *)(MEM_OAM + 0x0004) = 0x0000; 

    *(unsigned short *)(MEM_VRAM + 0x10000) = 0x0011; //line 1 top left
	*(unsigned short *)(MEM_VRAM + 0x10002) = 0x0000;
	*(unsigned short *)(MEM_VRAM + 0x10004) = 0x0101; // line 2
	*(unsigned short *)(MEM_VRAM + 0x10006) = 0x0000;
	*(unsigned short *)(MEM_VRAM + 0x10008) = 0x1001; // line 3
	*(unsigned short *)(MEM_VRAM + 0x1000A) = 0x0000;
	*(unsigned short *)(MEM_VRAM + 0x1000C) = 0x0001; // line 4
	*(unsigned short *)(MEM_VRAM + 0x1000E) = 0x0001;
	*(unsigned short *)(MEM_VRAM + 0x10010) = 0x0001; // line 5
	*(unsigned short *)(MEM_VRAM + 0x10012) = 0x0010;
	*(unsigned short *)(MEM_VRAM + 0x10014) = 0x0001; // line 6
	*(unsigned short *)(MEM_VRAM + 0x10016) = 0x0100;
	*(unsigned short *)(MEM_VRAM + 0x10018) = 0x0001; // line 7
	*(unsigned short *)(MEM_VRAM + 0x1001A) = 0x1000;
	*(unsigned short *)(MEM_VRAM + 0x1001C) = 0x0001; // line 8
	*(unsigned short *)(MEM_VRAM + 0x1001E) = 0x0000;
	
    *(unsigned short *)(MEM_VRAM + 0x10020) = 0x0000; //line 1 top right
	*(unsigned short *)(MEM_VRAM + 0x10022) = 0x1100;
	*(unsigned short *)(MEM_VRAM + 0x10024) = 0x0000; // line 2
	*(unsigned short *)(MEM_VRAM + 0x10026) = 0x1010;
	*(unsigned short *)(MEM_VRAM + 0x10028) = 0x0000; // line 3
	*(unsigned short *)(MEM_VRAM + 0x1002A) = 0x1001;
	*(unsigned short *)(MEM_VRAM + 0x1002C) = 0x1000; // line 4
	*(unsigned short *)(MEM_VRAM + 0x1002E) = 0x1000;
	*(unsigned short *)(MEM_VRAM + 0x10030) = 0x0100; // line 5
	*(unsigned short *)(MEM_VRAM + 0x10032) = 0x1000;
	*(unsigned short *)(MEM_VRAM + 0x10034) = 0x0010; // line 6
	*(unsigned short *)(MEM_VRAM + 0x10036) = 0x1000;
	*(unsigned short *)(MEM_VRAM + 0x10038) = 0x0001; // line 7
	*(unsigned short *)(MEM_VRAM + 0x1003A) = 0x1000;
	*(unsigned short *)(MEM_VRAM + 0x1003C) = 0x0000; // line 8
	*(unsigned short *)(MEM_VRAM + 0x1003E) = 0x1000;
	
    *(unsigned short *)(MEM_VRAM + 0x10040) = 0x0001; //line 9 bottom left
	*(unsigned short *)(MEM_VRAM + 0x10042) = 0x0000;
	*(unsigned short *)(MEM_VRAM + 0x10044) = 0x0001; // line 10
	*(unsigned short *)(MEM_VRAM + 0x10046) = 0x0000;
	*(unsigned short *)(MEM_VRAM + 0x10048) = 0x0001; // line 11
	*(unsigned short *)(MEM_VRAM + 0x1004A) = 0x0000;
	*(unsigned short *)(MEM_VRAM + 0x1004C) = 0x0001; // line 12
	*(unsigned short *)(MEM_VRAM + 0x1004E) = 0x0000;
	*(unsigned short *)(MEM_VRAM + 0x10050) = 0x0001; // line 13
	*(unsigned short *)(MEM_VRAM + 0x10052) = 0x0000;
	*(unsigned short *)(MEM_VRAM + 0x10054) = 0x0001; // line 14
	*(unsigned short *)(MEM_VRAM + 0x10056) = 0x0000;
	*(unsigned short *)(MEM_VRAM + 0x10058) = 0x0001; // line 15
	*(unsigned short *)(MEM_VRAM + 0x1005A) = 0x0000;
	*(unsigned short *)(MEM_VRAM + 0x1005C) = 0x0001; // line 16
	*(unsigned short *)(MEM_VRAM + 0x1005E) = 0x0000;

    *(unsigned short *)(MEM_VRAM + 0x10060) = 0x0000; //line 9 bottom left
	*(unsigned short *)(MEM_VRAM + 0x10062) = 0x1000;
	*(unsigned short *)(MEM_VRAM + 0x10064) = 0x0000; // line 10
	*(unsigned short *)(MEM_VRAM + 0x10066) = 0x1000;
	*(unsigned short *)(MEM_VRAM + 0x10068) = 0x0000; // line 11
	*(unsigned short *)(MEM_VRAM + 0x1006A) = 0x1000;
	*(unsigned short *)(MEM_VRAM + 0x1006C) = 0x0000; // line 12
	*(unsigned short *)(MEM_VRAM + 0x1006E) = 0x1000;
	*(unsigned short *)(MEM_VRAM + 0x10070) = 0x0000; // line 13
	*(unsigned short *)(MEM_VRAM + 0x10072) = 0x1000;
	*(unsigned short *)(MEM_VRAM + 0x10074) = 0x0000; // line 14
	*(unsigned short *)(MEM_VRAM + 0x10076) = 0x1000;
	*(unsigned short *)(MEM_VRAM + 0x10078) = 0x0000; // line 15
	*(unsigned short *)(MEM_VRAM + 0x1007A) = 0x1000;
	*(unsigned short *)(MEM_VRAM + 0x1007C) = 0x0000; // line 16
	*(unsigned short *)(MEM_VRAM + 0x1007E) = 0x1000;
}

void letter_A (void){
    //attribute 0 square, 16x16 palette, mosaic off, normal oBL, single-fold, no rotation scaling,
    //y coord = 0;
	*(volatile unsigned short *)(MEM_OAM + 0x0006) = 0x0000; 
    //attribute 1 obj size =16x16, no horizontal, vertical flip, no rotation scaling
    //x coord = 0
	*(volatile unsigned short *)(MEM_OAM + 0x0008) = 0x4000; 
    //obj attribute 2 pallette =16x16, priority 0, char 0
	*(volatile unsigned short *)(MEM_OAM + 0x000A) = 0x0001; 

    *(unsigned short *)(MEM_VRAM + 0x10080) = 0x0000; //line 9 bottom left
	*(unsigned short *)(MEM_VRAM + 0x10082) = 0x1000;
	*(unsigned short *)(MEM_VRAM + 0x10084) = 0x0000; // line 10
	*(unsigned short *)(MEM_VRAM + 0x10086) = 0x1000;
	*(unsigned short *)(MEM_VRAM + 0x10088) = 0x0000; // line 11
	*(unsigned short *)(MEM_VRAM + 0x1008A) = 0x1000;
	*(unsigned short *)(MEM_VRAM + 0x1008C) = 0x0000; // line 12
	*(unsigned short *)(MEM_VRAM + 0x1008E) = 0x1000;
	*(unsigned short *)(MEM_VRAM + 0x10090) = 0x0000; // line 13
	*(unsigned short *)(MEM_VRAM + 0x10092) = 0x1000;
	*(unsigned short *)(MEM_VRAM + 0x10094) = 0x0000; // line 14
	*(unsigned short *)(MEM_VRAM + 0x10096) = 0x1000;
	*(unsigned short *)(MEM_VRAM + 0x10098) = 0x0000; // line 15
	*(unsigned short *)(MEM_VRAM + 0x1009A) = 0x1000;
	*(unsigned short *)(MEM_VRAM + 0x1009C) = 0x0000; // line 16
	*(unsigned short *)(MEM_VRAM + 0x1009E) = 0x1000;
}

void mario_wins(void){
	*dispcnt = 0x1740; //bg mode0, display window 0 and 1, turn on bg2, bg1, bg0A
    
    letter_M();
}
void luigi_wins(void){

}
int main(void) {
	//set DISPCNT
	*dispcnt = 0x0700; //bg mode0, display window 0 and 1, turn on bg2, bg1, bg0

	*bg0cnt = 0x0801;
	*bg1cnt = 0x0902;
	*bg2cnt = 0x0A00;

	//set colors in PRAM 1
	bg_palette_memory[0] = 0x0000;//RGB15(0x00, 0x00, 0x00); //black
	bg_palette_memory[1] = 0x7C00; //blue = 1
	bg_palette_memory[2] = RGB15(0x1F, 0x00, 0x00); //red = 2
	bg_palette_memory[3] = RGB15(0x8, 0x8, 0x0); //brown = 3
	bg_palette_memory[4] = RGB15(0x1F, 0x1F, 0x0); //yellow = 4
	bg_palette_memory[5] = RGB15(0x1F, 0x1F, 0x1F); //white = 5
	bg_palette_memory[6] = RGB15(0xf7, 0xae, 0x4f); //skin = 6
	bg_palette_memory[7] = RGB15(0x0, 0x8, 0x8); //gray = 7

    //set colors in PRAM 2
	bg_palette_memory[17] = 0x7C00; //blue = 1
	bg_palette_memory[18] = RGB15(0x00, 0x1F, 0x00); //green = 2
	bg_palette_memory[19] = RGB15(0x8, 0x8, 0x0); //brown = 3
	bg_palette_memory[20] = RGB15(0x1F, 0x1F, 0x0); //yellow = 4
	bg_palette_memory[21] = RGB15(0x1F, 0x1F, 0x1F); //white = 5
	bg_palette_memory[22] = RGB15(0xf7, 0xae, 0x4f); //skin = 6
	bg_palette_memory[23] = RGB15(0x0, 0x8, 0x8); //gray = 7

	bg_palette_memory[33] = RGB15(0x1F, 0x00, 0x00); //red = 1
	bg_palette_memory[34] = RGB15(0x1F, 0x1F, 0x1F); //white = 2
	bg_palette_memory[35] = RGB15(0x7, 0x7, 0x7); //gray = 3
	bg_palette_memory[36] = RGB15(0x1F, 0x1F, 0x0); //yellow = 3
	bg_palette_memory[37] = RGB15(0x0, 0x1F, 0x1F); //tourquoise = 3
	bg_palette_memory[38] = RGB15(0x1F, 0x0, 0x1F); //magenta = 3
	bg_palette_memory[39] = RGB15(0x8, 0x8, 0x0); //brown = 3
	bg_palette_memory[40] = RGB15(0x0, 0x8, 0x8); //gray = 3

    //set colors in OBJ PRAM
    obj_palette_memory[1] = RGB15(0x1F, 0x1F, 0x1F); // white = 1
    obj_palette_memory[2] = RGB15(0x1F, 0x00, 0x00); // red = 2;

	//set screen data format for paddle 1
	//tile 1 is paddle 1
	*(volatile unsigned short *)(MEM_VRAM + 0x4800) = 0x0001;
	*(volatile unsigned short *)(MEM_VRAM + 0x4840) = 0x0002;
	*bg0hofs = PADDLE_0_X;
	*bg0vofs = CENTER_V_SCREEN;

	//paddle 2 is paddle 2 right shifted in a different color
	*(volatile unsigned short *)(MEM_VRAM + 0x4000) = 0x1401;
	*(volatile unsigned short *)(MEM_VRAM + 0x4040) = 0x1402;
	*bg1hofs = PADDLE_1_X;
	*bg1vofs = CENTER_V_SCREEN;

	//ball is tile 3
	*(volatile unsigned short *)(MEM_VRAM + 0x5000) = 0x2003;
	*bg2hofs = CENTER_H_SCREEN;
	*bg2vofs = CENTER_V_SCREEN;

	//set screen data format for paddle 1
	*(unsigned short *)(MEM_VRAM + 0x20) = 0x2200; //1-hathat
	*(unsigned short *)(MEM_VRAM + 0x22) = 0x0022; //1-hat
	*(unsigned short *)(MEM_VRAM + 0x24) = 0x2220; //2-hat 
	*(unsigned short *)(MEM_VRAM + 0x26) = 0x2222; //2-hat
	*(unsigned short *)(MEM_VRAM + 0x28) = 0x6770; //1-face
	*(unsigned short *)(MEM_VRAM + 0x2A) = 0x0067; //1-face
	*(unsigned short *)(MEM_VRAM + 0x2C) = 0x6760; //2-face
	*(unsigned short *)(MEM_VRAM + 0x2E) = 0x0667; //2-face
	*(unsigned short *)(MEM_VRAM + 0x30) = 0x6660; //3-face
	*(unsigned short *)(MEM_VRAM + 0x32) = 0x6676; //3-face
	*(unsigned short *)(MEM_VRAM + 0x34) = 0x6600; //4-face
	*(unsigned short *)(MEM_VRAM + 0x36) = 0x0777; //4-face
	*(unsigned short *)(MEM_VRAM + 0x38) = 0x6000; //5-face
	*(unsigned short *)(MEM_VRAM + 0x3A) = 0x0666; //5-face

    
	*(unsigned short *)(MEM_VRAM + 0x3C) = 0x2120; //1-shirt
	*(unsigned short *)(MEM_VRAM + 0x3E) = 0x0212; //1-shirt
	*(unsigned short *)(MEM_VRAM + 0x40) = 0x2122; //2-shirt
	*(unsigned short *)(MEM_VRAM + 0x42) = 0x2212; //2-shirt
	*(unsigned short *)(MEM_VRAM + 0x44) = 0x2122; //3-shirt
	*(unsigned short *)(MEM_VRAM + 0x46) = 0x2212; //3-shirt


	*(unsigned short *)(MEM_VRAM + 0x48) = 0x1415; //1-pants
	*(unsigned short *)(MEM_VRAM + 0x4A) = 0x5141; //1-pants
	*(unsigned short *)(MEM_VRAM + 0x4C) = 0x1155; //2-pants
	*(unsigned short *)(MEM_VRAM + 0x4E) = 0x5511; //2-pants
	*(unsigned short *)(MEM_VRAM + 0x50) = 0x0110; //3-pants
	*(unsigned short *)(MEM_VRAM + 0x52) = 0x0110; //3-pants
	*(unsigned short *)(MEM_VRAM + 0x54) = 0x0110; //4-pants
	*(unsigned short *)(MEM_VRAM + 0x56) = 0x0110; //4-pants
	
    *(unsigned short *)(MEM_VRAM + 0x58) = 0x0333; //1-shoes
	*(unsigned short *)(MEM_VRAM + 0x5A) = 0x3330; //1-shoes


	//set screen data format for ball
	*(unsigned short *)(MEM_VRAM + 0x60) = 0x1000;
	*(unsigned short *)(MEM_VRAM + 0x62) = 0x0001;
	*(unsigned short *)(MEM_VRAM + 0x64) = 0x1100;
	*(unsigned short *)(MEM_VRAM + 0x66) = 0x0011;
	*(unsigned short *)(MEM_VRAM + 0x68) = 0x3110; 
	*(unsigned short *)(MEM_VRAM + 0x6A) = 0x0113;
	*(unsigned short *)(MEM_VRAM + 0x6C) = 0x2333;
	*(unsigned short *)(MEM_VRAM + 0x6E) = 0x3332;
	*(unsigned short *)(MEM_VRAM + 0x70) = 0x2333;
	*(unsigned short *)(MEM_VRAM + 0x72) = 0x3332;
	*(unsigned short *)(MEM_VRAM + 0x74) = 0x3220;
	*(unsigned short *)(MEM_VRAM + 0x76) = 0x0223;
	*(unsigned short *)(MEM_VRAM + 0x78) = 0x2200;
	*(unsigned short *)(MEM_VRAM + 0x7A) = 0x0022;
	*(unsigned short *)(MEM_VRAM + 0x7C) = 0x2000;
	*(unsigned short *)(MEM_VRAM + 0x7E) = 0x0002;



	uint32 volatile key_states = 0;
	int x_dir = 2;
    int y_dir = 1;
    int paddle_velocity = 2;
    short ball_x = CENTER_H_SCREEN;
    short ball_y = CENTER_V_SCREEN;
    short player_1 = CENTER_V_SCREEN;
    short player_0 = CENTER_V_SCREEN;
    uint16 counter = 0;

   // turn sound on
    *soundcnt_x= (1 << 0x7);
    // snd1 on left/right ; both full volume
    *soundcnt_l = SDMG_BUILD_LR(SDMG_SQR1, 7);
    // DMG ratio to 100%
    *soundcnt_h= 0x2;

    // no sweep
    *sound1cnt_l= 0x00;
    // envelope: vol=12, decay, max step time (7) ; 50% duty
    *sound1cnt_h = 0xC78;


	//play a jig
	const uint8 lens[6]= { 3,4, 8, 8, 4, 3};
	const uint8 notes[6]= { 0x02, 0x05, 0x08};

	while (1) {
        mario_wins();
        counter = counter + 1;
        // Skip past the rest of any current V-Blank, then skip past the V-Draw
        while(REG_DISPLAY_VCOUNT >= 160);
        while(REG_DISPLAY_VCOUNT < 160);
        if (counter % 200 == 0x00){
            if (ball_x == CENTER_H_SCREEN && ball_y == CENTER_V_SCREEN){
                //reset_sound
                *soundcnt_x= (1 << 0x7);
                for(int ii=0; ii<3; ii++)
                {
                    //play the actual note
                    *sound1cnt_x = (0x1 << 15) | SND_RATE(notes[ii]&15, notes[ii]>>4);
                    for (int i = 0; i < (8*lens[ii] * 2000); i ++ );
                }
                *soundcnt_x= 0;
            }
            //turn sound off
            *soundcnt_x = 0; 
            
            //update location
            ball_x = ball_x + x_dir;
            ball_y = ball_y + y_dir;

            // get current key states (*REG_KEY_INPUT stores the states inverted)
            key_states = ~*REG_KEY_INPUT & KEY_ANY;
            if (key_states & KEY_DOWN) {
                player_1 = clamp((player_1 - paddle_velocity), (MAX_V_SCREEN + BALL_HEIGHT), MIN_V_SCREEN);
            }
            if (key_states & KEY_UP) {
                player_1 = clamp((player_1 + paddle_velocity), MAX_V_SCREEN, MIN_V_SCREEN);
            }
            if (key_states & KEY_A) {
                player_0 = clamp((player_0 - paddle_velocity), (MAX_V_SCREEN + BALL_HEIGHT), MIN_V_SCREEN);
            }
            if (key_states & KEY_R) {
                player_0 = clamp((player_0 + paddle_velocity), MAX_V_SCREEN, MIN_V_SCREEN);
            }

            //game over
            if (ball_x == PADDLE_1_X + BALL_WIDTH || ball_x == PADDLE_0_X - BALL_WIDTH) {
                *soundcnt_x= (1 << 0x7);
                for(int ii=2; ii>=0; ii--)
                {
                    //play the actual note
                    *sound1cnt_x = (0x1 << 15) | SND_RATE(notes[ii]&15, notes[ii]>>4);
                    for (int i = 0; i < (8*lens[ii + 3] * 2000); i ++ );
                }
                *soundcnt_x= 0;
                while (1) {
                    key_states = ~*REG_KEY_INPUT & KEY_ANY;
                    if (key_states & KEY_START){
                        player_0 = CENTER_V_SCREEN;
                        player_1 = CENTER_V_SCREEN;
                        ball_x = CENTER_H_SCREEN;
                        ball_y = CENTER_V_SCREEN;
                        break;
                    }
                }
                if (ball_x == PADDLE_1_X + BALL_WIDTH){ //mario wins
                    mario_wins();
                }
                else luigi_wins;

            }
            //bounce off vertical edges
            else if (ball_y == MIN_V_SCREEN || ball_y == MAX_V_SCREEN) {
                y_dir = -y_dir;
            }
            //bounce off paddle
            if (((ball_x - BALL_WIDTH == PADDLE_0_X) && 
                     (ball_y <= player_0 + PADDLE_HEIGHT - BALL_HEIGHT) && 
                     (ball_y >= player_0 - PADDLE_HEIGHT + BALL_HEIGHT - 8)) ||
                    ((ball_x == PADDLE_1_X - PADDLE_WIDTH) && 
                     (ball_y <= player_1 + PADDLE_HEIGHT - BALL_HEIGHT) && 
                     (ball_y >= player_1 - PADDLE_HEIGHT + BALL_HEIGHT - 8))
                    ) {
                x_dir = -x_dir;
                *soundcnt_x= (1 << 0x7);
	            *sound1cnt_x = (0x1 << 15) | SND_RATE(NOTE_A, 0); //octave
            }

            //update location registers
            *bg2hofs = ball_x;
            *bg2vofs = ball_y;
            *bg1vofs = player_1;
            *bg0vofs = player_0;
            
        }

    }
    return 0;
}
