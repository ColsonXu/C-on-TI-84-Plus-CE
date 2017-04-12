/* Keep these headers */
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <tice.h>

/* Standard headers - it's recommended to leave them included */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Shared libraries */
#include <graphx.h>

/* Include the sprite data */
#include "gfx/logo_gfx.h"

/* Put function prototypes here */

/* Put all your code here */
void main(void) {
    /* Initialize the 8bpp graphics */
    gfx_Begin( gfx_8bpp );
    
    /* Set up the palette for our sprites */
    gfx_SetPalette( logo_gfx_pal, sizeof(logo_gfx_pal), 0);
    
    /* Fill the screen with color index 0 */
    gfx_FillScreen( 0 );

    /* Draw a bunch of different styled sprites on the screen */
    
    gfx_TransparentSprite_NoClip( ubuntu, 96, 96 );
    
    /* Wait for a key to be pressed */
    while( !os_GetCSC() );
    
    /* Close the graphics and return to the OS */
    gfx_End();
    prgm_CleanUp();
}
