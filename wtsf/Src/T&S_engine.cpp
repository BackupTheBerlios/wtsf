/**********************************

Tiles & Sprite Main engine
Coded by Fragnatik

/!\ Tiles & Sprites are locked to
a dimension of 40 x 40 Pixels !
Dont load directly the image file
but load the txt file that contain
all informations about tiles !

**********************************/

#Define TILE_SIZE = 40;

class Tiles
{
    public :
    SDL_Surface *TileIMG = NULL;
    SDL_Rect TilePOS;
    std::string tilefile;
    bool Block = 0;
    int LoadTileFile(char * pathtile);
    void Tiles(char *tiledir, int x, int y);
    };
    
    void Tiles::Tiles(char *tiledir, int x, int y)
    {
        if (TileIMG = SDL_LoadIMG(tiledir) == 0)
        {
                std::cout << "Unable to initialize Tile Object !!! Maybe you have specified an incorrect path to the file !\n";
                delete this;
        }
        if (TileIMG->h != 40 || TileIMG->w !=40)
        {
                std::cout << "Unable to initialize Tile Object !!! You have specified a file with an incorrect size the correct size are 40 * 40 px !\n";
                TileIMG = NULL;
                delete this;
        }
        else
        {
                TilePOS->x = x;
                TilePOS->y = y;
                TilePOS->w = TILE_SIZE;
                TilePOS->h = TILE_SIZE;
                SDL_BlitSurface(TileIMG, NULL, screen, TilePOS);
                Update(screen);
                SDL_FreeSurface(TileIMG);
        }
    }
    
    int Tiles::LoadTileFile(char *pathtile)
    {
          std::ifstream tf(pathtile);
          if(!tf){
		   std::cout<<"Can't open TileSet file: "<<pathtile<<std::endl;
		   return -1;
		   }
		  char stf[256];
          while(!tf.eof())
          {
          tf.get(stf);
          if(strcmp(stf, "tilefile :\n") == 0)
            tf.get(tilefile);

    class Sprite
    {
        public :
        
