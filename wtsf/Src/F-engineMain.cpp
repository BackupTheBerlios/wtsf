/***********************************

Engine Main File
Coded By Fragnatik

***********************************/

#include "Include/F-Engine.h"

SDL_Surface *screen = NULL;
Mix_Music *bgmusic;

unsigned short playing =0;
unsigned short firsttime = 1;
int width = 800;
int height = 600;
int depth = 0;
Uint8 * keys;
int done = 0;
//!!!
signed short direction_x = 0;
signed short direction_y = 0;
//!!!

int SDL_Initialize(unsigned short mode = 1, char *caption = "When The Stars Fell (F-Engine)")
{
    std::cout << "Initializing SDL \n";
    
    if (SDL_Init (SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
    {
        std::cout << "Couldn't initialize SDL: " << SDL_GetError () << std::endl;
        exit (1);
    }
    atexit (SDL_Quit);
    
    std::cout << "Trying to initialize video mode " << mode <<" ...\n";

    switch(mode)
    {
    case 1 : screen = SDL_SetVideoMode (width, height, depth, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_FULLSCREEN | SDL_ANYFORMAT);
    break;
    case 2 : screen = SDL_SetVideoMode (width, height, depth, SDL_SWSURFACE | SDL_FULLSCREEN | SDL_ANYFORMAT);
    break;
    case 3 : screen = SDL_SetVideoMode (width, height, depth, SDL_SWSURFACE | SDL_ANYFORMAT);
    break;
    default : std::cout << "Video mode " << mode <<" isn't a correct video mode !\n";
    }    
    if (screen == NULL)
    {
        std::cout << "Couldn't set " << width << " x " << height << " x " << depth << " video mode: " << SDL_GetError () << std::endl;
        exit(2);
    }
    SDL_WM_SetCaption (caption, NULL);
    SDL_ShowCursor(0);

    std::cout << "Setting " << width << " x " << height << " x " << depth << " video mode\n";           
    std::cout << "Video mode " << mode <<" successfully initialized !\n";
    if(Mix_OpenAudio(44100, AUDIO_S16SYS, 2, 2048) < 0)
  {
    std::cout << "Warning: Couldn't set 44100 Hz 16-bit audio\n- Reason: " << SDL_GetError() << " \n";
  }
    bgmusic = Mix_LoadMUS("Music/bgmusic.mp3");
    Mix_PlayMusic(bgmusic, -1);
    Mix_VolumeMusic(128);
    playing =1;
}    

void clean_disp(SDL_Surface * screen)
{
    SDL_FillRect(screen, 0,SDL_MapRGB(screen->format,255,255,255));
    SDL_Flip(screen);
}

void UpdateScr(SDL_Surface * screen)
{
    SDL_UpdateRect(screen,0,0,0,0);
    SDL_Flip(screen);
    Sleep(1);
}    

//here added for tests
void sdl_test(SDL_Surface * screen)
{
    SDL_Surface * wiener;
    if (firsttime ==1)
    {
    char * file_name = "Tileset/wiener.bmp";
    wiener = IMG_Load(file_name);
    if (wiener == NULL) {
        std::cout << "Couldn't load " << file_name << " " << SDL_GetError() << '\n';
    }
    SDL_SetColorKey(wiener, SDL_SRCCOLORKEY, 0xff00de);  
    if (wiener->format->palette && screen->format->palette) {
    SDL_SetColors(screen, wiener->format->palette->colors, 0,
                  wiener->format->palette->ncolors);
              }
          firsttime=0;
          }    
              keys = SDL_GetKeyState(NULL);
if ( keys[SDLK_UP] ) { 
    direction_y -= 1;
    if (direction_y < -280)
    direction_y = -280;
 }
if ( keys[SDLK_DOWN] ) { 
    direction_y += 1;
    if (direction_y > 280)
    direction_y = 280;
     }
if ( keys[SDLK_LEFT] ) { 
    direction_x -= 1;
    if (direction_x < -380)
    direction_x = -380;
     }
if ( keys[SDLK_RIGHT] ) { 
    direction_x += 1;
    if (direction_x > 380)
    direction_x = 380;
     }
    SDL_Rect rectwiener;
    rectwiener.x = 380 + direction_x;
    rectwiener.y = 280 + direction_y;
    rectwiener.w = wiener->w;
    rectwiener.h = wiener->h;
    clean_disp(screen);
    if(SDL_BlitSurface(wiener, NULL, screen, &rectwiener) < 0)
        std::cout <<  "BlitSurface error: " << SDL_GetError() << "\n";    
    UpdateScr(screen);
}    
    //end of tests

int main (int argc, char *argv[])
{   
    SDL_Initialize();
    done = 0;
    while (!done)
    {
        SDL_Event event;
        /* Check for events */
        while (SDL_PollEvent (&event))
        {
          if (event.type == SDL_QUIT)
          {
                Mix_FreeMusic(bgmusic);
                done = 1;
            }    
          if (event.type == SDL_KEYDOWN)
          {
          if (event.key.keysym.sym == SDLK_ESCAPE)
                done = 1;
          if (event.key.keysym.sym == SDLK_SPACE)
          {
              if(playing ==1)
              Mix_PauseMusic();
              else
              Mix_ResumeMusic();
              playing = !playing;
          }
          if (event.key.keysym.sym == SDLK_c)
                    clean_disp(screen);
          if (event.key.keysym.sym == SDLK_F11)
                    SDL_SaveBMP(screen, "Screenshots/screenshot.bmp");
          /*if (event.key.keysym.sym == SDLK_UP)
          {
              while(event.type != SDL_KEYUP && !event.key.keysym.sym != SDLK_UP)
              direction_y -= 1;
              sdl_test(screen);
          }  */  
          /*if (event.key.keysym.sym == SDLK_DOWN)
          {
          }    
          if (event.key.keysym.sym == SDLK_RIGHT)
          {
          }
          if (event.key.keysym.sym == SDLK_LEFT)
          {            
          }*/
      }   
      /*if (event.type == SDL_KEYUP)
      {
      }*/     
        }
        sdl_test(screen);
        SDL_Delay(1);
    }
    std::cout << "Quiting ... After " << (SDL_GetTicks()/1000) << " seconds\n";
    return 0;
}
