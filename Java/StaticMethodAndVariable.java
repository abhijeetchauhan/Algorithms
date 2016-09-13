class StaticMethodAndVariable{
  static int a=5;
  static int b;
  static{
    b=a*2;
  }
  static void meth(int x){
    System.out.println("X is :"+x);
    System.out.println("A is :"+a);
    System.out.println("B is :"+b);
  }
  public static void main(String []g){
    meth(14);
  }
}