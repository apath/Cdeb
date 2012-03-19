// reste a faire bouger le choix en faisant un -100 en y avec la fleche en bas et un +100 avec la fleche de haut
// faire bouger le joueur dans le .c
// faire la collision avec l'ennemi
// faire l'option pause
// faire dans l'option continuer, quitter, aide, recommencer et options


#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL/SDL_ttf.h>
#include "main.h"


void pause();

int main(int argc, char *argv[])
{
    SDL_Surface *ecran = NULL, *jouer = NULL, *quitter = NULL, *imagedefond = NULL, *choix = NULL, *texte = NULL;
    SDL_Rect posjouer, posquit, posfond, poschoix;
    TTF_Font *police = NULL;
    int jtemp = 0;


    posfond.x = 0;
    posfond.y = 0;

    posjouer.x = 240;
    posjouer.y = 240;
                                //position
    posquit.x = 240;
    posquit.y = 340;

    poschoix.x = 240;
    poschoix.y = 240;

    int score = 0;

    SDL_Init(SDL_INIT_VIDEO | SDL_DOUBLEBUF);
    TTF_Init();

    SDL_WM_SetIcon(SDL_LoadBMP("icone.bmp"), NULL); // icone

    ecran = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE);
    SDL_WM_SetCaption("jeux", NULL); //titre

    imagedefond = IMG_Load("menu.jpg"); // fond d'ecran
    SDL_BlitSurface(imagedefond, NULL, ecran, &posfond);


    choix = IMG_Load("choix2.bmp"); // rectangle orange
    SDL_SetColorKey(choix, SDL_SRCCOLORKEY, SDL_MapRGB(choix->format, 255, 255, 255));
    SDL_BlitSurface(choix, NULL, ecran, &poschoix);

    jouer = IMG_Load("jouer.gif"); // jouer
    // SDL_SetColorKey(jouer, SDL_SRCCOLORKEY, SDL_MapRGB(jouer->format, 255, 255, 255));
    SDL_BlitSurface(jouer, NULL, ecran, &posjouer);

    quitter = SDL_LoadBMP("quitter.bmp"); // quitter
    // SDL_SetColorKey(quitter, SDL_SRCCOLORKEY, SDL_MapRGB(quitter->format, 255, 255, 255));
    SDL_BlitSurface(quitter, NULL, ecran, &posquit);



    SDL_Flip(ecran);

    int continuer = 1;
    SDL_Event event;
    int carre = 1; // 1 = haut, 2 = bas

    while (continuer) // boucle pause
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
                    case SDLK_KP_ENTER: // pour le pc portable SDL_kp_enter et SDLK_RETURN pour le fixe
                    if(carre == 1)
                    {
                        jeux(ecran, argc, argv, score, police, texte, continuer, jtemp);
                    }
                    else if(carre == 2)
                    {
                        continuer = 0;
                    }
                        break;

                    case SDLK_DOWN:
                    if(carre == 1)
                    {
                        poschoix.y += 100;
                        carre = 2;
                    }
                    else{}
                        break;

                    case SDLK_UP:
                    if(carre == 2)
                    {
                        poschoix.y -= 100;
                        carre = 1;
                    }

                    else{}

                        break;
                }
        }
        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
        SDL_BlitSurface(imagedefond, NULL, ecran, &posfond);
        SDL_BlitSurface(jouer, NULL, ecran, &posjouer);

        SDL_BlitSurface(quitter, NULL, ecran, &posquit);
        SDL_BlitSurface(choix, NULL, ecran, &poschoix);
        SDL_Flip(ecran);

    }

    SDL_FreeSurface(imagedefond);
    SDL_FreeSurface(jouer);
    SDL_FreeSurface(quitter);
    SDL_FreeSurface(choix);
    TTF_CloseFont(police);
    TTF_Quit();
    SDL_Quit();

    return EXIT_SUCCESS;
}

void pause()
{

}

