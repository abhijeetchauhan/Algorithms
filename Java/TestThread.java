class RunnableDemo implements Runnable{
  Thread t;
  String threadname;
  RunnableDemo(String s){
    threadname=s;
    System.out.println("Creating : "+s);
  }
  public void run(){
    System.out.println("Running : "+threadname);
    try{
      for(int i=4;i>0;i--){
        System.out.println("Thread : "+threadname+","+i);
        Thread.sleep(50);
      }
    }catch(InterruptedException e){
      System.out.println("Thread : "+threadname+"Interrupted");
    }
    System.out.println("Thread : "+threadname+"Exiting.");
  }
  public void start(){
    System.out.println("Starting :"+threadname);
    if(t==null){
      t = new Thread(this,threadname);
      t.start();
    }
  }
}
class ThreadDemo extends Thread{
  Thread t;
  String threadname;
  ThreadDemo(String s){
    threadname=s;
    System.out.println("Creating : "+s);
  }
  public void run(){
    System.out.println("Running : "+threadname);
    try{
      for(int i=4;i>0;i--){
        System.out.println("Thread : "+threadname+","+i);
        Thread.sleep(50);
      }
    }catch(InterruptedException e){
      System.out.println("Thread : "+threadname+"Interrupted");
    }
    System.out.println("Thread : "+threadname+"Exiting.");
  }
  public void start(){
    System.out.println("Starting :"+threadname);
    if(t==null){
      t = new Thread(this,threadname);
      t.start();
    }
  }
}
class TestThread{
  public static void main(String []g){
    RunnableDemo a = new RunnableDemo("First");
    a.start();
    ThreadDemo b = new ThreadDemo("Second");
    b.start();
  }
}