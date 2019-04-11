
#include <stdio.h>
#include "SDL/SDL.h"
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include<SDL/SDL_ttf.h>
#include"fonction.h"

void init_objet(objet *o,SDL_Surface *ecran)

{
//SDL_Init(SDL_INIT_VIDEO);

// ecran = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE);
SDL_WM_SetCaption("Chargement d'images en SDL", NULL);
SDL_Rect positionecran;

positionecran.x = 0;
positionecran.y = 0;

o->position1.x = 100;
o->position1.y = 70;
o->position2.x = 200;
o->position2.y = 70;
 
o->image1=SDL_LoadBMP("/home/maryem/Banana Tree.png");
o->image2=IMG_Load("/home/maryem/rock.bmp");


}

void afficherobjet(objet *o,SDL_Surface *ecran)
{

SDL_BlitSurface(o->image1,NULL,ecran,&o->position1);
SDL_BlitSurface(o->image2, NULL, ecran,&o->position2);

// On blitte par-dessus l'écran
SDL_Flip(ecran);
pause();

//SDL_FreeSurface(imageDeFond); /* On libère la surface */
// SDL_Quit();


}

void mouvement(SDL_Event event,SDL_Rect *posplayer,int *game)
{int directionSDL;
  SDL_EnableKeyRepeat(SDL_DEFAULT_REPEAT_DELAY,SDL_DEFAULT_REPEAT_INTERVAL);
  while(SDL_PollEvent(&event)){
        switch (event.type)
        {
        // exit if the window is closed
        case SDL_QUIT:
            *game = 0;
            break;
        case SDL_KEYDOWN:
        {

            if (event.key.keysym.sym == SDLK_d)
              directionSDL = 1;

            if (event.key.keysym.sym == SDLK_q)
              directionSDL = 2;
            if(event.key.keysym.sym==SDLK_z)
               directionSDL=3;
           if(event.key.keysym.sym==SDLK_s)
             directionSDL=4;
        }
        break;
        case SDL_KEYUP:
          directionSDL=0;
        break;

        }
        if(directionSDL == 1){
          posplayer->x+=10;
        }
        if(directionSDL == 2){
          posplayer->x-=10;
        }
          if(directionSDL == 3){
            posplayer->y-=10;
          }
            if(directionSDL == 4){
              posplayer->y+=10;
            }
      }

}


void mouvementaletoire(SDL_Rect *posenemy,int *game,int *test)
{ *test=1;


 if(*test==1)
 {
   posenemy->x+=1;
      SDL_Delay(10);
      if(posenemy->x==500)
      *test=2;
 }
if(*test==2)
 {
   posenemy->x-=1;
      SDL_Delay(10);
      if(posenemy->x==200)
      *test=1;
 }

}


int clavier (char pause ){

if(SDL_Init(SDL_INIT_VIDEO)!=0){
printf("Unable to initialize SDL:%s\n",SDL_GetError());
return 1;
}
SDL_Surface *screen;
SDL_Surface *image;
SDL_Surface *personnage;
SDL_Rect positionecran;
SDL_Rect positionpersonnage;
SDL_Event event;
screen=SDL_SetVideoMode(600,400,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
if (screen==NULL){
printf("Unable to set 600x400 video: %s\n",SDL_GetError());
return 1;
}

image =SDL_LoadBMP("nature.bmp");

if (image==NULL){
printf("Unable to load bitmap: %s\n",SDL_GetError());
return 1;
}
personnage = IMG_Load("player.png");
positionecran.x = 0;
positionecran.y = 0;
positionpersonnage.x = 100;
positionpersonnage.y = 260;
if (personnage==NULL){
printf("Unable to load png: %s\n",SDL_GetError());
return 1;
}

int done =1 ;
while(done)
{


SDL_BlitSurface(image,NULL,screen,&positionecran);

SDL_BlitSurface(personnage,NULL,screen,&positionpersonnage);

while(SDL_PollEvent(&event))
{
switch(event.type)
{
case SDL_QUIT:
done= 0;
break;

case SDL_KEYDOWN:
 { switch (event.key.keysym.sym) {
   case SDLK_ESCAPE:
   done =0;
   break;
   case SDLK_s:
     positionpersonnage.y=positionpersonnage.y+10;
     break;
   case SDLK_z:
   positionpersonnage.y=positionpersonnage.y-10;
     break;
   case SDLK_d:
   positionpersonnage.x=positionpersonnage.x+10;
  break;
   case SDLK_q:
   positionpersonnage.x=positionpersonnage.x-10;
    break;}
 }
}
}



SDL_Flip(screen);

}


SDL_FreeSurface(image);
SDL_FreeSurface(personnage);
pause= getchar();
return 0;
}


int souris  (char pause  )
{

  
if(SDL_Init(SDL_INIT_VIDEO)!=0){
printf("Unable to initialize SDL:%s\n",SDL_GetError());
return 1;
}
SDL_Surface *screen;
SDL_Surface *image;
SDL_Surface *personnage;
SDL_Rect positionecran;
SDL_Rect positionpersonnage; 

screen=SDL_SetVideoMode(600,400,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
if (screen==NULL){
printf("Unable to set 600x400 video: %s\n",SDL_GetError());
return 1;
}

image =SDL_LoadBMP("nature.bmp");

if (image==NULL){
printf("Unable to load bitmap: %s\n",SDL_GetError());
return 1;
}
personnage = IMG_Load("player.png");
positionecran.x = 0;
positionecran.y = 0;
positionpersonnage.x = 100;
positionpersonnage.y = 260;
if (personnage==NULL){
printf("Unable to load png: %s\n",SDL_GetError());
return 1;
}

int done =1 ;
while(done)
{


SDL_BlitSurface(image,NULL,screen,&positionecran);

SDL_BlitSurface(personnage,NULL,screen,&positionpersonnage);

while(SDL_PollEvent(&event))
{
switch(event.type)
{
case SDL_QUIT:
done= 0;
break;


 
case SDL_MOUSEBUTTONDOWN:

if(event.button.button==SDL_BUTTON_LEFT)
{ 

        

case SDL_MOUSEMOTION:
            positionpersonnage.x = event.motion.x;
            positionpersonnage.y = event.motion.y;
            break;


case SDL_MOUSEBUTTONUP:
            // On arrête le programme si on a fait un clic droit
            if ( event.button.button == SDL_BUTTON_RIGHT )
                done = 0;
            else {
                positionpersonnage.x = event.button.x;
                positionpersonnage.y = event.button.y;
                }

            break;
break;
}
}


}


SDL_Flip(screen);

}


SDL_FreeSurface(image);
SDL_FreeSurface(personnage);
pause= getchar();
return 0;
}

