#include <Gamebuino-Meta.h>
#include "tone.h"
#include "music_and_lyrics.h"
#include "logo.h"
/*  _    _          _____  _______     __  _   _ ________          __ __     ________          _____      ___   ___ ___  _____ 
 * | |  | |   /\   |  __ \|  __ \ \   / / | \ | |  ____\ \        / / \ \   / /  ____|   /\   |  __ \    |__ \ / _ \__ \| ____|
 * | |__| |  /  \  | |__) | |__) \ \_/ /  |  \| | |__   \ \  /\  / /   \ \_/ /| |__     /  \  | |__) |      ) | | | | ) | |__  
 * |  __  | / /\ \ |  ___/|  ___/ \   /   | . ` |  __|   \ \/  \/ /     \   / |  __|   / /\ \ |  _  /      / /| | | |/ /|___ \ 
 * | |  | |/ ____ \| |    | |      | |    | |\  | |____   \  /\  /       | |  | |____ / ____ \| | \ \     / /_| |_| / /_ ___) |
 * |_|  |_/_/    \_\_|    |_|      |_|    |_| \_|______|   \/  \/        |_|  |______/_/    \_\_|  \_\   |____|\___/____|____/ 
 * cf https://patorjk.com/software/taag/#p=display&f=Big&t=Happy%20new%20year
 * */

void setup() {
    gb.begin();
    gb.sound.playTick();
}

  // plays the main sound, the octave and the third
void play_chord_freq( uint32_t u32_frequency_hz, uint32_t u32_tone_time )
{
        gb.sound.tone( u32_frequency_hz, u32_tone_time*8/20 );
        gb.sound.tone( u32_frequency_hz*2, u32_tone_time*8/20 );
        gb.sound.tone( u32_frequency_hz*523/440, u32_tone_time*8/20 );
}

  // convert tone frequency to LED pattern
void draw_led_freq( uint16_t u16_frequency_hz )
{
    gb.lights.clear();
    float findex = log(u16_frequency_hz/220.0)/log(  pow(2.0,1.0/12)  );
    int iled_index = ((int)(findex+0.5))%24; // 0 to 23 note index => 8 leds with RGB
    switch ( iled_index % 3 )
    {
        case 0 : gb.lights.setColor(255, 0, 0 );break;
        case 1 : gb.lights.setColor(0, 255, 0 );break;
        case 2 : gb.lights.setColor(0, 0, 255 );break;
    }
    gb.lights.drawPixel( (iled_index/3)%2, (iled_index/3)/2 );
}

  // main loop
void loop()
{
    for (int i = 0; i < __countof__(melody) ; i++)
    {
        const char* pc_world = pc_text_array[i%__countof__(pc_text_array)];
        play_chord_freq( melody[i].u16_frequency_hz, melody[i].u16_delay_ms );
        draw_led_freq( melody[i].u16_frequency_hz);
        gb.display.clear();
        gb.display.setFontSize(2);
        gb.display.setColor( 1+i%15 );
        gb.display.setCursor(  8*(10-strlen(pc_world))/2, 64/2-8  );
        gb.display.print( pc_world );
        while(!gb.update());
        delay( melody[i].u16_delay_ms/2 );
    }
      // The end !
    gb.lights.clear();
    gb.display.drawImage(0, 0, LOGO_PICT);
    while(!gb.update());
    delay(2000);
}



