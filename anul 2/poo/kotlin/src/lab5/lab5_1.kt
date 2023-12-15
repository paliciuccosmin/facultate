package lab5

import kotlin.math.PI
import kotlin.math.pow

class Volume {
    fun calculateVolume(side: Double) {
        val volume = side.pow(3)
        println("Volume of Cube: $volume")
    }
    fun calculateVolume(radius: String) {
        val r=radius.toDouble()
        val volume = (4 / 3.0) * PI * r.pow(3)
        println("Volume of Sphere: $volume")
    }

    fun calculateVolume(baseLength: Double, height: Double) {
        val volume = (1 / 3.0) * baseLength.pow(2) * height
        println("Volume of Pyramid: $volume")
    }

    fun calculateVolume() {
        println("No specific volume calculation provided. Displaying a message.")
    }
}

fun main() {
    val volumeCalculator = Volume()

    volumeCalculator.calculateVolume(5.0) // Volumul unui cub
    volumeCalculator.calculateVolume(3.0) // Volumul unei sfere
    volumeCalculator.calculateVolume(4.0, 6.0) // Volumul unei piramide
    
    volumeCalculator.calculateVolume()
}
