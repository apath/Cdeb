#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "main.h"


void option(SDL_Surface *terrain, SDL_Surface *ecran, SDL_Surface * texte, int argc, char *argv[], int score, TTF_Font *police)
{
    SDL_Surface *option, *choix, *cont, *quit, *aide, *retry;
    SDL_Rect posoption, poschoix, poscontinue, posquit, posaide, posretry;

    int continuer = 1;
    int jtemp = 0;
    SDL_Event event;
    int carre = 1;

    posoption.x = 320 - 50;
    posoption.y = 240 - 50;

    poschoix.x = 320 - 50;
    poschoix.y = 240 - 50;

    poscontinue.x = 320 - 50;
    poscontinue.y = 240 - 50;

    posretry.x = 320 - 50;
    posretry.y = 240 - 0;

    posaide.x = 320 - 50;
    posaide.y = 240 + 50;

    posquit.x = 320 - 50;
    posquit.y = 240 + 100;

    option = IMG_Load("option.bmp");
    SDL_BlitSurface(option, NULL, ecran, &posoption);

    choix = IMG_Load("choix2.bmp");
    SDL_SetColorKey(choix, SDL_SRCCOLORKEY, SDL_MapRGB(choix->format, 255, 255, 255));
    SDL_BlitSurface(choix, NULL, ecran, &poschoix);

    cont = IMG_Load("continuer.bmp");
    SDL_SetColorKey(cont, SDL_SRCCOLORKEY, SDL_MapRGB(cont->format, 255, 255, 255));
    SDL_BlitSurface(cont, NULL, ecran, &poscontinue);

    retry = IMG_Load("reessayer.bmp");
    SDL_SetColorKey(retry, SDL_SRCCOLORKEY, SDL_MapRGB(retry->format, 255, 255, 255));
    SDL_BlitSurface(retry, NULL, ecran, &posretry);

    aide = IMG_Load("aide.bmp");
    SDL_SetColorKey(aide, SDL_SRCCOLORKEY, SDL_MapRGB(aide->format, 255, 255, 255));
    SDL_BlitSurface(aide, NULL, ecran, &posaide);

    quit = IMG_Load("quitter.bmp");
    SDL_SetColorKey(quit, SDL_SRCCOLORKEY, SDL_MapRGB(quit->format, 255, 255, 255));
    SDL_BlitSurface(quit, NULL, ecran, &posquit);

    SDL_EnableKeyRepeat(10000, 10000);

   while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
                break;

            case SDL_KEYDOWN:
               switch (event.key.keysym.sym)
               {
                case SDLK_UP:
                    if(carre == 1)
                    {

                    }
                    else
                    {
                        poschoix.y -= 50;
                        carre--;
                    }

                break;

                case SDLK_DOWN:
                    if(carre > 4)
                    {

                    }
                    else
                    {
                        poschoix.y += 50;
                        carre++;
                    }
                break;

                case SDLK_KP_ENTER:
                    if(carre == 1)
                    {
                        continuer = 0;
                    }
                    else if(carre == 2)
                    {
                        return jeux(ecran, texte, argc, argv, score, police, continuer, jtemp);
                    }
                    else if(carre == 3)
                    {
                        haide(ecran, texte, argc, argv, score, police);
                    }

                    else if(carre == 4)
                    {
                        return main(argc, argv);
                    }
                break;
               }

            break;
        }

        SDL_BlitSurface(option, NULL, ecran, &posoption);
        SDL_BlitSurface(cont, NULL, ecran, &poscontinue);
        SDL_BlitSurface(retry, NULL, ecran, &posretry);
        SDL_BlitSurface(aide, NULL, ecran, &posaide);
        SDL_BlitSurface(quit, NULL, ecran, &posquit);
        SDL_BlitSurface(choix, NULL, ecran, &poschoix);
        SDL_Flip(ecran);

    }
}
