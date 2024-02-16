class Car(val brand: String, val model: String) {
    constructor(brand: String, model: String, year: Int) : this(brand, model) {
        println("Secondary constructor called")
        println("Year: $year")
    }
}

fun main() {
    val car1 = Car("Toyota", "Camry")
    val car2 = Car("Honda", "Civic", 2022)
}
