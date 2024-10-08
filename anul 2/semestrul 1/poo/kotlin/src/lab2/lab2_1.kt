import java.time.LocalDateTime
import java.time.format.DateTimeFormatter

class CurrentDateTime {
    private val currentDateTime: LocalDateTime

    init {
        currentDateTime = LocalDateTime.now()
        val formatter = DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm:ss")
        val formattedDateTime = currentDateTime.format(formatter)
        println("Data și ora curentă: $formattedDateTime")
    }
}

fun main() {
    val currentDateInstance = CurrentDateTime()
}
