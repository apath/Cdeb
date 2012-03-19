
//reste a faire avancer le joueur par pixel
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "main.h"


void jeux(SDL_Surface *ecran, SDL_Surface * texte, int argc, char *argv[], int score, TTF_Font *police, int continuer, int jtemp)
{
    SDL_Surface *terrain = NULL, *joueur, *mur, *ennemi;
    SDL_Rect posterrain, posjoueur, posmur, posennemi, posscore;
    SDL_Color couleurNoire = {0, 0, 0};
    char affiche[20] = "";
    int itemp = 0;


    police = TTF_OpenFont("forte.ttf", 20);
    texte = TTF_RenderText_Solid(police, affiche, couleurNoire);
    sprintf(affiche, "Temps : %d", score);
    posterrain.x = 0;
    posterrain.y = 0;

    posjoueur.x = 320;
    posjoueur.y = 240;

    posmur.x = 120;
    posmur.y = 140;
    posmur.h = 32;
    posmur.w = 32;

    posennemi.x = 600;
    posennemi.y = 300;

    posscore.x = 0;
    posscore.y = 0;

    SDL_Event event;
    int tempsPrecedent = 0, tempsActuel = 0;
    continuer = 1;

    terrain = IMG_Load("terrain..png");
    SDL_BlitSurface(terrain, NULL, ecran, &posterrain);

    joueur = IMG_Load("heros5.bmp");
    SDL_SetColorKey(joueur, SDL_SRCCOLORKEY, SDL_MapRGB(joueur->format, 255, 255, 255));
    SDL_BlitSurface(joueur, NULL, ecran, &posjoueur);

    ennemi = IMG_Load("ennemi.bmp");
    SDL_SetColorKey(ennemi, SDL_SRCCOLORKEY, SDL_MapRGB(ennemi->format, 255, 255, 255));
    SDL_BlitSurface(ennemi, NULL, ecran, &posennemi);
    SDL_BlitSurface(ennemi, NULL, ecran, &posennemi);

    mur = IMG_Load("mur.bmp");
    SDL_BlitSurface(mur, NULL, ecran, &posmur);

    SDL_Flip(ecran);

    SDL_EnableKeyRepeat(1, 1);

    while (continuer)
    {
        SDL_PollEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
                break;
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {
                    case SDLK_UP:

                    if(posjoueur.y - 32 == posmur.y && posjoueur.x + 32 > posmur.x && posjoueur.x < posmur.x + 32)
                    {

                    }
                    else{posjoueur.y--;}
                    printf("position du joueur : %d, position du mur", posjoueur.x, posmur.x);

                    break;

                    case SDLK_DOWN:
                    if(posjoueur.y + 32 == posmur.y && posjoueur.x + 32 > posmur.x && posjoueur.x < posmur.x + 32)
                    {

                    }
                    else{posjoueur.y++;}

                    break;

                    case SDLK_RIGHT:
                    if(posjoueur.x + 32 == posmur.x && posjoueur.y + 32 > posmur.y && posjoueur.y < posmur.y + 32)
                    {

                    }
                    else{posjoueur.x++;}
                    break;

                    case SDLK_LEFT:
                    if(posjoueur.x - 32 == posmur.x && posjoueur.y + 32 > posmur.y && posjoueur.y < posmur.y + 32)
                    {

                    }
                    else{posjoueur.x--;}
                    break;

                    case SDLK_p:
                    option(terrain, ecran, argc, argv, score, police, texte);
                    break;

                }




        }


        tempsActuel = SDL_GetTicks();
        if (tempsActuel - tempsPrecedent > 30) // Intelligence artificielle
        {
            if(posjoueur.x > posennemi.x && posjoueur.y > posennemi.y)
            {
                posennemi.x++;
                posennemi.y++;
            }

            else if(posjoueur.x < posennemi.x && posjoueur.y < posennemi.y)
            {
                posennemi.x--;
                posennemi.y--;
            }

            else if(posjoueur.x < posennemi.x && posjoueur.y > posennemi.y)
            {
                posennemi.x--;
                posennemi.y++;
            }

            else if(posjoueur.x > posennemi.x && posjoueur.y < posennemi.y)
            {
                posennemi.x++;
                posennemi.y--;
            }

            else if(posjoueur.x > posennemi.x)
            {
                posennemi.x++;
            }

            else if(posjoueur.x < posennemi.x)
            {
                posennemi.x--;
            }

            else if(posjoueur.y > posennemi.y)
            {
                posennemi.y++;
            }

            else if(posjoueur.y < posennemi.y)
            {
                posennemi.y--;
            }

            else
            {
                score = 0;
            }


            sprintf(affiche, "Score : %d, %d, %d", score, itemp, jtemp);
            texte = TTF_RenderText_Solid(police, affiche, couleurNoire);
            //SDL_FreeSurface(texte);
            tempsPrecedent = tempsActuel;
        }


        itemp = SDL_GetTicks();

        if (itemp - jtemp > 1000) // Intelligence artificielle
        {
            score++;
            jtemp = itemp;
        }        //fscore(ecran, texte, argc, argv, score, police, continuer, jtemp);



        SDL_BlitSurface(terrain, NULL, ecran, &posterrain);
        SDL_BlitSurface(joueur, NULL, ecran, &posjoueur);
        SDL_BlitSurface(ennemi, NULL, ecran, &posennemi);
        SDL_BlitSurface(mur, NULL, ecran, &posmur);
        SDL_BlitSurface(texte, NULL, ecran, &posscore); // a cause de cette ligne le jeu se ferme immediatement
        SDL_Flip(ecran);
        }


}

int fscore(SDL_Surface *ecran, SDL_Surface * texte, int argc, char *argv[], int score, TTF_Font *police, int continuer, int jtemp)
{

}
