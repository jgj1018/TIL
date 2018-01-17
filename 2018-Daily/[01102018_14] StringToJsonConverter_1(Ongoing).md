Implementation is not done yet. It's ongoing practice.

```

class JsonConverter(val originalJsonString: String, var depth: Int = 1)
{
    companion object {
        const val KEY = 0
        const val VALUE = 1
    }

    var editingJsonString: String = originalJsonString
    var curlyBraceStack: MutableList<String> = mutableListOf<String>()
    var sourceMap: MutableMap<String, Any> = mutableMapOf<String, Any>()
    var key: String = "";
    var value: String = "";
    //lateinit var JsonArray: Array<T>

    init {
        //this.editingJsonString = originalJsonString
        //print(this.editingJsonString)
        //this.editingJsonString = this.editingJsonString.substring(10, 20)
    }

    fun convertJsonToObect()
    {
        if (isJson()) {
            //this.editingJsonString.substring()
            trimFirstCurlyBrace()
            makeSourceArrayFromString()
        }
        //makeObjectFromSourceArray()
    }

    fun trimFirstCurlyBrace()
    {
        var temp: String = this.editingJsonString
        temp = temp.substring(temp.indexOfFirst { it == '"' }, temp.lastIndex)
        this.curlyBraceStack.add(curlyBraceStack.count(), "{")
        this.editingJsonString = temp
        //this.editingJsonString = temp.substring(0, temp.indexOfLast { it == '}' })
    }

    fun makeSourceArrayFromString()
    {
        var cnt = 0;
        while (!this.editingJsonString.isBlank()) {
            if (cnt++ == 5) {
                break
            }
            setKeyValuePair()
            if (isCurlyBraceIncluded(this.value)) {

            } else {
                when (checkType()) {
                    "String" -> println("This value is String")
                    "Integer"-> println("This value is Integer")
                }
            }
        }
    }

    fun setKeyValuePair(): String
    {
        var commaIndex: Int = this.editingJsonString.indexOf(',')
        var keyValueString: String = this.editingJsonString.substring(0, commaIndex)
        this.editingJsonString = this.editingJsonString.substring(commaIndex+1, this.editingJsonString.lastIndex)
        var stringList: List<String> = keyValueString.split(":")
        this.key = stringList.get(KEY).trim()
        this.value = stringList.get(VALUE).trim()
        // this.tempMap.put(stringList.get(0).trim(), stringList.get(1).trim())
        println(this.key)
        println(this.value)
        return this.value
    }

    fun isCurlyBraceIncluded(valueString: String): Boolean
    {
        if (valueString.contains('{')) {
            this.depth++
        } else {
            this.depth--
        }
        return false
    }

    /**
     * This method is to set type for each value based on Kotlin type.
     * Each Json data type will be converted as below
     *
     * Json   -> Kotlin
     * =================
     * Number -> Integer
     * String -> String
     * Object -> Object
     * Array  -> Array
     * Boolean-> Boolean
     * Null   -> Null
     *
     */
    fun checkType(): String
    {
        val value: String = this.value
        if (value.first() == '"') {
            return "String"
        } else if (value.toIntOrNull() != null) {
            return "Integer"
        }
        return ""
    }
    
    /**
     * This method checks two things.
     * (1) The number of curly brace have to be even number.
     * (2) The string have to be started and ended with curly brace.
     */
    fun isJson(): Boolean
    {
        return true
    }

    /**
     * This method is to check if any specific string contains backslash for escaping.
     */
    fun isEscaped()
    {

    }

    fun makeObjectFromSourceArray()
    {

    }
}
```