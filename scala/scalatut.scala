object scalatut{
        def main(args: Array[String]){
                var i=0/*
                while(i<=10){
                        println(i)
                        i+=1
                }
                */
                println("printing even list: ")
                //val list=List(1,2,3,4,5,6,7,8,9)
                var evenlist=for { i<-1 to 20
                        if((i%2)==0)
                      } yield i
                for (i <- evenlist)
                        println(i)



        }
}
