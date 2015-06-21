#include <PWMAudio.h>
#include "gameover.h"

// Set this to be any PWM channel on your board.
#define AUDIO 8

PWMAudio sound(AUDIO, 11025);

void setup()
{
	// Slower chips (MX1/MX2) squeal at higher bit depths.  The
	// default is 12 - we'll reduce it to 10 for this. On a faster
	// board you can leave it at the default of 12.
	sound.setBitDepth(10);

	// It's important that, if you set the bit depth, you do it before
	// you begin the PWMAudio instance, since it sets values that are
	// used during initialization.
	sound.begin();

	// Now we'll just queue our sample to be played in the background.
	// The sample data is stored in the "gameover" array, and is
	// "gameover_len" samples long.  We don't want a delay, (first 0) 
	// nor any change in playback speed (second 0).
	sound.queueSample(gameover, gameover_len, 0, 0);
}

void loop()
{
	// Nothing to do in the loop - it's all timer and interrupt driven.
}
