
#include <stdio.h>

#include "SDL.h"
#include "gamestate.h"
#include "gameengine.h"
#include "playstate.h"
#include "menustate.h"

CPlayState CPlayState::m_PlayState;

void CPlayState::Init()
{
	SDL_Surface* temp = SDL_LoadBMP("play.bmp");

	bg = SDL_DisplayFormat(temp);

	SDL_FreeSurface(temp);

	printf("CPlayState Init\n");
}

void CPlayState::Cleanup()
{
	SDL_FreeSurface(bg);

	printf("CPlayState Cleanup\n");
}

void CPlayState::Pause()
{
	printf("CPlayState Pause\n");
}

void CPlayState::Resume()
{
	printf("CPlayState Resume\n");
}

void CPlayState::HandleEvents(CGameEngine* game)
{
	SDL_Event event;

	if (SDL_PollEvent(&event)) {
		switch (event.type) {
			case SDL_QUIT:
				game->Quit();
				break;

			case SDL_KEYDOWN:
				switch (event.key.keysym.sym) {
					case SDLK_ESCAPE:
						game->Quit();
						break;
					case SDLK_m:
						game->PushState( CMenuState::Instance() );
						break;
				}
				break;
		}
	}
}

void CPlayState::Update(CGameEngine* game)
{

}

void CPlayState::Draw(CGameEngine* game)
{
	SDL_BlitSurface(bg, NULL, game->screen, NULL);
	SDL_UpdateRect(game->screen, 0, 0, 0, 0);
}

