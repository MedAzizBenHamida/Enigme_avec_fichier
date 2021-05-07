#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "enigme.h"

/*********************************************************/
enigme genererEnigme(char *fichier_enigme.txt)
{
enigme e;
int i=1,q,r;
FILE *f=NULL;


f=fopen(fichier_enigme.txt,"r");

q=rand()%8;
r=rand()%8;
while(fscanf(f,"%s",e->Quest)!=EOF)
{
 if (i==q)
{ if((i%2)==0)
{
e->etat=1;
}
else{
e->etat=2;
}
break;
}else 
i++;
}




fclose(f);
return enigme;
}


/*********************************************************/
void afficher_enigme(enigme e)
{
SDL_Surface * Question = NULL;
SDL_Surface * Reponse1= NULL;
SDL_Surface * Reponse2= NULL;
SDL_Surface * ecran = NULL;
SDL_Surface * imagebg = NULL;

Mix_Music * music;


SDL_Rect posQ;
SDL_Rect posR1;
SDL_Rect posR2;
SDL_Rect posecran;

TTF_Font * police = NULL;
SDL_Color couleurblanc = {255,255,255};
TTF_Init();


posecran.x=0;
posecran.y=0;

posQ.x = 100;
posQ.y = 100;

posR1.x = 150;
posR1.y = 200;

posR2.x = 150;
posR2.y = 300;


music = Mix_LoadMUS("music.mp3");
if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)
{
printf("%s", Mix_GetError());
}

imagebg=IMG_Load("imagebg.png");

police = TTF_OpenFont("amatic.ttf", 80);

Question = TTF_RenderText_Blended(police,e.Quest, couleurblanc);
Reponse1 = TTF_RenderText_Blended(police,"VRAI", couleurblanc);
Reponse2= TTF_RenderText_Blended(police,"FAUX", couleurblanc);

SDL_BlitSurface(imagebg, NULL, ecran, &posecran);
SDL_BlitSurface(Question, NULL, ecran, &posQ);
SDL_BlitSurface(Reponse1, NULL, ecran, &posR1);
SDL_BlitSurface(Reponse2, NULL, ecran, &posR2);

Mix_PlayMusic(music, -1);

SDL_FreeSurface(Question);
SDL_FreeSurface(Reponse1);
SDL_FreeSurface(Reponse2);

TTF_CloseFont(police);
SDL_FreeSurface(Question);
SDL_FreeSurface(Reponse1);
SDL_FreeSurface(Reponse2);
Mix_FreeMusic(music);
Mix_CloseAudio();


}

/*********************************************************/
void resolution(enigme e)
{
int choix,j;
SDL_Event event;

SDL_Surface * succ = NULL;
SDL_Surface * ecran = NULL;
SDL_Surface * echec= NULL;

SDL_Rect position;



position.x = 100;
position.y = 100;


succ= IMG_Load("succ.png");
echec= IMG_Load("echec.png");


SDL_WaitEvent(&event);
switch(event.type)
{
case SDL_KEYDOWN:
	switch(event.key.keysym.sym)
	{
	case SDLK_KP1:
         choix=(1-e.etat);
 	break;
	case SDLK_KP2 :
	choix=(2-e.etat);
	break;
	
	}
	break;
       }break;
if(choix==0)
{
/*p->pv+=15;
p->score+=50;*/
SDL_BlitSurface(succ,NULL,ecran,&position);
}
else
{
/*p->score-=25;*/
SDL_BlitSurface(echec,NULL,ecran,&position);

}

SDL_FreeSurface(succ);
SDL_FreeSurface(echec);
}
/*********************************************************/






















