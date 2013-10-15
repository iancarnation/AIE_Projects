
#include <stdio.h>

#include "SDL.h"
#include "gameengine.h"
#include "gamestate.h"
#include "introstate.h"
#include "playstate.h"

CIntroState CIntroState::m_IntroState;

void CIntroState::Init()
{
	SDL_Surface* temp = SDL_LoadBMP("intro.bmp");

	bg = SDL_DisplayFormat(temp);

	SDL_FreeSurface(temp);

	// create the fader surface like the background with alpha
	fader = SDL_CreateRGBSurface( SDL_SRCALPHA, bg->w, bg->h, 
								  bg->format->BitsPerPixel, 
								  bg->format->Rmask, bg->format->Gmask, 
								  bg->format->Bmask, bg->format->Amask );

	// fill the fader surface with black
	SDL_FillRect (fader, NULL, SDL_MapRGB (bg->format, 0, 0, 0)) ;

	// start off opaque
	alpha = 255;

	SDL_SetAlpha(fader, SDL_SRCALPHA, alpha);

	printf("CIntroState Init\n");
}

void CIntroState::Cleanup()
{
	SDL_FreeSurface(bg);
	SDL_FreeSurface(fader);

	printf("CIntroState Cleanup\n");
}

void CIntroState::Pause()
{
	printf("CIntroState Pause\n");
}

void CIntroState::Resume()
{
	printf("CIntroState Resume\n");
}

void CIntroState::HandleEvents(CGameEngine* game)
{
	SDL_Event event;

	if (SDL_PollEvent(&event)) {
		switch (event.type) {
			case SDL_QUIT:
				game->Quit();
				break;

			case SDL_KEYDOWN:
				switch (event.key.keysym.sym) {
					case SDLK_SPACE:
						game->ChangeState( CPlayState::Instance() );
						break;

					case SDLK_ESCAPE:
						game->Quit();
						break;
				}
				break;
		}
	}
}

void CIntroState::Update(CGameEngine* game) 
{
	alpha--;

	if (alpha < 0)
		alpha = 0;

	SDL_SetAlpha(fader, SDL_SRCALPHA, alpha);
}

void CIntroState::Draw(CGameEngine* game) 
{
	SDL_BlitSurface(bg, NULL, game->screen, NULL);

	// no need to blit if it's transparent
	if ( alpha != 0 )
		SDL_BlitSurface(fader, NULL, game->screen, NULL);

	SDL_UpdateRect(game->screen, 0, 0, 0, 0);
}
