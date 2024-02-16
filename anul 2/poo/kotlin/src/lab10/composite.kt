// Component interface
interface Component {
    fun operation()
}

// Leaf class
class Leaf : Component {
    override fun operation() {
        println("Leaf operation")
    }
}

// Composite class
class Composite : Component {
    private val components = mutableListOf<Component>()

    fun add(component: Component) {
        components.add(component)
    }

    fun remove(component: Component) {
        components.remove(component)
    }

    override fun operation() {
        println("Composite operation")

        // Call operation on all child components
        for (component in components) {
            component.operation()
        }
    }
}

fun main() {
    // Create leaf components
    val leaf1 = Leaf()
    val leaf2 = Leaf()
    val leaf3 = Leaf()

    // Create composite component
    val composite = Composite()

    // Add leaf components to the composite
    composite.add(leaf1)
    composite.add(leaf2)
    composite.add(leaf3)

    // Call operation on the composite
    composite.operation()
}
