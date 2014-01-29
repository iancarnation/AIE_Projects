#include "Utilities.h"

unsigned int LoadTexture(const char* a_szTexture, unsigned int a_uiFormat /* = 
GL_RGBA */, unsigned int* a_uiWidth /* = nullptr */, unsigned int* a_uiHeight /* = 
nullptr */, unsigned int* a_uiBPP /* = nullptr*/) 
{ 
 FIBITMAP* pBitmap = nullptr; 
 
 // check the file signature and deduce its format and load it 
 FREE_IMAGE_FORMAT fif = FreeImage_GetFileType(a_szTexture, 0); 
 if (fif != FIF_UNKNOWN && FreeImage_FIFSupportsReading(fif)) 
 { 
 pBitmap = FreeImage_Load(fif, a_szTexture); 
 } 
 
 if (pBitmap == nullptr) 
 { 
 printf("Error: Failed to load image '%s'!\n", a_szTexture); 
 return 0; 
 } 
 
 // optionally get the image width and height 
 if (a_uiWidth != nullptr) 
 *a_uiWidth = FreeImage_GetWidth(pBitmap); 
 if (a_uiHeight != nullptr) 
 *a_uiHeight = FreeImage_GetHeight(pBitmap); 
 
 // force the image to RGBA 
 unsigned int bpp = FreeImage_GetBPP(pBitmap); 
 if( a_uiBPP != nullptr ) 
 *a_uiBPP = bpp/8; 
 
 FREE_IMAGE_COLOR_TYPE fi_colourType = FreeImage_GetColorType(pBitmap); 
 if (fi_colourType != FIC_RGBALPHA ) 
 { 
 FIBITMAP* ndib = FreeImage_ConvertTo32Bits(pBitmap); 
 FreeImage_Unload(pBitmap); 
 pBitmap = ndib; 
 bpp = FreeImage_GetBPP(pBitmap); 
 fi_colourType = FreeImage_GetColorType(pBitmap); 
 } 
 
 // get the pixel data 
 BYTE* pData = FreeImage_GetBits(pBitmap); 
 
 // try to determine data type of file (bytes/floats) 
 FREE_IMAGE_TYPE fit = FreeImage_GetImageType(pBitmap); 
 GLenum eType = (fit == FIT_RGBF || fit == FIT_FLOAT) ?  GL_FLOAT:GL_UNSIGNED_BYTE; 
 
 // create GL texture 
 GLuint textureID; 
 glGenTextures( 1, &textureID ); 
 glBindTexture( GL_TEXTURE_2D, textureID ); 
 glTexImage2D( GL_TEXTURE_2D, 0, GL_RGBA, 
 FreeImage_GetWidth(pBitmap), 
FreeImage_GetHeight(pBitmap), 0, 
a_uiFormat, eType, pData); 
 
 // specify default filtering and wrapping 
 glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); 
 glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); 
 glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE ); 
 glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE ); 
 // unbind texture 
 glBindTexture( GL_TEXTURE_2D, 0 ); 
 
 // delete data 
 FreeImage_Unload(pBitmap); 
 
 return textureID; 
}