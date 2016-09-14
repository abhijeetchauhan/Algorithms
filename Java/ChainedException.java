class ChainedException{
  public static void main(String []g){
    try{
      NullPointerException e = new NullPointerException("Top Layer");
      e.initCause(new ArithmeticException("cause"));
      throw e;
    }
    catch(NullPointerException e){
      System.out.println("Caught : "+e);
      System.out.println("Original Cause : "+e.getCause());
    }
  }
}