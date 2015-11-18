
#include <stdio.h>
  enum BirdType {DUCK, CHICK, DY};

class BirdBase
{
 public:
  int id=0;
 public:
  virtual void fly() const
  {
    printf("BirdBase::Fly\n");
  }

  virtual ~BirdBase() {
    printf("~BirdBase\n");
  }
};


class Duck :public BirdBase {
 public:
  void fly() const {
    printf("Duck::Fly\n");
  }

  ~Duck() {
    printf("~Duck\n");
  }

};

class Chick :public BirdBase {
 public:
  void fly() const {
    printf("Chick::Fly\n");
  }

  ~Chick() {
    printf("~Chick\n");
  }
};

class Dy:public BirdBase {
 public:
  void fly() const {
    printf("Dy::Fly\n");
  }

  ~Dy() {
    printf("~Dy\n");
  }
};


class XX : BirdBase {
 private:
  int *_buf;
 public:
  XX() {
    _buf = new int(3);
  }
   ~XX() {
     delete _buf;
   }
};

class BirdFactory
{
private:
  BirdFactory();
 public:
  static BirdBase* create(BirdType type)
  {
    switch (type) {
    case DUCK:
      return new Duck();
    case CHICK:
      return new Chick();
    case DY:
      return new Dy();
    }
    return nullptr;
  }

};
class XZ 
{
 public:
  virtual void area() const { printf("XZ::area\n"); }
  virtual ~XZ() { printf("~XZ\n"); }
};

class Ract : public XZ {
 protected: 
  int l;
  int w;

 public:
  Ract(int l, int w) : l(l), w(w) {
  }

  ~Ract() { printf("~Ract\n"); }
  virtual void area() const { printf("Ract::area: %d\n", l*w); }
  void getLen() const { printf("Ract::getLen: %d\n", l); }

};

class Square : public Ract
{
 public:
  Square(int l) : Ract(l, l)
  {}
  ~Square() { printf("~Square\n"); }

  virtual void area() const { printf("Square::area: %d\n", w*w ); }
};

class Circle: public XZ {
 private: 
  int r;

 public:
  Circle(int r) : r(r) {}

  void getR() const {
    printf("Ract::getR: %d\n", r);
  }
  void area() const {
    printf("Circle::area: %g\n", 3.14 * r *r);
  }
};

int main(int argc, char *argv[])
{
  XZ *p = new Square(3);
  delete p;

  //BirdBase *b1 = BirdFactory::create(BirdType::DUCK);
  //BirdBase *b2 = BirdFactory::create(BirdType::CHICK);
  //BirdBase *b3 = BirdFactory::create(BirdType::DY);

  //b1->fly();
  //b2->fly();
  //b3->fly();
  //delete b1;
  //delete b2;
  //delete b3;



  //Circle c(10);
  //Ract r(2,4);
  //Square s(4);

  //r.area();
  //c.area();

  //XZ *p = nullptr;
  //p = &r;
  //Ract *rp = &r;

  //XZ &rp = r;
  //rp.area();
  //(static_cast<Ract&>(rp)).getLen();

  //r.getLen();
  ////((Ract *)p)->getLen();

  //(static_cast<Ract *>(p))->getLen();
  //p->area();

  //p = &c;
  //p->area();

  //p = &s;
  //p->area();

  //Duck d;
  //d.fly();

  //Chick j;
  //j.fly();

  //Dy y;
  //y.fly();

  //BirdBase *b =&d;
  //b->fly();
  
  return 0;
}
