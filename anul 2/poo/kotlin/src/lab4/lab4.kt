import kotlin.reflect.KProperty

class Beer(
    protected var tip: String="Default",
    protected var origine:String="Default"
){
    fun fetchType(): String = tip
    fun fetchOrigin(): String = origine
    open fun getDetails(): String = "Tip: $tip, Origin: $origine"
}