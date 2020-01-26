import scala.math._
object  printmath{
  def main(args: Array[String]){
    def printprime(){
      var n=15
      var i=0
      for(i<-1 to n){
        var f=0
        //println("i: "+i)
        for(j<-1 to math.sqrt(i).toInt){
          //println("j: "+j)
          if(i%j==0&& j!=1){
            f=1;
          }
        }
        if(f==0){
          printf("%d ",i)
        }
      }
      println("")
    }
    printprime
  }
}
