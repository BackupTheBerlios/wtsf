/***********************************

Engine Main File
Coded By Fragnatik

***********************************/

#include <F-Engine.h>

SDL_Surface *screen = NULL;

int width = 800;
int height = 600;
signed short direction_x = 0;
signed short direction_y = 0;
bool left=0, right=0, up=0, down=0;
Uint8 * keys;

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
    char * file_name = "Tiles/wiener.bmp";
    wiener = IMG_Load(file_name);
    if (wiener == NULL) {
        std::cout << "Couldn't load " << file_name << " " << SDL_GetError() << '\n';
    }
    SDL_SetColorKey(wiener, SDL_SRCCOLORKEY, 0xff00de);  
    if (wiener->format->palette && screen->format->palette) {
    SDL_SetColors(screen, wiener->format->palette->colors, 0,
                  wiener->format->palette->ncolors);
              }
              /*keys = SDL_GetKeyState(NULL);
if ( keys[SDLK_UP] ) { direction_y -= 1; }
if ( keys[SDLK_DOWN] ) { direction_y += 1; }
if ( keys[SDLK_LEFT] ) { direction_x -= 1; }
if ( keys[SDLK_RIGHT] ) { direction_x += 1; }*/
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
    int done;
    int depth = 0;
    
    std::cout << "Initializing SDL \n";
    
    if (SDL_Init (SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
    {
        std::cout << "Couldn't initialize SDL: " << SDL_GetError () << std::endl;
        exit (1);
    }
    atexit (SDL_Quit);
    
    std::cout << "Trying to initialize video mode ...\n";

    screen = SDL_SetVideoMode (width, height, depth, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_FULLSCREEN | SDL_ANYFORMAT);
    if (screen == NULL)
    {
        std::cout << "Couldn't set " << width << " x " << height << " x " << depth << " video mode: " << SDL_GetError () << std::endl;
        exit(2);
    }
    SDL_WM_SetCaption ("When The Stars Fell (F-Engine)", NULL);

    std::cout << "Setting " << width << " x " << height << " x " << depth << " video mode\n";           
    std::cout << "Video mode successfully initialized !\n";
    
    done = 0;
    while (!done)
    {
        SDL_Event event;

        /* Check for events */
        while (SDL_PollEvent (&event))
        {
          if (event.type == SDL_QUIT)
                done = 1;
          if (event.type == SDL_KEYDOWN)
          {
          if (event.key.keysym.sym == SDLK_ESCAPE)
                done = 1;
          if (event.key.keysym.sym == SDLK_SPACE)
          {
                    /*display_img("test.bmp");
                    SDL_Flip(screen);
                    Sleep(1);*/
          }
          if (event.key.keysym.sym == SDLK_c)
                    clean_disp(screen);
          if (event.key.keysym.sym == SDLK_F11)
                    SDL_SaveBMP(screen, "Screenshots/screenshot.bmp");
          if (event.key.keysym.sym == SDLK_UP)
          {
          /*direction_y -= 5;
          if (direction_y < -280)
          direction_y = -280;*/
          }    
          if (event.key.keysym.sym == SDLK_DOWN)
          {
          /*direction_y += 5;
          if (direction_y > 280)
          direction_y = 280;*/
          }    
          if (event.key.keysym.sym == SDLK_RIGHT)
          {
          /*direction_x += 5;
          if (direction_x > 380)
          direction_x = 380;*/
          }
          if (event.key.keysym.sym == SDLK_LEFT)
          {
          /*left = !left;
          if (direction_x < -380)
          {
          direction_x = -380;
          }
          else
          {
          while (left = 1)
          {   
          direction_x -= 5;   
          Sleep(1);
          }
          }*/            
          }
      }   
      if (event.type == SDL_KEYUP)
      {
      }     
          sdl_test(screen);    
        }
    }
    std::cout << "Quiting ...\n";
    return 0;
}
