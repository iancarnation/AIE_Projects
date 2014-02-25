//////////////////////////////////////////////////////////////////////////
//	Author:	Jamie Stewart
//	Date:	12/11/2012
//	Brief:	This is the main entry point for access to the functionality provided by the 
//			AIE Static OpenGL Framework.
//////////////////////////////////////////////////////////////////////////
#ifndef _AIE_H_
#define _AIE_H_
//////////////////////////////////////////////////////////////////////////

#define DLLEXPORT __declspec(dllexport)


typedef enum
{
	MOUSE_BUTTON_1 = 0,
	MOUSE_BUTTON_2 = 1,
	MOUSE_BUTTON_3 = 2,
	KEY_SPACE	   = 32,
	KEY_SPECIAL	   = 256,
	KEY_ESC        = (KEY_SPECIAL+1),
	KEY_F1         = (KEY_SPECIAL+2),
	KEY_F2         = (KEY_SPECIAL+3),
	KEY_F3         = (KEY_SPECIAL+4),
	KEY_F4         = (KEY_SPECIAL+5),
	KEY_F5         = (KEY_SPECIAL+6),
	KEY_F6         = (KEY_SPECIAL+7),
	KEY_F7         = (KEY_SPECIAL+8),
	KEY_F8         = (KEY_SPECIAL+9),
	KEY_F9         = (KEY_SPECIAL+10),
	KEY_F10        = (KEY_SPECIAL+11),
	KEY_F11        = (KEY_SPECIAL+12),
	KEY_F12        = (KEY_SPECIAL+13),
	KEY_F13        = (KEY_SPECIAL+14),
	KEY_F14        = (KEY_SPECIAL+15),
	KEY_F15        = (KEY_SPECIAL+16),
	KEY_F16        = (KEY_SPECIAL+17),
	KEY_F17        = (KEY_SPECIAL+18),
	KEY_F18        = (KEY_SPECIAL+19),
	KEY_F19        = (KEY_SPECIAL+20),
	KEY_F20        = (KEY_SPECIAL+21),
	KEY_F21        = (KEY_SPECIAL+22),
	KEY_F22        = (KEY_SPECIAL+23),
	KEY_F23        = (KEY_SPECIAL+24),
	KEY_F24        = (KEY_SPECIAL+25),
	KEY_F25        = (KEY_SPECIAL+26),
	KEY_UP         = (KEY_SPECIAL+27),
	KEY_DOWN       = (KEY_SPECIAL+28),
	KEY_LEFT       = (KEY_SPECIAL+29),
	KEY_RIGHT      = (KEY_SPECIAL+30),
	KEY_LSHIFT     = (KEY_SPECIAL+31),
	KEY_RSHIFT     = (KEY_SPECIAL+32),
	KEY_LCTRL      = (KEY_SPECIAL+33),
	KEY_RCTRL      = (KEY_SPECIAL+34),
	KEY_LALT       = (KEY_SPECIAL+35),
	KEY_RALT       = (KEY_SPECIAL+36),
	KEY_TAB        = (KEY_SPECIAL+37),
	KEY_ENTER      = (KEY_SPECIAL+38),
	KEY_BACKSPACE  = (KEY_SPECIAL+39),
	KEY_INSERT     = (KEY_SPECIAL+40),
	KEY_DEL        = (KEY_SPECIAL+41),
	KEY_PAGEUP     = (KEY_SPECIAL+42),
	KEY_PAGEDOWN   = (KEY_SPECIAL+43),
	KEY_HOME       = (KEY_SPECIAL+44),
	KEY_END        = (KEY_SPECIAL+45),
	KEY_KP_0       = (KEY_SPECIAL+46),
	KEY_KP_1       = (KEY_SPECIAL+47),
	KEY_KP_2       = (KEY_SPECIAL+48),
	KEY_KP_3       = (KEY_SPECIAL+49),
	KEY_KP_4       = (KEY_SPECIAL+50),
	KEY_KP_5       = (KEY_SPECIAL+51),
	KEY_KP_6       = (KEY_SPECIAL+52),
	KEY_KP_7       = (KEY_SPECIAL+53),
	KEY_KP_8       = (KEY_SPECIAL+54),
	KEY_KP_9       = (KEY_SPECIAL+55),
	KEY_KP_DIVIDE  = (KEY_SPECIAL+56),
	KEY_KP_MULTIPLY= (KEY_SPECIAL+57),
	KEY_KP_SUBTRACT= (KEY_SPECIAL+58),
	KEY_KP_ADD     = (KEY_SPECIAL+59),
	KEY_KP_DECIMAL = (KEY_SPECIAL+60),
	KEY_KP_EQUAL   = (KEY_SPECIAL+61),
	KEY_KP_ENTER   = (KEY_SPECIAL+62),
	KEY_KP_NUM_LOCK= (KEY_SPECIAL+63),
	KEY_CAPS_LOCK  = (KEY_SPECIAL+64),
	KEY_SCROLL_LOCK= (KEY_SPECIAL+65),
	KEY_PAUSE      = (KEY_SPECIAL+66),
	KEY_LSUPER     = (KEY_SPECIAL+67),
	KEY_RSUPER     = (KEY_SPECIAL+68),
	KEY_MENU       = (KEY_SPECIAL+69),
	KEY_LAST       = KEY_MENU
};

