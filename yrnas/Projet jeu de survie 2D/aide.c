#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "main.h"

void haide(SDL_Surface *ecran, SDL_Surface * texte, int argc, char *argv[], int score, TTF_Font *police)
{
    SDL_Surface *aide;
    SDL_Rect posaide;

    posaide.x = 320 - 125;
    posaide.y = 240 - 75;

    int continuer = 1;
    SDL_Event event;

    aide = IMG_Load("imgaide2.bmp");
    SDL_SetColorKey(aide, SDL_SRCCOLORKEY, SDL_MapRGB(aide->format, 255, 255, 255));
    SDL_BlitSurface(aide, NULL, ecran, &posaide);

   while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
            break;
        }

        SDL_BlitSurface(aide, NULL, ecran, &posaide);
        SDL_Flip(ecran);
    }
}
