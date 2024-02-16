// Abstract Product A: Engine
interface Engine {
    fun getType(): String
}

// Concrete Product A1: CommercialEngine
class CommercialEngine : Engine {
    override fun getType(): String {
        return "Commercial Engine"
    }
}

// Concrete Product A2: MilitaryEngine
class MilitaryEngine : Engine {
    override fun getType(): String {
        return "Military Engine"
    }
}

// Abstract Product B: Wings
interface Wings {
    fun getType(): String
}

// Concrete Product B1: CommercialWings
class CommercialWings : Wings {
    override fun getType(): String {
        return "Commercial Wings"
    }
}

// Concrete Product B2: MilitaryWings
class MilitaryWings : Wings {
    override fun getType(): String {
        return "Military Wings"
    }
}

// Abstract Factory: AircraftFactory
interface AircraftFactory {
    fun createEngine(): Engine
    fun createWings(): Wings
}

// Concrete Factory 1: CommercialAircraftFactory
class CommercialAircraftFactory : AircraftFactory {
    override fun createEngine(): Engine {
        return CommercialEngine()
    }

    override fun createWings(): Wings {
        return CommercialWings()
    }
}

// Concrete Factory 2: MilitaryAircraftFactory
class MilitaryAircraftFactory : AircraftFactory {
    override fun createEngine(): Engine {
        return MilitaryEngine()
    }

    override fun createWings(): Wings {
        return MilitaryWings()
    }
}

// Client Code
fun buildAndDisplayAircraft(factory: AircraftFactory) {
    val engine = factory.createEngine()
    val wings = factory.createWings()

    println("Assembling an aircraft with ${engine.getType()} and ${wings.getType()}.")
}

fun main() {
    // Client uses Commercial Aircraft Factory
    val commercialFactory = CommercialAircraftFactory()
    buildAndDisplayAircraft(commercialFactory)

    // Client uses Military Aircraft Factory
    val militaryFactory = MilitaryAircraftFactory()
    buildAndDisplayAircraft(militaryFactory)
}
