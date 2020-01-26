object rec{
  def main(args: Array[String]){
    def factorial(num: Int): BigInt={
      if(num<=1){
        1
      }
      else{
        num*factorial(num-1)
      }
    }
    print("Factorial of 4  is: "+factorial(4))
  }
}
