class X {
  public:
  class Trouble {};
  class Small : public Trouble {};
  class Big : public Trouble {};
  void f() { throw Big(); }
};
int main() {
  X x;
  try {
     x.f();
  } 
  catch(X::Trouble) { printf("catch X::Trouble)\n"); }
  catch(X::Small) { printf("caugh X::Small\n"); }
  catch(X::Big) { printf("caugh X::Big\n"); }
}
