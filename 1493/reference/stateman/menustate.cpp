
#include <stdio.h>

#include "SDL.h"
#include "gameengine.h"
#include "gamestate.h"
#include "menustate.h"

CMenuState CMenuState::m_MenuState;

void CMenuState::Init()
{
	SDL_Surface* temp = SDL_LoadBMP("menu.bmp");

	bg = SDL_DisplayFormat(temp);

	SDL_FreeSurface(temp);

	printf("CMenuState Init\n");
}

void CMenuState::Cleanup()
{
	SDL_FreeSurface(bg);

	printf("CMenuState Cleanup\n");
}

void CMenuState::Pause()
{
	printf("CMenuState Pause\n");
}

void CMenuState::Resume()
{
	printf("CMenuState Resume\n");
}

void CMenuState::HandleEvents(CGameEngine* game)
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
						game->PopState();
						break;
				}
				break;
		}
	}
}

void CMenuState::Update(CGameEngine* game) 
{

}

void CMenuState::Draw(CGameEngine* game) 
{
	SDL_BlitSurface(bg, NULL, game->screen, NULL);
	SDL_UpdateRect(game->screen, 0, 0, 0, 0);
}
