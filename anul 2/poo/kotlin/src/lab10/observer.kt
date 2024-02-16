import java.util.*

// Observer interface
interface Observer {
    fun update()
}

// Concrete Observer
class ConcreteObserver : Observer {
    override fun update() {
        println("ConcreteObserver: Received an update.")
    }
}

// Subject interface
interface Subject {
    fun attach(observer: Observer)
    fun detach(observer: Observer)
    fun notifyObservers()
}

// Concrete Subject
class ConcreteSubject : Subject {
    private val observers: MutableList<Observer> = ArrayList()

    override fun attach(observer: Observer) {
        observers.add(observer)
    }

    override fun detach(observer: Observer) {
        observers.remove(observer)
    }

    override fun notifyObservers() {
        // Notify all observers
        for (observer in observers) {
            observer.update()
        }
    }
}

fun main() {
    // Create subject and observers
    val subject = ConcreteSubject()
    val observer1 = ConcreteObserver()
    val observer2 = ConcreteObserver()

    // Attach observers to the subject
    subject.attach(observer1)
    subject.attach(observer2)

    // Notify observers
    subject.notifyObservers()

    // Detach observer1 from the subject
    subject.detach(observer1)

    // Notify observers again
    subject.notifyObservers()
}
