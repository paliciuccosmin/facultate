open class Salad {
    private val ingredients = mutableListOf<String>()

    fun addIngredient(ingredient: String) {
        ingredients.add(ingredient)
    }

    fun display() {
        println("Salad Ingredients:")
        for (ingredient in ingredients) {
            println("- $ingredient")
        }
    }
}

abstract class SaladBuilder {
    abstract fun buildBase()
    abstract fun buildVegetables()
    abstract fun buildProtein()
    abstract fun getResult(): Salad
}

class GreekSaladBuilder : SaladBuilder() {
    private val salad = Salad()

    override fun buildBase() {
        salad.addIngredient("Lettuce")
    }

    override fun buildVegetables() {
        salad.addIngredient("Tomatoes")
        salad.addIngredient("Cucumbers")
        salad.addIngredient("Red onions")
        salad.addIngredient("Kalamata olives")
    }

    override fun buildProtein() {
        salad.addIngredient("Feta cheese")
    }

    override fun getResult(): Salad {
        return salad
    }
}

class CaesarSaladBuilder : SaladBuilder() {
    private val salad = Salad()

    override fun buildBase() {
        salad.addIngredient("Romaine lettuce")
    }

    override fun buildVegetables() {
        salad.addIngredient("Cherry tomatoes")
    }

    override fun buildProtein() {
        salad.addIngredient("Grilled chicken")
    }

    override fun getResult(): Salad {
        return salad
    }
}

class SaladDirector {
    fun makeSalad(builder: SaladBuilder): Salad {
        builder.buildBase()
        builder.buildVegetables()
        builder.buildProtein()
        return builder.getResult()
    }
}

fun main() {
    val director = SaladDirector()
    val greekSaladBuilder = GreekSaladBuilder()
    val greekSalad = director.makeSalad(greekSaladBuilder)

    val caesarSaladBuilder = CaesarSaladBuilder()
    val caesarSalad = director.makeSalad(caesarSaladBuilder)

    println("Greek Salad:")
    greekSalad.display()

    println("\nCaesar Salad:")
    caesarSalad.display()
}
