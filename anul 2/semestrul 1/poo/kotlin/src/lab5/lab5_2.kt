package lab5

open class Employee(var name: String, var baseSalary: Double){
    open fun printDetails(){
        println("Nume: $name,Rol: Angajat, Salariu de baza: $baseSalary")
    }
    open fun salaryCalculator(){
        println("Calcul salariu pentru Angajat: $baseSalary")
    }

}
open class Manager(name: String, baseSalary: Double, private var mangerBonus:Double): Employee(name, baseSalary) {
    override fun printDetails() {
        println("Nume: $name,Rol: Manager, Salariu de baza: $baseSalary")
    }
    override fun salaryCalculator() {
        println("Calcul salariu pentru Manager: ${baseSalary*mangerBonus}")
    }
}
class Director(name: String,baseSalary: Double,private var directorBonus:Double,private var department:String):Manager(name,baseSalary,directorBonus) {
    override fun printDetails() {
        println("Nume: $name,Rol: Director, Departament: $department, Salariu de baza: $baseSalary")
    }

    override fun salaryCalculator() {
        println("Calcul salariu pentru Director: ${baseSalary * directorBonus}")
    }

}
fun main() {
    val employee = Employee("Florin",2600.0)
    val manager = Manager("Andrei",2600.0,1.5)
    val director = Director("Daniel",2600.0,3.5,"Hr")

    employee.printDetails()
    employee.salaryCalculator()
    manager.printDetails()
    manager.salaryCalculator()
    director.printDetails()
    director.salaryCalculator()
}