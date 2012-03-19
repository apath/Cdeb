#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

int main(int argc, char *argv[]);
void jeux(SDL_Surface *ecran, SDL_Surface * texte, int argc, char *argv[], int score, TTF_Font *police, int continuer, int jtemp);
void option(SDL_Surface *terrain, SDL_Surface *ecran, SDL_Surface * texte, int argc, char *argv[], int score, TTF_Font *police);
void haide(SDL_Surface *ecran, SDL_Surface * texte, int argc, char *argv[], int score, TTF_Font *police);
int fscore(SDL_Surface *ecran, SDL_Surface * texte, int argc, char *argv[], int score, TTF_Font *police, int continuer, int jtemp);

#endif // MAIN_H_INCLUDED
