#include <stdlib.h>

#include <SDL/SDL.h>

#include <SDL/SDL_image.h>

#include <SDL/SDL_mixer.h>

#include <SDL/SDL_ttf.h>

#include "enigme.h"


int main() {
  int continuer = 1;
SDL_Surface * ecran = NULL;
SDL_Surface * imagebg = NULL;

SDL_Event event;

SDL_Rect posecran;

posecran.x = 0;
posecran.y = 0;

enigme e;
  



if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    printf("Unable to initialize SDL : %s\n", SDL_GetError());
    return 1;
  }
  ecran = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
  if (ecran == NULL) {
    printf("Unable to set video mode:%s\n", SDL_GetError());
    return 1;
  }
  imagebg = IMG_Load("imagebg.png");
  if (imagebg == NULL) {
    printf("Unable to load bg : %s\n", SDL_GetError());
    return 1;
  }






while (continuer)
{
SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran -> format, 255, 255, 255));
   SDL_BlitSurface(imagebg, NULL, ecran, & posecran);
/*if (interface=niveau)*/
genererEnigme(&fichier_enigme);
afficher_enigme(e);
resolution(e);
}

SDL_FreeSurface(ecran);
SDL_Quit();
return 0;
}





