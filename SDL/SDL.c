/******************************************************************************************
*Title: SDL
*Author : 
*Reviewer: 
*Description:
*Status: in developpment
*****************************************************************************************/
#include <SDL/SDL.h> /* SDL */
#include <stdio.h> /* printf / stderr */

void Pause();

enum end_prog
{
	SUCCESS = 0, FAILED = 1
};

int main(void)
{

    SDL_Surface *ecran = NULL; /* Le pointeur qui va stocker la surface de l'écran */
    SDL_Rect position; /* Position x et y pour l'écran qu'on va incorporer au premier */
    SDL_Surface *lignes[256] = {NULL};
    int i = 0;
    
    SDL_Init(SDL_INIT_VIDEO); /* Télécharger bibliothèque vidéo */

    ecran = SDL_SetVideoMode(640, 256, 32, SDL_HWSURFACE); /* On tente d'ouvrir une fenêtre. La fonction SetVideo renvoie un pointeur. 
    														HWSURFACE veut dire que l'écran est chargé en mémoire vidéo plus rapide mais moins grande */
    
    if (ecran == NULL) /* Si l'ouverture a échoué, on le note et on arrête */
    {
        fprintf(stderr, "Impossible de charger le mode vidéo : %s\n", SDL_GetError());
        exit(FAILED);
    }
    
     for (i = 256; i > 0; i--)
    {
    	lignes[i] = SDL_CreateRGBSurface(SDL_HWSURFACE, 640, 1, 32, 0, 0, 0, 0);    
   	}
        
    SDL_WM_SetCaption("Mon dégradé de couleurs !", NULL); /* Donner nom a une fenetre */
    
    SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0)); /* Fillrect remplit l'écran avec une couleur et MapRGB initialise la couleur avec le Rouge, B et V */  
    
    for (i = 256; i > 0; i--)
    {
    	position.x = 0; /* lignes sont à gauche */
    	position.y = i; /* La position verticale dépend du numéro de la ligne */ 
    	
    	SDL_FillRect(lignes[i], NULL, SDL_MapRGB(ecran->format, i, i, i)); /* dessin */
    	SDL_BlitSurface(lignes[i], NULL, ecran, &position); /* collage */
    }

    SDL_Flip(ecran); /* Mise à jour de l'écran avec nouvelle couleur*/
    Pause(); /* Fonction qui met en pause le programme */
    
    for (i = 256; i > 0; i--)
    {
    	SDL_FreeSurface(lignes[i]);
   	}
    

    SDL_Quit(); /* Désallouer la mémoire allouée par INIT */

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
