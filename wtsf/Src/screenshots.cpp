/*************************************
Screenshot Script
*************************************/
//attention je n'ai pas pu tester la portabilité de ce morceau de code !

/*int TkScreen(void)
{
    FILE * screensh;
    std::string save_name = "screenshot";
    //std::string nbrsave = "0";
    int nbrsave = 0;
    std::string def_name = save_name + nbrsave + ".bmp";
    existqst :
    if (!(screensh=fopen(c_str(def_name);,"r"))
    {
        nbrsave++;
        goto existqst;
    }    
    SDL_SaveBMP(screen, def_name);
    return 1;
} */   
/*int TkScreen(void)
{
    FILE * screensh;
    std::string save_name = "screenshot";
    std::string nbrsave = "0";
    int inbrsave = 0;
    char screenshc[20] = "screenshot.bmp";
    std::string def_name = save_name + ".bmp";
    existqst :
    if (!(screensh=fopen(def_name,"r"))
    {
        inbrsave++;
        nbrsave = inbrsave;
        goto existqst;
    }  */ 
    /*screenshc = c_str(def_name); 
    SDL_SaveBMP(screen, def_name);
    return 1;
}*/
