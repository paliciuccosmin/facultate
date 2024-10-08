// Clasa de bază Beer
open class Beer protected constructor(protected val type: String, protected val origin: String) {
    // Constructor default
    constructor() : this("", "")

    // Constructor cu parametrii
    constructor(type: String, origin: String, specificAttribute: String) : this(type, origin) {
        // Initializare atribut specific pentru clasa derivată
    }

    // Metode de get
    fun fetchType(): String = type
    fun fetchOrigin(): String = origin

    // Metodă de a întoarce detaliile despre bere
    open fun getDetails(): String = "Type: $type, Origin: $origin"
}

// Clasa derivată pentru Tipul A: etichetă pătrată
private class TypeA : Beer {
    private val length: Double

    // Constructor default
    constructor() : super("Type A", "Square Origin") {
        this.length = 0.0
    }

    // Constructor cu parametrii
    constructor(length: Double) : super("Type A", "Square Origin") {
        this.length = length
    }

    // Metodă pentru a calcula aria etichetei
    fun calculateLabelArea(): Double = length * length

    // Suprascrie metoda din clasa de bază pentru a afișa detaliile specifice
    override fun getDetails(): String = "${super.getDetails()}, Length: $length"
}

// Clasa derivată pentru Tipul B: etichetă rotundă și transparentă
private class TypeB : Beer {
    private val radius: Double

    // Constructor default
    constructor() : super("Type B", "Round and Transparent Origin") {
        this.radius = 0.0
    }

    // Constructor cu parametrii
    constructor(radius: Double) : super("Type B", "Round and Transparent Origin") {
        this.radius = radius
    }

    // Metodă pentru a calcula aria etichetei
    fun calculateLabelArea(): Double = Math.PI * radius * radius

    // Suprascrie metoda din clasa de bază pentru a afișa detaliile specifice
    override fun getDetails(): String = "${super.getDetails()}, Radius: $radius"
}

// Clasa derivată pentru Tipul C: în formă de triunghi dreptunghic
private class TypeC : Beer {
    private val base: Double
    private val height: Double

    // Constructor default
    constructor() : super("Type C", "Right Triangle Origin") {
        this.base = 0.0
        this.height = 0.0
    }

    // Constructor cu parametrii
    constructor(base: Double, height: Double) : super("Type C", "Right Triangle Origin") {
        this.base = base
        this.height = height
    }

    // Metodă pentru a calcula aria etichetei
    fun calculateLabelArea(): Double = 0.5 * base * height

    // Suprascrie metoda din clasa de bază pentru a afișa detaliile specifice
    override fun getDetails(): String = "${super.getDetails()}, Base: $base, Height: $height"
}

fun main() {
    // Exemplu de utilizare
    val typeA = TypeA(5.0)
    val typeB = TypeB(4.0)
    val typeC = TypeC(6.0, 3.0)

    println(typeA.getDetails())
    println("Type A Label Area: ${typeA.calculateLabelArea()}")

    println(typeB.getDetails())
    println("Type B Label Area: ${typeB.calculateLabelArea()}")

    println(typeC.getDetails())
    println("Type C Label Area: ${typeC.calculateLabelArea()}")
}