//////////////////////////////////////////////////////////////////////////
struct SColour
{
	SColour() {}
	SColour(unsigned int a_iColour) : colour(a_iColour) { }
	SColour(unsigned char r, unsigned char g, unsigned char b, unsigned char a)
	{
		colours.r = r;
		colours.g = g;
		colours.b = b;
		colours.a = a;
	}

	union
	{
		unsigned int colour;
		struct SColours
		{
			unsigned char a, r, g, b;
		} colours;
	};
};

//////////////////////////////////////////////////////////////////////////
// Call this function to initialise the framework 
//////////////////////////////////////////////////////////////////////////
DLLEXPORT int			Initialise( int a_iWidth, int a_iHeight, bool a_bFullscreen = false, const char* a_pWindowTitle = nullptr );
//////////////////////////////////////////////////////////////////////////
// This function should be called just prior to exiting your program
// it will unload all the components of the AIE Framework that have been loaded
//////////////////////////////////////////////////////////////////////////
DLLEXPORT void			Shutdown();
//////////////////////////////////////////////////////////////////////////
// This function is to be called each frame to update the current frame. 
//////////////////////////////////////////////////////////////////////////
DLLEXPORT bool			FrameworkUpdate();
//////////////////////////////////////////////////////////////////////////
// Call this function to clear any content that has been rendered to the screen 
//////////////////////////////////////////////////////////////////////////
DLLEXPORT void			ClearScreen();
//////////////////////////////////////////////////////////////////////////
// Call this function to Set the background colour
//////////////////////////////////////////////////////////////////////////
DLLEXPORT void			SetBackgroundColour( SColour a_BGColour );
//////////////////////////////////////////////////////////////////////////
// Call this function to set the current render colour
// this will cause any following calls to a draw function to have this colour
// applied to those objects which are drawn
//////////////////////////////////////////////////////////////////////////
DLLEXPORT void			SetRenderColour(  SColour a_sColour );
DLLEXPORT void			SetRenderColour( float a_fRed, float a_fGreen, float a_fBlue, float a_fAlpha = 1.f );

//////////////////////////////////////////////////////////////////////////
// Basic Sprite creation and manipulation functionality
//////////////////////////////////////////////////////////////////////////
DLLEXPORT unsigned int	CreateSprite( const char* a_pTextureName, int a_iWidth, int a_iHeight, bool a_bDrawFromCenter = true, SColour a_sColour = SColour(0xFF,0xFF,0xFF,0xFF) );
DLLEXPORT unsigned int	DuplicateSprite( unsigned int a_uiSpriteID );
DLLEXPORT void			SetSpriteColour( unsigned int a_uiSpriteID, SColour& a_sColour );
DLLEXPORT void			GetSpriteColour( unsigned int a_uiSpriteID, SColour& a_sColour );
DLLEXPORT void			MoveSprite( unsigned int a_uiSpriteID, float a_fXPos, float a_fYPos );
DLLEXPORT void			RotateSprite( unsigned int a_uiSpriteID, float a_fRotation );
DLLEXPORT void			DestroySprite( unsigned int a_uiSpriteID );
DLLEXPORT void			DrawSprite( unsigned int a_uiSpriteID );
DLLEXPORT void			SetSpriteUVCoordinates( unsigned int a_uiSpriteID, float a_minUCoord, float a_minVCoord, float a_maxUCoord, float a_maxVCoord );
DLLEXPORT void			GetSpriteUVCoordinates( unsigned int a_uiSpriteID, float& a_minUCoord, float& a_minVCoord, float& a_maxUCoord, float& a_maxVCoord );
DLLEXPORT void			SetSpriteScale( unsigned int a_uiSpriteID, float& a_fSpriteWidth, float& a_fSpriteHeight );
DLLEXPORT void			GetSpriteScale( unsigned int a_uiSpriteID, float& a_fSpriteWidth, float& a_fSpriteHeight );
//////////////////////////////////////////////////////////////////////////
// Basic Line Drawing Functionality
//////////////////////////////////////////////////////////////////////////
DLLEXPORT void			DrawLine( int a_iStartX, int a_iStartY, int a_iEndX, int a_iEndY );
DLLEXPORT void			DrawLine( int a_iStartX, int a_iStartY, int a_iEndX, int a_iEndY, SColour a_sColour );
DLLEXPORT void			DrawLine( int a_iStartX, int a_iStartY, int a_iEndX, int a_iEndY, SColour a_sStartColour, SColour a_sEndColour );

//////////////////////////////////////////////////////////////////////////
// Draws a String to the screen
//////////////////////////////////////////////////////////////////////////
DLLEXPORT void			DrawString( const char* a_pText, int a_iXPos, int a_iYPos, SColour a_sColour = SColour(0xFF,0xFF,0xFF,0xFF));

//////////////////////////////////////////////////////////////////////////
// Input Handling Functionality
//////////////////////////////////////////////////////////////////////////
DLLEXPORT bool			IsKeyDown( int a_iKey );
DLLEXPORT void			GetMouseLocation( int& a_iMouseX, int& a_iMouseY );
DLLEXPORT bool			GetMouseButtonDown( int a_iMouseButtonToTest );


//////////////////////////////////////////////////////////////////////////
// Gets the Delta Time
//////////////////////////////////////////////////////////////////////////
DLLEXPORT float 		GetDeltaTime();
//////////////////////////////////////////////////////////////////////////
#endif //_AIE_H_
//////////////////////////////////////////////////////////////////////////