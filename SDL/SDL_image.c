/******************************************************************************************
*Title: Lecture Data Variable
*Author : 
*Reviewer: 
*Description:
*Status: in developpment
*****************************************************************************************/
#include <SDL2/SDL.h> /* SDL */
#include <SDL/SDL_image.h> /* Inclusion du header de SDL_image (adapter le dossier au besoin) */
#include <stdio.h> /* printf / stderr */

void Pause();

enum end_prog
{
	SUCCESS = 0, FAILED = 1
};

int main(int argc, char *argv[])
{
   	SDL_Surface *ecran = NULL;
   	SDL_Surface *imageDeFond = NULL;
   	SDL_Surface *zozor = NULL;
    SDL_Rect positionFond, positionZozor;

    positionFond.x = 0;
    positionFond.y = 0;
    positionZozor.x = 500;
    positionZozor.y = 260;

    SDL_Init(SDL_INIT_VIDEO);

    /*SDL_WM_SetIcon(SDL_LoadBMP("sdl_icone.bmp"), NULL);*/

    ecran = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE);
    SDL_WM_SetCaption("Chargement d'images en SDL", NULL);

    imageDeFond = SDL_LoadBMP("lac_en_montagne.bmp");
    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);

    /* Chargement et blittage de Zozor sur la scène */
    zozor = SDL_LoadBMP("zozor.bmp");
    /* On rend le bleu derrière Zozor transparent : */
	SDL_SetColorKey(zozor, SDL_SRCCOLORKEY, SDL_MapRGB(zozor->format, 0, 0, 255));
	/* Transparence de l'image sans son fond. 128 est une valeur moyenne optimale */
	SDL_SetAlpha(zozor, SDL_SRCALPHA, 128);
    SDL_BlitSurface(zozor, NULL, ecran, &positionZozor);

    SDL_Flip(ecran);
    Pause();

    SDL_FreeSurface(imageDeFond);
    SDL_FreeSurface(zozor);
    SDL_Quit();

    return SUCCESS;
}

void Pause()
{
    int continuer = 1;
    SDL_Event event;
 
    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
        }
    }
}





