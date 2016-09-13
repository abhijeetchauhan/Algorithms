class Outer{
  int outer_x=10;
  static class Inner{
    void display(){
      System.out.println("Outer_x is ");
    }
  }
  public static void main(String []g){
    Outer out = new Outer();
    Outer.Inner a = new Outer.Inner();
    a.display();
  }
}