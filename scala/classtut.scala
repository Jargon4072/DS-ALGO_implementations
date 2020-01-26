object classtut{
  def main(args: Array[String]){
    var ram=new Student
    ram.setName("Ram")
    ram.setStandard("XI")
    println(ram.toString())
  }    //end of main
  class Student(var name: String,var standard: String){
    this.setName(name)
    val id=Student.newIdNum
    def getName(): String=name
    def getStandard(): String=standard
    def setName(name: String){
      if(!(name.matches(".*\\d+.*")))
        this.name=name
    }
    def setStandard(standard: String){
      this.standard=standard
    }
    def this(name: String){
      this("No Name","No Standard")
      this.setName(name)
    }
    def this(){
      this("No Name","No Standard")
    }
    override def toString():String={
      return "%s with id %d studies in %s standard".format(this.name, this.id, this.standard)
    }
  }
  object Student{
    private var idNumber=0
    private def newIdNum={ idNumber+=1; idNumber}
  }
  // TODO: implement inheritance just for practice
}
