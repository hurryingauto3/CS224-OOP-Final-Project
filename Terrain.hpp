class Terrain
{
    
public:
    float width;
    float height;
    float x_cor;
    float y_cor;
    bool passable;
};

class Door : public Terrain
{
private:
    bool state_open;
public:
  Door(){
      state_open=false;
      this->height = 5 ;
      this->width = 1 ;
  };
  void openclose_door(){
      if (state_open==false){
          state_open=true;
          this->passable=true;
      }
      if (state_open==true){
          state_open=false;
          this->passable=false;
      }
  };
};

class Wall : public Terrain
{
private:
    bool passable;
public:
    Wall(){
        passable=false;
        x_cor= 10;
        y_cor=10;
        this->width = 5;
        this->height = 5;
    }
    void collision(Player A){
            if (this->x_cor== A.getx()){
                A.setlocation(A.getx()-1,A.gety());
            };
            if (this->y_cor==A.gety()){
                A.setlocation(A.getx(),A.gety()-1);
            }
    };

};

class Window : public Terrain
{
private:
    bool status_broken;
public:
    void breakwindow(){
        if (status_broken==false){
            status_broken=true;
            this->passable=true;
        }
    };
    Window ()
    {
        status_broken=false;
        this->height=5;
        this->width=1;
    };
};