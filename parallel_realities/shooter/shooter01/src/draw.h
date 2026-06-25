
void prepareScene(void);
void presentScene(void);

SDL_Texture *loadTexture(char *filename);
int getTextureWidth(SDL_Texture *texture);
int getTextureHeight(SDL_Texture *texture);

void blit(SDL_Texture *texture, int x, int y);
