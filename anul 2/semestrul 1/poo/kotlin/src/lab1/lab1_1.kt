class Student {
    var nume: String? = null
    var prenume: String? = null
    var grupa: String? = null
    var pastrat: String? = null
    var imbunatatiri: String? = null
    var dezvoltarePersonala: String? = null
    var dupaFacultate: String? = null
}


fun main(args: Array<String>) {
    var student=Student()
    student.nume ="Paliciuc"
    student.prenume ="Cosmin-Constantin"
    student.grupa ="323AC"
    student.pastrat ="Formatul laboratorului"
    student.imbunatatiri ="nimic"
    student.dezvoltarePersonala ="Cursuri de 3D modelling"
    student.dupaFacultate="Full stack"
    println(student.nume)
    println(student.grupa)
    println(student.pastrat)
    println(student.imbunatatiri)
    println(student.dezvoltarePersonala)
    println(student.dupaFacultate)
}