
#include "common.h"

#include "draw.h"
#include "init.h"
#include "input.h"
#include "main.h"

App app;
Entity player;

int main(int argc, char *argv[])
{
	memset(&app, 0, sizeof(App));
	memset(&player, 0, sizeof(Entity));

	initSDL();

	player.x = 100;
	player.y = 100;
	player.texture = loadTexture("gfx/player.png");
	player.h = getTextureHeight(player.texture);
	player.w = getTextureWidth(player.texture);

	atexit(cleanup);

	while (1)
	{
		prepareScene();

		doInput();

        if (app.up)
        {
            player.y -= 4;
            if (player.y < 0) {
                player.y = 0;
            }
        }

        if (app.down)
        {
            player.y += 4;
            if (player.y >= SCREEN_HEIGHT - player.h) {
                player.y = SCREEN_HEIGHT - player.h;
            }
        }

        if (app.left)
        {
            player.x -= 4;
            if (player.x < 0) {
                player.x = 0;
            }
        }

        if (app.right)
        {
            player.x += 4;
            if (player.x >= SCREEN_WIDTH - player.w) {
                player.x = SCREEN_WIDTH - player.w;
            }
        }

		blit(player.texture, player.x, player.y);

		presentScene();

		SDL_Delay(16);
	}

	return 0;
}
