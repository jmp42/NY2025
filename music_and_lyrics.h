#include <Gamebuino-Meta.h>
#include "tone.h"

#define __countof__(A) (sizeof(A)/sizeof(A[0]))

typedef struct {
  uint16_t u16_frequency_hz;
  uint16_t u16_delay_ms;
} note_item_t;

/* ___  ___          _       
 * |  \/  |         (_)      
 * | .  . |_   _ ___ _  ___  
 * | |\/| | | | / __| |/ __| 
 * | |  | | |_| \__ \ | (__  
 * \_|  |_/\__,_|___/_|\___| 
 */                           
                 
const note_item_t melody[] = {
  { NOTE_D4, 1000 }, { NOTE_G4, 1000 }, { NOTE_G4, 500 }, { NOTE_A4, 500 }, { NOTE_G4, 500 }, { NOTE_FS4, 500 }, { NOTE_E4, 1000 }, { NOTE_E4, 1000 },// English
  { NOTE_E4, 1000 }, { NOTE_A4, 1000 }, { NOTE_A4, 500 }, { NOTE_B4, 500 }, { NOTE_A4, 500 }, { NOTE_G4, 500 }, { NOTE_FS4, 1000 }, { NOTE_D4, 1000 },// French
  { NOTE_D4, 1000 }, { NOTE_B4, 1000 }, { NOTE_B4, 500 }, { NOTE_C5, 500 }, { NOTE_B4, 500 }, { NOTE_A4, 500 }, { NOTE_G4, 1000 }, { NOTE_E4, 1000 }, // German
  { NOTE_D4, 500 }, { NOTE_D4, 500 },  { NOTE_E4, 1000 }, { NOTE_A4, 1000 }, { NOTE_FS4, 1000 }, { NOTE_G4, 2000 },                                   // And so on !
};

/*
 *  _                _          
 *| |              (_)         
 *| |    _   _ _ __ _  ___ ___ 
 *| |   | | | | '__| |/ __/ __|
 *| |___| |_| | |  | | (__\__ \
 *\_____/\__, |_|  |_|\___|___/
 *        __/ |                
 *       |___/                 
 */       
const char* pc_text_array[] = { "GAMEBUINO", "wishes", "you  ", "you a", "happy", "happy", "new", "year",  
                                "GAMEBUINO", "vous", "souhaite", "souhaite", "une", "une", "belle", "annee" ,
                                "GAMEBUINO", "wunscht", "euch    ", "euch ein", "frohes", "frohes", "neues", "Jahr" ,
                                "ta  ", "tata", "da", "ta", "da    ", "da da!", 
};
