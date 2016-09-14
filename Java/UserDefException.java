class MyException extends Exception{
  int detail;
  MyException(int a){
    detail=a;
  }
  public String toString(){
    return "My Exception: "+detail;
  }
}
class test{
  int a;
  test(int in){
    a=in;
  }
  void valid() throws MyException{
    if(a<10){
      throw new MyException(a);
    }
  }
}
class UserDefException{
  public static void main(String []g){
    test t = new test(4);
    //try{
    throw new NullPointerException();
    //t.valid();
    //}
    // catch(MyException e){
    //   System.out.println(e);
    // }
    // finally{
    //   System.out.println("finally called");
    // }
    // System.out.println("Outside finally");
  }
}