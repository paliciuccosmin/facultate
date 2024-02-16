// Subsystem classes
class SubsystemA {
    fun operationA() {
        println("Subsystem A operation")
    }
}

class SubsystemB {
    fun operationB() {
        println("Subsystem B operation")
    }
}

class SubsystemC {
    fun operationC() {
        println("Subsystem C operation")
    }
}

// Facade class
class Facade {
    private val subsystemA = SubsystemA()
    private val subsystemB = SubsystemB()
    private val subsystemC = SubsystemC()

    fun complexOperation() {
        subsystemA.operationA()
        subsystemB.operationB()
        subsystemC.operationC()
    }
}

fun main() {
    val facade = Facade()
    facade.complexOperation()
}
