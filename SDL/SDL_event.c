/******************************************************************************************
*Title: SDL EVENTS
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

int main(int argc, char *argv[])
{
    SDL_Surface *ecran = NULL;
    SDL_Surface *zozor = NULL;
    SDL_Rect positionZozor;
    SDL_Event event;
    int continuer = 1;

    SDL_Init(SDL_INIT_VIDEO);

    ecran = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE); /* Double Buffering + permet de resizer la fenetre */
    SDL_WM_SetCaption("Gestion des évènements en SDL", NULL);

    zozor = SDL_LoadBMP("zozor.bmp");
    SDL_SetColorKey(zozor, SDL_SRCCOLORKEY, SDL_MapRGB(zozor->format, 0, 0, 255));

    positionZozor.x = ecran->w / 2 - zozor->w / 2;
    positionZozor.y = ecran->h / 2 - zozor->h / 2;

    SDL_EnableKeyRepeat(10, 10); /* Activation de la répétition des touches */
    
    SDL_ShowCursor(SDL_DISABLE); /* Masquercurseur de la souris */

    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
       			continuer = 0;
        		break;
    		case SDL_MOUSEBUTTONUP: /* Clic de la souris */
    			if (event.button.button == SDL_BUTTON_LEFT)
    			{
    				positionZozor.x = event.button.x; /* On déplace Zozor selon ou on clic avec la souris */
            		positionZozor.y = event.button.y;
            	}
            case SDL_MOUSEMOTION: /* mouvement soouris */
            	positionZozor.x = event.motion.x; /* Coordoonnéees zozor se mettent à jour avec le déplacement de la souris */
            	positionZozor.y = event.motion.y;
    		   if (event.button.button == SDL_BUTTON_RIGHT)
    		   {  /*On arrête le programme si on a fait un clic droit */
                    continuer = 0;
               }               
        		break;
        	case SDL_VIDEORESIZE:
   				positionZozor.x = event.resize.w / 2 - zozor->w / 2;
    			positionZozor.y = event.resize.h / 2 - zozor->h / 2;
    			break;
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {
                    case SDLK_UP:
                        positionZozor.y--;
                        break;
                    case SDLK_DOWN:
                        positionZozor.y++;
                        break;
                    case SDLK_RIGHT:
                        positionZozor.x++;
                        break;
                    case SDLK_LEFT:
                        positionZozor.x--;
                        break;
                }
                break;
        }

        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
        SDL_BlitSurface(zozor, NULL, ecran, &positionZozor);
        SDL_Flip(ecran);
    }

    SDL_FreeSurface(zozor);
    SDL_Quit();

    return SUCCESS;
}

void Pause()
{
	SDL_Event event;
	int continuer = 1;
	
	while (continuer)
	{
   		SDL_WaitEvent(&event);
    	switch(event.type)
    	{
    	    case SDL_QUIT:
    	    {
    	        continuer = 0;
    	        break;
    	    }
    	    case SDL_KEYDOWN:
    	    {
            	switch (event.key.keysym.sym)
            	{
                	case SDLK_ESCAPE: /* Appui sur la touche Echap, on arrête le programme */
                	{
                    	continuer = 0;
                    	break;
                    }
            	}
            	break;
           	}
    	}
	}	
}


