class Sorter{


    fun sortingAlg(array: IntArray) {
       for(i in 0..array.size-2)
           for(j in i+1..array.size-1)
               if(array[i]<array[j]) {
                   array[i]=array[j].also{array[j]=array[i]}
               }
    }

    fun printArray(array: IntArray) {
        for (i in 0 until array.size) {
            print(array[i])
            print(" ")
        }
    }
}

fun main(){
    val arr= intArrayOf(40, 8, 11, 2, 99)
    var sorting=Sorter()
    sorting.sortingAlg(arr)
    sorting.printArray(arr)
}