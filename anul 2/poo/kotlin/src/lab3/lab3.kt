import java.time.LocalDate
import java.time.format.DateTimeFormatter
import kotlin.math.abs

class Student(
    private var nume: String,
    private var prenume: String,
    private var cnp: String,
    private var anulNasterii: String,
    private var numeFacultate: String,
    private var anInfiintareFacultate: Int
) {
    // Metodele de get si set pentru atributele private
    fun getNume(): String = nume
    fun setNume(nume: String) {
        this.nume = nume
    }

    fun getPrenume(): String = prenume
    fun setPrenume(prenume: String) {
        this.prenume = prenume
    }

    fun getCnp(): String = cnp
    fun setCnp(cnp: String) {
        this.cnp = cnp
    }

    fun getAnulNasterii(): String = anulNasterii
    fun setAnulNasterii(anulNasterii: String) {
        this.anulNasterii = anulNasterii
    }

    fun getNumeFacultate(): String = numeFacultate
    fun setNumeFacultate(numeFacultate: String) {
        this.numeFacultate = numeFacultate
    }

    fun getAnInfiintareFacultate(): Int = anInfiintareFacultate
    fun setAnInfiintareFacultate(anInfiintareFacultate: Int) {
        this.anInfiintareFacultate = anInfiintareFacultate
    }

    // Metoda pentru a returna sexul studentului in functie de CNP
    fun getSex(): String {
        val sexDigit = cnp[0].toString().toInt()
        return if (sexDigit % 2 == 0) "Feminin" else "Masculin"
    }

    // Metoda pentru a returna varsta studentului
    fun getVarsta(): Int {
        val anNastere = anulNasterii.substring(0, 4).toInt()
        val anCurent = LocalDate.now().year
        return anCurent - anNastere
    }

    // Metoda pentru a returna diferenta de ani dintre anul infiintarii facultatii si data nasterii studentului
    fun diferentaAni(): Int {
        val anNastere = anulNasterii.substring(0, 4).toInt()
        return abs( anInfiintareFacultate - anNastere)
    }
}

fun main() {
    // Exemplu de utilizare a clasei Student
    val student = Student("Popescu", "Ana", "2980523456789", "19950101", "Facultatea de Automatica si calculatoare", 1818)

    println("Nume: ${student.getNume()}")
    println("Prenume: ${student.getPrenume()}")
    println("CNP: ${student.getCnp()}")
    println("Sex: ${student.getSex()}")
    println("Varsta: ${student.getVarsta()} ani")
    println("Facultate: ${student.getNumeFacultate()}")
    println("An infiintare facultate: ${student.getAnInfiintareFacultate()}")
    println("Diferenta de ani: ${student.diferentaAni()} ani")
}
