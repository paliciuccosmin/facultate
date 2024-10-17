interface Handler {
    fun setNext(handler: Handler?)
    fun handleRequest(request: String)
}

class ConcreteHandlerA : Handler {
    private var nextHandler: Handler? = null

    override fun setNext(handler: Handler?) {
        nextHandler = handler
    }

    override fun handleRequest(request: String) {
        if (request == "A") {
            println("ConcreteHandlerA handles the request.")
        } else if (nextHandler != null) {
            nextHandler?.handleRequest(request)
        } else {
            println("No handler can handle the request.")
        }
    }
}

class ConcreteHandlerB : Handler {
    private var nextHandler: Handler? = null

    override fun setNext(handler: Handler?) {
        nextHandler = handler
    }

    override fun handleRequest(request: String) {
        if (request == "B") {
            println("ConcreteHandlerB handles the request.")
        } else if (nextHandler != null) {
            nextHandler?.handleRequest(request)
        } else {
            println("No handler can handle the request.")
        }
    }
}

class ConcreteHandlerC : Handler {
    private var nextHandler: Handler? = null

    override fun setNext(handler: Handler?) {
        nextHandler = handler
    }

    override fun handleRequest(request: String) {
        if (request == "C") {
            println("ConcreteHandlerC handles the request.")
        } else if (nextHandler != null) {
            nextHandler?.handleRequest(request)
        } else {
            println("No handler can handle the request.")
        }
    }
}

fun main() {
    val handlerA: Handler = ConcreteHandlerA()
    val handlerB: Handler = ConcreteHandlerB()
    val handlerC: Handler = ConcreteHandlerC()

    handlerA.setNext(handlerB)
    handlerB.setNext(handlerC)

    handlerA.handleRequest("A")
    handlerA.handleRequest("B")
    handlerA.handleRequest("C")
    handlerA.handleRequest("D")
}
